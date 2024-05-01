/*
 * Buzzer.h
 *
 * Created: 01/05/2024 18:00:59
 *  Author: ahelo
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//Octava China
#define C 6
#define C_SHARP 7
#define D 8
#define D_SHARP 9
#define E 10
#define F 11
#define F_SHARP 13
#define G 14
#define G_SHARP 15
#define A 17
#define A_SHARP 19
#define B 20




//Octava 0
#define OCT0_C 16
#define OCT0_C_SHARP 17
#define OCT0_D 18
#define OCT0_D_SHARP 19
#define OCT0_E 20
#define OCT0_F 21
#define OCT0_F_SHARP 23
#define OCT0_G 24
#define OCT0_G_SHARP 25
#define OCT0_A 27
#define OCT0_A_SHARP 29
#define OCT0_B 30

//Octava 3
#define OCT3_C 130.81
#define OCT3_C_SHARP 138.59
#define OCT3_D 146.83
#define OCT3_D_SHARP 155.56
#define OCT3_E 164.81
#define OCT3_F 174.61
#define OCT3_F_SHARP 185.00
#define OCT3_G 196.00
#define OCT3_G_SHARP 207.65
#define OCT3_A 220.00
#define OCT3_A_SHARP 233.08
#define OCT3_B 246.94

//Octava 4
#define OCT4_C 261.63
#define OCT4_C_SHARP 277.18
#define OCT4_D 293.66
#define OCT4_D_SHARP 311.13
#define OCT4_E 329.63
#define OCT4_F 349.23
#define OCT4_F_SHARP 369.99
#define OCT4_G 392.00
#define OCT4_G_SHARP 415.30
#define OCT4_A 440.00
#define OCT4_A_SHARP 466.16
#define OCT4_B 493.88


#define Periodo_NaNo 33 //Sound time like **bip
#define BUZZER_PIN  PB2 //puerto al que está el BUZZER
#define TOGGLEBIT(ADDRESS,BIT)	(ADDRESS ^= (1<<BIT))

//Función set-up
void init_buzzer() {
	// Configura el pin del buzzer como salida
	DDRB |= (1 << BUZZER_PIN);
}

//play sound
static inline void playSound_noTMR(uint8_t period_ms, uint8_t times) {
	int i = 0;
	for (i = 0; i < times; i++) {
		_delay_ms(period_ms);
		TOGGLEBIT(PORTB, BUZZER_PIN);
	}
}

// Hace que gane claridad el sonido
static inline void tocarNota(uint8_t nota, uint8_t periodo) {
	playSound_noTMR(nota, periodo);
	_delay_ms(300); // Tiempo para que se distingan las notas Concept:Contranota
}

//Para saber hacer un sonido u otro 
typedef enum {
	STARTING_SOUND,
	MATCH_SOUND,
	FAIL_SOUND
} Sonido_t;


// FUNCIONES SONIDOS

static inline void play_STARTING_SOUND() {
	int i;
	for(i =0;i <3 ;i++){
	tocarNota(1, Periodo_NaNo);	
	tocarNota(2, Periodo_NaNo);	
	tocarNota(4, Periodo_NaNo);	
	}
	
}

static inline void play_MATCH_SOUND() {
	tocarNota(5, Periodo_NaNo);
	
}

static inline void play_FAIL_SOUND() {
	tocarNota(6, Periodo_NaNo);
	//_delay_ms(500);
	tocarNota(7, Periodo_NaNo);
	//_delay_ms(500);
	tocarNota(9, Periodo_NaNo);
	//_delay_ms(500);
	tocarNota(11,Periodo_NaNo*3);
}



//Funcion que toca musica del menu del Soccer peruano 97 
static inline void SoccerPeruano97(){
			
			tocarNota(A, 20);
			tocarNota(A, 20);
			tocarNota(A, 20);
			_delay_ms(15);
			tocarNota(C, 20);
			tocarNota(E, 20);
			_delay_ms(15);
			tocarNota(G, 20);
			_delay_ms(15);
			tocarNota(F, 20);
			_delay_ms(15);
			tocarNota(E, 20);
			_delay_ms(15);
			tocarNota(D, 20);
			_delay_ms(15);
			tocarNota(C, 20);
			_delay_ms(15);
}

#endif /* BUZZER_H_ */