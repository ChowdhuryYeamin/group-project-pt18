#include "noisegate.h"

NoiseGate::NoiseGate(float percent) : percent(percent) {};
// Build a contructor for the class NoiseGate

NoiseGate::~NoiseGate() {}
// Build a NoiseGate destructor

void NoiseGate::Processor8_M_S(unsigned char buffer[], int bufferSize){
	/** 
	 * Build a function that noisegates 8 bit mono and stereo
	 * @param unsigned char buffer[], int bufferSize
	 */

    float noise =  percent * 128;
    float x = 128 + noise;
	float y = 128 - noise;

	for (int x=0; x < bufferSize; x++) {
		if (buffer[x] >= 128 && buffer[x] <= x) {
			buffer[x] = 128;
		}
        if (buffer[x] <= 128 && buffer[x] >= y) {
			buffer[x] = 128;
		}

}

void NoiseGate::Processor16_M_S(singed short buffer[], int bufferSize){
	/** 
	 * Build a function that noisegates 16 bit mono and stereo
	 * @param unsigned char buffer[], int bufferSize
	 */	
    double noise =  percent * 32767;
    double x = 0 + noise;
	double y = 0 - noise;

	for (int x=0; x < bufferSize; x++) {
		if (buffer[x] >= 0 && buffer[x] <= x) {
			buffer[x] = 0;
		}
        if (buffer[x] <= 0 && buffer[x] >= y) {
			buffer[x] = 0;
		}

}