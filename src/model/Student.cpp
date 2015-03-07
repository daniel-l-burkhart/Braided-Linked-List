/*
 * Node.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <Student.h>

namespace model {

Student::Student() {
	grade = 0;
	nextName = 0;
	nextGrade = 0;

}

Student::Student(string firstName, string lastName, string ID, double grade, Student* nextName, Student* nextGrade){
	this->firstName = firstName;
	this->lastName = lastName;
	this->ID = ID;
	this->grade = grade;
	this->nextName = nextName;
	this->nextGrade = nextGrade;
}



Student::~Student() {
	// TODO Auto-generated destructor stub
}

} /* namespace model */

const string& model::Student::getId() const {
	return ID;
}

const string& model::Student::getFirstName() const {
	return firstName;
}

double model::Student::getGrade() const {
	return grade;
}

const string& model::Student::getLastName() const {
	return lastName;
}
