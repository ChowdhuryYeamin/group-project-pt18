#ifndef ECHO_H
#define ECHO_H
#include <string>

#include "Processor.h"

using namespace std;
/**
 * @brief This is a echo class that inherits from the processor class.
 */
class Echo: public Processor{

/**	 
** @brief int attribute that stores delay for the echo.
*/	
    int echoDelay1;
    
public:
/**
 * @brief build a parameterized echo constructor and set atttribute. 
 */
   	Echo(int echoDelay1);

/**
 * @brief Build a echo destructor
 * 
 */	   
    ~Echo();

/**
 * @brief This is a override of the Processor 8 bit function that create echo according to the delay.
 * @param buffer Unsigned char buffer that contains 8 bit value from the wav file(buffer should already have values.)
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */    
	void Processor8_M_S(unsigned char* buffer, int bufferSize) override;
/**
 * @brief This is a override of the Processor 16 bit function that create echo according to the delay.
 * @param buffer Signed short buffer that contains 16 bit value from the wav file(buffer should already have values.)
 * @param bufferSize provides the size of the buffer to run any loops needed for this function.
 */
	void Processor16_M_S(signed short* buffer, int bufferSize) override;
};

#endif
