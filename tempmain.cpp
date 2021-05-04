#include <iostream>
#include <string>
#include <vector>
#include "audiofile.h"
#include "echo.h"
#include "noisegate.h"
#include "limiter.h"
#include "normalization.h"
#include "dataprinter.h"

using namespace std;

const std::string testfile = "./waves/waves";

void print(char* word, int size) {
     for(int x = 0; x < size; x++) {
         std::cout << word[x];
     }
     std::cout << std::endl;
}

void Menu(){
         std::cout << "*****MENU*****" << endl;
          std::cout << "1. Process Files" << endl;
          std::cout << "2. Create CSV File with Specs" << endl;
}

void alternateMenu(){
          std::cout << "*****Select an operation*****" << endl;
          std::cout << "1. Echo" << endl;
          std::cout << "2. Noisegate" << endl;
          std::cout << "3. Limiter" << endl;
          std::cout << "4. Normalizer" << endl;
          std::cout << "5. Edit File Metadata" << endl;
}

void metaDataMenu(){
     std::cout << "*****Select a Value to Change*****" << endl;
     std::cout << "Archival Location - IARL" << endl;
     std::cout << "Artist - IART" << endl;
     std::cout << "Commissioned - ICMS" << endl;
     std::cout << "Comments - ICMT" << endl;
     std::cout << "Copyright - ICOP" << endl;
     std::cout << "Creation Date - ICRD" << endl;
     std::cout << "Engineer - IENG" << endl;
     std::cout << "Genre - IGNR" << endl;
     std::cout << "Keywords - IKEY" << endl;
     std::cout << "Medium - IMED" << endl;
     std::cout << "Name - INAM" << endl;
     std::cout << "Product - IPRD" << endl;
     std::cout << "Subject - ISBJ" << endl;
     std::cout << "Software - ISFT" << endl;
     std::cout << "Source - ISRC" << endl;
     std::cout << "Source Form - ISRF" << endl;
     std::cout << "Technician - ITCH" << endl;
}

int main() {
     unsigned char echoDelay1;
     int userinput, i = 0, index = 0, loop = 0;
     char key[4], *string;
     std::string filename;
     Wav wav;
     wav_header wh;
     std::vector<Audio *> list;
     wav.readAllFiles(testfile);
     list = wav.getVectorList();
     for (auto x=begin (list); x != end(list); x++) {
         std::cout<< (*x)->getFilename() << std::endl;
         int y = (*x)->getCount();
         const std::string s = (*x)->getFilename();
         Menu();
         std::cin >> userinput;
         if(userinput == 1){
             std::cout << "Please enter the name of the file you'd like
to process" << endl;
             std::cin >> filename;
             alternateMenu();
             cin >> userinput;
             std::string s2 = s+"testingbuffer";
             unsigned char * b = wav.get8BitBuffer(s);
             do{
                 index++;
             }while(b[index] == '\0');
             if(userinput == 1 || wh.bits == 8){
                 Echo echo;
                 echo.Processor8_M_S(&b, &index);
             }
             else if(userinput == 1 || wh.bits == 16){
                 NoiseGate ng;
                 ng.Processor16_M_S(&b, &index);
             }
             else if(userinput == 2 || wh.bits == 8){
                 NoiseGate ng;
                 ng.Processor8_M_S(&b, &index);
             }
             else if(userinput == 2 || wh.bits == 16){
                 NoiseGate ng;
                 ng.Processor16_M_S(&b, &index);
             }
             else if(userinput == 3 || wh.bits == 8){
                 Limiter lm;
                 lm.Processor8_M_S(&b, &index);
             }
             else if(userinput == 3 || wh.bits == 16){
                 Limiter lm;
                 lm.Processor16_M_S(&b, &index);
             }
             else if(userinput == 4 || wh.bits == 8){
                 Normalization nm;
                 nm.Processor8_M_S(&b, &index);
             }
             else if(userinput == 4 || wh.bits == 16){
                 Normalization nm;
                 nm.Processor16_M_S(&b, &index);
             }
             else if(userinput == 5){
                 metaDataMenu();
                 std::cin >> key;
                 std::cout << "Input for this value: ";
                 std::cin >> string;
                 std::cout << endl;
                 do{
                     i++;
                 }while(string[i]!='\0');
                 char *md = new char[i];
                 //char *sr = new char[2];
                 //sr[0] = 'S';
                 //sr[1] = 'R';
                 metadata *Metadata = new metadata;

                 Metadata->header.metadata_chunk_type[0] = key[0];
                 Metadata->header.metadata_chunk_type[1] = key[1];
                 Metadata->header.metadata_chunk_type[2] = key[2];
                 Metadata->header.metadata_chunk_type[3] = key[3];

                 Metadata->data = md;
                 Metadata->header.metadata_chunk_size = 2;
         // Need to move id3 entry to always be at end of metadata
list.  New entries need to be added prior to id3 entry
                 (*x)->getMetadataList()[y] = (*x)->getMetadataList()[y-1];
                 (*x)->getMetadataList()[y-1] = *Metadata;

                 wav.updateMetadata((*x), (*x)->getMetadataList(), y+1);
             }
             else{
                 continue;
             }

             wav.newFile8Bit((*x), s2, b); // this is how to call if the
proccessors do work

(*x)->getMetadataList()[0].header.metadata_chunk_size =
(*x)->getMetadataList()[0].header.metadata_chunk_size - 6;
         }
         else if(userinput==2){
             DataPrinter dp;
             dp.WriteFile(list);
         }
         else{
             continue;
         }
     }
}
