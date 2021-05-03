#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"

using namespace std;

class Echo: public Processor{
    unsigned char echoDelay1;
    signed short echoDelay2;
public:
   	Echo(unsigned char echoDelay1);
    	~Echo();
    
	virtual void Processor8_M_S(unsigned char buffer[], int bufferSize) override;

	virtual void Processor16_M_S(signed short buffer[], int bufferSize) override;
};

#endif
