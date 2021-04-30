#ifndef PROCESSOR_H
#define PROCESSOR_H

using namespace std;

class Processor{
	void Processor8(unsigned char* soundvalues, int numvalues) = 0;
	void Processor16(unsigned char* soundvalues, int numvalues) = 0;
};

#endif
