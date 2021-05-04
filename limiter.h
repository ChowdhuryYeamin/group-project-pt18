#ifndef LIMITER_H
#define LIMITER_H
#include <string>
#include "Processor.h"

using namespace std;
/**
 * @brief 
 * This is a limiter class that inherits from the processor class.
 */
class Limiter: public Processor{

	public:
/**
 * @brief Build a limiter constructor. 
 */
	Limiter();

/**
 * @brief Destroy the Limiter object
 */
   	~Limiter();
	

/**
 * @brief This is a override of the Processor 8 bit function that can limit the audio of both mono and stereo.
 * It reduces any sounds over and below of a certain range and set them equal to the range.
 * @param buffer This unsigned char buffer has already been read in wav files.
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */
   	void Processor8_M_S(unsigned char* buffer, int bufferSize) override;

/**
 * @brief This is a override of the Processor 16 bit function that can limit the audio of both mono and stereo.
 * It reduces any sounds over and below of a certain range and set them equal to the range.
 * 
 * @param buffer This signed short buffer has already been read in wav files(reads 16 bits).
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */
    void Processor16_M_S(signed short* buffer, int bufferSize) override;	
};

#endif

