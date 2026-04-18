#include "Gpio.h"
#include "SSD.h"
#include "BitMath.h"

u8 seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void init(void)
{
    for (int i = 0; i < 7; i++)
        SetPinDDR(portC,i,output);

    SetPinDDR(portD,pin0,output);
    SetPinDDR(portD,pin1,output);
}

//============

void display(u8 number)
{
    if(number > 9)
        return;

    u8 pat = seg[number];

    for (u8 i = 0; i < 7; i++)
    {
        if(GET_BIT(pat,i))
            SetPinValue(portD, i, HIGH);
        else
            SetPinValue(portD, i, LOW);
    }
}

//============

void select(u8 digit)
{
    if(digit == 0)
    {
        SetPinValue(portD,pin0,HIGH);
        SetPinValue(portD,pin1,LOW);
    }
    else
    {
        SetPinValue(portD,pin0,LOW);
        SetPinValue(portD,pin1,HIGH);
    }
}
/*
#include "Gpio.h"
#include "SSD.h"
#include "BitMath.h"
u8 seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void init(void)
{
    for (int i = 0; i < 7; i++)
     SetPinDDR(portC,i,output);

SetPinDDR(portD,pin0,output);
SetPinDDR(portD,pin1,output);
}


//============

void diplay(u8 number)
{
if(number>9)
 return;
 u8 pat=seg[number];
 for (u8 i = 0; i < 7; i++)
 {
    if(GET_BIT(pat,i))
    SetPinValue(portD,HIGH,i);
    
    else
    SetPinValue(portD,LOW,i);
 }
 
}

//============

void select(u8 digit)
{
if(digit==0)
{
SetPinValue(portD,pin0,HIGH);
SetPinValue(portD,pin1,LOW);
}
else
{
SetPinValue(portD,pin0,LOW);
SetPinValue(portD,pin1,HIGH);
}
} */