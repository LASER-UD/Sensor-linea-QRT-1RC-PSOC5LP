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
    Control_Write(1);
    CyDelay(1000);
    Control_Write(0);
    int time=0;
    LCD_Start();
    LCD_Position(0,1);
    LCD_PrintString("Putos");
   
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Control_Write(1);
    for(;;)
    {
 
        time=0;
        Slinea_SetDriveMode(Slinea_DM_STRONG);
        Slinea_Write(1);
        CyDelay(12u);
        Slinea_SetDriveMode(Slinea_DM_DIG_HIZ);
        while(Slinea_Read()){
           time=time+1;
        }
            Control_Write(0);
        if(time<2500){
            Control_Write(0);
            // BLANCO
            CyDelay(700);
            //CyDelay(2000);
        }
        else{
          Control_Write(1);
        
        }    
     //////
//        time=0;
//        Slinea1_SetDriveMode(Slinea1_DM_STRONG);
//        Slinea1_Write(1);
//        CyDelay(12u);
//        Slinea1_SetDriveMode(Slinea1_DM_DIG_HIZ);
//        while(Slinea1_Read()){
//           time=time+1;
//        }
//            Control_Write(0);
//        if(time<2500){
//            Control_Write(0);
//            // BLANCO
//            CyDelay(700);
//            //CyDelay(2000);
//        }
//        else{
//          Control_Write(1);
//        
//        }    
//        
        
        
    }
}