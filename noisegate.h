#define NOISEGATE_H
#ifndef NOISEGATE_H

#include "Processor.h"

using namespace std;

class NoiseGate: public Processor{
	virtual void Processor(unsigned char* soundvalues, int numvalues) override{
		int index = 0;
		for(index; index < bufferSize; index++){
			if(soundvalues[index] < 128){
				soundvalues[index] = 128;
			}
			else{
				continue;
			}
	}
};

#endif
