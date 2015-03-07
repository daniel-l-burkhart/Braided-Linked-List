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
	Student* pHead;
	Student* pTail;
	void insertStudentName(Student* pStudent);
	void insertStudentGrade(Student* pStudent);

public:
	BraidedLinkedList();
	virtual ~BraidedLinkedList();

	bool DeleteStudentName(string studentID);
	void CreateStudent(string firstName, string lastName, string ID,
			int grade);
	void CreateListFromFile(vector<Student> vectorOfStudents);
};

} /* namespace model */

#endif /* MODEL_BRAIDEDLINKEDLIST_H_ */
