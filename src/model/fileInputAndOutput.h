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
public:
	fileInputAndOutput();
	virtual ~fileInputAndOutput();

	vector<string> loadFromFile(string file);

};

} /* namespace model */

#endif /* MODEL_FILEINPUTANDOUTPUT_H_ */
