/*
 * Node.h
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#ifndef MODEL_STUDENT_H_
#define MODEL_STUDENT_H_
#include <iosfwd>
#include <string>


using namespace std;

namespace model {

class Student {
private:
	string firstName;
	string lastName;
	string ID;
	double grade;

	void Insert(Student* pStudent);
	void Delete();

public:
	Student();
	Student(string firstName, string lastName, string ID, double grade, Student* nextName, Student* nextGrade);
	virtual ~Student();

	double getGrade() const {
		return grade;
	}

	const string& getLastName() const {
		return lastName;
	}

	const string& getId() const;

	Student* nextName;
		Student* nextGrade;
};


} /* namespace model */

#endif /* MODEL_STUDENT_H_ */
