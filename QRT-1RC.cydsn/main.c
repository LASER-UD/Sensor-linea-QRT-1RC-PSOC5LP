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

int main(void){
    int time=0;
    LCD_Start();
    LCD_Position(0,1);
    LCD_PrintString("Putos");
   
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LED_Write(0);
    for(;;)
    {
 
        time=0;
        Slinea_SetDriveMode(Slinea_DM_STRONG);
        Slinea_Write(1);
        CyDelay(3);
        Slinea_SetDriveMode(Slinea_DM_DIG_HIZ);
        while(Slinea_Read()){
           time=time+1;
        }
        LCD_Position(1,2);
        LCD_PrintNumber(time);
        
            LED_Write(0);
        if(time<1500){
            LED_Write(1);
        }
        else
            LED_Write(0);

            
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
