#include <iostream>
#include <string>
#include <vector>
#include "Wav.h"
#include "audiofile.h"

using namespace std;

const std::string testfile = "./waves/waves";

void print(char* word, int size) {
	for(int x = 0; x < size; x++) {
		std::cout << word[x];
	}
	std::cout << std::endl;
}

void Menu(){
     cout << "*****MENU*****" << endl;
     cout << "1. Process Files" << endl;
     cout << "2. Create CSV File with Specs" << endl;
}

void alternateMenu(){
     cout << "*****Select an operation*****" << endl;
     cout << "1. Echo" << endl;
     cout << "2. Noisegate" << endl;
     cout << "3. Limiter" << endl;
     cout << "4. Normalizer" << endl;
     cout << "5. Edit File Metadata" << endl;
}

int main() {
	int userinput;
	Wav wav;
	std::vector<Audio *> list;
	wav.readAllFiles(testfile);
	list = wav.getVectorList();

	for (auto x=begin (list); x != end(list); x++) {
		std::cout<< (*x)->getFilename() << std::endl;
		int y = (*x)->getCount();
		const std::string s = (*x)->getFilename();
		std::string s2 = s+"testingbuffer";

		unsigned char * b = wav.get8BitBuffer(s);
		// Add call to processors for each file here and modify the buffer
		wav.newFile8Bit((*x), s2, b); // this is how to call if the proccessors do work
	}
}

/*
		if (y != 0) {
			metadata *currentMetadata_List = (*x)->getMetadataList();
			std::cout << "current metadata" << std::endl;
			(*x)->printmd();
			
			for (int z =0; z < y; z++) {
				print((*(currentMetadata_List+z)).header.metadata_chunk_type, 4);
				std::cout << (*(currentMetadata_List+z)).header.metadata_chunk_size << std::endl;
				print((*(currentMetadata_List+z)).data,(*(currentMetadata_List+z)).header.metadata_chunk_size);
			}
			
		}
*/
