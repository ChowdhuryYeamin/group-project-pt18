#include "noisegate.h"

NoiseGate::NoiseGate(float percent) : percent(percent) {};
// Build a contructor for the class NoiseGate

NoiseGate::~NoiseGate() {}
// Build a NoiseGate destructor

void NoiseGate::Processor8_M_S(unsigned char* buffer, int bufferSize){
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
       		else if (buffer[x] <= 127 && buffer[x] >= y) {
			buffer[x] = 128;
		}
		else{
			continue;
		}
	}
}


void NoiseGate::Processor16_M_S(signed short* buffer, int bufferSize){
	double noise =  0.1 * 32767;
	signed short y = -noise;


	for (int x=0; x < bufferSize; x++) {
		if (buffer[x] >= 0) {
			if(buffer[x] <= noise){
				buffer[x] = 0;
			}
		}
       	else if (buffer[x] <= -1) {
			if(buffer[x] >= y){
			buffer[x] = 0;
			}
		}
		else{
			continue;
		}
		
	}
}

