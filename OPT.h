/*
 * OPT.h
 *
 * Created: 09/05/2024 19:29:28
 *  Author: ahelo
 */ 


#ifndef OPT_H_
#define OPT_H_

#include <avr/io.h> // Librería para el manejo de registros de E/S del AVR


// Definiciones de constantes para el ADC
#define PRESCALER_128 7

#define BLACK_VALUE 0 // Definir el valor para un sensor negro
#define WHITE_VALUE 1023 // Definir el valor para un sensor blanco

// Definir los números de los sensores ópticos
#define IR0 7
#define IR1 6
#define IR2 5
#define IR3 4
#define IR4 1

// Opciones para la referencia de voltaje
#define AVCC 1			// Utilizamos esta
#define ADC_LEFT 1
#define ADC_RIGHT 0     // Utilizamos esta

// Inicialización del ADC
//OPT_Init(AVCC,ADC_RIGHT);
static inline void OPT_Init(){ // Parámetros: VCC y alineación
	
	// Configuración del multiplexor del ADC (ADMUX)
	ADMUX &= ~(0b11101111);
	ADMUX |= (IR0 << MUX0);      // Por defecto, se selecciona el canal 0
	ADMUX |= (1 << REFS0);      // Configura la referencia de voltaje
	ADMUX |= (0 << ADLAR);    // Configura la alineación de los resultados

	// Configuración del registro de control del ADC (ADCSRA)
	ADCSRA &= ~(0b11111111);
	ADCSRA |= (1 << ADEN);                    // Habilita el ADC
	ADCSRA |= (PRESCALER_128 << ADPS0);       // Configura el preescalador
}



// Prototipo de la función para leer un sensor IR
uint16_t check_IR_Sensor(uint8_t sensorIR_number);

// Prototipo de la función para leer todos los sensores IR en fila
uint16_t* readSensors();

#endif /* OPT_H_ */