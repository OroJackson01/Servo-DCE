/*
 * TMR4.h
 *
 *  Author: ahelo
 */ 


#ifndef TMR4_H_
#define TMR4_H_

#define TMR4_DIV_CLK_0		0
#define TMR4_DIV_CLK_1		1
#define TMR4_DIV_CLK_8		4
#define TMR4_DIV_CLK_64		7
#define TMR4_DIV_CLK_256	9
#define TMR4_DIV_CLK_1024	11

// Define constantes para la configuración de dirección del giro
#define TMR4_EN_PIN_1 DDE6 // EN1
#define TMR4_EN_PIN_2 DDD6 // EN2

//=============        PWM Functions      =====================

inline void TMR4_PWM_Phase_Init(void) {
	// 1.- For making sure HW pins are configured as outputs.
	// Hardware outputs OC4D and !OC4A (Leonardo PD5,PD6)
	DDRD |=(1<<DDD7);
	DDRC |=(1<<DDC6);
	// 2.- Selecting the PWM waveform (Clear !OC4A).
	// 3.- Enable HW PWM in !OC4A
	TCCR4A |= (1<<COM4A0)|(1<<PWM4A);
	// 4.- Selecting the PWM waveform (Clear OC4D).
	// 5.- Enable HW PWM in OC4D
	TCCR4C |= (1<<PWM4D)|(1<<COM4D1);
	// 6.- Enable HW PWM in OC4D
	TCCR4D |= (1<<WGM40);
}

static inline  void TMR4_PWM_Phase_Start(uint8_t divClock) {
	// 1.- Clear the counter
	TCNT4 = 0;
	// 2.- Set prescaler and start timer
	//TCCR4B|=(1<<CS42)|(1<<CS41)|(1<<CS40);
	TCCR4B|=(divClock<<CS40);
}

static inline  void TMR4_PWM_Phase_Duty(uint8_t valueOCR4A, uint8_t valueOCR4D){
	OCR4D=valueOCR4D;
	OCR4A=~valueOCR4A;
}

static inline  void TMR4_PWM_Phase_Stop(void) {
	// 2.- Set prescaler to stop the timer
	TMR4_PWM_Phase_Duty(0,0);
	TCCR4B&=~((1<<CS40) | (1<<CS41) | (1<<CS42) | (1<<CS43));
	TCNT4 = 0;
	
}

#endif /* TMR4_H_ */