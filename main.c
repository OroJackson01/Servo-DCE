/*
 * Motors.c
 *
 * Created: 16/05/2024 19:52:24
 * Author : ahelo
 */ 





#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "TMR4.h"
#include "WHEELS.h"


int main(void)
{
	TMR4_PWM_Phase_Init();
	
	TMR4_PWM_Phase_Start(TMR4_DIV_CLK_64);
	while (1)
	{
		
		 // Avanzar
		 Robot_FWD(100, 100); // Velocidad izquierda: 100, Velocidad derecha: 100
		 _delay_ms(1000); // Esperar 1 segundo

		 // Retroceder
		 Robot_BWD(100, 100); // Velocidad izquierda: 100, Velocidad derecha: 100
		 _delay_ms(1000); // Esperar 1 segundo

		 // Girar a la derecha
		 Robot_RIGHT(100, 100); // Velocidad izquierda: 100, Velocidad derecha: 100
		 _delay_ms(1000); // Esperar 1 segundo

		 // Girar a la izquierda
		 Robot_LEFT(100, 100); // Velocidad;
		 _delay_ms(1000); // Esperar 1 segundo

		 // Parar
		 Robot_STOP();
	}
}

/*

*/


