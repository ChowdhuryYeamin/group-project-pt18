#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include <string>
#include "Processor.h"

using namespace std;

/**
 * @brief This is a normalization class that inherits from the processor class.
 */
class Normalization : public Processor{

    public:
/**
 * @brief build a new Normalization constructor. 
 */
    Normalization();

/**
 * @brief Destroy the Normalization constructor. 
 */
    ~Normalization();


/**
 * @brief This is a override of the Processor 8 bit function that can find the highest and lowest of the buffer.
 * Divide highest value of the buffer with the highest range to find high ratio.
 * Divide lowest value of the buffer with the lowest range to find low ratio.
 * Multiply all the sample volumes over 128 with the high ratio(255).
 * Multiply all the sample volumes below 128 with the low ratio(1).
 * Through these calculations, the function normalizes the audio.
 * @param buffer Unsigned char buffer that contains 8 bit value from the wav file(buffer should already have values.)
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */
    void Processor8_M_S(unsigned char* buffer, int bufferSize) override;

/**
 * @brief This is a override of the Processor 16 bit function that can find the highest and lowest of the buffer.
 * Divide highest value of the buffer with the highest range to find high ratio(32767).
 * Divide lowest value of the buffer with the lowest range to find low ratio(-32767).
 * Multiply all the sample volumes over 0 with the high ratio.
 * Multiply all the sample volumes below 0 with the low ratio.
 * Through these calculations, the function normalizes the audio.
 * @param buffer Signed short buffer that contains 16 bit value from the wav file(buffer should already have values.)
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */
    void Processor16_M_S(signed short* buffer, int bufferSize) override;


    
};

#endif
