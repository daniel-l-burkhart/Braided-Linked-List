/*
 * BraidedLinkedList.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <BraidedLinkedList.h>
#include <iostream>

using namespace std;

namespace model {

/**
 * Constructor of the class. Initializes everything to 0
 */
BraidedLinkedList::BraidedLinkedList() {
	this->pHeadName = 0;
	this->pHeadGrade = 0;
	this->pTailName = 0;
}

void BraidedLinkedList::checkForPreviousName(Student* pPrevious,
		Student* pStudent) {

	if (!pPrevious) {
		this->pHeadName = pStudent;
	}

	else {
		pPrevious->nextName = pStudent;
	}
}

/**
 * inserts student and sets Name pointers
 * @param pStudent
 * the pointer to the current student.
 */
void BraidedLinkedList::insertStudentName(Student *pStudent) {

	if (this->pHeadName == 0) {
		this->pHeadName = pStudent;
		return;
	}

	Student* pCurrent = this->pHeadName;
	Student* pPrevious = 0;

	while (pCurrent) {

		if (pStudent->getLastName().compare(pCurrent->getLastName()) < 0) {

			pStudent->nextName = pCurrent;
			this->checkForPreviousName(pPrevious, pStudent);
			return;

		}

		pPrevious = pCurrent;
		pCurrent = pCurrent->nextName;
	}

	pPrevious->nextName = pStudent;

}

/**
 * Checks if the previous grade is valid in order to
 * cause deletion to work successfully.
 * @param pPrevious
 * the previous node.
 * @param pStudent
 * the current student node.
 */
void BraidedLinkedList::checkForPreviousGrade(Student* pPrevious,
		Student* pStudent) {
	if (!pPrevious) {
		this->pHeadGrade = pStudent;
	} else {
		pPrevious->nextGrade = pStudent;
	}
}

/**
 * Inserts student and sets grade pointers.
 * @param pStudent
 * The current student pointer.
 */
void BraidedLinkedList::insertStudentGrade(Student *pStudent) {

	if (this->pHeadGrade == 0) {
		this->pHeadGrade = pStudent;

		return;
	}

	Student* pCurrent = this->pHeadGrade;
	Student* pPrevious = 0;

	while (pCurrent) {

		if (pStudent->getGrade() < pCurrent->getGrade()) {

			pStudent->nextGrade = pCurrent;

			this->checkForPreviousGrade(pPrevious, pStudent);
			return;
		}

		pPrevious = pCurrent;
		pCurrent = pCurrent->nextGrade;

	}

	pPrevious->nextGrade = pStudent;

}

void BraidedLinkedList::checkForTail(Student* pDeletePtr, Student* pPrevious) {
	if (pDeletePtr == this->pTailName) {
		this->pTailName = pPrevious;
	}
}

/**
 * finds student with passed in ID and deletes that object from the list.
 * @param studentID
 * the student ID
 * @return
 * true if ID was in list, false otherwise.
 */
bool BraidedLinkedList::DeleteStudentName(string studentID) {

	Student *pStudentToDelete = 0;
	Student *pCurrent;
	pCurrent = this->pHeadName;
	while (pCurrent != 0) {

		if (pCurrent->getId() == studentID) {
			pStudentToDelete = pCurrent;
			break;
		}

		else {
			Student *temp = pCurrent;
			pCurrent = temp->nextName;
		}
	}

	Student *pPrevious = 0;
	Student *pDeletePtr = 0;

	if (this->pHeadName == pStudentToDelete) {

		pDeletePtr = this->pHeadName;

		this->pHeadName = pDeletePtr->nextName;

		delete pDeletePtr;
		pDeletePtr = 0;
		return true;
	}

	pPrevious = this->pHeadName;
	pDeletePtr = this->pHeadName->nextName;

	while (pDeletePtr != 0) {

		if (pDeletePtr == pStudentToDelete) {

			pPrevious->nextName = pDeletePtr->nextName;

			this->checkForTail(pDeletePtr, pPrevious);

			delete pDeletePtr;
			pDeletePtr = 0;
			return true;
			break;
		}
		pPrevious = pDeletePtr;
		pDeletePtr = pDeletePtr->nextName;
	}
	return false;

}

/**
 * Creates a new student object.
 * @param firstName
 * The student's first name
 * @param lastName
 * The student's last name
 * @param ID
 * The student's ID
 * @param grade
 * The student's grade.
 */
void BraidedLinkedList::CreateStudent(string lastName, string firstName,
		string ID, int grade) {

	Student *createdStudent = new Student(lastName, firstName, ID, grade, 0, 0);

	this->insertStudentGrade(createdStudent);

	this->insertStudentName(createdStudent);

}

/**
 * Creates the student list from a vector of students loaded from the file
 * @param vectorOfStudents
 * the vector of student objects
 */
void BraidedLinkedList::CreateListFromFile(vector<Student>& vectorOfStudents) {

	this->clearList();

	for (vector<Student>::size_type i = 0; i < vectorOfStudents.size(); i++) {

		this->CreateStudent(vectorOfStudents[i].getLastName(),
				vectorOfStudents[i].getFirstName(), vectorOfStudents[i].getId(),
				vectorOfStudents[i].getGrade());

	}
	vector<Student> currentList = this->AlphabeticList();
	for(vector<Student>::size_type j = 0; j<currentList.size(); j++){
		cout << currentList[j].getLastName() << endl;
	}

}

/**
 * Clears the list and deletes all nodes.
 */
void BraidedLinkedList::clearList() {

	Student *pDel = this->pHeadName;

	while (pDel != 0) {

		this->pHeadName = this->pHeadName->nextName;

		delete pDel;
		pDel = 0;
		pDel = this->pHeadName;
	}
	this->pHeadName = 0;
	this->pHeadGrade = 0;
	this->pTailName = 0;
}

/**
 * Deconstructor of class. Deletes all nodes on heap.
 */
BraidedLinkedList::~BraidedLinkedList() {
	this->clearList();
}

/**
 * makes vector of students in list to be output to the user
 * @param pCurrent
 * The current pointer.
 * @param students
 * The vector of students
 */
void BraidedLinkedList::makeNameVector(Student* pCurrent,
		vector<Student>& students) {

	while (pCurrent != 0) {
		students.push_back(*pCurrent);
		Student* temp = pCurrent;
		pCurrent = temp->nextName;
	}
}

/**
 * creates and returns vector of students to be returned to the user in an alphabetized listing.
 * @return
 * a vector of students in alphabetical order.
 */
vector<Student> BraidedLinkedList::AlphabeticList() {
	vector<Student> students = vector<Student>();

	if (this->pHeadName != 0) {

		Student *pCurrent = this->pHeadName;
		this->makeNameVector(pCurrent, students);

	}

	return students;
}

/**
 * makes the vector for the grades ascending
 * @param pCurrent
 * current pointer
 * @param studentGrades
 * vector of students
 */
void BraidedLinkedList::makeGradeVector(Student* pCurrent,
		vector<Student>& studentGrades) {

	while (pCurrent != 0) {
		studentGrades.push_back(*pCurrent);
		Student* temp = pCurrent;
		pCurrent = temp->nextGrade;
	}
}

/**
 * makes and returns the vector of students in ascending grades.
 * @return
 * vector of students ordered by ascending grades.
 */
vector<Student> BraidedLinkedList::AscendingGrades() {
	vector<Student> studentGrades = vector<Student>();

	if (this->pHeadGrade != 0) {

		Student *pCurrent = this->pHeadGrade;

		this->makeGradeVector(pCurrent, studentGrades);
	}
	return studentGrades;
}

/**
 * reverses the list of students by name
 * @return
 * the list of students in reverse order
 */
vector<Student> BraidedLinkedList::ReverseList() {
	vector<Student> resultingVector = vector<Student>();

	this->makeReverseNameVector(this->pHeadName);
	resultingVector = this->reversedList;

	this->reversedList.clear();
	return resultingVector;
}

/**
 * creates the vector that reverses the students
 * @param pStudent
 * the current student pointer
 */
void BraidedLinkedList::makeReverseNameVector(Student* pStudent) {
	if (pStudent != 0) {

		this->makeReverseNameVector(pStudent->nextName);
		this->reversedList.push_back(*pStudent);

	} else {
		return;
	}

}

/**
 * creates the vector that reverses the students by grade
 * @param pStudentGrade
 * current student pointer to grade.
 */
void BraidedLinkedList::makeGradeDescendVector(Student* pStudentGrade) {
	if (pStudentGrade != 0) {

		this->makeGradeDescendVector(pStudentGrade->nextGrade);
		this->reversedGrades.push_back(*pStudentGrade);

	} else {
		return;
	}

}

/**
 * reverses the list of students ordered by grade to be output by the user.
 * @return
 * a vector with the students in descending order by grade.
 */
vector<Student> BraidedLinkedList::DescendingGrades() {
	vector<Student> gradesReversed = vector<Student>();

	this->makeGradeDescendVector(this->pHeadGrade);
	gradesReversed = this->reversedGrades;
	this->reversedGrades.clear();

	return gradesReversed;
}

} /* namespace model */

