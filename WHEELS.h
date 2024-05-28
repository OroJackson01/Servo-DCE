/*
 * WHEELS.h
 *
 * Created: 16/05/2024 22:33:53
 *  Author: ahelo
 */ 



#ifndef WHEELS_H_
#define WHEELS_H_

#include <stdint.h>
#include <avr/io.h> // Incluye las definiciones de IO para AVR

// Definiciones de pines (aseg�rate de que estos valores sean correctos para tu hardware)
#define TMR4_EN_PIN_1 DDE6 // EN1
#define TMR4_EN_PIN_2 DDD6 // EN2

// Prototipos de las funciones de configuraci�n de las ruedas
void setupWheels(void);

// Prototipos de las funciones de movimiento
void Robot_FWD(uint8_t speedLeft, uint8_t speedRight);
void Robot_BWD(uint8_t speedLeft, uint8_t speedRight);
void Robot_STOP(void);
void Robot_RIGHT(uint8_t speedLeft, uint8_t speedRight);
void Robot_LEFT(uint8_t speedLeft, uint8_t speedRight);

// Prototipo de la funci�n para establecer la direcci�n del giro de los motores
void TMR4_Set_Motor_Direction(uint8_t en1, uint8_t en2);

#endif /* WHEELS_H_ */

