#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// STEPPER
#include "step_motor.h"

int main(void)
{
	STEPPER_init();
	
	// ÇÑ ¹ÙÄû 513
	while (1) {
		
	STEPPER_rotate(RIGHT, +513);
	STEPPER_rotate(LEFT, +513);
}

	_delay_ms(1000);
}

