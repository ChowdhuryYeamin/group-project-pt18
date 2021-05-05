//Sean Rolandelli


#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAVEHEADER_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAVEHEADER_H

	/**
	This is the wav header, and it contains the technical data of the wav files.
	*/
typedef struct wav_header {
	//Riff Header
	char riff_header[4]; //"RIFF"
	int size; //size of wav file
	char wave_header[4]; //"Wave"

	//Format Header
	char fmt_header[4]; //"fmt " has trailing null
	int fmt_size; //size of format data
	short audio_format; //type of format
	short channels; //number of channels: 1=mono, 2=stereo
	int sample_rate; //number of samples per second (Hz)
	int byte_rate; //bytes per second: sample_rate*channels*(bits/8)
	short block_align; //channels*(bits/8)
	short bits; //8, 16, 24, or 32	

	//Data
	char data_header[4]; //"data"
	int data_bytes; //number of bytes in data: 
	
} wav_header;

	/**
	This is the metadata header, and it contains the size and information of the metadata.
	*/
typedef struct metadata_header {
	//Metadata Header
	char metadata_header[4]; //"LIST"
	int metadata_header_size; //size of list
	char metadata_header_info[4]; //"INFO"

} metadata_header;

	/**
	This is the metadata chunk header, and it contains the metadata chunk header information
	*/
typedef struct metadata_chunk {
	//Metadata Chunk Header
	char metadata_chunk_type[4]; //"INAM", "IART", or "ICMP"
	int metadata_chunk_size; //size of data

} metadata_chunk;

	/**
	This is the metadata, and it contains the chunk header and pointer to the data.
	*/
typedef struct metadata {
	//Saved Metadata
	metadata_chunk header;
	char* data; //What the metadata says
} metadata;


#endif //PROGRAMMING_ASSIGNMENT_3KL_WAVEHEADER_H
