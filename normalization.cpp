#include "normalization.h"

Normalization::Normalization(){};
Normalization::~Normalization(){}
    
void Normalization::Processor8_M_S(unsigned char buffer[], int bufferSize){
	double highestPeak;
	double lowestPeak;

	for (int x=0; x < bufferSize; x++) {
		if (buffer[x] >= 128){
			if (buffer[x] >= buffer[x + 1]){
				highestPeak = buffer[x];
			}
			else{
				highestPeak = buffer[x + 1];
			}
		}
		if (buffer[x] <= buffer[x + 1]) {
			lowestPeak = buffer[x];
		}
		else{
			lowestPeak = buffer[x + 1];
		}
	}
	double highRatio = 255/ highestPeak;
	double lowRatio = 1/lowestPeak;

	for (int x=0; x < bufferSize; x++) {
        	if(buffer[x] >= 128 ){
        		buffer[x] = buffer[x] * highestPeak; 
        	}
        	else{
        	    buffer[x] = buffer[x] * lowestPeak;
        	}
    	}
}

void Normalization::Processor16_M_S(signed short buffer[], int bufferSize){
	
	short highestPeak;
	short lowestPeak;

	for (int x=0; x < bufferSize; x++){
        	if (buffer[x] >= 0){
            		if (buffer[x] >= buffer[x + 1]){
				highestPeak = buffer[x];
			}
       	 		else{
          			highestPeak = buffer[x + 1];
        		}
		}
        	else{
        		if (buffer[x] <= buffer[x + 1]){
				lowestPeak = buffer[x];
			}
        		else{
          			lowestPeak = buffer[x + 1];
        		}
		}
        }
	double highRatio = 32767.0000/ highestPeak;
	double lowRatio = -32767.0000/lowestPeak;

	for (int x=0; x < bufferSize; x++){
		if(buffer[x] >= 0 ){
       			buffer[x] = buffer[x] * highestPeak; 
       		}
        	else{
            		buffer[x] = buffer[x] * lowestPeak;
        	}
    	}
}

