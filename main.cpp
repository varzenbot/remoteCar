#include "engine/Engine.hpp"
#include "sonar/Sonar.hpp"
#include "buzzer/Buzzer.hpp"

#include "defines.hpp"

#include <iostream>

using namespace std;

int main(void)
{
	if( wiringPiSetup() == -1 )
	{
		cout << ("WiringPiSetup FAIL !!\n");
		return -1;
	}

	Sonar s;
	s.init(TRIGGER, ECHO);
	cout << s.distance(30000)<<endl;

	Engine left(LEFT_1, LEFT_2),
	       right(RIGHT_1, RIGHT_2);

	Buzzer buzz(BUZZER);

	long start=0, now=0;

	bool stuck = false;

	while(1)
	{
		start = micros();
		while( s.distance(30000) < 15.0 ) // too close to an obstacle -> TURN LEFT
		{
			left.Drive(Direction::BWD);
			right.Drive(Direction::FWD);
		cout << "TO THE LEFT ! \n";	
			now = micros();
			cout << now << "-> "<<start<<"\n";

			if( ( now - start ) > 15000000 )
			{
				stuck = true;
				cout << "STUCK!! \n";
				break;
			}	
		}
		if(stuck)
		{
			buzz.PlaySong();
			
		}
		else
		{
			left.Drive();
			right.Drive();
		}

	}
}
