//Sean Rolandelli

#include <string>

#include "audiotype.h"

mono8::mono8(wav_header *wavheader, metadata *metadata_List[], int count_metadata, std::string filename) : Audio(wavheader, metadata_List, count_metadata, filename) {
}

mono16::mono16(wav_header *wavheader, metadata *metadata_List[], int count_metadata, std::string filename) : Audio(wavheader, metadata_List, count_metadata, filename) {
}

stereo8::stereo8(wav_header *wavheader, metadata *metadata_List[], int count_metadata, std::string filename) : Audio(wavheader, metadata_List, count_metadata, filename) {
}

stereo16::stereo16(wav_header *wavheader, metadata *metadata_List[], int count_metadata, std::string filename) : Audio(wavheader, metadata_List, count_metadata, filename) {
}

