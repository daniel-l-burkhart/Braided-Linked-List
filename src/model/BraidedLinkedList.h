/*
 * BraidedLinkedList.h
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#ifndef MODEL_BRAIDEDLINKEDLIST_H_
#define MODEL_BRAIDEDLINKEDLIST_H_

#include <Student.h>
#include<vector>

using namespace std;

namespace model {

class BraidedLinkedList {

private:
	Student* pHeadName;
	Student* pHeadGrade;
	Student* pTailName;

	vector<Student> reversedList;
	vector<Student> reversedGrades;

	void insertStudentName(Student* pStudent);
	void insertStudentGrade(Student* pStudent);
	void makeGradeVector(Student* pCurrent, vector<Student>& studentGrades);
	void makeNameVector(Student* pCurrent, vector<Student>& students);

	void makeReverseNameVector(Student* pHead);
	void makeGradeDescendVector(Student* pStudentGrade);
	void checkForTail(Student* pDeletePtr, Student* pPrevious);
	void checkForPreviousGrade(Student* pPrevious, Student* pStudent);
	void checkForPreviousName(Student* pPrevious, Student* pStudent);

	void clearList();

public:
	BraidedLinkedList();
	virtual ~BraidedLinkedList();

	bool DeleteStudentName(string studentID);
	void CreateStudent(string lastName, string firstName, string ID, int grade);

	void CreateListFromFile(vector<Student> &vectorOfStudents);

	vector<Student> AlphabeticList();
	vector<Student> AscendingGrades();
	vector<Student> ReverseList();
	vector<Student> DescendingGrades();

};

} /* namespace model */

#endif /* MODEL_BRAIDEDLINKEDLIST_H_ */
