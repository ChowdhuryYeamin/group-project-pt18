#define LIMITER_H
#ifndef LIMITER_H

#include "Processor.h"

using namespace std;


class Limiter: public Processor{

    public:

	Limiter::Limiter();
	// Build a contructor for the class Limiter

    Limiter::~Limiter();
	// Build a Limiter destructor

    void Processor8_M_S(unsigned char buffer[], int bufferSize);

    void Processor16_M_S(singed short buffer[], int bufferSize);

    Limiter::Limiter() {}
	// Build a contructor for the class Limiter

    Limiter::~Limiter() {}
	// Build a Limiter destructor


    
    

	
};

#endif

