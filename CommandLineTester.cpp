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
	cout << "Testing constructor..." << flush;
	string infilename = "cl_test_01.txt";
	ifstream fin(infilename.c_str());
	assert(fin.is_open());
	CommandLine c0 = CommandLine(fin);
	assert(c0.getArgCount() == 1);
	//assert(c0.noAmpersand());
	assert(c0.getArgVector(0) == "ps");
	cout << " 0 " << flush;
	cout << "passed!" << endl;
}

CommandLineTester::~CommandLineTester() {
	// TODO Auto-generated destructor stub
}

