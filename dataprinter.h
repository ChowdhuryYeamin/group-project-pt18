#ifndef DATA_PRINTER
#define DATA_PRINTER_H

#include <fstream>
#include <vector>
#include <string>

#define LENGTH 500

#include "audiofile.h"

using namespace std;

class DataPrinter: public WaveHeader{
     public:
     void WriteFile(){
         int i;
         ofstream fout("Metadata.csv");
         fout << "Size: " << WaveHeader.size << endl;
         fout << "Format Size: " << WaveHeader.fmt_size << endl;
         fout << "Audio Format: " WaveHeader.audio_format << endl;
         fout << "No. of Channels: " << WaveHeader.channels << endl;
         fout << "Sample Rate: " << WaveHeader.sample_rate << endl;
         fout << "Byte Rate: " << WaveHeader.byte_rate << endl;
         fout << "Block Align: " << WaveHeader.block_align << endl;
         fout << "Bits: " << WaveHeader.bits << endl;
         fout << "Data Bytes: " << WaveHeader.data_bytes << endl;
         for(i = 0; i < LENGTH; i++){
             fout << data[i] << endl;
         }
         fout.close()
     }
};

#endif

