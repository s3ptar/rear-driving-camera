/*******************************************************************************
* File Name: HC_SR04_1_REG.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_HC_SR04_1_REG_H) /* CY_STATUS_REG_HC_SR04_1_REG_H */
#define CY_STATUS_REG_HC_SR04_1_REG_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
    #include "CyLib.h"
#else
    #include "syslib/cy_syslib.h"
#endif

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} HC_SR04_1_REG_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 HC_SR04_1_REG_Read(void) ;
void HC_SR04_1_REG_InterruptEnable(void) ;
void HC_SR04_1_REG_InterruptDisable(void) ;
void HC_SR04_1_REG_WriteMask(uint8 mask) ;
uint8 HC_SR04_1_REG_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define HC_SR04_1_REG_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define HC_SR04_1_REG_INPUTS              8


/***************************************
*             Registers
***************************************/

/* Status Register */
#define HC_SR04_1_REG_Status             (* (reg8 *) HC_SR04_1_REG_sts_sts_reg__STATUS_REG )
#define HC_SR04_1_REG_Status_PTR         (  (reg8 *) HC_SR04_1_REG_sts_sts_reg__STATUS_REG )
#define HC_SR04_1_REG_Status_Mask        (* (reg8 *) HC_SR04_1_REG_sts_sts_reg__MASK_REG )
#define HC_SR04_1_REG_Status_Aux_Ctrl    (* (reg8 *) HC_SR04_1_REG_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_HC_SR04_1_REG_H */


/* [] END OF FILE */
