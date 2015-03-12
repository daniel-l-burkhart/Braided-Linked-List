/*
 * GradeBraiderTUI.h
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#ifndef VIEW_GRADEBRAIDERTUI_H_
#define VIEW_GRADEBRAIDERTUI_H_
#include <GradeBraiderController.h>
#include <Student.h>
#include <string>
#include <vector>

using controller::GradeBraiderController;
using std::string;
using namespace std;

namespace view {

class GradeBraiderTUI {
private:

	GradeBraiderController controller;
	void outputVector(vector<Student> studentVector);

	void mainMenu();
	void handleSelection(string userSelection);
	string lowerCaseString(string input);
	bool fileExists(string file);
	void handleResponse(string response, string file);

public:
	GradeBraiderTUI();
	virtual ~GradeBraiderTUI();
	void runMenuSystem();
	void LoadFileFromCommandLine(string file);

};

} /* namespace view */

#endif /* VIEW_GRADEBRAIDERTUI_H_ */
