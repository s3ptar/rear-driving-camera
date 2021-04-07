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
#include "project.h"
#include "stdio.h"

uint8_t HC_SR01_Distance;

int main(void)
{
    
    char uart_buffer[256];
    CyGlobalIntEnable; /* Enable global interrupts. */
   

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Enable();
    UART_1_Start();
    ISR_HC_SR04_1_Start();
    UART_1_ClearTxBuffer();
    SonicClock_Enable();
    PWM_CLOCK_Enable();
    PWM_1_Start();
    

    for(;;)
    {
        /* Place your application code here. */
        //wait for empty queue
        while(UART_1_ReadTxStatus()& UART_1_TX_STS_FIFO_FULL ){
        };
        CyDelay(2000u);
        //User_LED_Write(!User_LED_Read());
        sprintf(uart_buffer,"Distance %u mm \r\n",HC_SR01_Distance);
        UART_1_PutString(uart_buffer);
        

        //CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_CTW);
        
        
    }
}

/* [] END OF FILE */
