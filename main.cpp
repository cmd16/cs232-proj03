/*
 * main.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: cmd38
 */

#include "CommandLineTester.h"
#include "PathTester.h"
#include "CDShell.h"

int main(int argc, char* argv) {
//	CommandLineTester ClTester = CommandLineTester();
//	ClTester.runTests();
//    PathTester runTests;
//	runTests.testConstructor();
//	runTests.testFind();
	CDShell shell;
	shell.run();
	return 0;
}

