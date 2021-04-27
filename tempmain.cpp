#include <iostream>
#include <string>
#include <vector>
#include "Wav.h"
#include "audiofile.h"

const std::string testfile = "./waves/waves";

int main() {
	
	Wav wav;
	std::vector<Audio *> list;

	wav.readAllFiles(testfile);

	list = wav.getVectorList();

	for (auto x=begin (list); x != end(list); x++) {
		std::cout<< (*x)->getFilename() << std::endl;
	}

}
