/*
 * main.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: cmd38
 */

#include "CommandLineTester.h"
#include "PathTester.h"
#include "CDShell.h"

int main() {
// 	CommandLineTester ClTester = CommandLineTester();
// 	ClTester.runTests();
   PathTester PTester;
	PTester.runTests();
	// CDShell shell;
	// shell.run();
	return 0;
}

