/*
 * fileInputAndOutput.h
 *
 *  Created on: Feb 27, 2015
 *      Author: dburkha1
 */

#ifndef MODEL_FILEINPUTANDOUTPUT_H_
#define MODEL_FILEINPUTANDOUTPUT_H_

#include <string>
#include<vector>

using namespace std;

namespace model {

class fileInputAndOutput {
private:
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
