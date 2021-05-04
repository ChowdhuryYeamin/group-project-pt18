#include "limiter.h"

Limiter::Limiter() {};
	

Limiter::~Limiter() {}

void Limiter::Processor8_M_S(unsigned char* buffer, int bufferSize){
	
    double max= 0.9 * 255;
    double min= 0.1 * 255;

	for (int x=0; x < bufferSize; x++) {
		if (buffer[x] > max) {
			buffer[x]=max;
		}
        if (buffer[x] < min) {
			buffer[x]=min;
		}

	}
}

void Limiter::Processor16_M_S(signed short* buffer, int bufferSize){
		
    short max=0.9 * 32767;
    short min=0.9 * -32767;
	
    for (int x=0; x < bufferSize; x++) {
		if (buffer[x] >= max) {
			buffer[x]=max;
		}
        if (buffer[x] <= min) {
			buffer[x] = min;
		}
	}
}

    