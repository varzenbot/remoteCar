#include "Sounds.hpp"
/*
static const int song[] = {CM3, CM5, CM6, CM3, CM2, CM3, CM5, CM6, CH1, CM6, CM5, CM1, CM3, CM2,
		CM2, CM3, CM5, CM2, CM3, CL6, CL6, CL6, CM1, CM2, CM3, CM2, CL7, CL6, CM1, CL5};
static const int beat[] = {1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,3,1,1,1,1,1,1,1,2,1,1,
		1,1,1,1,1,1,3};*/
class Buzzer
{
	const static int song[];
	const static int beat[]; 
	int buzzPin;

	public:
	        Buzzer(int BuzzerPin);

		void PlaySong();

};

//		1,1,1,1,1,1,3};
