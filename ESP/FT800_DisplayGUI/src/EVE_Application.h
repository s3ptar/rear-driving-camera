/***********************************************************************
*! \file:                   EVE_CMD.h
*  \projekt:                Rear Drive Cam
*  \created on:             25.07.2020
*  \author:                 20.07.2021
*  \version:                0
*  \history:                -
*  \brief                   contains cmd and other stuff
***********************************************************************/
 
#ifndef _eve_application_h_
#define _eve_application_h_
 
/***********************************************************************
* Includes
**********************************************************************/
#include "stdint.h"
#include "error_codes.h"
/***********************************************************************
* Informations
**********************************************************************/
//https://www.dyclassroom.com/c/c-pointers-and-two-dimensional-array
 
/***********************************************************************
* Declarations
**********************************************************************/

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

error_type EVE_BootUp(void);
uint32_t read_CHIPID();

void updatecmdfifo(uint16_t count);
void waitcmdfifo_empty();
void recover_co_processor();
void play_sound(uint8_t sound, uint8_t note, uint8_t volume);
void TFT_off();
void TFT_on();
void TFT_dim(uint8_t percent);
void TFT_fadeout(uint16_t zeit);
void TFT_fadein(uint16_t zeit);
void dl(unsigned long cmd);
void video_timing(void);
void cmd_dlstart(void);
void Logo();
void test_disp(void);
void test_disp2(uint16_t loops);
void test(void);
void updatecmdfifo(uint16_t count);
void waitcmdfifo_empty();
void play_sound(uint8_t sound, uint8_t note, uint8_t volume);
void play_song(uint8_t device,uint8_t vol,  uint8_t *song);
void video_timing(void);
void cmd_dlstart(void);
void Logo();
void test_number();
void Touch();
void Time();
void Time2(uint16_t sek, uint16_t min, uint16_t hr);
void CLEAR_FRAMES();
void SAMAPP_Sound();
void GPU_Ball_Stencil();

#endif //_eve_application_h_