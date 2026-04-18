#ifndef Gpio_h
#define Gpio_h

#include "StdTypes.h"

//================ FUNCTIONS =================
void SetPinValue(u8 port,u8 pin, u8 value);
void SetPinDDR(u8 port, u8 pin, u8 DDR);
u8 GetPinValue(u8 port, u8 pin);

void init_kpd(void);
u8 KPD_GetKey(void);

//================ PORT MAP =================
#define portA 0
#define portB 1
#define portC 2
#define portD 3

//================ DDR / PORT / PIN (ATmega32 REAL ADDRESSES) =================
#define DDRA   (*(volatile u8*)0x3A)
#define DDRB   (*(volatile u8*)0x37)
#define DDRC   (*(volatile u8*)0x34)
#define DDRD   (*(volatile u8*)0x31)

#define PORTA  (*(volatile u8*)0x3B)
#define PORTB  (*(volatile u8*)0x38)
#define PORTC  (*(volatile u8*)0x35)
#define PORTD  (*(volatile u8*)0x32)

#define PINA   (*(volatile u8*)0x39)
#define PINB   (*(volatile u8*)0x36)
#define PINC   (*(volatile u8*)0x33)
#define PIND   (*(volatile u8*)0x30)

//================ VALUE =================
#define HIGH 1
#define LOW 0

#define output 1
#define input 0

//================ PINS =================
#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3

#define pin4 4
#define pin5 5
#define pin6 6

//================ KEYPAD MAP =================
#define NO_KEY 255
extern u8 KPD[4][4];

//================ CALC STATES =================
#define Fnum 1
#define Snum 2

#endif
/*
#ifndef Gpio_h
#define Gpio_h
#include "StdTypes.h"



void SetPinValue(u8 port,u8 pin, u8 value);
void SetPinDDR(u8 port, u8 pin, u8 DDR);
u8 GetPinValue(u8 port, u8 pin);

void init_kpd(void);
u8 KPD_GetKey(void);

#define portA 0
#define portB 1
#define portC 2
#define portD 3


#define DDRA 0
#define DDRB 1 
#define DDRC 2
#define DDRD 3

#define HIGH 1
#define LOW 0

#define output 1
#define input 0



#define portA_reg 0
#define portB_reg 1
#define portC_reg 2
#define portD_reg 3


#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3

#define REGpinA 0
#define REGpinB 1
#define REGpinC 2
#define REGpinD 3

//kpd pins
#define A pin0
#define B pin1
#define C pin2
#define D pin3
#define E pin4
#define F pin5
#define G pin6

//map
#define NO_KEY 255
extern u8 KPD [4][4];

// calc
#define Fnum 1
#define Snum 2


#endif  */

