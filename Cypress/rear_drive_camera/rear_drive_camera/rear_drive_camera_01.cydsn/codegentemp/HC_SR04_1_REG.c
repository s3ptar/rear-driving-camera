/*******************************************************************************
* File Name: HC_SR04_1_REG.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "HC_SR04_1_REG.h"

#if !defined(HC_SR04_1_REG_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: HC_SR04_1_REG_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 HC_SR04_1_REG_Read(void) 
{ 
    return HC_SR04_1_REG_Status;
}


/*******************************************************************************
* Function Name: HC_SR04_1_REG_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void HC_SR04_1_REG_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    HC_SR04_1_REG_Status_Aux_Ctrl |= HC_SR04_1_REG_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: HC_SR04_1_REG_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void HC_SR04_1_REG_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    HC_SR04_1_REG_Status_Aux_Ctrl &= (uint8)(~HC_SR04_1_REG_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: HC_SR04_1_REG_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void HC_SR04_1_REG_WriteMask(uint8 mask) 
{
    #if(HC_SR04_1_REG_INPUTS < 8u)
    	mask &= ((uint8)(1u << HC_SR04_1_REG_INPUTS) - 1u);
	#endif /* End HC_SR04_1_REG_INPUTS < 8u */
    HC_SR04_1_REG_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: HC_SR04_1_REG_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 HC_SR04_1_REG_ReadMask(void) 
{
    return HC_SR04_1_REG_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
