//Sean Rolandelli


#ifndef PROGRAMMING_ASSIGNMENT_3KL_AUDIOFILE_H
#define PROGRAMMING_ASSIGNMENT_3KL_AUDIOFILE_H

#include "WaveHeader.h"

class Audio {
	wav_header *wavheader;
	std::string filename;
	metadata *metadata_List;
	int count_metadata;
public:
	Audio(wav_header *wavheader, metadata metadata_List[], int count_metadata, std::string filename);
	~Audio();

	wav_header *getWavHeader();
	std::string getFilename();
	metadata *getMetadataList();
	int getCount();

};

#endif //PROGRAMMING_ASSIGNMENT_3KL_WAVEHEADER_H
