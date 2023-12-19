#include <math.h>
#include "kkobugi.h"

#define TRUE	1
#define FALSE	0

#define SERVO_ON_DRAWING 0
#define SERVO_NOT_DRAWING 45

// 아래 바꿔가면서 캘리브레이션할 것!
#define MM_TO_STEP_FACTOR 1
#define DEGREE_TO_STEP_FACTOR 2.7f

#define mm_to_step(mm) (round((mm) * MM_TO_STEP_FACTOR))
#define degree_to_step(degree) (round((degree) * DEGREE_TO_STEP_FACTOR))

// 그리고 있을 때 상태를 나타내는 플래그
int is_drawing = 0;

void KKOBUGI_init() {
	SERVO_init();
	STEPPER_init();
	
	KKOBUGI_stop_drawing();
}

// distance 가 양수이면, 앞으로 이동. vice versa.
// distance unit: mm
void KKOBUGI_go(int distance) {
	int steps = mm_to_step(distance);
	STEPPER_step(steps, steps);
}

// degree 가 양수이면, 오른쪽으로 회전. vice versa.
// degree unit: degree
void __KKOBUGI_turn(int degree, int pause_drawing) {
	int draw_again = FALSE;
	
	if (pause_drawing && is_drawing) {	
		KKOBUGI_stop_drawing();
		draw_again = TRUE;
	}
	
	int dist = degree_to_step(degree);
	STEPPER_step(+dist, -dist);
	
	if (draw_again)
		KKOBUGI_start_drawing();
}

// 그리고 있는지와 무관하게 회전한다.
void KKOBUGI_turn(int degree) {
	__KKOBUGI_turn(degree, FALSE);
}

// 그리고 있다면 잠깐 펜을 들고 회전하고, 다시 펜을 내린다.
void KKOBUGI_turn_with_pause(int degree) {
	__KKOBUGI_turn(degree, TRUE);
}

void KKOBUGI_start_drawing() {
	is_drawing = TRUE;
	SERVO_rotate(SERVO_ON_DRAWING);
}

void KKOBUGI_stop_drawing() {
	is_drawing = FALSE;
	SERVO_rotate(SERVO_NOT_DRAWING);
}