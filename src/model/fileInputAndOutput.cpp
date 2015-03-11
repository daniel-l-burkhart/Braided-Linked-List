/*
 * fileInputAndOutput.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <fileInputAndOutput.h>
#include <Student.h>
#include <cstdlib>
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

namespace model {

/**
 * constructor of class
 */
fileInputAndOutput::fileInputAndOutput() {

}

/**
 * destructor of class. closes files
 */
fileInputAndOutput::~fileInputAndOutput() {

}

void fileInputAndOutput::getLineFromFile(string line,
		vector<string> stringVector, ifstream& input,
		vector<Student>& studentVector) {

	while (getline(input, line)) {

		char delimiter = ',';

		stringVector = this->split(line, delimiter);

		double grade = atof(stringVector[3].c_str());

		Student currentStudent = Student(stringVector[0], stringVector[1],
				stringVector[2], grade, 0, 0);

		studentVector.push_back(currentStudent);
	}
}

/**
 * loads student objects from file.
 * @param file
 * the file to be loaded
 */
vector<Student> fileInputAndOutput::loadFromFile(string file) {

	vector<string> stringVector;

	vector<Student> studentVector;

	ifstream input(file.c_str());
	if (input.is_open()) {

		string line;

		this->getLineFromFile(line, stringVector, input, studentVector);
	}

	input.close();
	return studentVector;
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
vector<string> fileInputAndOutput::split(string line, char c) {
	vector<string> studentData;
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
	return studentData;
}

/**
 * saves current list of students to file
 * @param file
 * the file to be saved
 * @param pHead
 * the head pointer of the list.
 */
void fileInputAndOutput::saveToFile(string file,
		vector<Student> listOfStudents) {

	ofstream outputFile(file.c_str());
	char input;
	if(outputFile){
		cout << "The file already exists. Overwrite it? (y/n)" << endl;
		cin >> input;
	}

	for (vector<string>::size_type i = 0; i < listOfStudents.size(); i++) {
		outputFile << listOfStudents[i].getLastName() << ","
				<< listOfStudents[i].getFirstName() << ","
				<< listOfStudents[i].getId() << ","
				<< listOfStudents[i].getGrade();
		outputFile << '\n';
	}

	outputFile.close();
}

} /* namespace model */

