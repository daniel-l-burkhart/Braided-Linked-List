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

public:
	BraidedLinkedList();
	virtual ~BraidedLinkedList();
	void InsertStudentName(Student* pStudent);
	bool DeleteStudentName(string studentID);
	Student* CreateStudent(string firstName, string lastName, string ID,
			int grade);
};

} /* namespace model */

#endif /* MODEL_BRAIDEDLINKEDLIST_H_ */
