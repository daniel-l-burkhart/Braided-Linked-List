/*
 * GradeBraiderController.h
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#ifndef CONTROLLER_GRADEBRAIDERCONTROLLER_H_
#define CONTROLLER_GRADEBRAIDERCONTROLLER_H_

#include "BraidedLinkedList.h"
#include "fileInputAndOutput.h"
#include "GradeBraiderController.h"
#include "Student.h"

#include <string>
#include <vector>

using model::BraidedLinkedList;
using model::fileInputAndOutput;
using model::Student;

namespace controller {

class GradeBraiderController {

private:
	fileInputAndOutput ioVariable;
	BraidedLinkedList list;

public:
	GradeBraiderController();
	virtual ~GradeBraiderController();

	string LoadFile(string file);
	string SaveFile(string file);
	string InsertStudent(string lastName, string firstName, string ID, int grade);
	string DeleteStudent(string studentID);

	vector<Student> AlphabeticList();
	vector<Student> ReverseAlphabetic();
	vector<Student> GradeAscending();
	vector<Student> GradeDescending();

};

} /* namespace controller */

#endif /* CONTROLLER_GRADEBRAIDERCONTROLLER_H_ */
