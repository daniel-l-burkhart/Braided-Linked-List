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
	ifstream inputStream;
	ofstream outputStream;
	BraidedLinkedList student;
	void split(string line, char c, vector<string> studentData);
public:
	fileInputAndOutput();
	virtual ~fileInputAndOutput();

	void loadFromFile(string file);
	void saveToFile(string file, Student* pHead);

};

} /* namespace model */

#endif /* MODEL_FILEINPUTANDOUTPUT_H_ */
