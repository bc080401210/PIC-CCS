#include <16F877a.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)


#define init_segments() set_tris_c(0x00);

unsigned char seg_code[]=
   {192,249,164,176,153,146,130,248,128,144};//a=pin0,g=pin6,dp=pin7

int cnt=0;

void main()
{

init_segments();


  while(TRUE)
   {
      cnt++;
      if(cnt>9)cnt=1;
      output_c(seg_code[cnt]);
      delay_ms(500);  
   
   
   }

}
