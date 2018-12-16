/*******************************************************************************
* File Name: LCD_Char_1.h
* Version 1.2
*
* Description:
*  This header file contains registers and constants associated with the
*  Character LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CHARLCD_LCD_Char_1_H)
#define CY_CHARLCD_LCD_Char_1_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define LCD_Char_1_CONVERSION_ROUTINES     (1u)
#define LCD_Char_1_CUSTOM_CHAR_SET         (0u)

/* Custom character set types */
#define LCD_Char_1_NONE                     (0u)    /* No Custom Fonts      */
#define LCD_Char_1_HORIZONTAL_BG            (1u)    /* Horizontal Bar Graph */
#define LCD_Char_1_VERTICAL_BG              (2u)    /* Vertical Bar Graph   */
#define LCD_Char_1_USER_DEFINED             (3u)    /* User Defined Fonts   */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} LCD_Char_1_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void LCD_Char_1_Init(void) ;
void LCD_Char_1_Enable(void) ;
void LCD_Char_1_Start(void) ;
void LCD_Char_1_Stop(void) ;
void LCD_Char_1_WriteControl(uint8 cByte) ;
void LCD_Char_1_WriteData(uint8 dByte) ;
void LCD_Char_1_PrintString(char8 const string[]) ;
void LCD_Char_1_Position(uint8 row, uint8 column) ;
void LCD_Char_1_PutChar(char8 character) ;
void LCD_Char_1_IsReady(void) ;
void LCD_Char_1_SaveConfig(void) ;
void LCD_Char_1_RestoreConfig(void) ;
void LCD_Char_1_Sleep(void) ;
void LCD_Char_1_Wakeup(void) ;

#define LCD_Char_1_PosPrintString(row, col, string) LCD_Char_1_Position(row, col); LCD_Char_1_PrintString(string); 
#define LCD_Char_1_PosPutChar(row, col, character) LCD_Char_1_Position(row, col); LCD_Char_1_PutChar(character); 

#if((LCD_Char_1_CUSTOM_CHAR_SET == LCD_Char_1_VERTICAL_BG) || \
                (LCD_Char_1_CUSTOM_CHAR_SET == LCD_Char_1_HORIZONTAL_BG))

    void  LCD_Char_1_LoadCustomFonts(uint8 const customData[])
                        ;

    void  LCD_Char_1_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void LCD_Char_1_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((LCD_Char_1_CUSTOM_CHAR_SET == LCD_Char_1_VERTICAL_BG) */

#if(LCD_Char_1_CUSTOM_CHAR_SET == LCD_Char_1_USER_DEFINED)

    void LCD_Char_1_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((LCD_Char_1_CUSTOM_CHAR_SET == LCD_Char_1_USER_DEFINED) */

#if(LCD_Char_1_CONVERSION_ROUTINES == 1u)

    /* ASCII Conversion Routines */
    void LCD_Char_1_PrintInt8(uint8 value) ;
    void LCD_Char_1_PrintInt16(uint16 value) ;
    void LCD_Char_1_PrintNumber(uint16 value) ; 
	
	#define LCD_Char_1_PosPrintInt8(row, col, value) LCD_Char_1_Position(row, col); LCD_Char_1_PrintInt8(value); 
	#define LCD_Char_1_PosPrintInt16(row, col, value) LCD_Char_1_Position(row, col); LCD_Char_1_PrintInt16(value);
	#define LCD_Char_1_PosPrintNumber(row, col, value) LCD_Char_1_Position(row, col); LCD_Char_1_PrintNumber(value);

#endif /* LCD_Char_1_CONVERSION_ROUTINES == 1u */

/* Clear Macro */
#define LCD_Char_1_ClearDisplay() LCD_Char_1_WriteControl(LCD_Char_1_CLEAR_DISPLAY)

/* Off Macro */
#define LCD_Char_1_DisplayOff() LCD_Char_1_WriteControl(LCD_Char_1_DISPLAY_CURSOR_OFF)

/* On Macro */
#define LCD_Char_1_DisplayOn() LCD_Char_1_WriteControl(LCD_Char_1_DISPLAY_ON_CURSOR_OFF)


/***************************************
*           Global Variables
***************************************/

extern uint8 LCD_Char_1_initVar;
extern uint8 LCD_Char_1_enableState;
extern uint8 const CYCODE LCD_Char_1_customFonts[64u];


/***************************************
*           API Constants
***************************************/

/* Full Byte Commands Sent as Two Nibbles */
#define LCD_Char_1_DISPLAY_8_BIT_INIT       (0x03u)
#define LCD_Char_1_DISPLAY_4_BIT_INIT       (0x02u)
#define LCD_Char_1_DISPLAY_CURSOR_OFF       (0x08u)
#define LCD_Char_1_CLEAR_DISPLAY            (0x01u)
#define LCD_Char_1_CURSOR_AUTO_INCR_ON      (0x06u)
#define LCD_Char_1_DISPLAY_CURSOR_ON        (0x0Eu)
#define LCD_Char_1_DISPLAY_2_LINES_5x10     (0x2Cu)
#define LCD_Char_1_DISPLAY_ON_CURSOR_OFF    (0x0Cu)

#define LCD_Char_1_RESET_CURSOR_POSITION    (0x03u)
#define LCD_Char_1_CURSOR_WINK              (0x0Du)
#define LCD_Char_1_CURSOR_BLINK             (0x0Fu)
#define LCD_Char_1_CURSOR_SH_LEFT           (0x10u)
#define LCD_Char_1_CURSOR_SH_RIGHT          (0x14u)
#define LCD_Char_1_CURSOR_HOME              (0x02u)
#define LCD_Char_1_CURSOR_LEFT              (0x04u)
#define LCD_Char_1_CURSOR_RIGHT             (0x06u)

/* Point to Character Generator Ram 0 */
#define LCD_Char_1_CGRAM_0                  (0x40u)

/* Point to Display Data Ram 0 */
#define LCD_Char_1_DDRAM_0                  (0x80u)

/* LCD Characteristics */
#define LCD_Char_1_CHARACTER_WIDTH          (0x05u)
#define LCD_Char_1_CHARACTER_HEIGHT         (0x08u)

#if(LCD_Char_1_CONVERSION_ROUTINES == 1u)
    #define LCD_Char_1_NUMBER_OF_REMAINDERS (0x05u)
    #define LCD_Char_1_TEN                  (0x0Au)
#endif /* LCD_Char_1_CONVERSION_ROUTINES == 1u */

/* Nibble Offset and Mask */
#define LCD_Char_1_NIBBLE_SHIFT             (0x04u)
#define LCD_Char_1_NIBBLE_MASK              (0x0Fu)

/* LCD Module Address Constants */
#define LCD_Char_1_ROW_0_START              (0x80u)
#define LCD_Char_1_ROW_1_START              (0xC0u)
#define LCD_Char_1_ROW_2_START              (0x94u)
#define LCD_Char_1_ROW_3_START              (0xD4u)

/* Custom Character References */
#define LCD_Char_1_CUSTOM_0                 (0x00u)
#define LCD_Char_1_CUSTOM_1                 (0x01u)
#define LCD_Char_1_CUSTOM_2                 (0x02u)
#define LCD_Char_1_CUSTOM_3                 (0x03u)
#define LCD_Char_1_CUSTOM_4                 (0x04u)
#define LCD_Char_1_CUSTOM_5                 (0x05u)
#define LCD_Char_1_CUSTOM_6                 (0x06u)
#define LCD_Char_1_CUSTOM_7                 (0x07u)

/* Other constants */
#define LCD_Char_1_BYTE_UPPER_NIBBLE_SHIFT   (0x04u)
#define LCD_Char_1_BYTE_LOWER_NIBBLE_MASK    (0x0Fu)
#define LCD_Char_1_U16_UPPER_BYTE_SHIFT      (0x08u)
#define LCD_Char_1_U16_LOWER_BYTE_MASK       (0xFFu)
#define LCD_Char_1_CUSTOM_CHAR_SET_LEN       (0x40u)

#define LCD_Char_1_CMD_DELAY_US              (2500u)
#define LCD_Char_1_DATA_DELAY_US              (150u)
#define LCD_Char_1_NIB_DELAY_US               (100u)


/***************************************
*             Registers
***************************************/

#if(CY_PSOC5A)
#define LCD_Char_1_CNTL_REG        (* (reg8 *) LCD_Char_1_Cntl_Port_Async_ctrl_reg__CONTROL_REG )
#define LCD_Char_1_CNTL_PTR        (  (reg8 *) LCD_Char_1_Cntl_Port_Async_ctrl_reg__CONTROL_REG )
#else
#define LCD_Char_1_CNTL_REG        (* (reg8 *) LCD_Char_1_Cntl_Port_Sync_ctrl_reg__CONTROL_REG )
#define LCD_Char_1_CNTL_PTR        (  (reg8 *) LCD_Char_1_Cntl_Port_Sync_ctrl_reg__CONTROL_REG )
#endif /* CY_PSoC5A */

/***************************************
 *       Register Constants
 ***************************************/
                                                  
/* Pin Masks */
#define LCD_Char_1_E                        ((uint8) 0x10u)
#define LCD_Char_1_RS                       ((uint8) 0x20u)
#define LCD_Char_1_RW                       ((uint8) 0x40u)
#define LCD_Char_1_READY_BIT                ((uint8) 0x08u)
#define LCD_Char_1_DATA_MASK                ((uint8) 0x0Fu)


/***************************************
*       Obsolete function names
***************************************/
#if(LCD_Char_1_CONVERSION_ROUTINES == 1u)
    /* This function names are obsolete an they will be removed in future 
    * revisions of component.
    */
    #define LCD_Char_1_PrintDecUint16(x)   LCD_Char_1_PrintNumber(x)  
    #define LCD_Char_1_PrintHexUint8(x)    LCD_Char_1_PrintInt8(x)
    #define LCD_Char_1_PrintHexUint16(x)   LCD_Char_1_PrintInt16(x)        

#endif /* LCD_Char_1_CONVERSION_ROUTINES == 1u */

#endif /* CY_CHARLCD_LCD_Char_1_H */


/* [] END OF FILE */
