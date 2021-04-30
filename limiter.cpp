#include "limiter.h"

Limiter::Limiter() {};
	// Build a contructor for the class Limiter

Limiter::~Limiter() {}

void Limiter::Processor8_M_S(unsigned char buffer[], int bufferSize){
	/** 
	 * Build a function that limits 8 bit mono and stereo
	 * @param unsigned char buffer[], int bufferSize
	 */
    int max= 0.9 * 255;
    int min= 0.1 * 255;

	for (int x=0; x < bufferSize; x++) {
		if (buffer[x] > max) {
			buffer[x]=max;
		}
        if (buffer[x] < min) {
			buffer[x]=min;
		}

}

void Limiter::Processor16_M_S(singed short buffer[], int bufferSize){
	/** 
	 * Build a function that limits 16 bit mono and stereo
	 * @param unsigned char buffer[], int bufferSize
	 */	
    int max=0.9 * 32767;
    int min=0.9 * -32767;
	
    for (int x=0; x < bufferSize; x++) {
		if (buffer[x] >= max) {
			buffer[x]=max;
		}
        if (buffer[x] <= min) {
			buffer[x] = min;
		}
}

    