/*
 * OPT.c
 *
 * Created: 09/05/2024 19:29:05
 *  Author: ahelo
 */ 

#include "OPT.h"

#include <avr/io.h>

//----------------------------------------------------------------------
// Realiza una sola lectura ADC de forma síncrona (polling)

uint16_t ADC_Read_Single_Poll(uint8_t channel){
	ADCSRA |= (1 << ADIF);
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX2) | (1 << MUX3));
	ADMUX |= (channel << MUX0);
	ADCSRA |= (1 << ADSC);
	while((ADCSRA & (1 << ADIF)) == 0){}	// Verifica que el bit ADIF esté en 0
	return ADC;
}



// Realiza múltiples lecturas ADC de forma síncrona (polling) y promedia los resultados
uint16_t ADC_Read_Multiple_Poll(uint8_t channel, uint8_t n_veces){
	ADC_Read_Single_Poll(channel);		// Lectura de calibración, no se tomará en cuenta.
	uint16_t res = 0;
	for(uint8_t i = 0; i < n_veces; i++){
		res += ADC_Read_Single_Poll(channel);
	}
	switch(n_veces){
		case 1: break;
		case 2: res = res >> 1; break;
		case 4: res = res >> 2; break;
		case 8: res = res >> 3; break;
		case 16: res = res >> 4; break;
		case 32: res = res >> 5; break;
		default: res /= n_veces; break;
	}
	return res;
}


// Función para leer un sensor IR
uint16_t check_IR_Sensor(uint8_t sensorIR_number) {
	// Seleccionar el canal correspondiente al sensor IR dado
	return ADC_Read_Multiple_Poll(sensorIR_number,32);
}


// Función para leer todos los sensores IR en fila
uint16_t* readSensors() {
	static uint16_t values[5]; // Array para almacenar los valores de los sensores
	
	
	values[0] = check_IR_Sensor(IR0);
	
	values[1] = check_IR_Sensor(IR1);
	
	values[2] = check_IR_Sensor(IR2);
	
	values[3] = check_IR_Sensor(IR3);
	
	values[4] = check_IR_Sensor(IR4);
	
	return values;
}


