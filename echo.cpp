#include "echo.h"

Echo::Echo(unsigned char echoDelay1): echoDelay1(echoDelay1){}

Echo::~Echo(){}

void Echo::Processor8_M_S(unsigned char buffer[], int bufferSize){
	for (int x=0; x < bufferSize; x++) {
		int indexDelayed = x - echoDelay1;
      		if(indexDelayed > 256){
            		buffer[x] = (buffer[x] + buffer[x-echoDelay1]) * 0.5;
       		}
		else if(indexDelayed < 256 || indexDelayed > 128){
			buffer[x] = (buffer[x] + buffer[x-echoDelay1]);
		}
		else{
			continue;
		}
	}
}

void Echo::Processor16_M_S(signed short buffer[], int bufferSize){
	for (int x=0; x < bufferSize; x++) {
		int indexDelayed = x - echoDelay1;
      		if(indexDelayed > 256){
            		buffer[x] = (buffer[x] + buffer[x-echoDelay1]) * 0.5;
       		}
		else if(indexDelayed < 256 || indexDelayed > 128){
			buffer[x] = (buffer[x] + buffer[x-echoDelay1]);
		}
		else{
			continue;
		}
	}
}


