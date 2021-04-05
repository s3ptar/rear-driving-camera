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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Enable();
    UART_1_Start();
    UART_1_ClearTxBuffer();

    for(;;)
    {
        /* Place your application code here. */
        //wait for empty queue
        while(UART_1_ReadTxStatus()& UART_1_TX_STS_FIFO_FULL ){
        };
        UART_1_ClearTxBuffer();
        UART_1_PutString("Hello World \r\n") ;
        
    }
}

/* [] END OF FILE */
