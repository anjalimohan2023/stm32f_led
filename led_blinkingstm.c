#include<stdint.h>
#define RCC_BASE_ADD 0x40023800
#define GPIOG_BASE_ADDR 0x40021800
uint32_t *RCC_CR=(uint32_t*)RCC_BASE_ADD;
uint32_t *RCC_AHB1ENR=(uint32_t*)(RCC_BASE_ADD+0x30);
uint32_t *GPIOG_MODER=(uint32_t*)GPIOG_BASE_ADDR;
uint32_t *(GPIOG_OSPEEDR)=(uint32_t*)(GPIOG_BASE_ADDR+0x08);
uint32_t *(GPIOG_BSRR)=(uint32_t*)(GPIOG_BASE_ADDR+0x18);

int main(void)
{
	*RCC_CR |= (1<<0);
	*RCC_AHB1ENR |= (1<<6);
	*GPIOG_MODER |= (1<<26);
	*GPIOG_MODER |= (1<<28);
	*GPIOG_MODER &= ~(0<<27);
	*GPIOG_MODER &= ~(0<<29);

	*GPIOG_OSPEEDR |= (1<<26);
	*GPIOG_OSPEEDR |= (1<<28);


		while(1)
	{
		for(uint32_t i =0;i<100000;i++)
		{
			*GPIOG_BSRR |= (1<<13);
			*GPIOG_BSRR |= (1<<14);
			
		}
		for(uint32_t i =0;i<100000;i++)
		{
			*GPIOG_BSRR =(1<<29);
			*GPIOG_BSRR =(1<<30);
		}

	}

}
