#include "StdTypes.h"
#include "Gpio.h"

void main(void)
{
    u8 key;
    u16 num1 =0,num2=0;
    u8 op=0, rus=0;

    u8 state = Fnum;  

    while(1)
    {
        key = KPD_GetKey();

        if(key != NO_KEY)
        {
            //================ digits =================
            if(key >= '0' && key <= '9')
            {
                if(state == Fnum)
                {
                    num1 = num1 * 10 + (key - '0');
                }
                else if(state == Snum)
                {
                    num2 = num2 * 10 + (key - '0');
                }
            }

            //================ operators =================
            else if(key == '+' || key == '-' || key == '*' || key == '/')
            {
                op = key;
                state = Snum;
            }

            //================ equals =================
            else if(key == '=')
            {
                switch(op)
                {
                    case '+': rus = num1 + num2; break;
                    case '-': rus = num1 - num2; break;
                    case '*': rus = num1 * num2; break;
                    case '/':
                        if(num2 != 0)
                            rus = num1 / num2;
                        else
                            rus = 0;
                        break;
                }

                num1 = rus;
                num2 = 0;
                state = Fnum;
                op = 0;
            }
        }
    }
}
/*
#include "StdTypes.h"
#include "Gpio.h"
void main(void)
{
u8 key;    // الزرار ال جاي من الكيباد
u16 num1 =0,num2=0 ;
u8 op=0 , rus=0;
u8 state =0; //دا بيقولنا احنا بنكتب num1 ,num2 ؟

while(1)
{
     key=KPD_GetKey(); //اقرا الزرار 
if(key !=NO_KEY)
{
if(key>='0' && key <= '9') // هل الزرار رقم؟
{
if(state==Fnum)
{
//بضرب في 10 علشان أزق الرقم القديم شمال وأضيف الجديد
num1= num1 *10 + (key-'0');
}
else if(state==Snum)
{
num2= num2 *10 + (key-'0');
}
}
}


   else if(key == '+'||key == '-'|| key == '*'|| key == '/')
    {
     op=key;
     state=Snum;

    }
    else if(key== '=')
    {
  switch (op)
  {
  case '+': rus =num1+num2 ; break;
    case '-': rus =num1-num2 ; break;
      case '*': rus =num1*num2 ; break;
        case '/': 
        if(num2!=0)
        rus =num1/num2 ;
        else
    rus = 0;
break;
  }
//هي الاستيت دي ال هي ايه وليه = Fnum
  num1=rus; num2=0; state = Fnum; op = 0;
    }}} */