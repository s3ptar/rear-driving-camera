/*******************************************************************************
* File Name: SonicClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_SonicClock_H)
#define CY_CLOCK_SonicClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void SonicClock_Start(void) ;
void SonicClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SonicClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SonicClock_StandbyPower(uint8 state) ;
void SonicClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SonicClock_GetDividerRegister(void) ;
void SonicClock_SetModeRegister(uint8 modeBitMask) ;
void SonicClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 SonicClock_GetModeRegister(void) ;
void SonicClock_SetSourceRegister(uint8 clkSource) ;
uint8 SonicClock_GetSourceRegister(void) ;
#if defined(SonicClock__CFG3)
void SonicClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 SonicClock_GetPhaseRegister(void) ;
#endif /* defined(SonicClock__CFG3) */

#define SonicClock_Enable()                       SonicClock_Start()
#define SonicClock_Disable()                      SonicClock_Stop()
#define SonicClock_SetDivider(clkDivider)         SonicClock_SetDividerRegister(clkDivider, 1u)
#define SonicClock_SetDividerValue(clkDivider)    SonicClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define SonicClock_SetMode(clkMode)               SonicClock_SetModeRegister(clkMode)
#define SonicClock_SetSource(clkSource)           SonicClock_SetSourceRegister(clkSource)
#if defined(SonicClock__CFG3)
#define SonicClock_SetPhase(clkPhase)             SonicClock_SetPhaseRegister(clkPhase)
#define SonicClock_SetPhaseValue(clkPhase)        SonicClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SonicClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SonicClock_CLKEN              (* (reg8 *) SonicClock__PM_ACT_CFG)
#define SonicClock_CLKEN_PTR          ((reg8 *) SonicClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SonicClock_CLKSTBY            (* (reg8 *) SonicClock__PM_STBY_CFG)
#define SonicClock_CLKSTBY_PTR        ((reg8 *) SonicClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SonicClock_DIV_LSB            (* (reg8 *) SonicClock__CFG0)
#define SonicClock_DIV_LSB_PTR        ((reg8 *) SonicClock__CFG0)
#define SonicClock_DIV_PTR            ((reg16 *) SonicClock__CFG0)

/* Clock MSB divider configuration register. */
#define SonicClock_DIV_MSB            (* (reg8 *) SonicClock__CFG1)
#define SonicClock_DIV_MSB_PTR        ((reg8 *) SonicClock__CFG1)

/* Mode and source configuration register */
#define SonicClock_MOD_SRC            (* (reg8 *) SonicClock__CFG2)
#define SonicClock_MOD_SRC_PTR        ((reg8 *) SonicClock__CFG2)

#if defined(SonicClock__CFG3)
/* Analog clock phase configuration register */
#define SonicClock_PHASE              (* (reg8 *) SonicClock__CFG3)
#define SonicClock_PHASE_PTR          ((reg8 *) SonicClock__CFG3)
#endif /* defined(SonicClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SonicClock_CLKEN_MASK         SonicClock__PM_ACT_MSK
#define SonicClock_CLKSTBY_MASK       SonicClock__PM_STBY_MSK

/* CFG2 field masks */
#define SonicClock_SRC_SEL_MSK        SonicClock__CFG2_SRC_SEL_MASK
#define SonicClock_MODE_MASK          (~(SonicClock_SRC_SEL_MSK))

#if defined(SonicClock__CFG3)
/* CFG3 phase mask */
#define SonicClock_PHASE_MASK         SonicClock__CFG3_PHASE_DLY_MASK
#endif /* defined(SonicClock__CFG3) */

#endif /* CY_CLOCK_SonicClock_H */


/* [] END OF FILE */
