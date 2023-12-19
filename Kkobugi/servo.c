#include "servo.h"

#define F_CPU 1600000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <avr/io.h>
#include <util/delay.h>

void SERVO_init() {
		DDRB|=0x20;
		PORTB|=0x20;

		TCCR1A=0x82;
		TCCR1B=0x1b;
		ICR1=4999;     //TOP 0부터 시작
		
		OCR1A=375;     //0도 375, 90도 625
}

void SERVO_rotate(int degree) {
	OCR1A = 375 + (degree * ((float)25/9));
	//OCR1A = degree > 0 ? 500 : 375;
	_delay_ms(500);
}
