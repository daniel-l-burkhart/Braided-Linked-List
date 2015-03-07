/*
 * GradeBraiderTUI.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <GradeBraiderController.h>
#include <GradeBraiderTUI.h>
#include <cstdlib>
#include <iosfwd>
#include <iostream>

using controller::GradeBraiderController;
using namespace controller;

using namespace std;

namespace view {

GradeBraiderTUI::GradeBraiderTUI() {

	this->controller = GradeBraiderController();
	runMenuSystem();

}

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

void GradeBraiderTUI::mainMenu() {
	cout << "Please enter the desired action: (l)oad file, (s)ave file, "
			<< endl
			<< "(i)nsert, (d)elete, (a)lphabetic, re(v)erse alphabetic, "
			<< endl << "(g)rade ascending, grade des(c)ending, (q)uit >"
			<< endl;
	cout << endl;
}

void GradeBraiderTUI::handleSelection(string input) {
	char userInput;
	userInput = input[0];
	userInput = tolower(userInput);

	string file;

	switch(userInput){
	case 'l':{
		cout << "Please enter the name of the file that you would like to load in" << endl;
		cin >> file;
		this->controller.loadFile(file);
		break;
	}
	case 's':{
		cout << "Please enter the name of the file that you would like to save the list as. " << endl;
		cin >> file;
		this->controller.saveFile(file);
		break;
	}
	case 'i':{

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
	case 'd':{
		string studentID;
		cout << "Please enter the student ID of the student you would like to remove: "<<endl;
		cin >> studentID;
		cout << this->controller.deleteStudent(studentID);
		break;
	}

	case 'a':{
		cout << "The students in alphabetic order are: "<< endl;
		cout << this->controller.alphabeticList();
		break;
	}

	case 'r':{
		cout << "The students in reverse alphabetic order are: "<< endl;
		cout << this->controller.reverseAlphabetic();
		break;
	}

	case 'g':{
		cout << "The students in grade ascending are: " << endl;
		cout << this->controller.gradeAscending();
		break;
	}

	case 'c':{
		cout << "The students in grade descending are: " << endl;
		cout << this->controller.gradeDescending();
		break;
	}

	case 'q':{
		cout << "Good bye." <<endl;
		exit(0);
		break;
	}

	}
}

GradeBraiderTUI::~GradeBraiderTUI() {
	// TODO Auto-generated destructor stub
}

} /* namespace view */
