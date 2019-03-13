/*
 * CommandLineTester.h
 *
 *  Created on: Mar 13, 2019
 *      Author: cmd38
 */

#ifndef COMMANDLINETESTER_H_
#define COMMANDLINETESTER_H_

#include "CommandLine.h"

class CommandLineTester {
public:
	CommandLineTester();
	void runTests();
	void testConstructor();
	virtual ~CommandLineTester();
};

#endif /* COMMANDLINETESTER_H_ */
