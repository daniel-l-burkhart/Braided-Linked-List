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
#include <iostream>
#include <vector>
#include <iomanip>

using controller::GradeBraiderController;
using namespace controller;

using namespace std;

namespace view {

GradeBraiderTUI::GradeBraiderTUI() {

}

bool GradeBraiderTUI::fileExists(string file) {
	fstream outputFile(file.c_str());

	if (outputFile) {
		return true;
	}
	return false;
}

/**
 * initial menu the user sees on start up.
 */
void GradeBraiderTUI::RunMenuSystem() {
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
		cout << setw(15) << left << studentVector[i].getLastName() << setw(15)
				<< left << studentVector[i].getFirstName() << setw(15) << left
				<< studentVector[i].getId() << setw(15) << left
				<< studentVector[i].getGrade() << endl;
	}
}

void GradeBraiderTUI::LoadFileFromCommandLine(string file) {
	cout << this->controller.LoadFile(file) << endl;
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

		cout << endl
				<< "Please enter the name of the file that you would like to load in"
				<< endl;

		cin >> file;
		cout << endl << this->controller.LoadFile(file) << endl;
		break;
	}

	case 's': {

		string response;
		cout << endl
				<< "Please enter the name of the file that you would like to save the list as. "
				<< endl;
		cin >> file;

		if (this->fileExists(file)) {
			cout << "The file already exists. Overwrite it? (y/n)" << endl;
			cin >> response;

			this->handleResponse(response, file);
			break;

		} else {
			this->controller.SaveFile(file);
		}
		break;
	}

	case 'i': {

		string firstName;
		string lastName;
		string id;
		double grade;

		cout << endl << "Please enter the first name: ";
		cin >> firstName;
		firstName = this->lowerCaseString(firstName);
		firstName[0] = toupper(firstName[0]);
		cout << endl;

		cout << "Please enter the last name: ";
		cin >> lastName;
		lastName = this->lowerCaseString(lastName);
		lastName[0] = toupper(lastName[0]);
		cout << endl;

		cout << "Please enter the ID: ";
		cin >> id;
		cout << endl;

		cout << "Please enter the grade: ";

		while (!(cin >> grade) || grade < 0) {
			cin.clear();
			cout << "Please enter a valid number for the grade." << endl;
		}

		cout << endl;

		cout << this->controller.InsertStudent(firstName, lastName, id, grade)
				<< endl;
		break;
	}

	case 'd': {
		string studentID;
		cout << endl
				<< "Please enter the student ID of the student you would like to remove: "
				<< endl;
		cin >> studentID;
		cout << endl << this->controller.DeleteStudent(studentID);
		break;
	}

	case 'a': {
		cout << endl << "The students in alphabetic order are: " << endl;
		resultVector = this->controller.AlphabeticList();
		this->outputVector(resultVector);
		break;
	}

	case 'v': {
		cout << endl << "The students in reverse alphabetic order are: "
				<< endl;
		resultVector = this->controller.ReverseAlphabetic();
		this->outputVector(resultVector);
		break;
	}

	case 'g': {
		cout << endl << "The students in grade ascending are: " << endl;
		resultVector = this->controller.GradeAscending();
		this->outputVector(resultVector);
		break;
	}

	case 'c': {
		cout << endl << "The students in grade descending are: " << endl;
		resultVector = this->controller.GradeDescending();
		this->outputVector(resultVector);
		break;
	}

	case 'q': {
		cout << endl << "Good bye." << endl;
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
 * Handles action if the file to be saved already exists.
 * Lets the user choose if they want to overwrite or not.
 * @param response
 * The user's response.
 * @param file
 * the file that will output the data.
 */
void GradeBraiderTUI::handleResponse(string response, string file) {

	while (response.length() > 1) {
		cout << "Please enter y or n." << endl;
		cin >> response;
	}

	char yesOrNo = tolower(response[0]);

	if (yesOrNo == 'y') {
		this->controller.SaveFile(file);
	} else {
		return;
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
