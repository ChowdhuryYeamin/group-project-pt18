//Sean Rolandelli

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <experimental/filesystem>

#include "Wav.h"
#include "audiofile.h"
#include "audiotype.h"

void print(char* word, int size) {
	for(int x = 0; x < size; x++) {
		std::cout << word[x];
	}
	std::cout << std::endl;
}

void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);

	wav_header WavHeader;
	metadata_header MetadataHeader;

	metadata *metadata_list[10];

	unsigned char* buffer = NULL;

        if(file.is_open()) {
        	file.read((char*)&WavHeader, sizeof(wav_header));

        	buffer = new unsigned char[WavHeader.data_bytes];
        	file.read((char*)buffer, WavHeader.data_bytes);

		std::cout << WavHeader.size-36-WavHeader.data_bytes << std::endl;
		
		int x = WavHeader.size-36-WavHeader.data_bytes;

		if(x != 0) {
			file.read((char*)&MetadataHeader, sizeof(MetadataHeader));

			x=x-MetadataHeader.metadata_header_size;

			print(MetadataHeader.metadata_header,4);

			std::cout << MetadataHeader.metadata_header_size << std::endl;

			print(MetadataHeader.metadata_header_info,4);

			int counter=0;

			do {
				metadata *Metadata = new metadata;				

				file.read((char*)&Metadata->header, sizeof(metadata_chunk));

				print(Metadata->header.metadata_chunk_type,4);

				std::cout << Metadata->header.metadata_chunk_size << std::endl;
		
				Metadata->data = new char[Metadata->header.metadata_chunk_size];
        			
				file.read((char*)Metadata->data, Metadata->header.metadata_chunk_size);

				print((char*)Metadata->data,Metadata->header.metadata_chunk_size);

				x=x-sizeof(metadata_chunk)-Metadata->header.metadata_chunk_size;

				metadata_list[counter++] = Metadata;
			
			} while(x > 0);

	
		}

		if (WavHeader.channels == 1) {
			if (WavHeader.bits == 8) {
				mono8 *audiofile = new mono8(&WavHeader, fileName);
				list.push_back(audiofile);
			}
			else {
				mono16 *audiofile = new mono16(&WavHeader, fileName);
				list.push_back(audiofile);
			}
		}
		else {
			if (WavHeader.bits == 8) {
				stereo8 *audiofile = new stereo8(&WavHeader, fileName);
				list.push_back(audiofile);
			}
			else {
				stereo16 *audiofile = new stereo16(&WavHeader, fileName);
				list.push_back(audiofile);
			}
		}

        	file.close();
    	}
}

void Wav::readAllFiles(const std::string dirPath) {
	for (auto& x: std::experimental::filesystem::directory_iterator(dirPath)) {
		if(((std::string)x.path().filename()).compare(0,1,".") == 0) {
			continue;
		}
		readFile(x.path());
		std::cout << x.path() << std::endl;
	}
}
