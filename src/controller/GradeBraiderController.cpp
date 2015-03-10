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

/**
 * Constructor of class
 */
GradeBraiderController::GradeBraiderController() {
	// TODO Auto-generated constructor stub

}

/**
 * destructor of class.
 */
GradeBraiderController::~GradeBraiderController() {
	// TODO Auto-generated destructor stub
}

/**
 * loads in list from file.
 * @param inFile
 * the passed in file.
 */
void GradeBraiderController::loadFile(string inFile) {
	vector<Student> resultVector;
	this->ioVariable.loadFromFile(inFile);

}

/**
 * Outputs list to a file
 * @param file
 * the string location of the file
 * @return
 * a string status about the process
 */
string controller::GradeBraiderController::saveFile(string file) {


	string saveStatus;
	saveStatus = "File was saved successfully";
	return saveStatus;
}

/**
 * Inserts a student from the user directly
 * @param firstName
 * the student's first name
 * @param lastName
 * the student's last name
 * @param ID
 * the student's ID
 * @param grade
 * the student's grade.
 * @return
 *
 */
string controller::GradeBraiderController::insertStudent(string firstName,
		string lastName, string ID, int grade) {

	if(this->list.CreateStudent(firstName, lastName, ID, grade)){
	return "Student Created successfully";
	}else{
		return "Student was not created.";
	}
}

/**
 * deletes a student based on the ID given by the user
 * @param studentID
 * the passed in ID from the user
 * @return
 * string message that user was successfully deleted or that it wasn't if student ID wasn't in list.
 */
string controller::GradeBraiderController::deleteStudent(string studentID) {

	if (this->list.DeleteStudentName(studentID)) {
		return "Student was successfully deleted.";
	} else {
		return "There is no student in the list with that ID";
	}

}

/**
 * generates alphabetic ordering of list
 * @return
 * vector containing all students alphabetically.
 */
vector<Student> GradeBraiderController::alphabeticList() {
	return this->list.AlphabeticList();
}

/**
 * reverses the alphabetic listing of students
 * @return
 * a vector with the students in reverse alphabetic order.
 */
vector<Student> GradeBraiderController::reverseAlphabetic() {
	return this->list.ReverseList();
}

/**
 * makes a list of all students by ascending grade
 * @return
 * a vector of students ordered by grade, ascending.
 */
vector<Student> controller::GradeBraiderController::gradeAscending() {
	return this->list.AscendingGrades();
}

/**
 * generates a listing of the students by descending grade order
 * @return
 * a list of all students ordered by grade.
 */
vector<Student> controller::GradeBraiderController::gradeDescending() {
	return this->list.DescendingGrades();
}

} /* namespace controller */

