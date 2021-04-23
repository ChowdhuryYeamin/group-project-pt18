//Sean Rolandelli

#include <string>

#include "audiotype.h"

mono8::mono8(wav_header *wavheader, std::string filename) : Audio(wavheader, filename) {
}

mono16::mono16(wav_header *wavheader, std::string filename) : Audio(wavheader, filename) {
}

stereo8::stereo8(wav_header *wavheader, std::string filename) : Audio(wavheader, filename) {
}

stereo16::stereo16(wav_header *wavheader, std::string filename) : Audio(wavheader, filename) {
}

