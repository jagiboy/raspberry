#include "rpi.h"

//extern struct bcm2835_peripheral gpio;

int main()
{
	
	if(map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space. \n");
		return -1;
	}
	
	//define pin 7 as output
	
	INP_GPIO(4);
	OUT_GPIO(4);
	
	while(1)
	{                                        
		//Toggle pin 7 (blink a led!)
		GPIO_SET = 1 << 4;
		usleep(5 * 1000 * 100);
		
		GPIO_CLR = 1 << 4;
		usleep(5 * 1000 * 100);
	
	}
	
	return 0;
}
