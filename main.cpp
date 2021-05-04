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
/**
  * @brief Is called in the main function to display the user interface.
  */
}

void alternateMenu(){
           std::cout << "*****Select an operation*****" << endl;
           std::cout << "1. Echo" << endl;
           std::cout << "2. Noisegate" << endl;
           std::cout << "3. Limiter" << endl;
           std::cout << "4. Normalizer" << endl;
           std::cout << "5. Edit File Metadata" << endl;
/**
  * @brief Is called in the main function to display the user interface.
  */
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

/**
  * @brief Is called in the main function to display the user interface.
  */

int buffLength(unsigned char * b){
     int index = 0;
     do{
         index++;
         }while(b[index] == '\0');
     return(index);
/**
  * @brief Finds the length of the buffer so that it may be passed into
the Processor functions.
  */
}

int sbuffLength(short * bu){
     int index = 0;
     do{
         index++;
         }while(bu[index] == '\0');
     return(index);
/**
  * @brief Finds the length of the buffer so that it may be passed into
the Processor functions.
  */
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
/**
  * @brief User input is taken here.
  */
          if(userinput == 1){
              //std::cin >> filename;
              alternateMenu();
              cin >> userinput;
          /**
  * @brief Upon receiving the users selection for the alternateMenu(),
an if-else statement than performs the operation selected, be it Echo,
Noisegate, Normalizer or Limiter. A new object is than created using the
constructors in each function, the buffer length is taken and then the
pointer is set to the results given by the processor.
  */
              if(userinput == 1 && wh.bits == 8){
                 Processor *processor1 = new Echo(44100);
         unsigned char * b = wav.get8BitBuffer(s);
         index = buffLength(b);
                 processor1->Processor8_M_S(b, index);
         delete processor1;
              }
              else if(userinput == 1 && wh.bits == 16){
                  Processor *processor1 = new Echo(44100);
          short * bu = wav.get16BitBuffer(s);
          index = sbuffLength(bu);
                  processor1->Processor16_M_S(bu, index);
          delete processor1;
              }
              else if(userinput == 2 && wh.bits == 8){
                  Processor *processor2 = new NoiseGate(0.01);
          unsigned char * b = wav.get8BitBuffer(s);
          index = buffLength(b);
                  processor2->Processor8_M_S(b, index);
          delete processor2;
              }
              else if(userinput == 2 && wh.bits == 16){
                  Processor *processor2 = new NoiseGate(0.01);
          short * bu = wav.get16BitBuffer(s);
          index = sbuffLength(bu);
                  processor2->Processor16_M_S(bu, index);
          delete processor2;
              }
              else if(userinput == 3 && wh.bits == 8){
                  Processor *processor3 = new Limiter();
          unsigned char * b = wav.get8BitBuffer(s);
          index = buffLength(b);
                  processor3->Processor8_M_S(b, index);
          delete processor3;
              }
              else if(userinput == 3 && wh.bits == 16){
                  Processor *processor3 = new Limiter();
          short * bu = wav.get16BitBuffer(s);
          index = sbuffLength(bu);
                  processor3->Processor16_M_S(bu, index);
          delete processor3;
              }
              else if(userinput == 4 && wh.bits == 8){
                  Processor *processor4 = new Normalization();
          unsigned char * b = wav.get8BitBuffer(s);
          index = buffLength(b);
                  processor4->Processor8_M_S(b, index);
          delete processor4;
              }
              else if(userinput == 4 && wh.bits == 16){
                  Processor *processor4 = new Normalization();
          short * bu = wav.get16BitBuffer(s);
          index = sbuffLength(bu);
                  processor4->Processor16_M_S(bu, index);
          delete processor4;
              }
              else if(userinput == 5){
/**
  * @brief Upon receiving the users selection for the alternateMenu(),
an if-else statement than performs the operation selected, a new menu is
shown showing the metadata the user can change. The user than selects
the appropriate four letter combination,
  */
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
          /**
  * @brief This four letter combination and the input it is associated
with is than appended to the file.
  */
                  Metadata->header.metadata_chunk_type[0] = key[0];
                  Metadata->header.metadata_chunk_type[1] = key[1];
                  Metadata->header.metadata_chunk_type[2] = key[2];
                  Metadata->header.metadata_chunk_type[3] = key[3];
                  Metadata->data = md;
                  Metadata->header.metadata_chunk_size = 2;
                  (*x)->getMetadataList()[y] = (*x)->getMetadataList()[y-1];
                  (*x)->getMetadataList()[y-1] = *Metadata;
                  wav.updateMetadata((*x), (*x)->getMetadataList(), y+1);
              }
              else{
                  continue;
              }
          unsigned char * b = wav.get8BitBuffer(s);
              wav.newFile8Bit((*x), s2, b);
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
      return 0;
}
