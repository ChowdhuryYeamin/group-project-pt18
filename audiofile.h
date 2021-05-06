//Sean Rolandelli


#ifndef PROGRAMMING_ASSIGNMENT_3KL_AUDIOFILE_H
#define PROGRAMMING_ASSIGNMENT_3KL_AUDIOFILE_H

#include "WaveHeader.h"

/**
@brief This is the audio class, and it is the object that holds the information about each file
*/
class Audio {
	wav_header *wavheader;
	std::string filename;
	metadata *metadata_List;
	int count_metadata;
public:
	/**
	Constructs the audio class
	@param wavheader - wavheader structer with technical information
	@param metadata_List - an array of metadata structures
	@param count_metadata - the amount of metadata chunks
	@param filename - the name of the file
	*/
	Audio(wav_header *wavheader, metadata metadata_List[], int count_metadata, std::string filename);

	/**
	Audio deconstructor
	*/
	~Audio();

	/**
	Returns the wavheader
	@returns wavheader
	*/
	wav_header *getWavHeader();

	/**
	Returns the file name
	@returns filname
	*/
	std::string getFilename();

	/**
	Returns the array of metadata structures
	@returns metadata_List
	*/
	metadata *getMetadataList();

	/**
	Returns the number of metadata chunks
	@returns count_metadata
	*/
	int getCount();

};

#endif //PROGRAMMING_ASSIGNMENT_3KL_WAVEHEADER_H
