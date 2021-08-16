/***********************************************************************
*! \file:                   EVE_HAL.c
*  \projekt:                Rear Drive Cam
*  \created on:             25.07.2020
*  \author:                 R.Gräber
*  \version:                0
*  \history:                0
*  \brief                   handle spi communication
***********************************************************************/
 
/***********************************************************************
* Includes
***********************************************************************/
#include <Arduino.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "EVE_HAL.h"
#include <SPI.h>

/***********************************************************************
* Informations
***********************************************************************/
//https://www.dyclassroom.com/c/c-pointers-and-two-dimensional-array
/***********************************************************************
* Declarations
***********************************************************************/
#define EVE_INDEX_WRITE   (0x70 | DisplayID)
#define EVE_REG_WRITE     (0x72 | DisplayID)
#define EVE_REG_READ      (0x73 | DisplayID)
#define INDEX_WRITE_WORD  ((INDEX_WRITE)<<8)
#define REG_WRITE_WORD    ((REG_WRITE)<<8)
#define REG_READ_WORD     ((REG_READ)<<8)

#define ChipOn  1      
#define ChipOff 0 

#define EVE_CS_on  		digitalWrite(_nCS_Pin,false) 
#define EVE_CS_off 		digitalWrite(_nCS_Pin,true)


#define EVE_Power_off  	digitalWrite(_nPD_Pin,false)
#define EVE_Power_on   	digitalWrite(_nPD_Pin,false)
/***********************************************************************
* local Variable
***********************************************************************/

int _nCS_Pin, _nPD_Pin, _nINT_Pin;

/***********************************************************************
* Global Variable
***********************************************************************/



/***********************************************************************
* Constant
***********************************************************************/

/***********************************************************************
* local VFunctions
***********************************************************************/
void SelectChipOnOff(bool ChipOnOff);

/***********************************************************************
*! \fn          void EVE_HAL_init( int SCLK_Pin, int MISO_Pin,int MOSI_Pin, 
*                                  int nCS_Pin, int nPD_Pin, int nINT_Pin)
*  \brief       initialization from SPI and Pins
*  \param       int SCLK_Pin, int MISO_Pin,int MOSI_Pin -> SPI Pins
*  \param       int nCS_Pin, int nPD_Pin, int nINT_Pin -> Ctrl Pins
*  \exception   none
*  \return      chip id
***********************************************************************/
void EVE_HAL_init( int SCLK_Pin, int MISO_Pin,int MOSI_Pin, int nCS_Pin, int nPD_Pin, int nINT_Pin){
    SPI.begin(SCLK_Pin,MISO_Pin,nCS_Pin);
    SPISettings(16000000,SPI_MSBFIRST, SPI_MODE0);
    _nCS_Pin = nCS_Pin;
    _nPD_Pin = nPD_Pin;
    _nINT_Pin = nINT_Pin;
    pinMode(_nCS_Pin, OUTPUT);
    pinMode(_nPD_Pin, OUTPUT);
    pinMode(_nINT_Pin, INPUT);
    EVE_CS_off;                          // cs high
    EVE_Power_off;                          // PD high 


}

/***********************************************************************
*! \fn          void EVE_HAL_init( int SCLK_Pin, int MISO_Pin,int MOSI_Pin, 
*                                  int nCS_Pin, int nPD_Pin, int nINT_Pin)
*  \brief       initialization from SPI and Pins
*  \param       int SCLK_Pin, int MISO_Pin,int MOSI_Pin -> SPI Pins
*  \param       int nCS_Pin, int nPD_Pin, int nINT_Pin -> Ctrl Pins
*  \exception   none
*  \return      chip id
***********************************************************************/
void SelectChipOnOff(bool ChipOnOff){
    unsigned char go=1;
    uint32_t timeout=1000000;
    if (ChipOnOff == ChipOn)
        EVE_CS_on;
    else if (ChipOnOff == ChipOff){
        while(go){
            timeout--;
            if(timeout==0)go=0;    
        } 
        EVE_CS_off;  
    } 
        
}


/***********************************************************************
*! \fn          void EVE_HAL_WRITE8(uint32_t address, uint8_t data)
*  \brief       write 8Bit with spi
*  \param       uint32_t address -> Register Adress
*  \param       uint8_t data -> Data to write
*  \exception   none
*  \return      none
***********************************************************************/
void EVE_HAL_WRITE8(uint32_t address, uint8_t data){

    SelectChipOnOff(ChipOn);
    SPI.transfer(0x80|(address>>16));
    SPI.transfer(address>>8);
    SPI.transfer(address);
    SPI.transfer(data);
    SelectChipOnOff(ChipOff);

}

/***********************************************************************
*! \fn          void EVE_HAL_WRITE16(uint32_t address, uint16_t data)
*  \brief       write 16Bit with spi
*  \param       uint32_t address -> Register Adress
*  \param       uint16_t data -> Data to write
*  \exception   none
*  \return      none
***********************************************************************/
void EVE_HAL_WRITE16(uint32_t address, uint16_t data){

    SelectChipOnOff(ChipOn);
    SPI.transfer(0x80|(address>>16));
    SPI.transfer(address>>8);
    SPI.transfer(address);
    SPI.transfer(data&0xFF);
    SPI.transfer((data>>8)&0xff);
    SelectChipOnOff(ChipOff);

}

/***********************************************************************
*! \fn          void EVE_HAL_WRITE32(uint32_t address, uint32_t data)
*  \brief       write 32Bit with spi 
*  \param       uint32_t address -> Register Adress
*  \param       uint32_t data -> Data to write
*  \exception   none
*  \return      none
***********************************************************************/
void EVE_HAL_WRITE32(uint32_t address, uint32_t data){

    SelectChipOnOff(ChipOn);
    SPI.transfer(0x80|(address>>16));
    SPI.transfer(address>>8);
    SPI.transfer(address);
    SPI.transfer(data&0xFF);
    SPI.transfer((data>>8)&0xff);
    SPI.transfer((data>>16)&0xff);
    SPI.transfer((data>>24)&0xff);
    SelectChipOnOff(ChipOff);

}


/***********************************************************************
*! \fn          uint8_t EVE_HAL_Read8(uint32_t address)
*  \brief       read 8Bit with spi 
*  \param       uint32_t address -> Register Adress
*  \exception   none
*  \return      dread data
***********************************************************************/
uint8_t EVE_HAL_Read8(uint32_t address){

    SelectChipOnOff(ChipOn);
    SPI.transfer(0x00|(address>>16));
    SPI.transfer(address>>8);
    SPI.transfer(address);

}
uint16_t EVE_HAL_Read16(uint32_t address);
uint32_t EVE_HAL_Read32(uint32_t address);