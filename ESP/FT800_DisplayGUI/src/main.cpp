#include <Arduino.h>
#include "FT_Gpu_Hal.h"
#include "WiFi.h"
#include <HTTPClient.h>
#include <esp_task_wdt.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
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
/***********************************************************************
* Global Variable
***********************************************************************/

/***********************************************************************
* Constant
***********************************************************************/


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
    
    if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
        http.begin("http://192.168.0.19/capture"); //Specify the URL
        int httpCode = http.GET();                                        //Make the request
 
        if (httpCode > 0) { //Check for the returning code
 
            String payload = http.getString();
            Serial.println(httpCode);
            Serial.println(payload);
        }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
    // put your main code here, to run repeatedly:
    delay(10000);
}