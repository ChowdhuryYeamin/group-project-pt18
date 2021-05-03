#include <iostream>
#include <string>
#include <vector>
#include "Wav.h"
#include "audiofile.h"

const std::string testfile = "./waves/waves";

void print(char* word, int size) {
	for(int x = 0; x < size; x++) {
		std::cout << word[x];
	}
	std::cout << std::endl;
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
		std::string s2 = s + "-test.wav";
		Audio *a = (*x);

		unsigned char * b = wav.get8BitBuffer(s);
		wav.newFile8Bit(a, s2, b);
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

}
