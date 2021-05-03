//Sean Rolandelli

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <experimental/filesystem>

#include "Wav.h"
#include "audiofile.h"
#include <string>


unsigned char* Wav::get8BitBuffer(const std::string &filePath) {
	std::ifstream file(filePath,std::ios::binary | std::ios::in);
	unsigned char* buffer = NULL;
	wav_header WavHeader;
	if(file.is_open()) {
std::cout<< "file: " << filePath << std::endl;
		file.read((char*)&WavHeader, sizeof(wav_header));
std::cout << "GB: " << filePath << " " << WavHeader.data_bytes << std::endl;
		buffer = new unsigned char[WavHeader.data_bytes];
		file.read((char*)buffer, WavHeader.data_bytes);
		file.close();
	}

	return buffer;
}

signed short* Wav::get16BitBuffer(const std::string &filePath) {
	std::ifstream file(filePath,std::ios::binary | std::ios::in);
	signed short* buffer = NULL;
	wav_header WavHeader;
	if(file.is_open()) {
		file.read((char*)&WavHeader, sizeof(wav_header));
		buffer = new signed short[WavHeader.data_bytes];
		file.read((char*)buffer, WavHeader.data_bytes);
		file.close();
	}

	return buffer;
}

std::vector<Audio*> Wav::getVectorList() {
	return list;
}

void printx(char* word, int size) {
	for(int x = 0; x < size; x++) {
		std::cout << word[x];
	}
	std::cout << std::endl;
}

void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
        if(file.is_open()) {

		wav_header WavHeader;
		metadata_header MetadataHeader;
		unsigned char* buffer = NULL;
        	
		file.read((char*)&WavHeader, sizeof(wav_header));
std::cout << "RF: " << fileName << " " << WavHeader.data_bytes << std::endl;
        	buffer = new unsigned char[WavHeader.data_bytes];
        	file.read((char*)buffer, WavHeader.data_bytes);
		
		metadata metadata_List[20];
		int counter=0;
		int x = WavHeader.size-36-WavHeader.data_bytes;

		if(x != 0) {
			file.read((char*)&MetadataHeader, sizeof(MetadataHeader));
			x=x-MetadataHeader.metadata_header_size;

			do {	
				metadata Metadata;	
						
				file.read((char*)&Metadata.header, sizeof(metadata_chunk));

				Metadata.data = new char[Metadata.header.metadata_chunk_size];
				file.read((char*)Metadata.data, Metadata.header.metadata_chunk_size);

				x=x-sizeof(metadata_chunk)-Metadata.header.metadata_chunk_size;
				metadata_List[counter++] = Metadata;
			
			} while(x > 0);

	
		}

/*			for (int z =0; z < counter; z++) {
				printx(metadata_List[z].header.metadata_chunk_type, 4);
				std::cout << metadata_List[z].header.metadata_chunk_size << std::endl;
				printx(metadata_List[z].data,metadata_List[z].header.metadata_chunk_size);
			}
*/
		Audio *audiofile = new Audio(&WavHeader, metadata_List, counter, fileName);
				list.push_back(audiofile);
        	file.close();
    	}
}

void Wav::readAllFiles(const std::string dirPath) {
	for (auto& x: std::experimental::filesystem::directory_iterator(dirPath)) {
		if(((std::string)x.path().filename()).compare(0,1,".") == 0) {
			continue;
		}
		readFile(x.path());

	}
}

int Wav::newFile8Bit(Audio* audio, const std::string newName, unsigned char* buffer) {
	std::ifstream ifile;
	ifile.open(newName);

	if (ifile.fail()) {
		std::cout << "File: " << newName << std::endl;
		std::ofstream ofile(newName,std::ios::binary | std::ios::out);
std::cout << "NF: "<< newName << " " << audio->getWavHeader()->data_bytes << std::endl;
		ofile.write((char *)audio->getWavHeader(), sizeof(wav_header));
		ofile.write((char *)buffer, audio->getWavHeader()->data_bytes);


		ifile.close();
		ofile.close();
		return 0;
	} else {
		std::cout << "File name already exists: '" << newName << "' is not valid" << std::endl;
		ifile.close();
		return 1;
	}
}

int Wav::newFile16Bit(Audio* audio, const std::string newName, signed short* buffer) {

}

/*
void Wav::updateMetadata(Audio *audio, metadata *newMetadata_List[], int count) {

	wav_header *wavheader = audio->getWavHeader();
	std::string fileName = audio->getFilename();
	std::ofstream file;
	
	if (count > 0) {
		int MetadataSize = 0;
		for (int x=0; x < count; x++) {
			MetadataSize += newMetadata_List[x]->header.metadata_chunk_size + sizeof(metadata_chunk);
		}
		MetadataSize += sizeof(metadata_header);

		wavheader->size = sizeof(wavheader) + wavheader->data_bytes + MetadataSize;
		std::experimental::filesystem::resize_file(fileName,sizeof(wavheader) + wavheader->data_bytes);

		metadata_header newMetadataHeader;
		newMetadataHeader.metadata_header[0] = 'L';
		newMetadataHeader.metadata_header[1] = 'I';
		newMetadataHeader.metadata_header[2] = 'S';
		newMetadataHeader.metadata_header[3] = 'T';
		newMetadataHeader.metadata_header_size = MetadataSize;
		newMetadataHeader.metadata_header_info[0] = 'I';
		newMetadataHeader.metadata_header_info[1] = 'N';
		newMetadataHeader.metadata_header_info[2] = 'F';
		newMetadataHeader.metadata_header_info[3] = 'O';

		file.open(fileName, std::ios::app);

		file.write((char*)&newMetadataHeader, sizeof(metadata_header));
		for(int x=0; x < count; x++) {
			file.write((char*)&newMetadata_List[x]->header, sizeof(metadata_chunk));
			file.write((char*)&newMetadata_List[x]->data, newMetadata_List[x]->header.metadata_chunk_size);
		}
		file.seekp(0);
		file.write((char*)&wavheader,sizeof(wavheader));

		file.close();
	}
	else {
		wavheader->size = sizeof(wavheader) + wavheader->data_bytes;
		std::experimental::filesystem::resize_file(fileName,sizeof(wavheader) + wavheader->data_bytes);

		file.open(fileName, std::ios::app);

		file.seekp(0);
		file.write((char*)&wavheader,sizeof(wavheader));

		file.close();
	}
}
*/









