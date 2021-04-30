#ifndef PROCESSOR_H
#define PROCESSOR_H

using namespace std;

class Processor{
<<<<<<< HEAD
	virtual void Processor8_M_S(unsigned char buffer[], int bufferSize) = 0;

    void Processor16_M_S(singed short buffer[], int bufferSize) = 0;
=======
	void Processor8(unsigned char* soundvalues, int numvalues) = 0;
	void Processor16(unsigned char* soundvalues, int numvalues) = 0;
>>>>>>> 2ee6b43f694dc56e8f924a4507561589c3bbe096
};

#endif
