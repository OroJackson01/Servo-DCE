/*
 * Optical.c
 *
 * Created: 09/05/2024 17:50:30
 * Author : ahelo
 */ 

#include <avr/io.h>
#include "Buzzer.h"
#include "OPT.h"
#include "m_usb.h"
#include "m_general.h"
#include "m_usb.h"


#define BLACK_VALUE_THRESHOLD 256
#define WHITE_VALUE_THRESHOLD 768

int main(void)
{
	
	init_buzzer();
	play_STARTING_SOUND();
	OPT_Init();
	
	m_usb_init(); // USB peripheral setup
	while(!m_usb_isconnected()); // Wait for a USB connection
	m_usb_tx_string("Empezamos las lecturas!\n\r"); 	
	
	int i=0;
    uint16_t *valores;
	uint16_t readS;
	
	while(1){
	valores= readSensors();
	readS=valores[i];
	
	
	
	
	if ((WHITE_VALUE + BLACK_VALUE)/2 >readS){
			play_MATCH_SOUND();
			m_usb_tx_string("Leido color Negro\n\r");		
	}
	else{
			play_FAIL_SOUND();
			m_usb_tx_string("Leido color Blanco\n\r");		
		
	}
	

			
	i=(i+1)%5;
	_delay_ms(250);
	}
    
}

