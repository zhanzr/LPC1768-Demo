#include <stdio.h>
#include <stdint.h>
#include "LPC17xx.h"

#define	HZ	1000

volatile static uint32_t g_Ticks;

void SysTick_Handler(void)
{
  g_Ticks++;
}

void SimpleDelay(uint32_t d)
{
	uint32_t t = d * 100;
	while(--t)
	{
		__NOP();
	}
}

int main(void)
{
  /* Configure SysTick */
  SysTick_Config(SystemCoreClock/HZ);
	
	printf("hello lpc1768\n");
	
	while(1)
	{
		printf("%u\t%u\n", SystemCoreClock, g_Ticks);
		SimpleDelay(10000);		
		printf("%u\t%u\n", SystemCoreClock, g_Ticks);
		SimpleDelay(10000);		
		printf("%u\t%u\n", SystemCoreClock, g_Ticks);
	}
	
	return 0;
}
