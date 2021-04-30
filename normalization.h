#define NORMALIZATION_H
#ifndef NORMALIZATION_H

#include "Processor.h"

using namepace std;

class Normalization : public Processor{
    private:

    public:

    Normalization();
    ~Normalization();
    
    void Processor8_M_S(unsigned char buffer[], int bufferSize);

    void Processor16_M_S(singed short buffer[], int bufferSize);


    
};




#endif