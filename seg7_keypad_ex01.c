#include <16F877a.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)
#include <kbd.c>

#define seg_init() set_tris_c(0x00);
/*
//#define COL0 (1 << 5)
//#define COL1 (1 << 6)
//#define COL2 (1 << 7)

//#define ROW0 (1 << 1)
//#define ROW1 (1 << 2)
//#define ROW2 (1 << 3)
//#define ROW3 (1 << 4)

*/
unsigned char seg_code[]=
   {192,249,164,176,153,146,130,248,128,144};//a=pin0,g=pin6,dp=pin7

int cnt=0;

void main()
{
char k;
seg_init();
kbd_init();


  while(TRUE)
   {
       k=kbd_getc();
      if(k!=0)
        if(k=='*')
        {
          output_high(PIN_B0);
          delay_ms(100);
          
        }
        else if(k=='#')
        {
          output_low(PIN_B0);
          delay_ms(100);
        }
        else{
        
         cnt=k-48;
         output_c(seg_code[cnt]);
         delay_ms(100);
        
        }
   
   
   }

}
