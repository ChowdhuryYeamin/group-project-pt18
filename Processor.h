#ifndef PROCESSOR_H
#define PROCESSOR_H

using namespace std;

class Processor{
	virtual void Processor8_M_S(unsigned char buffer[], int bufferSize) = 0;

    	virtual void Processor16_M_S(signed short buffer[], int bufferSize) = 0;

};

#endif
