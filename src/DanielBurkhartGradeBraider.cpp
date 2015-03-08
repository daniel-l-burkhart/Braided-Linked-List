//============================================================================
// Name        : DanielBurkhartGradeBraider.cpp
// Author      : Daniel Burkhart
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <GradeBraiderController.h>
#include <iostream>
#include<fstream>
#include <vector>
#include <string>

using controller::GradeBraiderController;

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
	GradeBraiderController controller;
	vector<string> stringVector;

	if (argc != 2)

		cout << "usage: " << argv[0] << " <filename>\n";
	else {

		ifstream the_file(argv[1]);

		if (!the_file.is_open())
			cout << "Could not open file\n";
		else {
			string x;

			while (getline(the_file, x)) {
				cout << x;
			}

		}

	}
	return 0;
}
