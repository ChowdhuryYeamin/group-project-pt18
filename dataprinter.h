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
	DataPrinter(char size[4], int fmt_size, short audio_format, short channels, int sample_rate, int byte_rate, short block_align, short bits, int data_bytes);
	~DataPrinter();

     	void WriteFile();
};

#endif

