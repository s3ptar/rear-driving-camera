/*******************************************************************************
* File Name: WakeUpIST.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_WakeUpIST_H)
#define CY_ISR_WakeUpIST_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void WakeUpIST_Start(void);
void WakeUpIST_StartEx(cyisraddress address);
void WakeUpIST_Stop(void);

CY_ISR_PROTO(WakeUpIST_Interrupt);

void WakeUpIST_SetVector(cyisraddress address);
cyisraddress WakeUpIST_GetVector(void);

void WakeUpIST_SetPriority(uint8 priority);
uint8 WakeUpIST_GetPriority(void);

void WakeUpIST_Enable(void);
uint8 WakeUpIST_GetState(void);
void WakeUpIST_Disable(void);

void WakeUpIST_SetPending(void);
void WakeUpIST_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the WakeUpIST ISR. */
#define WakeUpIST_INTC_VECTOR            ((reg32 *) WakeUpIST__INTC_VECT)

/* Address of the WakeUpIST ISR priority. */
#define WakeUpIST_INTC_PRIOR             ((reg8 *) WakeUpIST__INTC_PRIOR_REG)

/* Priority of the WakeUpIST interrupt. */
#define WakeUpIST_INTC_PRIOR_NUMBER      WakeUpIST__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable WakeUpIST interrupt. */
#define WakeUpIST_INTC_SET_EN            ((reg32 *) WakeUpIST__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the WakeUpIST interrupt. */
#define WakeUpIST_INTC_CLR_EN            ((reg32 *) WakeUpIST__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the WakeUpIST interrupt state to pending. */
#define WakeUpIST_INTC_SET_PD            ((reg32 *) WakeUpIST__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the WakeUpIST interrupt. */
#define WakeUpIST_INTC_CLR_PD            ((reg32 *) WakeUpIST__INTC_CLR_PD_REG)


#endif /* CY_ISR_WakeUpIST_H */


/* [] END OF FILE */
