


#include <16F887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)


#include "flex_lcd.c" 
#include "flex_kbd.c"
    
//========================== 
void main() 
{ 

char k=0;
kbd_init();
lcd_init();  // Always call this first. 

lcd_putc("\fHello World\n"); 
lcd_putc("Line Number 2"); 
delay_ms (370);
lcd_putc('\f');
lcd_putc('a');
lcd_send_byte(0,0x0E);   //cursor on;
lcd_send_byte(0,0x0f);
while(1)
   {
        k=kbd_getc(); 
         if(k!=0)  {
            if(k=='*')
             {
               lcd_putc('\f');
             
             
             }
             else if(k=='#')
             {
             
             
             lcd_putc("\b \b");
             }
             else if(k=='A')
             {
               lcd_putc('\b');
             
             
             }
             else if(k=='B')
              {
               lcd_send_byte(0,0x14);
              
              }
              else if(k=='C')
              {
               lcd_putc('\n');
              
              }
              else if(k=='D')
              {
               lcd_gotoxy(1,1);
              
              }
             else
             {
               lcd_putc(k);
             
             }
         
         
         }




   }
} 
