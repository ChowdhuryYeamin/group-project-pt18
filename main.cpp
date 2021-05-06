#include <iostream>

#include <string>

#include <vector>

#include "audiofile.h"

#include "echo.h"

#include "noisegate.h"

#include "limiter.h"

#include "normalization.h"

#include "dataprinter.h"

/** @file
Author 1: Yeamin Chowdhury
*Creates all the processor classes and doxygen documentation.
*Processor (abstract)
*Noise Gate
*Echo
*Normalization
*Author 2: Sean Rolandelli
*Created structures in wavheader.h
*Created the wave file
*Reading and writing of all technical data, buffer, and metadata
*Doxygen Generation
*Author 3: Ryan Krysinski
*Created the main.cpp and data printer class which prints csv.
*Integration of all of the code in main.
*Doxygen Commenting.
*
*Issues faced
*Everyone worked on the main.cpp file.
*The biggest issue was we could not figure out how to write the metadata out.
*As we were not fimiliar with audio processing, understanding how the wave file works was sort of hard.
*/

using namespace std;

const std::string testfile = "./waves/waves";

void print(char * word, int size) {
        for (int x = 0; x < size; x++) {
                std::cout << word[x];
        }
}

void Menu() {
        std::cout << "*****MENU*****" << endl;
        std::cout << "1. Process Files" << endl;
        std::cout << "2. Create CSV File with Specs" << endl;
        /**
         * @brief Is called in the main function to display the user interface.
         */
}

void alternateMenu() {
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

void metaDataMenu() {
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

int xbuffLength(unsigned char * b) {
        int index = 0;
        do {
                index++;
        } while (b[index] == '\0');
        return (index);
        /**
           * @brief Finds the length of the buffer so that it may be passed into
        the Processor functions.
           */
}

int xsbuffLength(short * bu) {
        int index = 0;
        do {
                index++;
        } while (bu[index] == '\0');
        return (index);
        /**
           * @brief Finds the length of the buffer so that it may be passed into
        the Processor functions.
           */
}

int main() {
        unsigned char echoDelay1;
        int userinput, i = 0, index = 0, loop = 0;
        char key[4];
        std::string filename;
        Wav wav;
        wav_header * wh;
        Audio * a;
        std::vector < Audio * > list;
        wav.readAllFiles(testfile);
        list = wav.getVectorList();

        Menu();
        std::cout<<"Enter menu number: ";
        std::cin >> userinput;

        /**
         * @brief User input is taken here.
         */
        if (userinput == 1) {
                int xx = 1;
                int fileinput;
                for (auto x = begin(list); x != end(list); x++) {
                        std::cout << xx++ << " " << ( * x) -> getFilename() << std::endl;
                }
                //      		int y = (*x)->getCount();
                //      		const std::string s = (*x)->getFilename();

                std::cout << "Please select the number of the file you'd like to process: ";
                std::cin >> fileinput;
                int yy = 1;
                for (auto x = begin(list); x != end(list); x++) {
                        a = ( * x);
                        if (fileinput == yy) {
                                break;
                        }
                        yy++;
                }

                alternateMenu();
                std::cout<<"Enter the number of the operation you want to preform: ";
                cin >> userinput;

                /**
  * @brief Upon receiving the users selection for the alternateMenu(),
an if-else statement than performs the operation selected, be it Echo,
Noisegate, Normalizer or Limiter. A new object is than created using the
constructors in each function, the buffer length is taken and then the
pointer is set to the results given by the processor.
  */

                if (userinput == 5) {
			std::string str;
                        /**
                          * @brief Upon receiving the users selection for the alternateMenu(),
                        an if-else statement than performs the operation selected, a new menu is
                        shown showing the metadata the user can change. The user than selects
                        the appropriate four letter combination,
                          */
                        metaDataMenu();
                        std::cout<<"Enter the 4 character code that you want to modify: ";
                        std::cin >> key;
                        std::cout << "Input for the value for ";
                        print(key,4);
                        std::cout << ": ";
                        std::cin >> str;
                        std::cout << endl;

			i = str.length();

                        char * md = new char[i];
			for (int ww = 0; ww < i; ww++) {
				md[ww] = str[ww];
			}			
                        metadata * Metadata = new metadata;
                        /**
  * @brief This four letter combination and the input it is associated
with is then appended to the file.
  */

                        Metadata -> header.metadata_chunk_type[0] = key[0];
                        Metadata -> header.metadata_chunk_type[1] = key[1];
                        Metadata -> header.metadata_chunk_type[2] = key[2];
                        Metadata -> header.metadata_chunk_type[3] = key[3];

                        Metadata -> data = md;
                        Metadata -> header.metadata_chunk_size = i;
                        
                        int y = a->getCount();

                        a -> getMetadataList()[y] = a -> getMetadataList()[y - 1];
                        a -> getMetadataList()[y - 1] = * Metadata;

                        wav.updateMetadata(a, a -> getMetadataList(), y + 1);
                } else {
                        std::string newFileName;
                        std::cout << "New Output File Name: ";
                        std::cin >> newFileName;
                        wh = a -> getWavHeader();
                        index = wh -> data_bytes;
                        std::string filepath = a -> getFilename();
                        if (userinput == 1 && wh->bits == 8) {
                                Processor * processor1 = new Echo(44100);
                                unsigned char * b = wav.get8BitBuffer(filepath);
                                //index = buffLength(b);
                                processor1 -> Processor8_M_S(b, index);
                                wav.newFile8Bit(a, newFileName, b);
                                delete processor1;
                        } else if (userinput == 1 && wh->bits == 16) {
                                Processor * processor1 = new Echo(44100);
                                short * b = wav.get16BitBuffer(filepath);
                                //index = sbuffLength(bu);
                                processor1 -> Processor16_M_S(b, index);
                                wav.newFile16Bit(a, newFileName, b);
                                delete processor1;
                        } else if (userinput == 2 && wh->bits == 8) {
                                Processor * processor2 = new NoiseGate(0.01);
                                unsigned char * b = wav.get8BitBuffer(filepath);
                                //index = buffLength(b);
                                processor2 -> Processor8_M_S(b, index);
                                wav.newFile8Bit(a, newFileName, b);
                                delete processor2;
                        } else if (userinput == 2 && wh->bits == 16) {
                                Processor * processor2 = new NoiseGate(0.01);
                                short * b = wav.get16BitBuffer(filepath);
                                // index = sbuffLength(bu);
                                processor2 -> Processor16_M_S(b, index);
                                wav.newFile16Bit(a, newFileName, b);
                                delete processor2;
                        } else if (userinput == 3 && wh->bits == 8) {
                                Processor * processor3 = new Limiter();
                                unsigned char * b = wav.get8BitBuffer(filepath);
                                //index = buffLength(b);
                                processor3 -> Processor8_M_S(b, index);
                                wav.newFile8Bit(a, newFileName, b);
                                delete processor3;
                        } else if (userinput == 3 && wh->bits == 16) {
                                Processor * processor3 = new Limiter();
                                short * b = wav.get16BitBuffer(filepath);
                                // index = sbuffLength(bu);
                                processor3 -> Processor16_M_S(b, index);
                                wav.newFile16Bit(a, newFileName, b);
                                delete processor3;
                        } else if (userinput == 4 && wh->bits == 8) {
                                Processor * processor4 = new Normalization();
                                unsigned char * b = wav.get8BitBuffer(filepath);
                                //index = buffLength(b);
                                processor4 -> Processor8_M_S(b, index);
                                wav.newFile8Bit(a, newFileName, b);
                                delete processor4;
                        } else if (userinput == 4 && wh->bits == 16) {
                                Processor * processor4 = new Normalization();
                                short * b = wav.get16BitBuffer(filepath);
                                //index = sbuffLength(bu);
                                processor4 -> Processor16_M_S(b, index);
                                wav.newFile16Bit(a, newFileName, b);
                                delete processor4;
                        }
                        //need to ask user for file name and call new8bit....
                }\
        } else if (userinput == 2) {
                //DataPrinter dp;
                //dp.WriteFile(list);
        }

return 0;
}
