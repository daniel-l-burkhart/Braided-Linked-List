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

vector<Student> fileInputAndOutput::getLineFromFile(ifstream& input) {
	vector<string> stringVector;

	vector<Student> studentVector;
	string line;

	while (getline(input, line)) {

		char delimiter = ',';

		stringVector = this->split(line, delimiter);

		int grade = atof(stringVector[3].c_str());

		Student currentStudent = Student(stringVector[0], stringVector[1],
				stringVector[2], grade, 0, 0);

		studentVector.push_back(currentStudent);
	}
	return studentVector;
}

/**
 * loads student objects from file.
 * @param file
 * the file to be loaded
 */
vector<Student> fileInputAndOutput::LoadFromFile(string file) {

	vector<Student> resultVector;

	ifstream input(file.c_str());
	if (input.is_open()) {

		resultVector = this->getLineFromFile(input);
	}

	input.close();
	return resultVector;
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
	int delimiter = line.find(c);

	while (delimiter >= 0) {

		studentData.push_back(line.substr(i, delimiter - i));
		i = ++delimiter;
		delimiter = line.find(c, delimiter);

		if (delimiter < 0) {
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
bool fileInputAndOutput::SaveToFile(string file,
		vector<Student> listOfStudents) {

	ofstream outputFile(file.c_str());

	if (outputFile.bad()) {
		outputFile.close();
		return false;
	}

	for (vector<string>::size_type i = 0; i < listOfStudents.size(); i++) {
		outputFile << listOfStudents[i].getLastName() << ","
				<< listOfStudents[i].getFirstName() << ","
				<< listOfStudents[i].getId() << ","
				<< listOfStudents[i].getGrade();
		outputFile << '\n';
	}
	outputFile.close();
	return true;

}

} /* namespace model */

