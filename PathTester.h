/*
 * PathTester.h
 *
 *  Created on: Mar 25, 2019, for CS 232 at Calvin College
 *      Author: Daniel Ackuaku
 */

#ifndef PATHTESTER_H_
#define PATHTESTER_H_
#include "Path.h"

class PathTester {
public:
	PathTester();
	void runTests();
	void testConstructor();
	void testFind();
	void testFindcmd38();
	virtual ~PathTester();
};

#endif /* PATHTESTER_H_ */
