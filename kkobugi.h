enum FB_Direction {
	FORWARD = +1, BACKWAR = -1,
	};
	
void KKOBUGI_init();
void KKOBUGI_go(FB_Direction dir);
void KKOBUGI_turn(int degree);
void KKOBUGI_start_drawing();
void KKOBUGI_stop_drawing();
