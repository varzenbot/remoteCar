#include <wiringPi.h>

enum Direction
{
	STOP = 0,
	FWD = 1,
	BWD = 2
};

class Engine
{
	const int _pin1, _pin2;
	void setPinMode(void);
	void resetPins(void)
	{
		digitalWrite(_pin1,LOW);
		digitalWrite(_pin2,LOW);
	}

	public:

	Engine() :  _pin1(-1),_pin2(-1) {}
	Engine(const int P1, const int P2) : _pin1(P1), _pin2(P2) { setPinMode(); }
	
	void Drive(enum Direction d = Direction::FWD);
};
