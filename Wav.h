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
	/**
	This returns the vector list that has each files audio class
	*/
	std::vector<Audio*> getVectorList();

	/**
	This returns the buffer for 8 bit files
	@param filePath - which file in the directory is being used
	*/
	unsigned char* get8BitBuffer(const std::string &filePath);

	/**
	This returns the buffer for 16 bit files
	@param filePath - which file in the directory is being used
	*/
	signed short* get16BitBuffer(const std::string &filePath);

	/**
	This reads all of the technical and metadata from a file and stores them in the proper structures, as well as putting each files audio class in a vector list
	@param fp - which file is being read
	*/
	void readFile(const std::string &fp);

	/**
	This loops through readFile until all files from the directory have been read
	@param dirPath - the directory path
	*/
	void readAllFiles(const std::string dirPath);

	/**
	This resizes the files so that the new metadata is writen in the correct place, and also allows the user to delete all metadata by setting count to zero
	@param audio - audio class for the file that was changed
	@param newMetadata_LIst - an array with the new metadata
	@param count - how many chunks of metadata there will be
	*/
	void updateMetadata(Audio *audio, metadata newMetadata_List[], int count);

	/**
	This creates a new file in the case that the audio went through a proccessor
	@param audio - audio class for the file that was proccessed
	@param newName - the name for the new file
	@param buffer - the proccessed audio
	@returns 0 - the newName was valid and a new file was created
	@returns 1 - the newNamw was not valid and a file was not created
	*/
	int newFile8Bit(Audio* audio, const std::string newName, unsigned char* buffer);

	/**
	This does the same thing as newFile8Bit, but to make it clear in the main function this was made to show when a 16 bit file is used
	@param audio - audio class for the file that was proccessed
	@param newName - the name for the new file
	@param buffer - the proccessed audio
	@returns the same as newFile8Bit
	*/
	int newFile16Bit(Audio* audio, const std::string newName, signed short* buffer);
};

#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
