#define NOISEGATE_H
#ifndef NOISEGATE_H

#include "Processor.h"

using namespace std;

class NoiseGate: public Processor{
	virtual void Processor(unsigned char* soundvalues, int numvalues) override{
	}
};

#endif
