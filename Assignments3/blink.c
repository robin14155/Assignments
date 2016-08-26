#define F_CPU 16000000UL //1 MHz

void delay(int time) //delay function
{
    volatile unsigned int rate=F_CPU/17500;//rate is the num of times the for loop should execute for 1ms delay				
    volatile unsigned int i;
    while(time--)						
    {
	for(i=0;i<=rate;i++)
	{
	    __asm__ __volatile__ ("nop");//nop is used for "No Operation" i.e to not change the state of any register during execution
        }
    }
}

int main (void)
{
volatile uint8_t *dir = (volatile uint8_t *)0x24;     //DDRB
volatile uint8_t *port = (volatile uint8_t *)0x25;	  //PORTB
*dir = 0xff;  //1<<5 _BV(5) 

  while (1)
    {
*port=0x20;
delay(1000);
*port=0x00;
delay(1000);

    }

  return 1;
}




