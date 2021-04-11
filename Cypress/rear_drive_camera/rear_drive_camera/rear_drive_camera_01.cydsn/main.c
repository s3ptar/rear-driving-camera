/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/***********************************************************************
* Includes
***********************************************************************/

#include "project.h"
#include "stdio.h"
#include "jsmn.h"

/***********************************************************************
* Informations
***********************************************************************/
//https://www.hackster.io/PSoC_Rocks/psoc-4-measuring-distance-with-hcsr-04-and-cy8ckit-049-4200-db84e8
//https://github.com/zserge/jsmn
/***********************************************************************
* Declarations
***********************************************************************/
 
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
*! \fn          int16_t create_fb(char *dataPtr, byte *fb)
*  \brief       reset the Framebuffer
*  \param       dataPtr String to scroll across
*  \param       fb Pointer to the frame buffer array
*  \exception   none
*  \return      length of frame buffer
***********************************************************************/  
CY_ISR(MyCustomISR){
        
}

/***********************************************************************
*! \fn          int main(void)
*  \brief       start function
*  \param       dataPtr String to scroll across
*  \param       fb Pointer to the frame buffer array
*  \exception   none
*  \return      length of frame buffer
***********************************************************************/ 
int main(void)
{
    
    char uart_buffer[256];
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Enable();
    UART_1_Start();
    UART_1_ClearTxBuffer();
    Range_CLK_Start();
    CNT_RESET_Write(0);
    CyGlobalIntEnable; /* Enable global interrupts. */
    

    for(;;)
    {
        
        CNT_RESET_Write(0);
        CyDelay(1u);
        CNT_RESET_Write(1);
        CyDelay(1u);
        CNT_RESET_Write(0);
        HC_SR04_1_Trigger_Write(1);
        CyDelay(1u);
        HC_SR04_1_Trigger_Write(0);
        CyDelay(10000u);
        
        /* Place your application code here. */
        //wait for empty queue
        while(UART_1_ReadTxStatus()& UART_1_TX_STS_FIFO_FULL ){
        };
        
        //User_LED_Write(!User_LED_Read());
        sprintf(uart_buffer,"Distance %u cm \r\n",Range_1_Read());
        UART_1_PutString(uart_buffer);
        
        
        
        
        //CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_CTW);
        
        
    }
}

/* [] END OF FILE */
