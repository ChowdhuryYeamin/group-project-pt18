#include "echo.h"

Echo::Echo(int echoDelay1): echoDelay1(echoDelay1){};

Echo::~Echo(){}


void Echo::Processor8_M_S(unsigned char *buffer, int bufferSize){	
	for (int x=0; x < bufferSize; x++) {
		int indexDelayed = x - echoDelay1;
      		if(indexDelayed > 0){
            		buffer[x] = (buffer[x] + buffer[x-echoDelay1]) * 0.5;
					cout << buffer[x] << endl;
       		}
			else{
				continue;
			}
	}	

}

void Echo::Processor16_M_S(signed short *buffer, int bufferSize){
	
	for (int x=0; x < bufferSize; x++) {
		int indexDelayed = x - echoDelay1;
      		if(indexDelayed > 0){
            		buffer[x] = (buffer[x] + buffer[x-echoDelay1]) * 0.5;
					cout << buffer[x] << endl;
       		}
			else{
				continue;
			}
		}
	

}




