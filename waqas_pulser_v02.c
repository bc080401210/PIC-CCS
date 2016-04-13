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


#define RELAY1 PIN_B7
#define RELAY2 PIN_B6
#define RELAY3 PIN_B5
#define RELAY4 PIN_B4
#define RELAY5 PIN_B3
#define RELAY6 PIN_B2

#define LED_STATUS PIN_B1


#define SP_ON_TIME 100  //single pulse on Time in millis



//----------------------------------------------------------------------
//Variable define Area
unsigned char seg_code[]=
   {192,249,164,176,153,146,130,248,128,144};//a=pin0,g=pin6,dp=pin7

char cnt=0;
//---------------------------------------------------------------------
//Function Prototype Area


void single_pulse_loop_1(int o_t,int of_t)
{
   output_high(RELAY1);
   delay_ms(o_t);
   output_low(RELAY1);
   delay_ms(of_t);
   

}

void single_pulse_loop_2(int o_t,int of_t)
{
   output_high(RELAY2);
   delay_ms(o_t);
   output_low(RELAY2);
   delay_ms(of_t);
   

}

void single_pulse_loop_3(int o_t,int of_t)
{
   output_high(RELAY3);
   delay_ms(o_t);
   output_low(RELAY3);
   delay_ms(of_t);
   

}

void single_pulse_loop_4(int o_t,int of_t)
{
   output_high(RELAY4);
   delay_ms(o_t);
   output_low(RELAY4);
   delay_ms(of_t);
   

}

void single_pulse_loop_5(int o_t,int of_t)
{
   output_high(RELAY5);
   delay_ms(o_t);
   output_low(RELAY5);
   delay_ms(of_t);
   

}

void single_pulse_loop_6(int o_t,int of_t)
{
   output_high(RELAY6);
   delay_ms(o_t);
   output_low(RELAY6);
   delay_ms(of_t);
   

}






void off_all_pulses()
{
   output_b(0x00);

}


unsigned int get_potValue(unsigned char channel)
{
 unsigned int value=0;
 set_adc_channel(channel);
 delay_ms(1);
 value = read_adc();
 delay_ms(1);
 return value;
}






//----------------------------------------------------------------------
void main()
{
char k;
seg_init();
kbd_init();
cnt=1;
output_c(seg_code[cnt]);
set_tris_b(0x00); //tris b all output;
off_all_pulses();

setup_adc_ports( ALL_ANALOG );
setup_adc(ADC_CLOCK_INTERNAL);     





  while(TRUE)
   {
       k=kbd_getc();
      if(k!=0)
        if(k=='*')
        {
        unsigned int ot,oft,sht,i=0;
         ot = get_potValue(0);
         delay_ms(5);
         oft=get_potValue(1);
         delay_ms(5);
         sht=get_potValue(2);
         
         output_high(LED_STATUS);
         
         while(k!='0')
         {
            output_high(RELAY1);
             k=kbd_getc();if(k=='0')break;
            delay_ms(ot);
             k=kbd_getc();if(k=='0')break;
            output_low(RELAY1);
             k=kbd_getc();if(k=='0')break;
            delay_ms(sht);
             k=kbd_getc();if(k=='0')break;
            output_high(RELAY2);
             k=kbd_getc();if(k=='0')break;
            delay_ms(ot);
             k=kbd_getc();if(k=='0')break;
            output_low(RELAY2);
             k=kbd_getc();if(k=='0')break;
            delay_ms(sht);
             k=kbd_getc();if(k=='0')break;
            
            output_high(RELAY3);
             k=kbd_getc();if(k=='0')break;
            delay_ms(ot);
             k=kbd_getc();if(k=='0')break;
            output_low(RELAY3);
             k=kbd_getc();if(k=='0')break;
            delay_ms(sht);
             k=kbd_getc();if(k=='0')break;
             k=kbd_getc();if(k=='0')break;
            
            output_high(RELAY4);
             k=kbd_getc();if(k=='0')break;
            delay_ms(ot);
             k=kbd_getc();if(k=='0')break;
            output_low(RELAY4);
             k=kbd_getc();if(k=='0')break;
            delay_ms(sht);
             k=kbd_getc();if(k=='0')break;
            
            output_high(RELAY5);
             k=kbd_getc();if(k=='0')break;
            delay_ms(ot);
             k=kbd_getc();if(k=='0')break;
              k=kbd_getc();if(k=='0')break;
            output_low(RELAY5);
             k=kbd_getc();if(k=='0')break;
            delay_ms(sht);
             k=kbd_getc();if(k=='0')break;
              k=kbd_getc();if(k=='0')break;
            
            output_high(RELAY6);
             k=kbd_getc();if(k=='0')break;
            delay_ms(ot);
             k=kbd_getc();if(k=='0')break;
            output_low(RELAY6);
             k=kbd_getc();if(k=='0')break;
            delay_ms(sht);
             k=kbd_getc();if(k=='0')break;
             k=kbd_getc();if(k=='0')break;
              k=kbd_getc();if(k=='0')break;
               k=kbd_getc();if(k=='0')break;
        }
            output_low(LED_STATUS);
        
         
          
        
          
        }
        else if(k=='#')
        {
        
        unsigned int ot,oft,sht,i=0,j=0;
         ot = get_potValue(0);
         delay_ms(5);
         oft=get_potValue(1);
         delay_ms(5);
         sht=get_potValue(2);
         
         output_high(LED_STATUS);
         
         for(j=0;j<cnt;j++)
         {
            output_high(RELAY1);
            delay_ms(ot);
            output_low(RELAY1);
            delay_ms(sht);
            output_high(RELAY2);
            delay_ms(ot);
            output_low(RELAY2);
            delay_ms(sht);
            
            output_high(RELAY3);
            delay_ms(ot);
            output_low(RELAY3);
            delay_ms(sht);
            
            
            output_high(RELAY4);
            delay_ms(ot);
            output_low(RELAY4);
            delay_ms(sht);
            
            output_high(RELAY5);
            delay_ms(ot);
            output_low(RELAY5);
            delay_ms(sht);
            
            output_high(RELAY6);
            delay_ms(ot);
            output_low(RELAY6);
            delay_ms(sht);
            
            
            
            
            
            
         }
            output_low(LED_STATUS);
            
            
         
          
        }
        else if(k=='0')
        {
        
        
        }
        else{
        
         cnt=k-48;
         output_c(seg_code[cnt]);
        
        }
   
   
   }

}
