
/***********************************************************************
*! \file:                   EVE_LCD_Type.h
*  \projekt:                Rear Drive Cam
*  \created on:             20.07.2021
*  \author:                 R. Gräber
*  \version:                0
*  \history:                -
*  \brief                   contains the lcd definitions
***********************************************************************/
 
#ifndef _eve_lcd_type_h_
#define _eve_lcd_type_h_
 
/***********************************************************************
* Includes
**********************************************************************/
#include "stdio.h"
#include "stdint.h"
#include "config.h"
/***********************************************************************
* Informations
**********************************************************************/
//https://download.bastelgarage.ch/Datasheet/ESP8266_Heltec_Wifi_Kit_Schema.png
 
/***********************************************************************
* Declarations
**********************************************************************/

#define _LCD_Type_ET0430_

#if defined(_LCD_Type_ET0430_)
#define LCD_DispWidth    480
#define LCD_DispHeight   272
#define LCD_DispHCycle   548
#define LCD_DispHOffset  43
#define LCD_DispHSync0   0
#define LCD_DispHSync1   41
#define LCD_DispVCycle   292
#define LCD_DispVOffset  12
#define LCD_DispVSync0   0
#define LDC_DispVSync1   10
#define LCD_DispPCLK     5
#define LCD_DispSwizzle  0
#define LCD_DispPCLKPol  1
 
/* the GLYN display has inverted backlite */
#define Inv_Backlite     1

#endif

/***********************************************************************
* Global Variable
**********************************************************************/

/***********************************************************************
 * Constant
 **********************************************************************/
 
/***********************************************************************
 * Macros
 **********************************************************************/
 
/***********************************************************************
 * Funtions
 **********************************************************************/
#endif //_eve_lcd_type_h_