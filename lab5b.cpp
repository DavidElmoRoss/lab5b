/*
    Title:  Program to show RAW data from POT and equivalent Voltage
    Author: YOUR NAME HERE
    Date:   Today's DATE HERE
    Description:    Program to show RAW data from POT and equivalent 
                    Voltage by multiplying the RAW data by 3.3
*/   
// Include Section
#include "Grove_LCD_RGB_Backlight.h"        // Grove LCD header file
#include "mbed.h"                           // mbed header file
    
// Function Prototype Section
void clear(void);                           // clears the PC screen
void position(int x, int y);                // positions screen cursor at (x,y)

// Hardware definition Section
Grove_LCD_RGB_Backlight LCD(D14,D15);       // lcd is associated with (D14,D15)
AnalogIn pot(A1);                           // pot is associated with A1
const int MAX=20;                           // MAX is dimension of Buffer Array
int main(void) 
{
   char buffer[MAX];                        // buffer has MAX elements
   double voltage,voltage1;                 // variable for storing voltage
   short i;                                 // variable used to null array
   for(i=0;i<=MAX-1;++i)                    // NULL all elements 0 to MAX-1
   {
     buffer[i]=0;                           // set element to NULL character
   }
   LCD.clear();                             // clear lcd screen
   LCD.locate(0,0);                         // 1st column 1st row
   sprintf(buffer,"Reading  Voltage");
   LCD.print(buffer);
   LCD.setRGB(0x00,0x00,0xff);              // set background to blue
   for(;;)                                  // infinite loop
   {
      voltage=pot.read();                   // voltage reading (0-1) from pot
      voltage1=3.33*voltage;                // scale to 3.33 volts
      LCD.locate(2,1);                      // 4th column 2nd row
      sprintf(buffer,"%5.3f  %5.3f",
      voltage,voltage1);                    // voltage to string in buffer
      LCD.print(buffer);                    // print buffer on lcd
      wait(0.05);
   }
}
