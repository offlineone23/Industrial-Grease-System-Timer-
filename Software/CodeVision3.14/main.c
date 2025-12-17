/*******************************************************
Project : Auto Start Grease system
Version : 2
Date    : 1401/07
Author  : offlineone23@gmail.com==09131066907
Company : www.esfahansteel.com
Comments: Amir Shoaei


Chip type               : ATmega128A
Program type            : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 1024
*******************************************************/

#include <mega128a.h>
#include <alcd.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

//Declare Functions:
void SETTING(void);
void gs2z1(void);
void gs3z1(void);
void gs5z2(void);
void gs018(void);
void gs020(void);
void gs2z5(void);
void gs888(void);
void gs889(void);
void gs8810(void);
void gs8811(void);
void gs8812(void);
void gs8813(void);
void gs8814(void);
void gs8815(void);
void gs8816(void);
void gs8817(void);
void gs8818(void);
void gs8819(void);
void gs3z7(void);
void gs4z7(void);
void gs008(void);
void gs012(void);
void gs014(void);
void gs015(void);
void gs010(void);
void gs013(void);
void gs016(void);
void gs017(void);

//Global variables:
unsigned int h=0,m=0,s=0,page=0,shift=0;
int minutetimerflag=0,flag=0,cntr=0,delay=10,s1=60,set=0;
unsigned char ch[16],ch2[9];

int h2z1=0,m2z1=0,ch2z1=12,cm2z1=0,flag2z1=0;
int h3z1=0,m3z1=0,ch3z1=12,cm3z1=0,flag3z1=0;
int h5z2=0,m5z2=0,ch5z2=4,cm5z2=0,flag5z2=0;
int h018=0,m018=0,ch018=1,cm018=0,flag018=0;
int h020=0,m020=0,ch020=0,cm020=20,flag020=0;
int h2z5=0,m2z5=0,ch2z5=16,cm2z5=0,flag2z5=0;
int h888=0,m888=0,ch888=2,cm888=0,flag888=0;
int h889=0,m889=0,ch889=2,cm889=0,flag889=0;
int h8810=0,m8810=0,ch8810=4,cm8810=0,flag8810=0;
int h8811=0,m8811=0,ch8811=4,cm8811=0,flag8811=0;
int h8812=0,m8812=0,ch8812=6,cm8812=0,flag8812=0;
int h8813=0,m8813=0,ch8813=6,cm8813=0,flag8813=0;
int h8814=0,m8814=0,ch8814=6,cm8814=0,flag8814=0;
int h8815=0,m8815=0,ch8815=6,cm8815=0,flag8815=0;
int h8816=0,m8816=0,ch8816=8,cm8816=0,flag8816=0;
int h8817=0,m8817=0,ch8817=8,cm8817=0,flag8817=0;
int h8818=0,m8818=0,ch8818=8,cm8818=0,flag8818=0;
int h8819=0,m8819=0,ch8819=8,cm8819=0,flag8819=0;
int h3z7=0,m3z7=0,ch3z7=16,cm3z7=0,flag3z7=0;
int h4z7=0,m4z7=0,ch4z7=16,cm4z7=0,flag4z7=0;
int h008=0,m008=0,ch008=16,cm008=0,flag008=0;
int h010=0,m010=0,ch010=8,cm010=0,flag010=0;
int h012=0,m012=0,ch012=16,cm012=0,flag012=0;
int h013=0,m013=0,ch013=8,cm013=0,flag013=0;
int h014=0,m014=0,ch014=4 ,cm014=0,flag014=0;
int h015=0,m015=0,ch015=4 ,cm015=0,flag015=0;
int h016=0,m016=0,ch016=8,cm016=0,flag016=0;
int h017=0,m017=0,ch017=8,cm017=0,flag017=0;

// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Reinitialize Timer1 value
TCNT1H=0xC400 >> 8;
TCNT1L=0xC400 & 0xff;
s++;
s1--;
}

void main(void)
{

SETTING();

//Declair variables:
{
h2z1=ch2z1;m2z1=cm2z1;
h3z1=ch3z1;m3z1=cm3z1;
h5z2=ch5z2;m5z2=cm5z2;
h018=ch018;m018=cm018;
h020=ch020;m020=cm020;
h2z5=ch2z5;m2z5=cm2z5;
h888=ch888;m888=cm888;
h889=ch889;m889=cm889;
h8810=ch8810;m8810=cm8810;
h8811=ch8811;m8811=cm8811;
h8812=ch8812;m8812=cm8812;
h8813=ch8813;m8813=cm8813;
h8814=ch8814;m8814=cm8814;
h8815=ch8815;m8815=cm8815;
h8816=ch8816;m8816=cm8816;
h8817=ch8817;m8817=cm8817;
h8818=ch8818;m8818=cm8818;
h8819=ch8819;m8819=cm8819;
h3z7=ch3z7;m3z7=cm3z7;
h4z7=ch4z7;m4z7=cm4z7;
h008=ch008;m008=cm008;
h010=ch010;m010=cm010;
h012=ch012;m012=cm012;
h013=ch013;m013=cm013;
h014=ch014;m014=cm014;
h015=ch015;m015=cm015;
h016=ch016;m016=cm016;
h017=ch017;m017=cm017;
}
while (1)
 {
  //Main Timer
  {
   if(s>59)
    {s=0;
     m++;
     minutetimerflag=1;
    }
   if(m>59)
    {m=0;
     h++;
    }
   if(h>7)
    {h=0;
     shift++;
    } 
   if(s1<0)
    s1=59;
   if(shift>100)
   shift=0;  
  }

 //calling functions:
{  gs2z1();  
  gs3z1();
  gs5z2();
  gs018();
  gs020();
  gs2z5();
  gs888();
  gs889();
  gs8810();
  gs8811();
  gs8812();
  gs8813();
  gs8814();
  gs8815();
  gs8816();
  gs8817();
  gs8818();
  gs8819();
  gs3z7();
  gs4z7();
  gs008();
  gs012();
  gs014();
  gs015();
  gs010();
  gs013();
  gs016();
  gs017();  
}

  if(minutetimerflag==1)
   minutetimerflag=0;  

  //Flags
  {
    switch (flag)
    {case 0:
        { 
         break;
        }
     case 1:
        {
         if(flag2z1==1)
          {PORTD.0=1;
           cntr=delay;
           flag=2;
           break;
          }
         if(flag3z1==1)
          {PORTD.1=1;
           cntr=delay;
           flag=2;
           break;
          }
         if(flag5z2==1)
          {PORTD.2=1;
           cntr=delay;
           flag=2;
           break;
          }
         if(flag018==1)
          {PORTD.3=1;
           cntr=delay;
           flag=2;
           break;
          }          
         if(flag020==1)
          {PORTD.4=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag2z5==1)
          {PORTD.5=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag888==1)
          {PORTD.6=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag889==1)
          {PORTD.7=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8810==1)
          {PORTC.0=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8811==1)
          {PORTC.1=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8812==1)
          {PORTC.2=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8813==1)
          {PORTC.3=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8814==1)
          {PORTC.4=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8815==1)
          {PORTC.5=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8816==1)
          {PORTC.6=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8817==1)
          {PORTC.7=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8818==1)
          {PORTA.7=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag8819==1)
          {PORTA.6=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag3z7==1)
          {PORTA.5=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag4z7==1)
          {PORTA.4=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag008==1)
          {PORTA.3=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag012==1)
          {PORTA.2=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag014==1)
          {PORTA.1=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag015==1)
          {PORTA.0=1;
           cntr=delay;
           flag=2;
           break;
          }
          if(flag010==1)
          {PORTF=(1<<PORTF7);
           cntr=delay;
           flag=2;
           break;
          }
          if(flag013==1)
          {PORTF=(1<<PORTF6);
           cntr=delay;
           flag=2;
           break;
          }
          if(flag016==1)
          {PORTF=(1<<PORTF5);
           cntr=delay;
           flag=2;
           break;
          }
          if(flag017==1)
          {PORTF=(1<<PORTF4);
           cntr=delay;
           flag=2;
           break;
          }
            
         flag=0; 
         break;  
        }
     case 2:
        {
         if(cntr==0)
          flag=3;
         else
          cntr--;                         
         break; 
        }    
     case 3:
        {
         if(flag2z1==1)
          {PORTD.0=0;
           flag2z1=0;
           flag=1;
           break; 
          }
         
         if(flag3z1==1)
          {PORTD.1=0;
           flag3z1=0;
           flag=1;
           break;
          }  
         if(flag5z2==1)
          {PORTD.2=0;
           flag5z2=0;
           flag=1;
           break;
          }
         if(flag018==1)
          {PORTD.3=0;
           flag018=0;
           flag=1;
           break;
          }
         if(flag020==1)
          {PORTD.4=0;
           flag020=0;
           flag=1;
           break;
          }
         if(flag2z5==1)
          {PORTD.5=0;
           flag2z5=0;
           flag=1;
           break;
          }
         if(flag888==1)
          {PORTD.6=0;
           flag888=0;
           flag=1;
           break;
          }
         if(flag889==1)
          {PORTD.7=0;
           flag889=0;
           flag=1;
           break;
          }
         if(flag8810==1)
          {PORTC.0=0;
           flag8810=0;
           flag=1;
           break;
          }
         if(flag8811==1)
          {PORTC.1=0;
           flag8811=0;
           flag=1;
           break;
          }
         if(flag8812==1)
          {PORTC.2=0;
           flag8812=0;
           flag=1;
           break;
          }
         if(flag8813==1)
          {PORTC.3=0;
           flag8813=0;
           flag=1;
           break;
          }
         if(flag8814==1)
          {PORTC.4=0;
           flag8814=0;
           flag=1;
           break;
          }
         if(flag8815==1)
          {PORTC.5=0;
           flag8815=0;
           flag=1;
           break;
          }
         if(flag8816==1)
          {PORTC.6=0;
           flag8816=0;
           flag=1;
           break;
          }
         if(flag8817==1)
          {PORTC.7=0;
           flag8817=0;
           flag=1;
           break;
          }
         if(flag8818==1)
          {PORTA.7=0;
           flag8818=0;
           flag=1;
           break;
          }
         if(flag8819==1)
          {PORTA.6=0;
           flag8819=0;
           flag=1;
           break;
          }
         if(flag3z7==1)
          {PORTA.5=0;
           flag3z7=0;
           flag=1;
           break;
          }
         if(flag4z7==1)
          {PORTA.4=0;
           flag4z7=0;
           flag=1;
           break;
          }
         if(flag008==1)
          {PORTA.3=0;
           flag008=0;
           flag=1;
           break;
          }
         if(flag012==1)
          {PORTA.2=0;
           flag012=0;
           flag=1;
           break;
          }
         if(flag014==1)
          {PORTA.1=0;
           flag014=0;
           flag=1;
           break;
          }
          if(flag015==1)
          {PORTA.0=0;
           flag015=0;
           flag=1;
           break;
          }
          if(flag010==1)
          {PORTF=(0<<PORTF7);
           flag010=0;
           flag=1;
           break;
          }
         if(flag013==1)
          {PORTF=(0<<PORTF6);
           flag013=0;
           flag=1;
           break;
          }
         if(flag016==1)
          {PORTF=(0<<PORTF5);
           flag016=0;
           flag=1;
           break;
          }
         if(flag017==1)
          {PORTF=(0<<PORTF4);
           flag017=0;
           flag=1;
           break;
          }
                       
         break;
         }
     }    
  }


  //Display
  {
    if(PINE.2==0)
    {delay_ms(10);
     page++;
     set=0;
    }
    if(page>28)
    page=0;

    switch (page)
    {case 0:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         lcd_puts("MainClock  Shift");
         lcd_gotoxy(0,1);
         sprintf(ch,"%02d:%02d:%02d    %02d",h,m,s,shift);
         lcd_puts(ch);
         break;
        }
     case 1:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"2z1 =>   %02d:%02d",ch2z1,cm2z1);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h2z1,m2z1,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm2z1=cm2z1+10;
             if(cm2z1>50)
              cm2z1=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch2z1++;
             if(ch2z1>48)
              ch2z1=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h2z1=ch2z1;m2z1=cm2z1;
           delay_ms(10);
           set=0;
          }   
         break;
        }    
     case 2:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"3z1 =>   %02d:%02d",ch3z1,cm3z1);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h3z1,m3z1,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm3z1=cm3z1+10;
             if(cm3z1>50)
              cm3z1=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch3z1++;
             if(ch3z1>48)
              ch3z1=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h3z1=ch3z1;m3z1=cm3z1;
           delay_ms(10);
           set=0;
          }         
         break;
        }
     case 3:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"5z2 =>   %02d:%02d",ch5z2,cm5z2);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h5z2,m5z2,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm5z2=cm5z2+10;
             if(cm5z2>50)
              cm5z2=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch5z2++;
             if(ch5z2>48)
              ch5z2=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h5z2=ch5z2;m5z2=cm5z2;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 4:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"018 =>   %02d:%02d",ch018,cm018);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h018,m018,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm018=cm018+10;
             if(cm018>50)
              cm018=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch018++;
             if(ch018>48)
              ch018=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h018=ch018;m018=cm018;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 5:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"020 =>   %02d:%02d",ch020,cm020);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h020,m020,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm020=cm020+10;
             if(cm020>50)
              cm020=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch020++;
             if(ch020>48)
              ch020=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h020=ch020;m020=cm020;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 6:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"2z5 =>   %02d:%02d",ch2z5,cm2z5);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h2z5,m2z5,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm2z5=cm2z5+10;
             if(cm2z5>50)
              cm2z5=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch2z5++;
             if(ch2z5>48)
              ch2z5=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h2z5=ch2z5;m2z5=cm2z5;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 7:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"888 =>   %02d:%02d",ch888,cm888);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h888,m888,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm888=cm888+10;
             if(cm888>50)
              cm888=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch888++;
             if(ch888>48)
              ch888=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h888=ch888;m888=cm888;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 8:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"889 =>   %02d:%02d",ch889,cm889);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h889,m889,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm889=cm889+10;
             if(cm889>50)
              cm889=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch889++;
             if(ch889>48)
              ch889=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h889=ch889;m889=cm889;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }        
     case 9:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8810 =>  %02d:%02d",ch8810,cm8810);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8810,m8810,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8810=cm8810+10;
             if(cm8810>50)
              cm8810=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8810++;
             if(ch8810>48)
              ch8810=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8810=ch8810;m8810=cm8810;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }                                        
     case 10:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8811 =>  %02d:%02d",ch8811,cm8811);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8811,m8811,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8811=cm8811+10;
             if(cm8811>50)
              cm8811=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8811++;
             if(ch8811>48)
              ch8811=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8811=ch8811;m8811=cm8811;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 11:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8812 =>  %02d:%02d",ch8812,cm8812);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8812,m8812,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8812=cm8812+10;
             if(cm8812>50)
              cm8812=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8812++;
             if(ch8812>48)
              ch8812=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8812=ch8812;m8812=cm8812;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 12:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8813 =>  %02d:%02d",ch8813,cm8813);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8813,m8813,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8813=cm8813+10;
             if(cm8813>50)
              cm8813=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8813++;
             if(ch8813>48)
              ch8813=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8813=ch8813;m8813=cm8813;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 13:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8814 =>  %02d:%02d",ch8814,cm8814);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8814,m8814,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8814=cm8814+10;
             if(cm8814>50)
              cm8814=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8814++;
             if(ch8814>48)
              ch8814=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8814=ch8814;m8814=cm8814;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 14:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8815 =>  %02d:%02d",ch8815,cm8815);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8815,m8815,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8815=cm8815+10;
             if(cm8815>50)
              cm8815=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8815++;
             if(ch8815>48)
              ch8815=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8815=ch8815;m8815=cm8815;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 15:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8816 =>  %02d:%02d",ch8816,cm8816);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8816,m8816,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8816=cm8816+10;
             if(cm8816>50)
              cm8816=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8816++;
             if(ch8816>48)
              ch8816=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8816=ch8816;m8816=cm8816;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 16:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8817 =>  %02d:%02d",ch8817,cm8817);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8817,m8817,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8817=cm8817+10;
             if(cm8817>50)
              cm8817=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8817++;
             if(ch8817>48)
              ch8817=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8817=ch8817;m8817=cm8817;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 17:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8818 =>  %02d:%02d",ch8818,cm8818);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8818,m8818,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8818=cm8818+10;
             if(cm8818>50)
              cm8818=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8818++;
             if(ch8818>48)
              ch8818=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8818=ch8818;m8818=cm8818;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 18:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"8819 =>  %02d:%02d",ch8819,cm8819);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h8819,m8819,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm8819=cm8819+10;
             if(cm8819>50)
              cm8819=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch8819++;
             if(ch8819>48)
              ch8819=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h8819=ch8819;m8819=cm8819;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 19:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"3z7  =>  %02d:%02d",ch3z7,cm3z7);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h3z7,m3z7,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm3z7=cm3z7+10;
             if(cm3z7>50)
              cm3z7=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch3z7++;
             if(ch3z7>48)
              ch3z7=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h3z7=ch3z7;m3z7=cm3z7;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 20:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"4z7  =>  %02d:%02d",ch4z7,cm4z7);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h4z7,m4z7,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm4z7=cm4z7+10;
             if(cm4z7>50)
              cm4z7=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch4z7++;
             if(ch4z7>48)
              ch4z7=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h4z7=ch4z7;m4z7=cm4z7;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 21:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"008  =>  %02d:%02d",ch008,cm008);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h008,m008,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm008=cm008+10;
             if(cm008>50)
              cm008=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch008++;
             if(ch008>48)
              ch008=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h008=ch008;m008=cm008;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }    
     case 22:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"010 =>   %02d:%02d",ch010,cm010);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h010,m010,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm010=cm010+10;
             if(cm010>50)
              cm010=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch010++;
             if(ch010>48)
              ch010=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h010=ch010;m010=cm010;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 23:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"012 =>   %02d:%02d",ch012,cm012);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h012,m012,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm012=cm012+10;
             if(cm012>50)
              cm012=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch012++;
             if(ch012>48)
              ch012=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h012=ch012;m012=cm012;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 24:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"013 =>   %02d:%02d",ch013,cm013);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h013,m013,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm013=cm013+10;
             if(cm013>50)
              cm013=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch013++;
             if(ch013>48)
              ch013=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h013=ch013;m013=cm013;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 25:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"014 =>   %02d:%02d",ch014,cm014);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h014,m014,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm014=cm014+10;
             if(cm014>50)
              cm014=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch014++;
             if(ch014>48)
              ch014=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h014=ch014;m014=cm014;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 26:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"015 =>   %02d:%02d",ch015,cm015);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h015,m015,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm015=cm015+10;
             if(cm015>50)
              cm015=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch015++;
             if(ch015>48)
              ch015=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h015=ch015;m015=cm015;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 27:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"016 =>   %02d:%02d",ch016,cm016);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h016,m016,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm016=cm016+10;
             if(cm016>50)
              cm016=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch016++;
             if(ch016>48)
              ch016=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h016=ch016;m016=cm016;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
     case 28:
        {
         lcd_clear();
         lcd_gotoxy(0,0);
         sprintf(ch,"017 =>   %02d:%02d",ch017,cm017);
         lcd_puts(ch);
         lcd_gotoxy(0,1);
         sprintf(ch2,"%02d:%02d:%02d",h017,m017,s1);
         lcd_puts(ch2);
         if(PINE.3==0)
          {delay_ms(20);
           set++;
          } 
         if(set==1)  
          {lcd_gotoxy(8,1);
           lcd_puts("    ''");
           if(PINE.4==0)
            {delay_ms(10);
             cm017=cm017+10;
             if(cm017>50)
              cm017=0;
            }
          }  
          if(set==2)   
           {lcd_gotoxy(8,1);
            lcd_puts(" ''");
            if(PINE.4==0)
            {delay_ms(10);
             ch017++;
             if(ch017>48)
              ch017=0;
            }
           }
         if(set==3)
          {lcd_gotoxy(8,1);
           lcd_puts("setting");
           h017=ch017;m017=cm017;
           delay_ms(10);
           set=0;
          }
                  
         break;
        }
    
    }

  }
 }          
} 

//functions:
void SETTING(void)
{
// Input/Output Ports initialization
// Port A initialization
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);

// Port C initialization
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);

// Port D initialization 
DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);

// Port E initialization 
DDRE=(0<<DDE4) | (0<<DDE3) | (0<<DDE2);
PORTE=(1<<PORTE4) | (1<<PORTE3) | (1<<PORTE2);

// Port F initialization 
DDRF=(1<<DDF7) | (1<<DDF6) | (1<<DDF5) | (1<<DDF4) | (0<<DDF3) | (0<<DDF2) | (0<<DDF1) | (0<<DDF0); 
PORTF=(0<<PORTF7) | (0<<PORTF6) | (0<<PORTF5) | (0<<PORTF4) | (0<<PORTF3) | (0<<PORTF2) | (0<<PORTF1) | (0<<PORTF0);

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 15.625 kHz
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// OC1C output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 0.80282 s
// Timer1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
// Compare C Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<COM1C1) | (0<<COM1C0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
TCNT1H=0xC4;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
OCR1CH=0x00;
OCR1CL=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);
ETIMSK=(0<<TICIE3) | (0<<OCIE3A) | (0<<OCIE3B) | (0<<TOIE3) | (0<<OCIE3C) | (0<<OCIE1C);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTB Bit 0
// RD - PORTB Bit 1
// EN - PORTB Bit 2
// D4 - PORTB Bit 3
// D5 - PORTB Bit 4
// D6 - PORTB Bit 5
// D7 - PORTB Bit 6
// Characters/line: 16
lcd_init(16);

// Global enable interrupts
#asm("sei")
}

void gs2z1(void)
{
 if(minutetimerflag==1)
  {m2z1--;
   if(m2z1<0)
   {if(h2z1==0)
     {flag2z1=1;
      flag=1;
      h2z1=ch2z1;
      m2z1=cm2z1;
     } 
    else 
    {h2z1--;
     m2z1=59;
    } 
   } 
  }
    
}

void gs3z1(void)
{
 if(minutetimerflag==1)
  {m3z1--; 
   if(m3z1<0)
   {if(h3z1==0)
     {flag3z1=1;
      flag=1;
      h3z1=ch3z1;
      m3z1=cm3z1;
     } 
    else 
    {h3z1--;
     m3z1=59;
    } 
   } 
  }
    
}

void gs5z2(void)
{
 if(minutetimerflag==1)
  {m5z2--; 
   if(m5z2<0)
   {if(h5z2==0)
     {flag5z2=1;
      flag=1;
      h5z2=ch5z2;
      m5z2=cm5z2;
     } 
    else 
    {h5z2--;
     m5z2=59;
    } 
   } 
  }
    
}

void gs018(void)
{
 if(minutetimerflag==1)
  {m018--; 
   if(m018<0)
   {if(h018==0)
     {flag018=1;
      flag=1;
      h018=ch018;
      m018=cm018;
     } 
    else 
    {h018--;
     m018=59;
    } 
   } 
  }
    
}

void gs020(void)
{
 if(minutetimerflag==1)
  {m020--; 
   if(m020<0)
   {if(h020==0)
     {flag020=1;
      flag=1;
      h020=ch020;
      m020=cm020;
     } 
    else 
    {h020--;
     m020=59;
    } 
   } 
  }
    
}

void gs2z5(void)
{
 if(minutetimerflag==1)
  {m2z5--; 
   if(m2z5<0)
   {if(h2z5==0)
     {flag2z5=1;
      flag=1;
      h2z5=ch2z5;
      m2z5=cm2z5;
     } 
    else 
    {h2z5--;
     m2z5=59;
    } 
   } 
  }
    
}

void gs888(void)
{
 if(minutetimerflag==1)
  {m888--; 
   if(m888<0)
   {if(h888==0)
     {flag888=1;
      flag=1;
      h888=ch888;
      m888=cm888;
     } 
    else 
    {h888--;
     m888=59;
    } 
   } 
  }
    
}

void gs889(void)
{
 if(minutetimerflag==1)
  {m889--; 
   if(m889<0)
   {if(h889==0)
     {flag889=1;
      flag=1;
      h889=ch889;
      m889=cm889;
     } 
    else 
    {h889--;
     m889=59;
    } 
   } 
  }
    
}

void gs8810(void)
{
 if(minutetimerflag==1)
  {m8810--; 
   if(m8810<0)
   {if(h8810==0)
     {flag8810=1;
      flag=1;
      h8810=ch8810;
      m8810=cm8810;
     } 
    else 
    {h8810--;
     m8810=59;
    } 
   } 
  }
    
}

void gs8811(void)
{
 if(minutetimerflag==1)
  {m8811--; 
   if(m8811<0)
   {if(h8811==0)
     {flag8811=1;
      flag=1;
      h8811=ch8811;
      m8811=cm8811;
     } 
    else 
    {h8811--;
     m8811=59;
    } 
   } 
  }
    
}

void gs8812(void)
{
 if(minutetimerflag==1)
  {m8812--; 
   if(m8812<0)
   {if(h8812==0)
     {flag8812=1;
      flag=1;
      h8812=ch8812;
      m8812=cm8812;
     } 
    else 
    {h8812--;
     m8812=59;
    } 
   } 
  }
    
}

void gs8813(void)
{
 if(minutetimerflag==1)
  {m8813--; 
   if(m8813<0)
   {if(h8813==0)
     {flag8813=1;
      flag=1;
      h8813=ch8813;
      m8813=cm8813;
     } 
    else 
    {h8813--;
     m8813=59;
    } 
   } 
  }
    
}

void gs8814(void)
{
 if(minutetimerflag==1)
  {m8814--; 
   if(m8814<0)
   {if(h8814==0)
     {flag8814=1;
      flag=1;
      h8814=ch8814;
      m8814=cm8814;
     } 
    else 
    {h8814--;
     m8814=59;
    } 
   } 
  }
    
}

void gs8815(void)
{
 if(minutetimerflag==1)
  {m8815--; 
   if(m8815<0)
   {if(h8815==0)
     {flag8815=1;
      flag=1;
      h8815=ch8815;
      m8815=cm8815;
     } 
    else 
    {h8815--;
     m8815=59;
    } 
   } 
  }
    
}

void gs8816(void)
{
 if(minutetimerflag==1)
  {m8816--; 
   if(m8816<0)
   {if(h8816==0)
     {flag8816=1;
      flag=1;
      h8816=ch8816;
      m8816=cm8816;
     } 
    else 
    {h8816--;
     m8816=59;
    } 
   } 
  }
    
}

void gs8817(void)
{
 if(minutetimerflag==1)
  {m8817--; 
   if(m8817<0)
   {if(h8817==0)
     {flag8817=1;
      flag=1;
      h8817=ch8817;
      m8817=cm8817;
     } 
    else 
    {h8817--;
     m8817=59;
    } 
   } 
  }
    
}

void gs8818(void)
{
 if(minutetimerflag==1)
  {m8818--; 
   if(m8818<0)
   {if(h8818==0)
     {flag8818=1;
      flag=1;
      h8818=ch8818;
      m8818=cm8818;
     } 
    else 
    {h8818--;
     m8818=59;
    } 
   } 
  }
    
}

void gs8819(void)
{
 if(minutetimerflag==1)
  {m8819--; 
   if(m8819<0)
   {if(h8819==0)
     {flag8819=1;
      flag=1;
      h8819=ch8819;
      m8819=cm8819;
     } 
    else 
    {h8819--;
     m8819=59;
    } 
   } 
  }
    
}

void gs3z7(void)
{
 if(minutetimerflag==1)
  {m3z7--; 
   if(m3z7<0)
   {if(h3z7==0)
     {flag3z7=1;
      flag=1;
      h3z7=ch3z7;
      m3z7=cm3z7;
     } 
    else 
    {h3z7--;
     m3z7=59;
    } 
   } 
  }
    
}

void gs4z7(void)
{
 if(minutetimerflag==1)
  {m4z7--; 
   if(m4z7<0)
   {if(h4z7==0)
     {flag4z7=1;
      flag=1;
      h4z7=ch4z7;
      m4z7=cm4z7;
     } 
    else 
    {h4z7--;
     m4z7=59;
    } 
   } 
  }
    
}

void gs008(void)
{
 if(minutetimerflag==1)
  {m008--; 
   if(m008<0)
   {if(h008==0)
     {flag008=1;
      flag=1;
      h008=ch008;
      m008=cm008;
     } 
    else 
    {h008--;
     m008=59;
    } 
   } 
  }
    
}

void gs012(void)
{
 if(minutetimerflag==1)
  {m012--; 
   if(m012<0)
   {if(h012==0)
     {flag012=1;
      flag=1;
      h012=ch012;
      m012=cm012;
     } 
    else 
    {h012--;
     m012=59;
    } 
   } 
  }
    
}

void gs014(void)
{
 if(minutetimerflag==1)
  {m014--; 
   if(m014<0)
   {if(h014==0)
     {flag014=1;
      flag=1;
      h014=ch014;
      m014=cm014;
     } 
    else 
    {h014--;
     m014=59;
    } 
   } 
  }
    
}

void gs015(void)
{
 if(minutetimerflag==1)
  {m015--; 
   if(m015<0)
   {if(h015==0)
     {flag015=1;
      flag=1;
      h015=ch015;
      m015=cm015;
     } 
    else 
    {h015--;
     m015=59;
    } 
   } 
  }
    
}

void gs010(void)
{
 if(minutetimerflag==1)
  {m010--; 
   if(m010<0)
   {if(h010==0)
     {flag010=1;
      flag=1;
      h010=ch010;
      m010=cm010;
     } 
    else 
    {h010--;
     m010=59;
    } 
   } 
  }
    
}

void gs013(void)
{
 if(minutetimerflag==1)
  {m013--; 
   if(m013<0)
   {if(h013==0)
     {flag013=1;
      flag=1;
      h013=ch013;
      m013=cm013;
     } 
    else 
    {h013--;
     m013=59;
    } 
   } 
  }
    
}

void gs016(void)
{
 if(minutetimerflag==1)
  {m016--; 
   if(m016<0)
   {if(h016==0)
     {flag016=1;
      flag=1;
      h016=ch016;
      m016=cm016;
     } 
    else 
    {h016--;
     m016=59;
    } 
   } 
  }
    
}

void gs017(void)
{
 if(minutetimerflag==1)
  {m017--; 
   if(m017<0)
   {if(h017==0)
     {flag017=1;
      flag=1;
      h017=ch017;
      m017=cm017;
     } 
    else 
    {h017--;
     m017=59;
    } 
   } 
  }
    
}
