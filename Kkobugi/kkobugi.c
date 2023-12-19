#include "kkobugi.h"
#include "stepper.h"
#include "servo.h"

#define SERVO_ON_DRAWING 0
#define SERVO_NOT_DRAWING 45

#define CM_TO_STEP_FACTOR_LEFT 1 //이거 바꿔가면서 캘리브레이션
#define CM_TO_STEP_FACTOR_RIGHT 1 //이거 바꿔가면서 캘리브레이션
//#define DEGREE_TO_STEP_FACTOR_LEFT 1.425 //이거 바꿔가면서 캘리브레이션
#define DEGREE_TO_STEP_FACTOR_LEFT 2.7f //이거 바꿔가면서 캘리브레이션
#define DEGREE_TO_STEP_FACTOR_RIGHT 2.7f //이거 바꿔가면서 캘리브레이션

#define DEGREE_BIAS_OUTER	0.1f // 회전 시 바깥쪽 바퀴 편향 정도

#define cm_to_step_left(cm) ((cm) * CM_TO_STEP_FACTOR_LEFT)
#define cm_to_step_right(cm) ((cm) * CM_TO_STEP_FACTOR_RIGHT)
#define degree_to_step_left(degree) ((degree) * DEGREE_TO_STEP_FACTOR_LEFT)
#define degree_to_step_right(degree) ((degree) * DEGREE_TO_STEP_FACTOR_RIGHT)

void KKOBUGI_init() {
	SERVO_init();
	STEPPER_init();
	
	KKOBUGI_stop_drawing();
}

// If distance is positive value, then go forward. vice versa.
// distance unit: cm
void KKOBUGI_go(int distance) {
	STEPPER_step(+cm_to_step_left(distance), +cm_to_step_right(distance));
}

void KKOBUGI_turn(int degree) {
	__KKOBUGI_turn(degree, 0);
}

void KKOBUGI_turn_with_pause(int degree) {
	__KKOBUGI_turn(degree, 1);
}

// If degree is positive value, then turn right. vice versa.
// degree unit: degree
void __KKOBUGI_turn(int degree, int pause_drawing) {
	if (pause_drawing)
	KKOBUGI_stop_drawing();
	
	int left_dist = degree_to_step_left(degree);
	int right_dist = degree_to_step_right(degree);
	
	//if (degree > 0) // turn right => outer wheel is right one
	//	STEPPER_step(0, DEGREE_BIAS_OUTER);
	//else if (degree < 0)
	//	STEPPER_step(DEGREE_BIAS_OUTER, 0);
	STEPPER_step(+left_dist, -right_dist);
	
	if (pause_drawing)
	KKOBUGI_start_drawing();
}

void KKOBUGI_start_drawing() {
	SERVO_rotate(SERVO_ON_DRAWING);
}

void KKOBUGI_stop_drawing() {
	SERVO_rotate(SERVO_NOT_DRAWING);
}