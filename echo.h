#define ECHO_H
#ifndef ECHO_H

using namespace std;

class Echo{
    unsigned char echoDelay1;
    signed short echoDelay2;

public:

    Echo(unsigned char echoDelay1): echoDelay1(echoDelay1){};
    ~Echo(){}
    
void Processor8(unsigned char buffer[], int bufferSize,bool){
    
	for (int x=0; x < bufferSize; x++) {
		int indexDelayed = x - echoDelay1;
        if(indexDelayed > 0){
            buffer[x] = (buffer[x] + buffer[x-echoDelay1]) * 0.5;
       }

    }

}

void Processor16(singed short buffer[], int bufferSize, bool){
    
	for (int x=0; x < bufferSize; x++) {
		int indexDelayed = x - echoDelay1;
        if(indexDelayed > 0){
            buffer[x] = (buffer[x] + buffer[x-echoDelay1]) * 0.5;
        }
    }
}




};

#endif
