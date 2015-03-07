/*
 * fileInputAndOutput.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <fileInputAndOutput.h>
#include <Student.h>
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

void fileInputAndOutput::loadFromFile(string file) {

	vector<string> stringVector;

	ifstream infile(file.c_str());

	while (infile.is_open()) {

		char delimiter = ',';
		string line;

		getline(infile, line, '\n');

		this->split(line, delimiter, stringVector);

		int grade;
		istringstream convert(stringVector[3]);
		convert >> grade;

		this->student.CreateStudent(stringVector[0], stringVector[1],
				stringVector[2], grade);

		stringVector.clear();
		line.clear();

	}

}

void fileInputAndOutput::split(string line, char c,
		vector<string> studentData) {
	int i = 0;
	int j = line.find(c);

	while (j >= 0) {
		studentData.push_back(line.substr(i, j - i));
		i = ++j;
		j = line.find(c, j);

		if (j < 0) {
			studentData.push_back(line.substr(i, line.length()));
		}
	}
}

void fileInputAndOutput::saveToFile(string file, Student* pHead) {

	ofstream os(file.c_str());

	for (Student *pTemp = pHead; pTemp != 0; pTemp = pTemp->nextName) {
		os << pTemp->getLastName() << "," << pTemp->getFirstName() << ","
				<< pTemp->getId() << "," << pTemp->getGrade() << endl;
	}
}

} /* namespace model */

