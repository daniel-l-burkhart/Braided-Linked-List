/*
 * fileInputAndOutput.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <fileInputAndOutput.h>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

namespace model {

fileInputAndOutput::fileInputAndOutput() {
	// TODO Auto-generated constructor stub

}

fileInputAndOutput::~fileInputAndOutput() {
	// TODO Auto-generated destructor stub
}

vector<string> fileInputAndOutput::loadFromFile(string file){
	vector<string> stringVector;
	ifstream infile(file.c_str());



	while(!infile.is_open()){
		size_t pos = 0;
		string delimiter = ",";
		string line;
		string currentWord;

		getline(infile, line);
		while((pos = line.find(delimiter)) != std::string::npos){
			currentWord = line.substr(0, pos);
			stringVector.push_back(currentWord);
		}
	}

	string lastName;
	string firstName;
	string ID;
	string stringGrade;
	int grade = 0;



return stringVector;

}

} /* namespace model */
