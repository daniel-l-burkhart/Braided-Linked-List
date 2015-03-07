/*
 * GradeBraiderController.h
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#ifndef CONTROLLER_GRADEBRAIDERCONTROLLER_H_
#define CONTROLLER_GRADEBRAIDERCONTROLLER_H_
#include <BraidedLinkedList.h>
#include <fileInputAndOutput.h>
#include <string>
#include <vector>

using model::BraidedLinkedList;
using model::fileInputAndOutput;

namespace controller {

class GradeBraiderController {
private:
	fileInputAndOutput ioVariable;
	BraidedLinkedList list;
public:
	GradeBraiderController();
	virtual ~GradeBraiderController();
	vector<string> loadFile(string file);
	string saveFile(string file);
	string insertStudent(string firstName, string lastName, string ID, int grade);
	string deleteStudent(string studentID);
	string alphabeticList();
	string reverseAlphabetic();
	string gradeAscending();
	string gradeDescending();


};

} /* namespace controller */

#endif /* CONTROLLER_GRADEBRAIDERCONTROLLER_H_ */
