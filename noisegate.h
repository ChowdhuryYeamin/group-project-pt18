#define NOISEGATE_H
#ifndef NOISEGATE_H

#include "Processor.h"

using namespace std;

class NoiseGate : public Processor{
	float percent;
	// add attribute that stores the percentage of audio needs to be noisegated.

public:

NoiseGate(float percent);
// Build a contructor for the class NoiseGate

~NoiseGate();
// Build a NoiseGate destructor

    void Processor8_M_S(unsigned char buffer[], int bufferSize);

    void Processor16_M_S(singed short buffer[], int bufferSize);


};

#endif
