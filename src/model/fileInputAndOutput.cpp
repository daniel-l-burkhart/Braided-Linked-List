/*
 * fileInputAndOutput.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include "fileInputAndOutput.h"
#include "Student.h"

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

/**
 * Helper method that deals with each line of the file load in.
 *
 * @param input
 * the input file.
 * @return
 * A vector of Student objects to be inserted to the linked list.
 */
vector<Student> fileInputAndOutput::getLineFromFile(ifstream& input) {
	vector<string> stringVector;

	vector<Student> studentVector;
	string line;

	while (getline(input, line)) {

		char delimiter = ',';

		stringVector = this->split(line, delimiter);

		int grade = atof(stringVector[3].c_str());

		stringVector[0] = this->stringToLower(stringVector[0]);
		stringVector[1] = this->stringToLower(stringVector[1]);

		Student currentStudent = Student(stringVector[0], stringVector[1],
				stringVector[2], grade, 0, 0);

		studentVector.push_back(currentStudent);
	}
	return studentVector;
}

/**
 * Helper method to keep all names in the list
 * whether inserted or loaded the same format
 * for sorting.
 *
 * @param name
 * The passed in name.
 * @return
 * a lowercase representation of the string
 * with the first letter of the name capitalized.
 */
string fileInputAndOutput::stringToLower(string name) {

	for (string::size_type i = 0; i < name.size(); i++) {

		name[i] = tolower(name[i]);
	}

	name[0] = toupper(name[0]);

	return name;
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
 * @param listOfStudents
 * The list of students to be output to the file.
 */
bool fileInputAndOutput::SaveToFile(string file,
		vector<Student> students) {

	ofstream outputFile(file.c_str());

	if (outputFile.bad()) {
		outputFile.close();
		return false;
	}

	for (vector<string>::size_type i = 0; i < students.size(); i++) {
		outputFile << students[i].getLastName() << ","
				<< students[i].getFirstName() << ","
				<< students[i].getId() << ","
				<< students[i].getGrade();
		outputFile << "\r\n";
	}

	outputFile.close();
	return true;

}

} /* namespace model */

