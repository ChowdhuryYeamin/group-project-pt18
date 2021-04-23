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
	MetaDataFinder(std::string file_type, std::string modification_date, std::string location, std::string method, std::string CRC, int size, int compressed, int index){
		setfiletype(file_type);
		setmoddate(modification_date);
		setlocation(location);
		setmethod(method);
		setcrc(CRC);
		setsize(size);
		setcomp(compressed);
		setindex(index);
	}
	void scanMetaData();
	void scanTechSpecs();
	void addToVector(){
		MetaDataFinder *newpoint = new MetaDataFinder(file_type, modification_date, location, method, CRC, size, compressed, index);
		data.push_back(*newpoint);
	}
	void setfiletype(std::string new_file_type){
		file_type = new_file_type;
	}
	void setmoddate(std::string new_modification_date){
		modification_date = new_modification_date;
	}
	void setlocation(std::string new_location){
		location = new_location;
	}
	void setmethod(std::string new_method){
		method = new_method;
	}
	void setcrc(std::string new_CRC){
		CRC = new_CRC;
	}
	void setsize(int new_size){
		size = new_size;
	}
	void setcomp(int new_compressed){
		compressed = new_compressed;
	}
	void setindex(int new_index){
		index = new_index;
	}
};
	
#endif
