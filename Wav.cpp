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
		file.read((char*)&WavHeader, sizeof(wav_header));
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
/*
void printx(char* word, int size) {
	for(int x = 0; x < size; x++) {
		std::cout << word[x];
	}
	std::cout << std::endl;
}
*/
void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
        if(file.is_open()) {

		wav_header *WavHeader = new wav_header;
		metadata_header *MetadataHeader = new metadata_header;
		unsigned char* buffer = NULL;
        	
		file.read((char*)WavHeader, sizeof(wav_header));
        	buffer = new unsigned char[WavHeader->data_bytes];
        	file.read((char*)buffer, WavHeader->data_bytes);
		
		metadata *metadata_List = new metadata[20];
		int counter=0;
		int x = WavHeader->size-36-WavHeader->data_bytes;

		if(x != 0) {
			file.read((char*)MetadataHeader, sizeof(MetadataHeader));
			x=x-MetadataHeader->metadata_header_size;
std::cout<<"RF: header: " << MetadataHeader->metadata_header[0] << std::endl;
std::cout<<"RF: header: " << MetadataHeader->metadata_header[1] << std::endl;
			do {	
				metadata *Metadata = new metadata;	
						
				file.read((char*)&Metadata->header, sizeof(metadata_chunk));
std::cout<<"RF chunksize = " << Metadata->header.metadata_chunk_type[0] << std::endl;
std::cout<<"RF chunksize = " << Metadata->header.metadata_chunk_size << std::endl;
				Metadata->data = new char[Metadata->header.metadata_chunk_size];
				//file.read((char*)Metadata->data, Metadata->header.metadata_chunk_size);

				x=x-sizeof(metadata_chunk)-Metadata->header.metadata_chunk_size;
				metadata_List[counter++] = *Metadata;
			
			} while(x > 0);

	
		}

		Audio *audiofile = new Audio(WavHeader, metadata_List, counter, fileName);
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

int writeMetadata(std::ofstream *file, metadata newMetadata_List[], int count) {
	metadata_header newMetadataHeader;
	int MetadataSize = 0;
std::cout << "count="<<count << std::endl;
	for (int x=0; x < count-1; x++) { //count-1 is to account for id3 in total size but not as metadata size
		MetadataSize += newMetadata_List[x].header.metadata_chunk_size + sizeof(metadata_chunk);
	}

	newMetadataHeader.metadata_header[0] = 'L';
	newMetadataHeader.metadata_header[1] = 'I';
	newMetadataHeader.metadata_header[2] = 'S';
	newMetadataHeader.metadata_header[3] = 'T';
	newMetadataHeader.metadata_header_size = MetadataSize;
	newMetadataHeader.metadata_header_info[0] = 'I';
	newMetadataHeader.metadata_header_info[1] = 'N';
	newMetadataHeader.metadata_header_info[2] = 'F';
	newMetadataHeader.metadata_header_info[3] = 'O';

	file->write((char*)&newMetadataHeader.metadata_header, 4);
	file->write((char*)&newMetadataHeader.metadata_header_size, sizeof(int));
	file->write((char*)&newMetadataHeader.metadata_header_info, 4);

	for(int x=0; x < count; x++) {
std::cout << "chucksize="<<newMetadata_List[x].header.metadata_chunk_size << std::endl;
		file->write((char*)&newMetadata_List[x].header.metadata_chunk_type, 4);
		file->write((char*)&newMetadata_List[x].header.metadata_chunk_size, sizeof(int));
		file->write(newMetadata_List[x].data, newMetadata_List[x].header.metadata_chunk_size);
	}

	return MetadataSize + sizeof(metadata_header) + newMetadata_List[count-1].header.metadata_chunk_size + sizeof(metadata_chunk);
}



int Wav::newFile8Bit(Audio* audio, const std::string newName, unsigned char* buffer) {
	std::ifstream ifile;
	ifile.open(newName);

	if (ifile.fail()) {
std::cout<< newName << std::endl;
		std::ofstream ofile(newName,std::ios::binary | std::ios::out);
		ofile.write((char *)audio->getWavHeader(), sizeof(wav_header));
		//ofile.write((char *)buffer, audio->getWavHeader()->data_bytes);
std::cout<< audio->getWavHeader()->data_bytes << std::endl;
		writeMetadata(&ofile, audio->getMetadataList(), audio->getCount());

		ifile.close();
		ofile.close();
		return 0;
	} 
	else {
		std::cout << "File name already exists, pick a new name" << std::endl;
		ifile.close();
		return 1;
	}
}

int Wav::newFile16Bit(Audio* audio, const std::string newName, signed short* buffer) {
	return newFile8Bit(audio, newName, (unsigned char *)buffer);
}


void Wav::updateMetadata(Audio *audio, metadata newMetadata_List[], int count) {

	wav_header *wavheader = audio->getWavHeader();
	std::string fileName = audio->getFilename();
	std::ofstream file;
	
	if (count > 0) {
		
		std::experimental::filesystem::resize_file(fileName,sizeof(wavheader) + wavheader->data_bytes);
		file.open(fileName, std::ios::app);

		int MetadataSize = writeMetadata(&file, newMetadata_List, count);
		wavheader->size = sizeof(wavheader) + wavheader->data_bytes + MetadataSize;
	}
	else {
		wavheader->size = sizeof(wavheader) + wavheader->data_bytes;
		std::experimental::filesystem::resize_file(fileName, sizeof(wavheader) + wavheader->data_bytes);

		file.open(fileName, std::ios::app);
	}
	
	file.seekp(0);
	file.write((char*)&wavheader,sizeof(wavheader));
	file.close();
}


/*
void Wav::reWriteFile(std::string filename, char* data){
	wav_header WavHeader;
	metadata_header MetadataHeader;
	file.read((char*)&WavHeader, sizeof(wav_header));
	int x = WavHeader.size-36-WavHeader.data_bytes;
	ofstream fout(filename);
	file.read((char*)buffer, WavHeader.data_bytes);
	if(fout.is_open()){
		if(x != 0){
			while(x > 0){
				fout << data[i] << endl;
			}
		}
		else{
			continue;
		}
		fout.close();
	}
	else{
		cout << "ERROR: File metadata could not be rewritten" << endl;
	}
}
*/
