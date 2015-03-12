/*
 * fileInputAndOutput.h
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#ifndef MODEL_FILEINPUTANDOUTPUT_H_
#define MODEL_FILEINPUTANDOUTPUT_H_

#include <BraidedLinkedList.h>
#include <string>
#include<vector>
#include <fstream>

using namespace std;

namespace model {

class fileInputAndOutput {
private:

	BraidedLinkedList student;
	vector<string> split(string line, char c);
	vector<Student> getLineFromFile(string line,
			ifstream& input);

public:
	fileInputAndOutput();
	virtual ~fileInputAndOutput();

	vector<Student> loadFromFile(string file);
	void saveToFile(string file, vector<Student> listOfStudents);

};

} /* namespace model */

#endif /* MODEL_FILEINPUTANDOUTPUT_H_ */
