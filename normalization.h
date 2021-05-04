#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include "Processor.h"

using namespace std;

class Normalization : public Processor{

    public:

    Normalization();
    ~Normalization();
    
    void Processor8_M_S(unsigned char* buffer, int bufferSize) override;

    void Processor16_M_S(signed short* buffer, int bufferSize) override;


    
};

#endif
