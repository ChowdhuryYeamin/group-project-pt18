//Sean Rolandelli

#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAV_H

#include <vector>
#include <experimental/filesystem>
#include <iostream>

#include "WaveHeader.h"
#include "audiofile.h"

class Wav {
	std::vector<Audio*> list;
public:
	void readFile(const std::string &fp);
	void readAllFiles(const std::string dirPath);
};

#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
