//Sean Rolandelli


#ifndef PROGRAMMING_ASSIGNMENT_3KL_AUDIOFILE_H
#define PROGRAMMING_ASSIGNMENT_3KL_AUDIOFILE_H

#include "WaveHeader.h"

class Audio {
protected:
	wav_header *wavheader;
	std::string filename;
public:
	Audio(wav_header *wavheader, std::string filename);
	~Audio();
};

#endif //PROGRAMMING_ASSIGNMENT_3KL_WAVEHEADER_H
