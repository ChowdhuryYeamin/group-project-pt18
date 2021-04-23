//Sean Rolandelli

#include <iostream>
#include <string>

#include "WaveHeader.h"
#include "audiofile.h"


class mono8: public Audio {
public:
	mono8(wav_header *wavheader, std::string filename);
};

class mono16: public Audio {
public:
	mono16(wav_header *wavheader, std::string filename);
};

class stereo8: public Audio {
public:
	stereo8(wav_header *wavheader, std::string filename);
};

class stereo16: public Audio {
public:
	stereo16(wav_header *wavheader, std::string filename);
};

