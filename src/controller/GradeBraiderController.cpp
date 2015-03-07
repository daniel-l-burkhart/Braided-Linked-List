/*
 * GradeBraiderController.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <GradeBraiderController.h>
#include <Student.h>
#include <string>

using model::Student;

using namespace std;

namespace controller {



GradeBraiderController::GradeBraiderController() {
	// TODO Auto-generated constructor stub

}

GradeBraiderController::~GradeBraiderController() {
	// TODO Auto-generated destructor stub
}

vector<string> GradeBraiderController::loadFile(string inFile){
	vector<Student> resultVector;
	resultVector = ioVariable.loadFromFile(inFile);
	this->list.CreateListFromFile(resultVector);
	return resultVector;
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

string controller::GradeBraiderController::alphabeticList() {
	return "";
}

string controller::GradeBraiderController::reverseAlphabetic() {
	return "";
}

string controller::GradeBraiderController::gradeAscending() {
	return "";
}

string controller::GradeBraiderController::gradeDescending() {
	return "";
}

} /* namespace controller */


