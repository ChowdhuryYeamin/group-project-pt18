#define ECHO_H
#ifndef ECHO_H

#include "Processor.h"

using namespace std;

class Echo: public Processor{
	virtual void Processor(unsigned char* soundvalues, int numvalues) override{
		int index, val;
		for(i = 0; i < numvalues; index++){
			val = soundvalues[i] + soundvalues[index-period];
			if(newval < soundvalues[index-period]){
				soundvalues[i] = newval;
			}
			else if(val > 255){
				soundvalues[i] = 255;
			}
			else{
				continue;
			}
		}
	}
};

#endif
