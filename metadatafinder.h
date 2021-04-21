#ifndef METADATAFINDER_H
#define METADATAFINDER_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class MetaDataFinder{
	protected:
	std::string file_type, modification_date, location, method, CRC;
	int size, compressed, index;
	vector<MetaDataFinder> data;
	public:
	MetaDataFinder(std::string file_type, std::string modification_date, std::string location, std::string method, std::string CRC, int size, int compressed, int index);
	void scanMetaData();
	void scanTechSpecs();
	void addToVector();
};
	
#endif
