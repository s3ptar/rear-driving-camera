/*******************************************************************************
* File Name: NewHCSR04DataRequest.h
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
#if !defined(CY_ISR_NewHCSR04DataRequest_H)
#define CY_ISR_NewHCSR04DataRequest_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void NewHCSR04DataRequest_Start(void);
void NewHCSR04DataRequest_StartEx(cyisraddress address);
void NewHCSR04DataRequest_Stop(void);

CY_ISR_PROTO(NewHCSR04DataRequest_Interrupt);

void NewHCSR04DataRequest_SetVector(cyisraddress address);
cyisraddress NewHCSR04DataRequest_GetVector(void);

void NewHCSR04DataRequest_SetPriority(uint8 priority);
uint8 NewHCSR04DataRequest_GetPriority(void);

void NewHCSR04DataRequest_Enable(void);
uint8 NewHCSR04DataRequest_GetState(void);
void NewHCSR04DataRequest_Disable(void);

void NewHCSR04DataRequest_SetPending(void);
void NewHCSR04DataRequest_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the NewHCSR04DataRequest ISR. */
#define NewHCSR04DataRequest_INTC_VECTOR            ((reg32 *) NewHCSR04DataRequest__INTC_VECT)

/* Address of the NewHCSR04DataRequest ISR priority. */
#define NewHCSR04DataRequest_INTC_PRIOR             ((reg8 *) NewHCSR04DataRequest__INTC_PRIOR_REG)

/* Priority of the NewHCSR04DataRequest interrupt. */
#define NewHCSR04DataRequest_INTC_PRIOR_NUMBER      NewHCSR04DataRequest__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable NewHCSR04DataRequest interrupt. */
#define NewHCSR04DataRequest_INTC_SET_EN            ((reg32 *) NewHCSR04DataRequest__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the NewHCSR04DataRequest interrupt. */
#define NewHCSR04DataRequest_INTC_CLR_EN            ((reg32 *) NewHCSR04DataRequest__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the NewHCSR04DataRequest interrupt state to pending. */
#define NewHCSR04DataRequest_INTC_SET_PD            ((reg32 *) NewHCSR04DataRequest__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the NewHCSR04DataRequest interrupt. */
#define NewHCSR04DataRequest_INTC_CLR_PD            ((reg32 *) NewHCSR04DataRequest__INTC_CLR_PD_REG)


#endif /* CY_ISR_NewHCSR04DataRequest_H */


/* [] END OF FILE */
