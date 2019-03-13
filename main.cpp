/*
 * main.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: cmd38
 */

#include "CommandLineTester.h"

int main(int argc, char* argv) {
	CommandLineTester ClTester = CommandLineTester();
	ClTester.runTests();
	return 0;
}

