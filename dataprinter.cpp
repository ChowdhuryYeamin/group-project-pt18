
#include "dataprinter.h"

using namespace std;

DataPrinter::DataPrinter() {};

DataPrinter::~DataPrinter() {}

void DataPrinter::WriteFile(vector<Audio*> list){
     int index;
     wav_header wavh;
     metadata md;
         ofstream fout("Metadata.csv");
     for(index = 0; index < list.size(); index++){
         fout << "File No. " << index << endl;
             fout << "Size: " << wavh.size << endl;
             fout << "Format Size: " << wavh.fmt_size << endl;
             fout << "Audio Format: " << wavh.audio_format << endl;
             fout << "No. of Channels: " << wavh.channels << endl;
             fout << "Sample Rate: " << wavh.sample_rate << endl;
             fout << "Byte Rate: " << wavh.byte_rate << endl;
             fout << "Block Align: " << wavh.block_align << endl;
             fout << "Bits: " << wavh.bits << endl;
             fout << "Data Bytes: " << wavh.data_bytes << endl;
                 fout << md.data[index] << endl;
         }
         fout.close();
}
