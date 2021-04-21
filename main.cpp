#include <iostream>
#include <string>

using namespace std:

void Menu(){
	cout << "*****MENU*****" << endl;
	cout << "1. Process Files" << endl;
	cout << "2. Create CSV File with Specs" << endl;
}

void findFileNames(){
	//Will go over and find filenames in the directory
}

int main() {
	int userinput, i = 1, index = 0;
	vector<std::string> filenames; 
	findFileNames
	Menu();
	cin >> userinput;
	while(i==1){
		if(userinput==1){
			//Stuff to process files
		}
		else if(userinput==2){
			for(index; index < filenames.size(); index++){
				MetaDataFinder scanMetaData(filenames[index]);
				MetaDataFinder scanTechSpecs(filenames[index]);
				MetaDataFinder addToVector(filenames[index]);
				DataPrinter WriteFile();
			}
		}
		else{
			cout << "ERROR: Invalid request" << endl;
		}
	}
    	return 0;
}
