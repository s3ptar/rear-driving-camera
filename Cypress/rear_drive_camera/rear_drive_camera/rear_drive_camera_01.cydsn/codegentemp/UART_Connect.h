/*******************************************************************************
* File Name: UART_Connect.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_UART_Connect_H) /* Pins UART_Connect_H */
#define CY_PINS_UART_Connect_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UART_Connect_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UART_Connect__PORT == 15 && ((UART_Connect__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    UART_Connect_Write(uint8 value);
void    UART_Connect_SetDriveMode(uint8 mode);
uint8   UART_Connect_ReadDataReg(void);
uint8   UART_Connect_Read(void);
void    UART_Connect_SetInterruptMode(uint16 position, uint16 mode);
uint8   UART_Connect_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the UART_Connect_SetDriveMode() function.
     *  @{
     */
        #define UART_Connect_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define UART_Connect_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define UART_Connect_DM_RES_UP          PIN_DM_RES_UP
        #define UART_Connect_DM_RES_DWN         PIN_DM_RES_DWN
        #define UART_Connect_DM_OD_LO           PIN_DM_OD_LO
        #define UART_Connect_DM_OD_HI           PIN_DM_OD_HI
        #define UART_Connect_DM_STRONG          PIN_DM_STRONG
        #define UART_Connect_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define UART_Connect_MASK               UART_Connect__MASK
#define UART_Connect_SHIFT              UART_Connect__SHIFT
#define UART_Connect_WIDTH              1u

/* Interrupt constants */
#if defined(UART_Connect__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in UART_Connect_SetInterruptMode() function.
     *  @{
     */
        #define UART_Connect_INTR_NONE      (uint16)(0x0000u)
        #define UART_Connect_INTR_RISING    (uint16)(0x0001u)
        #define UART_Connect_INTR_FALLING   (uint16)(0x0002u)
        #define UART_Connect_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define UART_Connect_INTR_MASK      (0x01u) 
#endif /* (UART_Connect__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UART_Connect_PS                     (* (reg8 *) UART_Connect__PS)
/* Data Register */
#define UART_Connect_DR                     (* (reg8 *) UART_Connect__DR)
/* Port Number */
#define UART_Connect_PRT_NUM                (* (reg8 *) UART_Connect__PRT) 
/* Connect to Analog Globals */                                                  
#define UART_Connect_AG                     (* (reg8 *) UART_Connect__AG)                       
/* Analog MUX bux enable */
#define UART_Connect_AMUX                   (* (reg8 *) UART_Connect__AMUX) 
/* Bidirectional Enable */                                                        
#define UART_Connect_BIE                    (* (reg8 *) UART_Connect__BIE)
/* Bit-mask for Aliased Register Access */
#define UART_Connect_BIT_MASK               (* (reg8 *) UART_Connect__BIT_MASK)
/* Bypass Enable */
#define UART_Connect_BYP                    (* (reg8 *) UART_Connect__BYP)
/* Port wide control signals */                                                   
#define UART_Connect_CTL                    (* (reg8 *) UART_Connect__CTL)
/* Drive Modes */
#define UART_Connect_DM0                    (* (reg8 *) UART_Connect__DM0) 
#define UART_Connect_DM1                    (* (reg8 *) UART_Connect__DM1)
#define UART_Connect_DM2                    (* (reg8 *) UART_Connect__DM2) 
/* Input Buffer Disable Override */
#define UART_Connect_INP_DIS                (* (reg8 *) UART_Connect__INP_DIS)
/* LCD Common or Segment Drive */
#define UART_Connect_LCD_COM_SEG            (* (reg8 *) UART_Connect__LCD_COM_SEG)
/* Enable Segment LCD */
#define UART_Connect_LCD_EN                 (* (reg8 *) UART_Connect__LCD_EN)
/* Slew Rate Control */
#define UART_Connect_SLW                    (* (reg8 *) UART_Connect__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UART_Connect_PRTDSI__CAPS_SEL       (* (reg8 *) UART_Connect__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UART_Connect_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UART_Connect__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UART_Connect_PRTDSI__OE_SEL0        (* (reg8 *) UART_Connect__PRTDSI__OE_SEL0) 
#define UART_Connect_PRTDSI__OE_SEL1        (* (reg8 *) UART_Connect__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UART_Connect_PRTDSI__OUT_SEL0       (* (reg8 *) UART_Connect__PRTDSI__OUT_SEL0) 
#define UART_Connect_PRTDSI__OUT_SEL1       (* (reg8 *) UART_Connect__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UART_Connect_PRTDSI__SYNC_OUT       (* (reg8 *) UART_Connect__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(UART_Connect__SIO_CFG)
    #define UART_Connect_SIO_HYST_EN        (* (reg8 *) UART_Connect__SIO_HYST_EN)
    #define UART_Connect_SIO_REG_HIFREQ     (* (reg8 *) UART_Connect__SIO_REG_HIFREQ)
    #define UART_Connect_SIO_CFG            (* (reg8 *) UART_Connect__SIO_CFG)
    #define UART_Connect_SIO_DIFF           (* (reg8 *) UART_Connect__SIO_DIFF)
#endif /* (UART_Connect__SIO_CFG) */

/* Interrupt Registers */
#if defined(UART_Connect__INTSTAT)
    #define UART_Connect_INTSTAT            (* (reg8 *) UART_Connect__INTSTAT)
    #define UART_Connect_SNAP               (* (reg8 *) UART_Connect__SNAP)
    
	#define UART_Connect_0_INTTYPE_REG 		(* (reg8 *) UART_Connect__0__INTTYPE)
#endif /* (UART_Connect__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UART_Connect_H */


/* [] END OF FILE */
