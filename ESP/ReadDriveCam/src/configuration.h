/***********************************************************************
*! \file:                   configuration.h
*  \projekt:                FT800_ESP
*  \created on:             25.07.2020
*  \author:                 R. Gräber
*  \version:                0
*  \history:                -
*  \brief                   Definitionsfile for global variables
***********************************************************************/
 
#ifndef _configuration_h_
#define _configuration_h_
 
/***********************************************************************
* Includes
**********************************************************************/
#include "stdint.h"
#include "SPI.h"
#include "error_codes.h"
#include <Arduino.h>
#include "settings.h"
#if defined(ESP8266)
    #include <ESP8266WiFi.h>
    #include "LittleFS.h"
#elif defined(ESP32)
    #include "WiFi.h"
    #include "SPIFFS.h"
#endif
#include <ESPAsyncWebServer.h>
#ifdef _mozilla_iot_enable_
    #define ARDUINOJSON_USE_LONG_LONG 1
    #include <Thing.h>
    #include <WebThingAdapter.h>
#endif
#include <ArduinoJson.h>
/***********************************************************************
 * Informations
 **********************************************************************/
//https://www.dyclassroom.com/c/c-pointers-and-two-dimensional-array
 
/***********************************************************************
 * Declarations
 **********************************************************************/
 #define glb_device_name_length  64
 #define wlan_reconnects         3

/*++++++++++++++++++++++++++++++
    ESP_LOGE - error (lowest)
    ESP_LOGW - warning
    ESP_LOGI - info
    ESP_LOGD - debug
    ESP_LOGV - verbose (highest)
    ++++++++++++++++++++++++++*/
 enum log_infomations{
    dbg_nolog = 0,
    dbg_error,
    dbg_warning,
    dbg_info,
    dbg_debug,
    dbg_verbose

};
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
error_type restore_configuration();
error_type connect_wlan();
error_type config_mozilla_iot();
void update_iot();
void system_delay(uint32_t ms_delay);
void system_log(const char *msg, uint8_t InformationClass);

#endif //_filehandling_h_