#define LIMITER_H
#ifndef LIMITER_H

#include "Processor.h"

using namespace std;

class Limiter: public Processor{
	virtual void Processor(unsigned char* soundvalues, int numvalues) override{
	}
}

#endif

