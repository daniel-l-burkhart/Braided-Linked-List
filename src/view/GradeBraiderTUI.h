/*
 * GradeBraiderTUI.h
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#ifndef VIEW_GRADEBRAIDERTUI_H_
#define VIEW_GRADEBRAIDERTUI_H_
#include <GradeBraiderController.h>
#include <string>

using controller::GradeBraiderController;
using std::string;
using namespace std;

namespace view {

class GradeBraiderTUI {
private:

	GradeBraiderController controller;

public:
	GradeBraiderTUI();
	virtual ~GradeBraiderTUI();
	void runMenuSystem();
	void mainMenu();
	void handleSelection(string userSelection);
};

} /* namespace view */

#endif /* VIEW_GRADEBRAIDERTUI_H_ */
