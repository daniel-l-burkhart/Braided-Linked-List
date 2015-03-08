/*
 * GradeBraiderTUI.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <GradeBraiderController.h>
#include <GradeBraiderTUI.h>
#include <Student.h>
#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <vector>

using controller::GradeBraiderController;
using namespace controller;

using namespace std;

namespace view {

GradeBraiderTUI::GradeBraiderTUI() {

	this->controller = GradeBraiderController();
	runMenuSystem();

}

/**
 * initial menu the user sees on start up.
 */
void GradeBraiderTUI::runMenuSystem() {
	string input;
	string file;
	cout << "Welcome to Daniel Burkhart's grade braider" << endl;

	mainMenu();

	cin >> input;
	while (input.length() != 1) {
		mainMenu();
		cin >> input;
	}
	handleSelection(input);

}

/**
 * The main menuing system.
 */
void GradeBraiderTUI::mainMenu() {
	cout << "Please enter the desired action: (l)oad file, (s)ave file, "
			<< endl
			<< "(i)nsert, (d)elete, (a)lphabetic, re(v)erse alphabetic, "
			<< endl << "(g)rade ascending, grade des(c)ending, (q)uit >"
			<< endl;
	cout << endl;
}

/**
 * outputs a vector to the user with formatting.
 * @param studentVector
 * The passed in vector.
 */
void GradeBraiderTUI::outputVector(vector<Student> studentVector) {

	for (vector<Student>::size_type i = 0; i < studentVector.size(); i++) {
		cout << studentVector[i].getLastName() << " "
				<< studentVector[i].getFirstName() << " "
				<< studentVector[i].getId() << " "
				<< studentVector[i].getGrade() << endl;
	}
}

/**
 * handles the selection made by the user
 * @param input
 * the input string from the user.
 */
void GradeBraiderTUI::handleSelection(string input) {
	char userInput;
	userInput = input[0];
	userInput = tolower(userInput);

	vector<Student> resultVector = vector<Student>();

	string file;

	switch (userInput) {
	case 'l': {
		cout
				<< "Please enter the name of the file that you would like to load in"
				<< endl;
		cin >> file;
		this->controller.loadFile(file);
		break;
	}
	case 's': {
		cout
				<< "Please enter the name of the file that you would like to save the list as. "
				<< endl;
		cin >> file;
		this->controller.saveFile(file);
		break;
	}
	case 'i': {

		string firstName;
		string lastName;
		string id;
		int grade;

		cout << "Please enter the first name: ";
		cin >> firstName;
		cout << endl;

		cout << "Please enter the last name: ";
		cin >> lastName;
		cout << endl;

		cout << "Please enter the ID: ";
		cin >> id;
		cout << endl;

		cout << "Please enter the grade: ";
		cin >> grade;
		cout << endl;

		this->controller.insertStudent(firstName, lastName, id, grade);
		break;
	}
	case 'd': {
		string studentID;
		cout
				<< "Please enter the student ID of the student you would like to remove: "
				<< endl;
		cin >> studentID;
		cout << this->controller.deleteStudent(studentID);
		break;
	}

	case 'a': {
		cout << "The students in alphabetic order are: " << endl;
		resultVector = this->controller.alphabeticList();
		this->outputVector(resultVector);
		break;
	}

	case 'r': {
		cout << "The students in reverse alphabetic order are: " << endl;
		resultVector = this->controller.reverseAlphabetic();
		this->outputVector(resultVector);
		break;
	}

	case 'g': {
		cout << "The students in grade ascending are: " << endl;
		resultVector = this->controller.gradeAscending();
		this->outputVector(resultVector);
		break;
	}

	case 'c': {
		cout << "The students in grade descending are: " << endl;
		resultVector = this->controller.gradeDescending();
		this->outputVector(resultVector);
		break;
	}

	case 'q': {
		cout << "Good bye." << endl;
		exit(0);
		break;
	}

	}
}

/**
 * Destructor of class
 */
GradeBraiderTUI::~GradeBraiderTUI() {
	// TODO Auto-generated destructor stub
}

} /* namespace view */
