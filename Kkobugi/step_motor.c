#include <util/delay.h>
#include <stdlib.h>
#include "step_motor.h"

#define STEPPER_DDR		DDRE
#define STEPPER_PORT	PORTE
#define STEPPER_PIN		PINE
#define STEPPER_L1		PB1
#define STEPPER_L2		PB3
#define STEPPER_L3		PB5
#define STEPPER_L4		PB7
#define STEPPER_R1		PB2
#define STEPPER_R2		PB4
#define STEPPER_R3		PB6
#define STEPPER_R4		PB8
#define STEPPER_DELAY	40

unsigned int full_pattern[4] = {
	0b1100,
	0b0110,
	0b0011,
	0b1001,
};

stepper_t stepper_left = {
	{
		PB1, PB3, PB5, PB7
	},
	{
		0b10100000,
		0b00101000,
		0b00001010,
		0b10000010,
	}
};

stepper_t stepper_right = {
	{
		PB0, PB2, PB4, PB6
	},
	{
		0b01010000,
		0b00010100,
		0b00000101,
		0b01000001,
	}
};

void STEPPER_init() {
	STEPPER_DDR = 0xFF;
}

void STEPPER_cleanup() {
}

void STEPPER_rotate(enum STEPPER_TYPE type, int steps) {
	stepper_t* stepper = type == LEFT ? &stepper_left : &stepper_right;
	
	// FullStep
	if (steps > 0) { // CLOCKWISE
		for (int i = 0; i < steps; i++) {
			for (int j = 0; j < 4; j++) {
				STEPPER_PORT = 0x00;
				
				if (full_pattern[j%4] & 0x8) STEPPER_PORT |= (1 << stepper->pin[0]);
				if (full_pattern[j%4] & 0x4) STEPPER_PORT |= (1 << stepper->pin[1]);
				if (full_pattern[j%4] & 0x2) STEPPER_PORT |= (1 << stepper->pin[2]);
				if (full_pattern[j%4] & 0x1) STEPPER_PORT |= (1 << stepper->pin[3]);
				
				_delay_ms(STEPPER_DELAY);
			}
		}
	} else {
		for (int i = 0; i < (-steps); i++) {
			for (int j = 7; j >= 0; j--) {
				STEPPER_PORT = 0x00;
				
				if (full_pattern[j%4] & 0x8) STEPPER_PORT |= (1 << stepper->pin[0]);
				if (full_pattern[j%4] & 0x4) STEPPER_PORT |= (1 << stepper->pin[1]);
				if (full_pattern[j%4] & 0x2) STEPPER_PORT |= (1 << stepper->pin[2]);
				if (full_pattern[j%4] & 0x1) STEPPER_PORT |= (1 << stepper->pin[3]);
				
				_delay_ms(STEPPER_DELAY);
			}
		}
	}
}