//============================================================================
// Name        : DanielBurkhartGradeBraider.cpp
// Author      : Daniel Burkhart
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <GradeBraiderTUI.h>
#include <iostream>
#include <vector>
#include <string>

using controller::GradeBraiderController;
using view::GradeBraiderTUI;

using namespace std;

/**
 * Main method of program
 * @param argc
 * arg count
 * @param argv
 * the args passed in through the command line
 * @return
 * 0 if successful.
 */
int main(int argc, const char * argv[]) {

	GradeBraiderController controller = GradeBraiderController();
	GradeBraiderTUI tui = GradeBraiderTUI();

	if (argc != 1) {

		tui.LoadFileFromCommandLine(argv[1]);
		tui.runMenuSystem();
	} else {

		tui.runMenuSystem();
	}

	return 0;
}
