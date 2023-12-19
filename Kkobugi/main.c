#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "kkobugi.h"

void draw();

void gakto_bojeong() {
	KKOBUGI_turn(90);
	KKOBUGI_turn(90);
	KKOBUGI_turn(180);
}

void servo_bojeong() {
	_delay_ms(1000);
	while (1) {
		KKOBUGI_start_drawing();
		_delay_ms(1000);
		KKOBUGI_stop_drawing();
		_delay_ms(1000);
	}
}

int main(void) {
	KKOBUGI_init();
	_delay_ms(3000);
	
	draw();
	//gakto_bojeong();
	//servo_bojeong();
}

void draw() {
	int i;
	
	//사각형
	//KKOBUGI_start_drawing();
	//for (i = 5; i--; ) {
	//	KKOBUGI_go(100);
	//	KKOBUGI_turn(-90);
	//}
	//KKOBUGI_stop_drawing();
	
	// 점선
	//KKOBUGI_start_drawing();
	//KKOBUGI_go(+50);
	//KKOBUGI_stop_drawing();
	//KKOBUGI_go(+50);
	//KKOBUGI_start_drawing();
	//KKOBUGI_go(+50);
	//KKOBUGI_stop_drawing();
	
	// 지그재그
	//KKOBUGI_turn(+10);
	//KKOBUGI_start_drawing();
	//for (i = 3; i--; ) {
	//	KKOBUGI_go(+50);
	//	KKOBUGI_turn(-20);
	//	KKOBUGI_go(+50);
	//	KKOBUGI_turn(+20);
	//}
	//KKOBUGI_stop_drawing();
	
	// 반원
	//KKOBUGI_start_drawing();
	//for (i = 12; i--; ) {
	//	KKOBUGI_go(+10);
	//	KKOBUGI_turn(15/*180/12*/);
	//}
	//KKOBUGI_turn(-90);
	//KKOBUGI_go(-100);
	//KKOBUGI_stop_drawing();
	
	// U
	//KKOBUGI_start_drawing();
	//
	//KKOBUGI_go(+60);
	//KKOBUGI_turn(-45);
	//KKOBUGI_go(+10);
	//KKOBUGI_turn(-45);
	//KKOBUGI_go(+30);
	//KKOBUGI_turn(-45);
	//KKOBUGI_go(+10);
	//KKOBUGI_turn(-45);
	//KKOBUGI_go(+60);
	//
	//KKOBUGI_stop_drawing();
	
	// 사각형 (한 방향)
	//KKOBUGI_start_drawing();
	//KKOBUGI_go(+100);
	//KKOBUGI_turn(-90);
	//KKOBUGI_go(+100);
	//KKOBUGI_turn(+90);
	//KKOBUGI_go(-100);
	//KKOBUGI_turn(-90);
	//KKOBUGI_go(-100);
	//KKOBUGI_stop_drawing();
	
	// 제자리
	//KKOBUGI_start_drawing();
	//KKOBUGI_turn(+20);
	//KKOBUGI_turn(-40);
	//KKOBUGI_turn(+20);
	//KKOBUGI_stop_drawing();
	
	// 원
	//KKOBUGI_start_drawing();
	//KKOBUGI_turn(-30);
	//for (i = 360/15; i--; ) {
	//	KKOBUGI_go(20);
	//	KKOBUGI_turn(+15);
	//}
	//KKOBUGI_stop_drawing();
	
	// UOS
	//KKOBUGI_go(+80);
	//KKOBUGI_start_drawing();
	//KKOBUGI_go(-80);
	//KKOBUGI_turn(-45);
	//KKOBUGI_go(-20);
	//KKOBUGI_turn(-45);
	//KKOBUGI_go(-30);
	//KKOBUGI_turn(+135);
	//KKOBUGI_go(+20);
	//KKOBUGI_turn(-45);
	//KKOBUGI_go(+80);
	//KKOBUGI_stop_drawing();
	//KKOBUGI_go(-80);
	
	// A
	//KKOBUGI_turn(+20);
	//KKOBUGI_start_drawing();
	//KKOBUGI_go(+200);
	//KKOBUGI_stop_drawing();
	//KKOBUGI_start_drawing();
	//KKOBUGI_turn(-40);
	//KKOBUGI_go(-200);
	//KKOBUGI_stop_drawing();
	//KKOBUGI_go(100);
	//KKOBUGI_turn(-70);
	//KKOBUGI_start_drawing();
	//KKOBUGI_go(100);
	//KKOBUGI_stop_drawing();
	////
	//KKOBUGI_turn(+90);
	//KKOBUGI_go(-180);
	//
	//KKOBUGI_turn(+90);
	//KKOBUGI_go(200);
	//
	//// B
	//KKOBUGI_turn(-90);
	//KKOBUGI_start_drawing();
	//KKOBUGI_go(250);
	//KKOBUGI_turn_with_pause(+90);
	//KKOBUGI_go(+20);
	//for (i = 4; i--; ) {
	//	KKOBUGI_go(40);
	//	KKOBUGI_turn_with_pause(+45);
	//}
	//KKOBUGI_go(+60);
	//KKOBUGI_stop_drawing();
	//KKOBUGI_go(-60);
	//KKOBUGI_start_drawing();
	//for (i = 3; i--; ) {
	//	KKOBUGI_turn(+45);
	//	KKOBUGI_go(-40);
	//}
	//KKOBUGI_turn(+45);
	//KKOBUGI_go(-60);
	
	//for (i = 360/12; i--; ) {
	//	KKOBUGI_go(20);
	//	KKOBUGI_turn_with_pause(+12);
	//}
	//
	//KKOBUGI_stop_drawing();
	
	//KKOBUGI_turn(+90);
	KKOBUGI_start_drawing();
	for (int go = 180, i = 5; i--; go*=-1) {
	KKOBUGI_go(go);
	KKOBUGI_turn_with_pause(-36);
}	
KKOBUGI_stop_drawing();

	//KKOBUGI_go(600);
	//
	//KKOBUGI_start_drawing();
	//for (i = 5; i--;) {
	//	
	//	KKOBUGI_go(100);
	//	KKOBUGI_turn_with_pause(-36);
	//	KKOBUGI_go(-100);
	//	KKOBUGI_turn_with_pause(108);
	//}
	//KKOBUGI_stop_drawing();
}

// STEPPER
//#include "step_motor.h"
//
//int main(void)
//{
//	STEPPER_init();

// 한 바퀴 513
//while (1) {

//STEPPER_rotate(RIGHT, +513);
//STEPPER_rotate(LEFT, +513);
//}

//_delay_ms(1000);
//}

//#include "stepper.h"
//#include "servo.h"
//
//int main(void) {
//
//	DDRA = 0xFF;
//	STEPPER_init();
//	SERVO_init();
//
//	_delay_ms(5000);
//
//	SERVO_rotate(90);
//
//	PORTA = 0xFF;
//}


// 방향제어

//#define F_CPU 1600000UL
//#define __DELAY_BACKWARD_COMPATIBLE__
//#include <avr/io.h>
//#include <util/delay.h>
//
//int main(void)
//{
//	DDRB|=0x20;
//	PORTB|=0x20;
//
//	TCCR1A=0x82;
//	TCCR1B=0x1b;
//	ICR1=4999;     //TOP 0부터 시작
//	OCR1A=375;     //0도
//	while(1)
//	{
//		OCR1A=250;     //-90도
//		_delay_ms(1000);
//		OCR1A=500;     //90도
//		_delay_ms(1000);
//	}
//}



//int main(void)
// {
//	 DDRE = 0xFF;
//
//	 PORTE = 0xFF;
// }
