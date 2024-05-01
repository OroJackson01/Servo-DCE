/*
 * Buzzer.c
 *
 * Created: 01/05/2024 16:57:13
 * Author : ahelo
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Buzzer.h"


int main(void)
{
	init_buzzer();
    /* Replace with your application code */
    while (1) 
    {
		play_STARTING_SOUND();
		_delay_ms(5000);
		play_MATCH_SOUND();
		_delay_ms(5000);
		play_FAIL_SOUND();
		_delay_ms(5000);



    }
}

