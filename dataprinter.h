#ifndef DATA_PRINTER_H
#define DATA_PRINTER_H

#include <fstream>
#include <vector>
#include <string>

#define LENGTH 500

#include "Wav.h"

using namespace std;

class DataPrinter: public Wav{
     public:
     void WriteFile();
};

#endif

