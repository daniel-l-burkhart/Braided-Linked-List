/*
 * GradeBraiderController.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <GradeBraiderController.h>
#include <Student.h>
#include <iosfwd>
#include <string>
#include <fstream>
#include <vector>

using model::Student;

using namespace std;

namespace controller {



GradeBraiderController::GradeBraiderController() {
	// TODO Auto-generated constructor stub

}

GradeBraiderController::~GradeBraiderController() {
	// TODO Auto-generated destructor stub
}

void GradeBraiderController::loadFile(string inFile){
	vector<Student> resultVector;
	this->ioVariable.loadFromFile(inFile);

}

string controller::GradeBraiderController::saveFile(string file) {

	fstream saveFile;

	//saveFile.open(file.c_str(), ios_base::out| file.c_str(), ios_base::in);

	string saveStatus;
	saveStatus = "File was saved successfully";
	return saveStatus;
}

string controller::GradeBraiderController::insertStudent(string firstName,
		string lastName, string ID, int grade) {

	this->list.CreateStudent(firstName, lastName, ID, grade);
	return "Student Created successfully";
}

string controller::GradeBraiderController::deleteStudent(string studentID) {

	if(this->list.DeleteStudentName(studentID)){
		return "Student was successfully deleted.";
	}
	else{
		return "There is no student in the list with that ID";
	}

}

vector<Student> GradeBraiderController::alphabeticList() {
	return this->list.AlphabeticList();
}

vector<Student> GradeBraiderController::reverseAlphabetic() {
	return this->list.ReverseList();
}

vector<Student> controller::GradeBraiderController::gradeAscending() {
	return this->list.AscendingGrades();
}

vector<Student> controller::GradeBraiderController::gradeDescending() {
	return this->list.DescendingGrades();
}

} /* namespace controller */


