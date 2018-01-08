#include <softTone.h>
#include <wiringPi.h>
#include "Buzzer.hpp"


const int Buzzer::song[] = {CM3, CM5, CM6, CM3, CM2, CM3, CM5, CM6, CH1, CM6, CM5, CM1, CM3, CM2,
		CM2, CM3, CM5, CM2, CM3, CL6, CL6, CL6, CM1, CM2, CM3, CM2, CL7, CL6, CM1, CL5};

const int Buzzer::beat[] = {1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,3,1,1,1,1,1,1,1,2,1,1};

Buzzer::Buzzer(int BuzzerPin) : buzzPin(BuzzerPin)
{	
	if(softToneCreate(BuzzerPin) == -1)
		throw;
}


void Buzzer::PlaySong()
{
		for(int i=0; i<sizeof(Buzzer::song)/4; i++)
		{
			softToneWrite( buzzPin, Buzzer::song[i]);
			delay( Buzzer::beat[i] * 500);
		}
}
