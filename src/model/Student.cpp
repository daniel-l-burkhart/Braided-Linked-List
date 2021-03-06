/*
 * Student.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include "Student.h"

namespace model {

/**
 * Constructor of the class
 */
Student::Student() {
	this->grade = 0;
	this->nextName = 0;
	this->nextGrade = 0;

}

/**
 * Constructor of class with all variables associated with the object.
 * @param firstName
 * The student's first name.
 * @param lastName
 * The student's last name.
 * @param ID
 * the student's ID
 * @param grade
 * The student's grade
 * @param nextName
 * The pointer to the next student by name
 * @param nextGrade
 * The pointer to the next student by grade.
 */
Student::Student(string lastName, string firstName, string ID, int grade,
		Student* nextName, Student* nextGrade) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->ID = ID;
	this->grade = grade;
	this->nextName = nextName;
	this->nextGrade = nextGrade;
}

/**
 * destructor of class
 */
Student::~Student() {
	// TODO Auto-generated destructor stub
}

/**
 * Gets the ID
 * @return
 * the student's ID
 */
const string& model::Student::getId() const {
	return ID;
}

/**
 * gets the first name
 * @return
 * the student's first name
 */
const string& model::Student::getFirstName() const {
	return firstName;
}

/**
 * gets the grade.
 * @return
 * the student's grade.
 */
int model::Student::getGrade() const {
	return grade;
}

/**
 * gets the last name
 * @return
 * the student's last name.
 */
const string& model::Student::getLastName() const {
	return lastName;
}

} /* namespace model */


