#include<stdint.h>
//#define uint32 unsigned int
#define RCC_BASE_ADD 0x40023800
#define GPIOA_BASE_ADDR 0x40020000
uint32_t *RCC_CR=(uint32_t*)RCC_BASE_ADD;
uint32_t *RCC_AHB1ENR=(uint32_t*)(RCC_BASE_ADD+0x30);
uint32_t *GPIOA_MODER=(uint32_t*)GPIOA_BASE_ADDR;
uint32_t *(GPIOA_OSPEEDR)=(uint32_t*)(GPIOA_BASE_ADDR+0x08);
uint32_t *(GPIOA_BSRR)=(uint32_t*)(GPIOA_BASE_ADDR+0x18);
uint32_t *(GPIOA_OTYPER)=(uint32_t*)(GPIOA_BASE_ADDR+0x04);
uint32_t *(GPIOA_PUPDR)=(uint32_t*)(GPIOA_BASE_ADDR+0x0C);

int main(void)
{
	*RCC_CR |= (1<<0);
	*RCC_AHB1ENR |= (1<<0);
	*GPIOA_MODER |= (1<<0);
	*GPIOA_MODER &= ~(1<<1);
	*GPIOA_OTYPER &=~(1<<0);
	*GPIOA_PUPDR |=(1<<0);
	*GPIOA_PUPDR &=~(1<<1);

	*GPIOA_OSPEEDR |= (1<<0);
	*GPIOA_OSPEEDR |= (1<<1);


		while(1)
	{
		for(uint32_t
			i=0;i<100000;i++)
		{
			*GPIOA_BSRR |= (1<<0);
			

		}
		for(uint32_t i=0;i<100000;i++)
		{
			*GPIOA_BSRR |=(1<<16);
			
		}

	}

}
