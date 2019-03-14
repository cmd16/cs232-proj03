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
#include <string.h>
using namespace std;

CommandLineTester::CommandLineTester() {
	// TODO Auto-generated constructor stub

}

void CommandLineTester::runTests() {
	testConstructor();
}

void CommandLineTester::testConstructor() {
	cout << "Testing constructor... " << flush;
	string infilename = "cl_test_0.txt";
	ifstream fin(infilename.c_str());
	assert(fin.is_open());
	CommandLine c0 = CommandLine(fin);
	fin.close();
	assert(c0.getArgCount() == 1);
	assert(c0.noAmpersand());
	assert(strcmp(c0.getCommand(), "ps") == 0);
	cout << "0 " << flush;

	infilename = "cl_test_01.txt";
	ifstream fin1(infilename.c_str());
	assert(fin1.is_open());
	CommandLine c1 = CommandLine(fin1);
	fin1.close();
	assert(c1.getArgCount() == 5);
	assert(! c1.noAmpersand());
	assert(strcmp(c1.getCommand(), "ls") == 0);
	assert(strcmp(c1.getArgVector(1), "..") == 0);
	assert(strcmp(c1.getArgVector(2), "-a") == 0);
	assert(strcmp(c1.getArgVector(3), "--directory") == 0);
	assert(strcmp(c1.getArgVector(4), "&") == 0);
	cout << "1 " << flush;
	cout << "Passed!" << endl;
}

CommandLineTester::~CommandLineTester() {
	// TODO Auto-generated destructor stub
}

