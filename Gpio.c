#include "Gpio.h"
#include "StdTypes.h"

u8 KPD[4][4]=
{
    {7,8,9,'/'},
    {4,5,6,'*'},
    {1,2,3,'-'},
    {'C', 0, '=', '+'}
};

//====================================

void SetPinValue(u8 port, u8 pin, u8 value)
{
    switch (value)
    {
        case HIGH:
            switch (port)
            {
                case portA: SET_BIT(PORTA,pin); break;
                case portB: SET_BIT(PORTB,pin); break;
                case portC: SET_BIT(PORTC,pin); break;
                case portD: SET_BIT(PORTD,pin); break;
            }
        break;

        case LOW:
            switch (port)
            {
                case portA: CLR_BIT(PORTA,pin); break;
                case portB: CLR_BIT(PORTB,pin); break;
                case portC: CLR_BIT(PORTC,pin); break;
                case portD: CLR_BIT(PORTD,pin); break;
            }
        break;
    }
}

//====================================

void SetPinDDR(u8 port, u8 pin, u8 DDR)
{
    switch (DDR)
    {
        case output:
            switch (port)
            {
                case portA: SET_BIT(DDRA,pin); break;
                case portB: SET_BIT(DDRB,pin); break;
                case portC: SET_BIT(DDRC,pin); break;
                case portD: SET_BIT(DDRD,pin); break;
            }
        break;

        case input:
            switch (port)
            {
                case portA: CLR_BIT(DDRA,pin); break;
                case portB: CLR_BIT(DDRB,pin); break;
                case portC: CLR_BIT(DDRC,pin); break;
                case portD: CLR_BIT(DDRD,pin); break;
            }
        break;
    }
}

//==============================================

u8 GetPinValue(u8 port, u8 pin)
{
    u8 value=0;

    switch (port)
    {
        case portA: value = GET_BIT(PINA,pin); break;
        case portB: value = GET_BIT(PINB,pin); break;
        case portC: value = GET_BIT(PINC,pin); break;
        case portD: value = GET_BIT(PIND,pin); break;
    }

    return value;
}

//==============================================

void init_kpd(void)
{
    // rows
    SetPinDDR(portA,pin0,output);
    SetPinDDR(portA,pin1,output);
    SetPinDDR(portA,pin2,output);
    SetPinDDR(portA,pin3,output);

    // pull-up rows
    SetPinValue(portA,pin0,HIGH);
    SetPinValue(portA,pin1,HIGH);
    SetPinValue(portA,pin2,HIGH);
    SetPinValue(portA,pin3,HIGH);

    // cols
    SetPinDDR(portB,pin0,input);
    SetPinDDR(portB,pin1,input);
    SetPinDDR(portB,pin2,input);
    SetPinDDR(portB,pin3,input);

    // pull-up cols
    SetPinValue(portB,pin0,HIGH);
    SetPinValue(portB,pin1,HIGH);
    SetPinValue(portB,pin2,HIGH);
    SetPinValue(portB,pin3,HIGH);
}

//==========================================

u8 KPD_GetKey(void)
{
    for(u8 row=0; row<4; row++)
    {
        // reset rows
        SetPinValue(portA,pin0,HIGH);
        SetPinValue(portA,pin1,HIGH);
        SetPinValue(portA,pin2,HIGH);
        SetPinValue(portA,pin3,HIGH);

        // activate row
        SetPinValue(portA,row,LOW);

        for(u8 col=0; col<4; col++)
        {
            if(GetPinValue(portB,col)==LOW)
            {
                while(GetPinValue(portB,col)==LOW); // wait release
                return KPD[row][col];
            }
        }
    }

    return NO_KEY;
}
/*
#include "Gpio.h"
#include "StdTypes.h"

u8 KPD[4][4]=
{
{7,8,9,'/'},
{4,5,6,'*'},
{1,2,3,'-'},
{'C', 0, '=', '+'}
};
void SetPinValue(u8 port, u8 pin, u8 value)
{
  
    switch (value)
    {
          case HIGH :
        switch (port)
        {
        case portA:
            SET_BIT(portA_reg,pin);
            break;
        
        case portB:
            SET_BIT(portB_reg,pin);
            break;

            case portC:
           SET_BIT(portC_reg,pin);
            break;

            case portD:
             SET_BIT(portD_reg,pin);
            break;
        }
           break;



        case LOW:
       switch (port)
        {
        case portA:
            CLR_BIT(portA_reg,pin);
            break;
        
        case portB:
            CLR_BIT(portB_reg,pin);
            break;

            case portC:
           CLR_BIT(portC_reg,pin);
            break;

            case portD:
             CLR_BIT(portD_reg,pin);
            break;
        }
      break;
    }
}



//====================================


void SetPinDDR(u8 port, u8 pin, u8 DDR)
{
  
    switch (DDR)
    {
          case output :
        switch (port)
        {
        case portA:
            SET_BIT(DDRA,pin);
            break;
        
        case portB:
            SET_BIT(DDRB,pin);
            break;

            case portC:
           SET_BIT(DDRC,pin);
            break;

            case portD:
             SET_BIT(DDRD,pin);
            break;
        }
           break;



        case input:
       switch (port)
        {
        case portA:
            CLR_BIT(DDRA,pin);
            break;
        
        case portB:
            CLR_BIT(DDRB,pin);
            break;

            case portC:
           CLR_BIT(DDRC,pin);
            break;

            case portD:
             CLR_BIT(DDRD,pin);
            break;
        }
      break;
    }
}



//==============================================
 
u8 GetPinValue(u8 port, u8 pin)
{
    u8 value=0;

switch (port)
{
case portA:
   value = GET_BIT(REGpinA,pin);
    break;

case portB:
   value = GET_BIT(REGpinB,pin);
    break;

    case portC:
   value = GET_BIT(REGpinC,pin);
    break;

    case portD:
   value = GET_BIT(REGpinD,pin);
    break;
}
return value ;
}



//=================================



void init_kpd(void)
{
    //row
    SetPinDDR(portA,pin0,output);
    SetPinDDR(portA,pin1,output);
    SetPinDDR(portA,pin2,output);
    SetPinDDR(portA,pin3,output);

    //pullup
    SetPinValue(portA,pin0,HIGH);
    SetPinValue(portA,pin1,HIGH);
    SetPinValue(portA,pin2,HIGH);
    SetPinValue(portA,pin3,HIGH);

    //colm
    SetPinDDR(portB,pin0,input);
    SetPinDDR(portB,pin1,input);
    SetPinDDR(portB,pin2,input);
    SetPinDDR(portB,pin3,input);
   
    
    //pullup
    SetPinValue(portB,pin0,HIGH);
    SetPinValue(portB,pin1,HIGH);
    SetPinValue(portB,pin2,HIGH);
    SetPinValue(portB,pin3,HIGH);

}//مبدايا ملهم high لان دا init بس


//==========================================
u8 KPD_GetKey(void)
{
    for(u8 row=0;row<4;row++)
{
     SetPinValue(portA,pin0,HIGH);
     SetPinValue(portA,pin1,HIGH);
     SetPinValue(portA,pin2,HIGH);
     SetPinValue(portA,pin3,HIGH);

     SetPinValue(portA,row,LOW);

    for(u8 col=0;col<4;col++)
    {
if(GetPinValue(portB,col)==LOW) //
{
while (GetPinValue(portB,col)==LOW); //

return KPD[row][col];

}}}
return NO_KEY;
}




//==========================================

*/