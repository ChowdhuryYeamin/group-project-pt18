#ifndef DATA_PRINTER
#define DATA_PRINTER_H

#include <fstream>
#include <vector>
#include <string>

#include "metadatafinder.h"

using namespace std;

class DataPrinter: public MetaDataFinder{
	public:
	void WriteFile{
		int i;
		ofstream fout("Metadata.csv");
		for(i = 0; i < data.size(); i++){
			fout << "File Type: " << data[i].getftype() << endl;
			fout << "Modification Date: " << data[i].getmoddate << endl;
			fout << "Location: " << data[i].getlocation << endl;
			fout << "Method: " << data[i].getmethod << endl;
			fout << "CRC: " << data[i].getcrc << endl;
			fout << "Compression: " << data[i].getcomp << endl;
			fout << "Index: " << data[i].getindex << endl;
			fout << "Size: " << data[i].getsize << endl;	
		}
		fout.close()
	}
	std::string getftype(){
		return file_type;
	}
	std::string getmoddate(){
		return modification_date;
	}
	std::string getlocation(){
		return location;
	}
	std::string getmethod(){
		return method;
	}
	std::string getcrc(){
		return CRC;
	}
	int getcomp(){
		return compressed;
	}
	int getindex(){
		return index;
	}
	int getsize(){
		return size;
	}			
};

#endif
