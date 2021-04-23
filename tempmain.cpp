#include <iostream>
#include <string>
#include "Wav.h"

const std::string testfile = "./waves/waves";

int main() {
	
	Wav wav;

	wav.readAllFiles(testfile);


}
