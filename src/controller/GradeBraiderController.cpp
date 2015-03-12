/*
 * GradeBraiderController.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <fileInputAndOutput.h>
#include <GradeBraiderController.h>
#include <Student.h>
#include <string>
#include <vector>

using model::fileInputAndOutput;
using model::Student;

using namespace std;

namespace controller {

/**
 * Constructor of class
 */
GradeBraiderController::GradeBraiderController() {
	this->list = BraidedLinkedList();
	this->ioVariable = fileInputAndOutput();
}

/**
 * destructor of class.
 */
GradeBraiderController::~GradeBraiderController() {

}

/**
 * loads in list from file.
 * @param inFile
 * the passed in file.
 */
string GradeBraiderController::LoadFile(string inFile) {

	vector<Student> resultVector;
	resultVector = this->ioVariable.LoadFromFile(inFile);

	if (resultVector.size() > 0) {
		this->list.CreateListFromFile(resultVector);

		return "The file was loaded successfully.";
	}

	return "The file does not exist or could not be found.";

}

/**
 * Outputs list to a file
 * @param file
 * the string location of the file
 * @return
 * a string status about the process
 */
string controller::GradeBraiderController::SaveFile(string file) {

	vector<Student> alphabeticList = this->list.AlphabeticList();

	if(this->ioVariable.SaveToFile(file, alphabeticList)){
		return "File was saved successfully.";
	}

	return "File was not saved successfully.";
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
string controller::GradeBraiderController::InsertStudent(string firstName,
		string lastName, string ID, int grade) {

	this->list.CreateStudent(lastName, firstName, ID, grade);
	return "Student Created successfully";

}

/**
 * deletes a student based on the ID given by the user
 * @param studentID
 * the passed in ID from the user
 * @return
 * string message that user was successfully deleted or that it wasn't if student ID wasn't in list.
 */
string controller::GradeBraiderController::DeleteStudent(string studentID) {

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
vector<Student> GradeBraiderController::AlphabeticList() {
	return this->list.AlphabeticList();
}

/**
 * reverses the alphabetic listing of students
 * @return
 * a vector with the students in reverse alphabetic order.
 */
vector<Student> GradeBraiderController::ReverseAlphabetic() {
	return this->list.ReverseList();
}

/**
 * makes a list of all students by ascending grade
 * @return
 * a vector of students ordered by grade, ascending.
 */
vector<Student> controller::GradeBraiderController::GradeAscending() {
	return this->list.AscendingGrades();
}

/**
 * generates a listing of the students by descending grade order
 * @return
 * a list of all students ordered by grade.
 */
vector<Student> controller::GradeBraiderController::GradeDescending() {
	return this->list.DescendingGrades();
}

} /* namespace controller */

