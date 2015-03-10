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
	cout << "Welcome to Daniel Burkhart's grade braider" << endl;

	while (true) {

		this->mainMenu();
		cin >> input;

		while (input.length() != 1) {
			cout << endl << "I'm sorry. That input is invalid. Please try again"
					<< endl;
			this->mainMenu();
			cin >> input;
		}
		this->handleSelection(input);
	}

}

/**
 * The main menuing system.
 */
void GradeBraiderTUI::mainMenu() {
	cout << endl
			<< "Please enter the desired action: (l)oad file, (s)ave file, "
			<< endl
			<< "(i)nsert, (d)elete, (a)lphabetic, re(v)erse alphabetic, "
			<< endl << "(g)rade ascending, grade des(c)ending, (q)uit >";
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
		double grade;

		cout << "Please enter the first name: ";
		cin >> firstName;
		firstName = this->lowerCaseString(firstName);
		cout << endl;

		cout << "Please enter the last name: ";
		cin >> lastName;
		lastName = this->lowerCaseString(lastName);
		cout << endl;

		cout << "Please enter the ID: ";
		cin >> id;
		cout << endl;

		cout << "Please enter the grade: ";
		while (!(cin >> grade)) {
			cin.clear();
			cout << "Please enter a number for the grade." << endl;
		}

		cout << endl;

		cout << this->controller.insertStudent(firstName, lastName, id, grade)
				<< endl;
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

	case 'v': {
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

	default: {
		cout << endl << "I'm sorry. That input is invalid. Please try again"
				<< endl;
	}

	}
}

/**
 * Method to keep all names lower case for sorting
 * @param input
 * the string input
 * @return
 * a lower case equivalent of the input string
 */
string GradeBraiderTUI::lowerCaseString(string input) {
	string result;
	for (int i = 0; input[i]; i++) {
		input[i] = tolower(input[i]);
	}
	return input;
}

/**
 * Destructor of class
 */
GradeBraiderTUI::~GradeBraiderTUI() {
	// TODO Auto-generated destructor stub
}

} /* namespace view */
