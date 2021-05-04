#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <iostream>
#include <algorithm>

/**
 * @brief Build an inerface processor class, which only contains 2 pure virtual functions.
 * One function processes 8 bit unsigned char buffer .
 * The other function processes 16 signed short bit buffers.
 * They can process both mono and stereo.
 * They will be implemented in limiter, noisegate, normalization, and echo classes. 
 */
class Processor{
/**
 * @brief It is a pure virtual function the preocesses 8 bit buffer. 
 * @param buffer Unsigned char buffer that contains 8 bit value from the wav file(buffer should already have values.)
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */
	virtual void Processor8_M_S(unsigned char* buffer, int bufferSize) = 0;

/**
 * @brief It is a pure virtual function the preocesses 16 bit buffer. 
 * @param buffer Signed short buffer that contains 16 bit value from the wav file(buffer should already have values.)
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */
    virtual void Processor16_M_S(signed short* buffer, int bufferSize) = 0;

};

#endif
