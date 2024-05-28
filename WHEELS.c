/*
 * WHEELS.c
 *
 * Created: 16/05/2024 22:33:33
 *  Author: ahelo
 */ 



#include "WHEELS.h"
#include "TMR4.h"

// Funci�n para configurar las ruedas
void setupWheels(void) {
	
	// Configura los pines EN1 y EN2 como salidas
	DDRD |= (1 << TMR4_EN_PIN_1);
	DDRE |= (1 << TMR4_EN_PIN_2);

	// Inicializa el temporizador TMR4
	TMR4_PWM_Phase_Init();
}

// Funci�n para avanzar el robot
void Robot_FWD(uint8_t speedLeft, uint8_t speedRight) {
	TMR4_PWM_Phase_Start(TMR4_DIV_CLK_64);
	TMR4_Set_Motor_Direction(0, 0); // Establece la direcci�n para avanzar
	TMR4_PWM_Phase_Duty(speedLeft, speedRight); // Establece la velocidad de los motores izquierdo y derecho
}

// Funci�n para retroceder el robot
void Robot_BWD(uint8_t speedLeft, uint8_t speedRight) {
	TMR4_PWM_Phase_Start(TMR4_DIV_CLK_64);
	TMR4_Set_Motor_Direction(1, 1); // Establece la direcci�n para retroceder
	TMR4_PWM_Phase_Duty(speedLeft, speedRight); // Establece la velocidad de los motores izquierdo y derecho
}

// Funci�n para detener el robot
void Robot_STOP(void) {
	TMR4_PWM_Phase_Stop(); // Detiene ambos motores
}

// Funci�n para girar a la derecha
void Robot_RIGHT(uint8_t speedLeft, uint8_t speedRight) {
	TMR4_PWM_Phase_Start(TMR4_DIV_CLK_64);
	TMR4_Set_Motor_Direction(1, 0); // Establece la direcci�n para girar a la derecha
	TMR4_PWM_Phase_Duty(speedLeft, speedRight); // Establece la velocidad de los motores izquierdo y derecho
}

// Funci�n para girar a la izquierda
void Robot_LEFT(uint8_t speedLeft, uint8_t speedRight) {
	TMR4_PWM_Phase_Start(TMR4_DIV_CLK_64);
	TMR4_Set_Motor_Direction(0, 1); // Establece la direcci�n para girar a la izquierda
	TMR4_PWM_Phase_Duty(speedLeft, speedRight); // Establece la velocidad de los motores izquierdo y derecho
}

// Funci�n para establecer la direcci�n del giro de los motores
void TMR4_Set_Motor_Direction(uint8_t en1, uint8_t en2) {
	// Establecer la direcci�n del giro de los motores utilizando los pines EN1 y EN2
	if (en1)
	PORTD|= (1 << TMR4_EN_PIN_1);
	else
	PORTD &= ~(1 << TMR4_EN_PIN_1);

	if (en2)
	PORTE |= (1 << TMR4_EN_PIN_2);
	else
	PORTE &= ~(1 << TMR4_EN_PIN_2);
}


