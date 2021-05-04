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
	
	Wav wav;
	std::vector<Audio *> list;
	wav.readAllFiles(testfile);
	list = wav.getVectorList();

	for (auto x=begin (list); x != end(list); x++) {
		std::cout<< (*x)->getFilename() << std::endl;
		int y = (*x)->getCount();
		const std::string s = (*x)->getFilename();
//		std::string s2 = s+"testingbuffer";

//		unsigned char * b = wav.get8BitBuffer(s);
		// Add call to processors for each file here and modify the buffer
//		wav.newFile8Bit((*x), s2, b); // this is how to call if the proccessors do work

//		(*x)->getMetadataList()[0].header.metadata_chunk_size = (*x)->getMetadataList()[0].header.metadata_chunk_size - 6;

		
		char *sr = new char[2];
		sr[0] = 'S';
		sr[1] = 'R';
		metadata *Metadata = new metadata;

		Metadata->header.metadata_chunk_type[0] = 'I';
		Metadata->header.metadata_chunk_type[1] = 'C';
		Metadata->header.metadata_chunk_type[2] = 'M';
		Metadata->header.metadata_chunk_type[3] = 'T';

		Metadata->data = sr;
		Metadata->header.metadata_chunk_size = 2;
		// Need to move id3 entry to always be at end of metadata list.  New entries need to be added prior to id3 entry
		(*x)->getMetadataList()[y] = (*x)->getMetadataList()[y-1];
		(*x)->getMetadataList()[y-1] = *Metadata;

		wav.updateMetadata((*x), (*x)->getMetadataList(), y+1);

		
	}
}













