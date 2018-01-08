#include "Engine.hpp"
#include <wiringPi.h>


void Engine::setPinMode(void)
{
	pinMode(this->_pin1, OUTPUT);
	pinMode(this->_pin2, OUTPUT);
}

void Engine::Drive(Direction d)
{
	resetPins();
	switch(d)
	{
		case STOP:
			break;
		case FWD:
			digitalWrite(this->_pin1, HIGH);
			break;
		case BWD:
			digitalWrite(this->_pin2, HIGH);
			break;
	}
	delay(100);
}
