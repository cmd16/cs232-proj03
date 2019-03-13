/*
 * CommandLine.h
 *
 *  Created on: Mar 13, 2019
 *      Author: cmd38
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
using namespace std;

class CommandLine {
public:
	CommandLine(istream& in);
	virtual ~CommandLine();
};

#endif /* COMMANDLINE_H_ */
