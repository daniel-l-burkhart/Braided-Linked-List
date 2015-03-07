/*
 * BraidedLinkedList.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#include <BraidedLinkedList.h>

namespace model {

BraidedLinkedList::BraidedLinkedList() {
	pHead = 0;
	pTail = 0;
}

void BraidedLinkedList::insertStudentName(Student *pStudent) {
	if (pHead == 0) {
		this->pHead = pStudent;
	}

	else {
		Student* pCurrent = this->pHead;
		Student* pPrevious = this->pHead;

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

	if (pHead == 0) {
		this->pHead = pStudent;
	}

	else {
		Student* pCurrent = this->pHead;
		Student* pPrevious = this->pHead;

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
	pCurrent = this->pHead;
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

	if (pHead == pStudentToDelete) {

		pDeletePtr = pHead;

		pHead = pDeletePtr->nextName;
		delete pDeletePtr;
		return true;
	}

	pPrevious = pHead;
	pDeletePtr = pHead->nextName;

	while (pDeletePtr != 0) {

		if (pDeletePtr == pStudentToDelete) {

			pPrevious->nextName = pDeletePtr->nextName;

			if (pDeletePtr == pTail) {
				pTail = pPrevious;
			}
			delete pDeletePtr;
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
	Student* pCurrent = pHead;

	while (pCurrent != 0) {
		Student *temp = pCurrent;
		pCurrent = pCurrent->nextName;
		delete temp;
		temp = 0;
	}
}

void model::BraidedLinkedList::CreateListFromFile(
		vector<Student> vectorOfStudents) {
}

} /* namespace model */

