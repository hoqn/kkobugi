#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "stepper.h"

#define L_DDR	DDRE
#define L_PORT	PORTE
#define L_PIN	PINE
#define L_A		0x80
#define L_B		0x20
#define L_C		0x40
#define L_D		0x10

#define R_DDR	DDRF
#define R_PORT	PORTF
#define R_PIN	PINF
#define R_A		0x01
#define R_B		0x04
#define R_C		0x10
#define R_D		0x40

#define DELAY	5

unsigned int full_pattern[4] = {
	0b1001,
	0b0011,
	0b0110,
	0b1100,
};

void STEPPER_init() {
	L_DDR= 0xFF;
	R_DDR= 0xFF;
}

void STEPPER_step(int left_step, int right_step) {
	
	int left_step_abs = left_step >= 0 ? left_step : -left_step;
	int right_step_abs = right_step >= 0 ? right_step : -right_step;
	
	int max_step = left_step_abs > right_step_abs ? left_step_abs : right_step_abs;
	
	for (volatile int i = 0; i < max_step; i ++) {
		for (volatile int j = 0, k = 3; j < 4 && k >= 0; j++, k--) {
			// left
			if (i < left_step_abs) {
				L_PORT = 0x00;
				volatile int q = left_step > 0 ? j%4 : k%4;
				
				volatile unsigned int val = 0x00;
				
				if (full_pattern[q] & 0x8) val |= L_A;
				if (full_pattern[q] & 0x4) val |= L_B;
				if (full_pattern[q] & 0x2) val |= L_C;
				if (full_pattern[q] & 0x1) val |= L_D;
				
				L_PORT |= val;
			}
			
			// right
			if (i < right_step_abs) {
				R_PORT = 0x00;
				volatile int q = right_step > 0 ? j%4 : k%4;
				
				volatile unsigned int val = 0x00;
				
				if (full_pattern[q] & 0x8) val |= R_A;
				if (full_pattern[q] & 0x4) val |= R_B;
				if (full_pattern[q] & 0x2) val |= R_C;
				if (full_pattern[q] & 0x1) val |= R_D;
				
				R_PORT |= val;
			}
			
			_delay_ms(DELAY);
		}
	}
}
