//Sean Rolandelli

#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAV_H

#include <vector>
#include <experimental/filesystem>
#include <iostream>
#include <string>

#include "WaveHeader.h"
#include "audiofile.h"

class Wav {
	std::vector<Audio*> list;
public:
	std::vector<Audio*> getVectorList();

	unsigned char* get8BitBuffer(const std::string &filePath);
	signed short* get16BitBuffer(const std::string &filePath);



	void readFile(const std::string &fp);
	void readAllFiles(const std::string dirPath);
<<<<<<< HEAD

	void updateMetadata(Audio *audio, metadata *newMetadata_List[], int count);

	int newFile8Bit(Audio* audio, const std::string newName, unsigned char* buffer);
	int newFile16Bit(Audio* audio, const std::string newName, signed short* buffer);
=======
	
	void reWriteFile(std::string filename, char *data);
>>>>>>> c24de9ca973795182d4f6e5358935b0f09e73cdb
};

#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
