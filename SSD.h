#ifndef SSD_h
#define SSD_h

//reg portc
#define PORTC *((volatile u8*)0x28)
#define DDRC *((volatile u8*)0x27)

void init(void);
void display(u8 num);

#endif


