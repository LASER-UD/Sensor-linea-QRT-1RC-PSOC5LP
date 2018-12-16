/*******************************************************************************
* File Name: Slinea.h  
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

#if !defined(CY_PINS_Slinea_H) /* Pins Slinea_H */
#define CY_PINS_Slinea_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Slinea_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Slinea__PORT == 15 && ((Slinea__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Slinea_Write(uint8 value);
void    Slinea_SetDriveMode(uint8 mode);
uint8   Slinea_ReadDataReg(void);
uint8   Slinea_Read(void);
void    Slinea_SetInterruptMode(uint16 position, uint16 mode);
uint8   Slinea_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Slinea_SetDriveMode() function.
     *  @{
     */
        #define Slinea_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Slinea_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Slinea_DM_RES_UP          PIN_DM_RES_UP
        #define Slinea_DM_RES_DWN         PIN_DM_RES_DWN
        #define Slinea_DM_OD_LO           PIN_DM_OD_LO
        #define Slinea_DM_OD_HI           PIN_DM_OD_HI
        #define Slinea_DM_STRONG          PIN_DM_STRONG
        #define Slinea_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Slinea_MASK               Slinea__MASK
#define Slinea_SHIFT              Slinea__SHIFT
#define Slinea_WIDTH              1u

/* Interrupt constants */
#if defined(Slinea__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Slinea_SetInterruptMode() function.
     *  @{
     */
        #define Slinea_INTR_NONE      (uint16)(0x0000u)
        #define Slinea_INTR_RISING    (uint16)(0x0001u)
        #define Slinea_INTR_FALLING   (uint16)(0x0002u)
        #define Slinea_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Slinea_INTR_MASK      (0x01u) 
#endif /* (Slinea__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Slinea_PS                     (* (reg8 *) Slinea__PS)
/* Data Register */
#define Slinea_DR                     (* (reg8 *) Slinea__DR)
/* Port Number */
#define Slinea_PRT_NUM                (* (reg8 *) Slinea__PRT) 
/* Connect to Analog Globals */                                                  
#define Slinea_AG                     (* (reg8 *) Slinea__AG)                       
/* Analog MUX bux enable */
#define Slinea_AMUX                   (* (reg8 *) Slinea__AMUX) 
/* Bidirectional Enable */                                                        
#define Slinea_BIE                    (* (reg8 *) Slinea__BIE)
/* Bit-mask for Aliased Register Access */
#define Slinea_BIT_MASK               (* (reg8 *) Slinea__BIT_MASK)
/* Bypass Enable */
#define Slinea_BYP                    (* (reg8 *) Slinea__BYP)
/* Port wide control signals */                                                   
#define Slinea_CTL                    (* (reg8 *) Slinea__CTL)
/* Drive Modes */
#define Slinea_DM0                    (* (reg8 *) Slinea__DM0) 
#define Slinea_DM1                    (* (reg8 *) Slinea__DM1)
#define Slinea_DM2                    (* (reg8 *) Slinea__DM2) 
/* Input Buffer Disable Override */
#define Slinea_INP_DIS                (* (reg8 *) Slinea__INP_DIS)
/* LCD Common or Segment Drive */
#define Slinea_LCD_COM_SEG            (* (reg8 *) Slinea__LCD_COM_SEG)
/* Enable Segment LCD */
#define Slinea_LCD_EN                 (* (reg8 *) Slinea__LCD_EN)
/* Slew Rate Control */
#define Slinea_SLW                    (* (reg8 *) Slinea__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Slinea_PRTDSI__CAPS_SEL       (* (reg8 *) Slinea__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Slinea_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Slinea__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Slinea_PRTDSI__OE_SEL0        (* (reg8 *) Slinea__PRTDSI__OE_SEL0) 
#define Slinea_PRTDSI__OE_SEL1        (* (reg8 *) Slinea__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Slinea_PRTDSI__OUT_SEL0       (* (reg8 *) Slinea__PRTDSI__OUT_SEL0) 
#define Slinea_PRTDSI__OUT_SEL1       (* (reg8 *) Slinea__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Slinea_PRTDSI__SYNC_OUT       (* (reg8 *) Slinea__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Slinea__SIO_CFG)
    #define Slinea_SIO_HYST_EN        (* (reg8 *) Slinea__SIO_HYST_EN)
    #define Slinea_SIO_REG_HIFREQ     (* (reg8 *) Slinea__SIO_REG_HIFREQ)
    #define Slinea_SIO_CFG            (* (reg8 *) Slinea__SIO_CFG)
    #define Slinea_SIO_DIFF           (* (reg8 *) Slinea__SIO_DIFF)
#endif /* (Slinea__SIO_CFG) */

/* Interrupt Registers */
#if defined(Slinea__INTSTAT)
    #define Slinea_INTSTAT            (* (reg8 *) Slinea__INTSTAT)
    #define Slinea_SNAP               (* (reg8 *) Slinea__SNAP)
    
	#define Slinea_0_INTTYPE_REG 		(* (reg8 *) Slinea__0__INTTYPE)
#endif /* (Slinea__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Slinea_H */


/* [] END OF FILE */
