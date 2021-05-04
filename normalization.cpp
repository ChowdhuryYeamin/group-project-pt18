#include "normalization.h"

Normalization::Normalization(){};
Normalization::~Normalization(){}
    
void Normalization::Processor8_M_S(unsigned char* buffer, int bufferSize){
	unsigned char highestPeak;
	unsigned char lowestPeak;

	for (int x=0; x < bufferSize; x++){

		unsigned char H, L;

        	if (buffer[x] >= 128){
            	if (buffer[x] >= buffer[x + 1]){
					H = buffer[x];
					if(H >= highestPeak){
						highestPeak = H;
					}
				
			}
       	 		else{
          			H = buffer[x + 1];
						if(H >= highestPeak){
						highestPeak = H;
					}
					  
        		}
		}
        	else if (buffer[x] <= 127){
        		if (buffer[x] <= buffer[x + 1]){
					L = buffer[x];
					if(L <= lowestPeak){
						lowestPeak = L;
					}
				}

        		else{
          			L = buffer[x + 1];
					if(L <= lowestPeak){
						lowestPeak = L;
					}
					 
        		}
		}
	
    }
	double highRatio = 255/ highestPeak;
	double lowRatio = 1/lowestPeak;

	for (int x=0; x < bufferSize; x++) {
        	if(buffer[x] >= 128 ){
        		buffer[x] = buffer[x] * highRatio; 
        	}
        	else{
        	    buffer[x] = buffer[x] * lowRatio;
        	}
    	}
}

void Normalization::Processor16_M_S(signed short* buffer, int bufferSize){
	signed short highestPeak;
	signed short lowestPeak;

	for (int x=0; x < bufferSize; x++){

		signed short H, L;

        	if (buffer[x] >= 0){
            	if (buffer[x] >= buffer[x + 1]){
					H = buffer[x];
					if(H >= highestPeak){
						highestPeak = H;
					}
				
			}
       	 		else{
          			H = buffer[x + 1];
						if(H >= highestPeak){
						highestPeak = H;
					}
					  
        		}
		}
        	else if (buffer[x] <= -1){
        		if (buffer[x] <= buffer[x + 1]){
					L = buffer[x];
					if(L <= lowestPeak){
						lowestPeak = L;
					}
				}

        		else{
          			L = buffer[x + 1];
					if(L <= lowestPeak){
						lowestPeak = L;
					}
					 
        		}
		}
	
    }

	double highRatio = 32767.0000/ highestPeak;
	double lowRatio = -32767.0000/lowestPeak;

	for (int x=0; x < bufferSize; x++){
		if(buffer[x] >= 0 ){
       			buffer[x] = buffer[x] * highRatio; 
			    
       		}
        	else{
            		buffer[x] = buffer[x] * lowRatio;
					
        	}
    	}
}
