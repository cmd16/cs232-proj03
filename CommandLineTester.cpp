/*
 * CommandLineTester.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: cmd38
 */

#include "CommandLineTester.h"
#include <cassert>
#include <istream>
#include <fstream>
using namespace std;

CommandLineTester::CommandLineTester() {
	// TODO Auto-generated constructor stub

}

void CommandLineTester::runTests() {
	testConstructor();
}

void CommandLineTester::testConstructor() {
	string infilename = "cl_test_01.txt";
	ifstream fin(infilename.c_str());
	assert(fin.is_open());
	CommandLine c0 = CommandLine(fin);
}

CommandLineTester::~CommandLineTester() {
	// TODO Auto-generated destructor stub
}

