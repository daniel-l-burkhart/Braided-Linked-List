/*
 * BraidedLinkedList.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <BraidedLinkedList.h>

namespace model {

BraidedLinkedList::BraidedLinkedList() {
	this->pHeadName = 0;
	this->pHeadGrade = 0;
	this->pTailGrade = 0;
	this->pTailName = 0;
}

void BraidedLinkedList::insertStudentName(Student *pStudent) {
	if (this->pHeadName == 0) {
		this->pHeadName = pStudent;
	}

	else {
		Student* pCurrent = this->pHeadName;
		Student* pPrevious = this->pHeadName;

		while (pCurrent != 0) {

			if (pStudent->getLastName() < pCurrent->getLastName()) {
				pPrevious = pStudent;
				pStudent->nextName = pCurrent;
				return;
			}

			else {
				pPrevious = pCurrent;
				pCurrent = pStudent->nextName;
			}
		}
	}
}

void BraidedLinkedList::insertStudentGrade(Student *pStudent) {

	if (this->pHeadGrade == 0) {
		this->pHeadGrade = pStudent;
	}

	else {
		Student* pCurrent = this->pHeadGrade;
		Student* pPrevious = this->pHeadGrade;

		while (pCurrent != 0) {

			if (pStudent->getGrade() < pCurrent->getGrade()) {
				pPrevious = pStudent;
				pStudent->nextName = pCurrent;
				return;
			}

			else {
				pPrevious = pCurrent;
				pCurrent = pStudent->nextName;
			}
		}
	}
}

bool BraidedLinkedList::DeleteStudentName(string studentID) {

	Student *pStudentToDelete;
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

			if (pDeletePtr == this->pTailName) {
				this->pTailName = pPrevious;
			}
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

void BraidedLinkedList::CreateStudent(string firstName, string lastName,
		string ID, int grade) {
	Student *createdStudent = new Student(firstName, lastName, ID, grade, 0, 0);

	this->insertStudentName(createdStudent);
	this->insertStudentGrade(createdStudent);
}

BraidedLinkedList::~BraidedLinkedList() {
	Student* pCurrent = this->pHeadName;

	while (pCurrent != 0) {
		Student *temp = pCurrent;
		pCurrent = pCurrent->nextName;
		delete temp;
		temp = 0;
	}
}

void BraidedLinkedList::CreateListFromFile(vector<Student> vectorOfStudents) {
}

void BraidedLinkedList::makeNameVector(Student* pCurrent,
		vector<Student>& students) {
	while (pCurrent != 0) {
		students.push_back(*pCurrent);
		Student* temp = pCurrent;
		pCurrent = temp->nextName;
	}
}

vector<Student> BraidedLinkedList::AlphabeticList() {
	vector<Student> students = vector<Student>();

	if (this->pHeadName != 0) {
		Student *pCurrent = this->pHeadName;
		this->makeNameVector(pCurrent, students);
	}

	return students;
}

void BraidedLinkedList::makeGradeVector(Student* pCurrent,
		vector<Student>& studentGrades) {
	while (pCurrent != 0) {
		studentGrades.push_back(*pCurrent);
		Student* temp = pCurrent;
		pCurrent = temp->nextGrade;
	}
}

vector<Student> BraidedLinkedList::AscendingGrades() {
	vector<Student> studentGrades = vector<Student>();

	if (this->pHeadGrade != 0) {

		Student *pCurrent = this->pHeadGrade;

		this->makeGradeVector(pCurrent, studentGrades);
	}
	return studentGrades;
}

vector<Student> BraidedLinkedList::ReverseList() {
	vector<Student> resultingVector = vector<Student>();

	this->makeReverseNameVector(this->pHeadName);
	resultingVector = this->reversedList;

	this->reversedList.clear();
	return resultingVector;
}

void BraidedLinkedList::makeReverseNameVector(Student* pStudent) {
	if (pStudent != 0) {
		this->makeReverseNameVector(pStudent->nextName);
		this->reversedList.push_back(*pStudent);
	}
}

void BraidedLinkedList::makeGradeDescendVector(Student* pStudentGrade) {
	if (pStudentGrade != 0) {
		this->makeGradeDescendVector(pStudentGrade->nextGrade);
		this->reversedGrades.push_back(*pStudentGrade);
	}
}

vector<Student> BraidedLinkedList::DescendingGrades() {
	vector<Student> gradesReversed = vector<Student>();

	this->makeGradeDescendVector(this->pHeadGrade);
	gradesReversed = this->reversedGrades;
	this->reversedGrades.clear();

	return gradesReversed;
}

} /* namespace model */

