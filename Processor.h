#define PROCESSOR_H
#ifndef PROCESSOR_H

using namespace std;

class Processor{
	virtual void Processor(unsigned char* soundvalues, int numvalues) = 0;
};

#endif
