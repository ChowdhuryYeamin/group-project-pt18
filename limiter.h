#define LIMITER_H
#ifndef LIMITER_H

#include "Processor.h"

using namespace std;

class Limiter: public Processor{
	virtual void Processor(unsigned char* soundvalues, int numvalues) override{
		int i;
		for(i = 0; i < numvalues; i++){
			if(soundvalues[i] > 204){
				soundvalues[i] = 204;
			}
			else{
				continue;
			}
	}
}
	}
}

#endif

