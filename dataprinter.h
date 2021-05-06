#ifndef DATA_PRINTER_H
#define DATA_PRINTER_H

#include <fstream>
#include <vector>
#include <string>

#include "Wav.h"

using namespace std;

class DataPrinter {
     	public:
	/**
 * @brief This is a dataprinter class, it inherits from the Wav class
 */
     	DataPrinter();
	/**
 * @brief This is a constructor for the dataprinter class;
 */

	~DataPrinter();
	/**
 * @brief This is a destructor for the dataprinter class.
 */

    	void WriteFile(vector<Audio*> list);
	/**
 * @brief Writes off key technical information and metadata for all files using a far loop. Takes in the vector list of all the audio files as an argument and loops through them accordingly.
   @param list - contains all audio objects so that they can be printed into the CSV file. 
 */
};

#endif
