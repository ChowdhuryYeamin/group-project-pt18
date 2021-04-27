//Sean Rolandelli

#include <string>

#include "audiofile.h"

Audio::Audio(wav_header *wavheader, metadata *metadata_List[], int count_metadata, std::string filename) : wavheader(wavheader), metadata_List(metadata_List), count_metadata(count_metadata), filename(filename) {
}

Audio::~Audio() {
}

wav_header *Audio::getWavHeader() {
	return wavheader;
}

std::string Audio::getFilename() {
	return filename;
}

metadata **Audio::getMetadataList() {
	return metadata_List;
}

int Audio::getCount() {
	return count_metadata;
}
