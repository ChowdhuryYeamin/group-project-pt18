#ifndef NOISEGATE_H
#define NOISEGATE_H
#include <string>

#include "Processor.h"

using namespace std;

/**
 * @brief This is a noisegate class that inherits from the processor class.
 */
class NoiseGate : public Processor{

/**	 
** @brief float attribute that stores the percentage of audio needs to be noisegated.
*/
	float percent;
	
	public:

/**
 * @brief build a parameterized noisegate constructor and set the percent atttribute. 
 */
	NoiseGate(float percent);
	
/**
 * @brief Build a NoiseGate destructor
 * 
 */
	~NoiseGate();

/**
 * @brief This is a override of the Processor 8 bit function that can reduce noises acording to the given percent.
 * Reduces the noises over and below 128 values to 128.
 * @param buffer Unsigned char buffer that contains 8 bit value from the wav file(buffer should already have values.)
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */
    void Processor8_M_S(unsigned char* buffer, int bufferSize) override;

/**
 * @brief This is a override of the Processor 16 bit function that can reduce noises acording to the given percent.
 * Reduces the noises over and below 0 values to 0.
 * @param buffer Signed short buffer that contains 16 bit value from the wav file(buffer should already have values.)
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */
    void Processor16_M_S(signed short* buffer, int bufferSize) override;


};

#endif
