#ifndef STEP_MOTOR_H_
#define STEP_MOTOR_H_

#include <avr/io.h>

typedef struct {
	int pin[4];
	unsigned int pattern[4];
} stepper_t;

enum STEPPER_TYPE {
	LEFT,
	RIGHT,	
};

void STEPPER_init();
void STEPPER_cleanup();
void STEPPER_rotate(enum STEPPER_TYPE type, int steps);

#endif /* STEP_MOTOR_H_ */