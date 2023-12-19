#define F_CPU 16000000UL
#include <util/delay.h>
#include "kkobugi.h"

void draw();

int main(void) {
	KKOBUGI_init();
	_delay_ms(3000);
	
	draw();
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
	
	KKOBUGI_start_drawing();
	
	for (i = 360/12; i--; ) {
		KKOBUGI_go(20);
		KKOBUGI_turn_with_pause(+12);
	}
	
	KKOBUGI_stop_drawing();
	
	//KKOBUGI_turn(+90);
	
	//Star
	//KKOBUGI_start_drawing();
	//for (int go = 180, i = 5; i--; go*=-1) {
	//	KKOBUGI_go(go);
	//	KKOBUGI_turn_with_pause(-36);
	//}
	//KKOBUGI_stop_drawing();

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
