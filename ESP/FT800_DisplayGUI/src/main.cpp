#include <Arduino.h>
#include "FT_Gpu_Hal.h"
#include "WiFi.h"
#include <HTTPClient.h>
#include <esp_task_wdt.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "FT_Gpu.h"
/***********************************************************************
* Informations
***********************************************************************/
//https://github.com/espressif/arduino-esp32/tree/master/libraries/ESP32/examples/Camera/CameraWebServer
/***********************************************************************
* Declarations
***********************************************************************/
char* ssid = "chilihotdog";
char* password = "bxJHckMMkGqEPfY3Jf3nZnAn5FtGYwKZSkzVvbzFHNbpUZfv79GXm8afDuNu";
FT800 eve(5,10,9);
HTTPClient http;
uint8_t jpg_buffer[8192];
uint8_t *ptr_jpg_buffer;
char data[32];
/***********************************************************************
* Global Variable
***********************************************************************/

/***********************************************************************
* Constant
***********************************************************************/

unsigned short marker;
unsigned short length;
unsigned short y_pic_size;
unsigned short x_pic_size;

uint32_t cur_string_pos;
ft_uint16_t blocklen;
/***********************************************************************
* Local Funtions
***********************************************************************/


/***********************************************************************
*! \fn          void setup()
*  \brief       Arduino Setup - Routine
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void setup() {
    // put your setup code here, to run once:
    

    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector x
    
    Serial.begin(115200);
    Serial.println("WiFi");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    Serial.println("Connected");
    eve.Bootup();
    eve.Ft_Gpu_Hal_Init();
    eve.Ft_Gpu_CoCmd_Logo();

    
}

void loop() {
    // put your main code here, to run repeatedly:

    //
delay(10000);

    eve.Ft_Gpu_CoCmd_Dlstart();                                   // start a new display command list
    eve.Ft_App_WrCoCmd_Buffer(CLEAR_COLOR_RGB(255,255,255));      // set the clear color to white
    eve.Ft_App_WrCoCmd_Buffer(CLEAR(1,1,1));                      // clear buffers -> color buffer,stencil buffer, tag buffer
    eve.Ft_App_WrCoCmd_Buffer(COLOR_RGB(255,255,255));         // set current color
    
    if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
        http.begin("http://192.168.0.19/capture"); //Specify the URL
        int httpCode = http.GET();                                        //Make the request
 
        if (httpCode > 0) { //Check for the returning code
 
            String payload = http.getString();
            //Serial.println(httpCode);
            //Serial.println(payload);
            unsigned int Fsize = payload.length();
            cur_string_pos = 0;
            Serial.print("File Size:");Serial.println(Fsize);

            ptr_jpg_buffer = &jpg_buffer[0];
            for(uint16_t loop_index=0; loop_index < Fsize; loop_index++ ){
               *ptr_jpg_buffer = (uint8_t)payload.substring(loop_index+0,loop_index+1)[0];
               ptr_jpg_buffer ++;
            }
            //clear String 
            payload = "";
            
            marker = jpg_buffer[0] + (jpg_buffer[1]<<8);
            cur_string_pos = 0;
            //length = payload.substring(cur_string_pos+2,2).toInt();
            do {
                if(marker == 0xFFC0) break;
                if(marker & 0xFF00 != 0xFF00) break;
                if(cur_string_pos > Fsize) break;
                //if (fseek(fp, length - 2,SEEK_CUR) != 0) break;
                marker = jpg_buffer[cur_string_pos+1] + (jpg_buffer[cur_string_pos+0]<<8);
                sprintf(&data[0],"0x%04x", marker);
                cur_string_pos += 2;
                Serial.print("Marker :");Serial.print(data);Serial.print(" Pos:");Serial.println(cur_string_pos); 
            } while(1);
            if(marker != 0xFFC0){
                Serial.println("no FFC0 Marker, wrong format no baseline DCT-based JPEG");  // no FFC0 Marker, wrong format no baseline DCT-based JPEG
            }else{
                cur_string_pos += 3;
                y_pic_size = jpg_buffer[cur_string_pos+1] + (jpg_buffer[cur_string_pos+0]<<8);
                Serial.print("Y Pic Size:");Serial.println(y_pic_size);
                cur_string_pos += 2; 
                x_pic_size = jpg_buffer[cur_string_pos+1] + (jpg_buffer[cur_string_pos+0]<<8);
                Serial.print("X Pic Size:");Serial.println(x_pic_size);

                cur_string_pos = 0;
                eve.Ft_Gpu_Hal_WrCmd32(CMD_LOADIMAGE);
                eve.Ft_Gpu_Hal_WrCmd32(0);//destination address of jpg decode
                eve.Ft_Gpu_Hal_WrCmd32(0);//output format of the bitmap - default is rgb565
                while(Fsize > 0) {
                    /* download the data into the command buffer by 8kb one shot */
                    blocklen = Fsize>8192?8192:Fsize;
                    /* copy the data into pbuff and then transfter it to command buffer */
                    //fread(pbuff,1,blocklen,fp);
                    Fsize -= blocklen;
                    Serial.print("File Size:");Serial.println(Fsize);
                    /* copy data continuously into command memory */
                    eve.Ft_Gpu_Hal_WrCmdBuf(&jpg_buffer[0],blocklen); //alignment is already taken care by this api
                }
                Serial.println("Display IT");
                eve.Ft_App_WrCoCmd_Buffer(BEGIN(BITMAPS));
                eve.Ft_Gpu_CoCmd_LoadIdentity();
                //TFT.Ft_Gpu_CoCmd_Rotate((45*65536/360));//rotate by 45 degrees anticlock wise
                //TFT.Ft_Gpu_CoCmd_Scale(32768,32768);//scale by  2x2
                eve.Ft_Gpu_CoCmd_SetMatrix();
                eve.Ft_App_WrCoCmd_Buffer(VERTEX2F(0,0));
 
                eve.Ft_App_WrCoCmd_Buffer(DISPLAY());                                   // Display the image
                eve.Ft_Gpu_CoCmd_Swap();                                                // Swap the current display list
 
                eve.Ft_App_Flush_Co_Buffer();                                           // Download the commands into fifo
                eve.Ft_Gpu_Hal_WaitCmdfifo_empty();                                     // Wait till coprocessor completes the operation

            }
        }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
    // put your main code here, to run repeatedly:
    
}
