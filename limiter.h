#ifndef LIMITER_H
#define LIMITER_H

#include "Processor.h"

using namespace std;


class Limiter: public Processor{

	public:
	Limiter();
	// Build a contructor for the class Limiter

   	~Limiter();
	// Build a Limiter destructor

   	void Processor8_M_S(unsigned char* buffer, int bufferSize) override;

    void Processor16_M_S(signed short* buffer, int bufferSize) override;	
};

#endif

