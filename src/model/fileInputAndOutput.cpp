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
#include <sstream>

using namespace std;

namespace model {

/**
 * constructor of class
 */
fileInputAndOutput::fileInputAndOutput() {
	// TODO Auto-generated constructor stub

}

/**
 * destructor of class. closes files
 */
fileInputAndOutput::~fileInputAndOutput() {

}

/**
 * loads student objects from file.
 * @param file
 * the file to be loaded
 */
void fileInputAndOutput::loadFromFile(string file) {

	vector<string> stringVector;
	ifstream input(file.c_str());


	while (input.is_open()) {

		char delimiter = ',';
		string line;

		getline(input, line, '\n');

		this->split(line, delimiter, stringVector);

		int grade;
		istringstream convert(stringVector[3]);
		convert >> grade;

		this->student.CreateStudent(stringVector[0], stringVector[1],
				stringVector[2], grade);

		stringVector.clear();
		line.clear();

	}

	input.close();

}

/**
 * splits the string based on the comma
 * @param line
 * the passed in string
 * @param c
 * the char delimiter
 * @param studentData
 * the vector of data from the line
 */
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

/**
 * saves current list to file
 * @param file
 * the file to be saved
 * @param pHead
 * the head pointer of the list.
 */
void fileInputAndOutput::saveToFile(string file, Student* pHead) {

	ofstream outputFile(file.c_str());


	for (Student *pTemp = pHead; pTemp != 0; pTemp = pTemp->nextName) {
		outputFile << pTemp->getLastName() << ","
				<< pTemp->getFirstName() << "," << pTemp->getId() << ","
				<< pTemp->getGrade() << endl;
	}

	outputFile.close();
}

} /* namespace model */

