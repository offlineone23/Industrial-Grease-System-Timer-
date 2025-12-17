/*******************************************************
Project : Auto Start Grease System
Version : 2
Date    : 2025/12
Author  : Amir Shoaei (offlineone23@gmail.com)
Company : www.esfahansteel.com
Comments: Refactored for 28-channel management

Microcontroller           : ATmega128A
Program type              : Application
AVR Core Clock frequency  : 16.000000 MHz
Memory model              : Small
External RAM size         : 0
Data Stack size           : 1024
*******************************************************/

#include <mega128a.h>
#include <alcd.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

#define MAX_CHANNELS 28

// Structure representing each grease system channel
typedef struct {
    unsigned int hour;       // Current hour
    unsigned int minute;     // Current minute
    unsigned int ch_hour;    // Default activation hour
    unsigned int ch_minute;  // Default activation minute
    char port;               // Output port: 'A','B','C','D','E','F'
    unsigned char pin;       // Pin number within the port
    unsigned char flag;      // Activation flag
} Channel;

// Array of 28 channels with default time and pin assignments
Channel channels[MAX_CHANNELS] = {
    {0,0,2,12,'D',0,0}, {0,0,3,12,'D',1,0}, {0,0,5,2,'D',2,0}, {0,0,0,18,'D',3,0},
    {0,0,0,20,'D',4,0}, {0,0,2,5,'D',5,0}, {0,0,8,8,'D',6,0}, {0,0,8,9,'D',7,0},
    {0,0,8,10,'C',0,0}, {0,0,8,11,'C',1,0}, {0,0,8,12,'C',2,0}, {0,0,8,13,'C',3,0},
    {0,0,8,14,'C',4,0}, {0,0,8,15,'C',5,0}, {0,0,8,16,'C',6,0}, {0,0,8,17,'C',7,0},
    {0,0,8,18,'A',7,0}, {0,0,8,19,'A',6,0}, {0,0,3,7,'A',5,0}, {0,0,4,7,'A',4,0},
    {0,0,0,8,'A',3,0}, {0,0,0,12,'A',2,0}, {0,0,0,14,'A',1,0}, {0,0,0,15,'A',0,0},
    {0,0,0,10,'F',7,0}, {0,0,0,13,'F',6,0}, {0,0,0,16,'F',5,0}, {0,0,0,17,'F',4,0}
};

// Main timer variables
unsigned int h=0,m=0,s=0,s1=60,shift=0;
int minutetimerflag=0,flag=0,cntr=10,set=0;
char ch[16], ch2[9];

// Timer1 overflow interrupt for time counting
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    TCNT1H=0xC400 >> 8;
    TCNT1L=0xC400 & 0xff;
    s++;
    s1--;
}

// Initial setup function
void SETTING(void)
{
    lcd_init(16);
    // Set ports as outputs
    DDRA=0xFF; DDRB=0xFF; DDRC=0xFF; DDRD=0xFF; DDRE=0xFF; DDRF=0xFF;
    
    // Timer1 configuration
    TCCR1A=0;
    TCCR1B=1<<CS12; // Prescaler 256
    TCNT1H=0xC400 >> 8;
    TCNT1L=0xC400 & 0xff;
    TIMSK=1<<TOIE1; // Enable overflow interrupt
    
    #asm("sei")  // Enable global interrupt
}

// Activate a channel
void activate_channel(Channel *ch)
{
    switch(ch->port)
    {
        case 'A': PORTA |= (1<<ch->pin); break;
        case 'B': PORTB |= (1<<ch->pin); break;
        case 'C': PORTC |= (1<<ch->pin); break;
        case 'D': PORTD |= (1<<ch->pin); break;
        case 'E': PORTE |= (1<<ch->pin); break;
        case 'F': PORTF |= (1<<ch->pin); break;
    }
}

// Deactivate a channel
void deactivate_channel(Channel *ch)
{
    switch(ch->port)
    {
        case 'A': PORTA &= ~(1<<ch->pin); break;
        case 'B': PORTB &= ~(1<<ch->pin); break;
        case 'C': PORTC &= ~(1<<ch->pin); break;
        case 'D': PORTD &= ~(1<<ch->pin); break;
        case 'E': PORTE &= ~(1<<ch->pin); break;
        case 'F': PORTF &= ~(1<<ch->pin); break;
    }
    ch->flag = 0;
}

// Check all channels for activation based on current time
void check_channels(void)
{
    for(int i=0;i<MAX_CHANNELS;i++)
    {
        Channel *ch=&channels[i];
        if(h==ch->hour && m==ch->minute && ch->flag==0)
        {
            ch->flag=1;
            activate_channel(ch);
            cntr=10;
            flag=2;
            break;
        }
    }
}

void main(void)
{
    SETTING();

    // Initialize channel times
    for(int i=0;i<MAX_CHANNELS;i++)
    {
        channels[i].hour = channels[i].ch_hour;
        channels[i].minute = channels[i].ch_minute;
    }

    while(1)
    {
        // Update time
        if(s>59){ s=0; m++; minutetimerflag=1; }
        if(m>59){ m=0; h++; }
        if(h>7){ h=0; shift++; }
        if(s1<0) s1=59;
        if(shift>100) shift=0;

        // Manage channel activation
        check_channels();

        // Handle flag cycles and turning off channels
        switch(flag)
        {
            case 2: if(cntr==0) flag=3; else cntr--; break;
            case 3:
                for(int i=0;i<MAX_CHANNELS;i++)
                {
                    if(channels[i].flag==1)
                        deactivate_channel(&channels[i]);
                }
                flag=1;
                break;
        }

        // Display time and shift on LCD
        lcd_clear();
        lcd_gotoxy(0,0);
        sprintf(ch,"Time:%02d:%02d:%02d S:%02d",h,m,s,shift);
        lcd_puts(ch);

        delay_ms(500);
    }
}
