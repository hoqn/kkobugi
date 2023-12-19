typedef struct {
	unsigned int ddr,
	unsigned int port,
	unsigned int pin,
	unsigned int sig[4],
	unsigned int delay,
	} stepper_t;

void STEPPER_init(stepper_t *stepper);
void STEPPER_step(stepper_t *stepper, int step);
