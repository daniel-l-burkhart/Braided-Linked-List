/*
 * Node.h
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#ifndef MODEL_STUDENT_H_
#define MODEL_STUDENT_H_

#include <string>

using namespace std;

namespace model {

class Student {
private:

	string firstName;
	string lastName;
	string ID;
	int grade;

public:
	Student();
	Student(string lastName, string firstName, string ID, int grade,
			Student* nextName, Student* nextGrade);
	virtual ~Student();

	const string& getId() const;
	const string& getFirstName() const;
	int getGrade() const;
	const string& getLastName() const;

	Student* nextName;
	Student* nextGrade;
};

} /* namespace model */

#endif /* MODEL_STUDENT_H_ */
