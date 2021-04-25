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
 /* DMA Configuration for DMA_TX */
#define DMA_TX_BYTES_PER_BURST      (1u)
#define DMA_TX_REQUEST_PER_BURST    (1u)
#define DMA_TX_SRC_BASE             (CYDEV_SRAM_BASE)
#define DMA_TX_DST_BASE             (CYDEV_PERIPH_BASE)

/* DMA Configuration for DMA_RX */
#define DMA_RX_BYTES_PER_BURST      (1u)
#define DMA_RX_REQUEST_PER_BURST    (1u)
#define DMA_RX_SRC_BASE             (CYDEV_PERIPH_BASE)
#define DMA_RX_DST_BASE             (CYDEV_SRAM_BASE)

#define BUFFER_SIZE                 (8u)
#define STORE_TD_CFG_ONCMPLT        (1u)



/* The txBuffer size is equal (BUFFER_SIZE-1) because for SPI Mode where CPHA == 0 and
* CPOL == 0 one byte writes directly in SPI TX FIFO using SPIS_WriteTxDataZero() API.
*/
/***********************************************************************
* Global Variable
***********************************************************************/
uint8_t  dma_bufer[] = "Greetings from DMA Transfer \r\n";
/* Variable declarations for DMA_TX and DMA_RX*/
uint8 txChannel, rxChannel;
uint8 txTD, rxTD;
/***********************************************************************
* Constant
***********************************************************************/
 
/***********************************************************************
* Local Funtions
***********************************************************************/

void DmaTxConfiguration(void);
void DmaRxConfiguration(void);


uint8 txBuffer [BUFFER_SIZE-1] = {0x09u, 0x0Au, 0x0Bu, 0x0Cu, 0x0Du, 0x0Eu, 0x0Fu};
uint8 rxBuffer [BUFFER_SIZE];
    
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


/*******************************************************************************
* Function Name: DmaTxConfiguration
********************************************************************************
* Summary:
*  Configures the DMA to manage data transfers from the TX buffer (allocated in 
*  RAM) into SPIS TX FIFO.
*   
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DmaTxConfiguration()
{
    txChannel = DMA_MEM_TO_UART_DmaInitialize(DMA_TX_BYTES_PER_BURST, DMA_TX_REQUEST_PER_BURST, 
                                        HI16(DMA_TX_SRC_BASE), HI16(DMA_TX_DST_BASE));

    txTD = CyDmaTdAllocate();

    CyDmaTdSetConfiguration(txTD, (BUFFER_SIZE-1), CY_DMA_DISABLE_TD, TD_INC_SRC_ADR);
    CyDmaTdSetAddress(txTD, LO16((uint32) txBuffer), LO16((uint32) UART_1_TXDATA_PTR));
    CyDmaChSetInitialTd(txChannel, txTD);
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
    
    DMA_MEM_TO_UART_Init();

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
        CyDelay(3000u);
        
        /* Place your application code here. */
        //wait for empty queue
        while(UART_1_ReadTxStatus()& UART_1_TX_STS_FIFO_FULL ){
        };
        
        //User_LED_Write(!User_LED_Read());
        sprintf(uart_buffer,"Distance %u cm \r\n",Range_1_Read());
        //UART_1_PutString(uart_buffer);
        
        
        
        
        //CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_CTW);
        
        
    }
}

/* [] END OF FILE */
