//Sean Rolandelli

#include <string>

#include "audiofile.h"

Audio::Audio(wav_header *wavheader, std::string filename) : wavheader(wavheader), filename(filename) {
}

Audio::~Audio() {
}
