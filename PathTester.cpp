/*
 * PathTester.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: dma2
 */

#include "PathTester.h"
#include "Path.h"

vector<string> dir;
PathTester::PathTester() {
	// TODO Auto-generated constructor stub

}

void PathTester::testConstructor(){
	Path test;
	char *testSize;
	testSize = getenv("PATH");

	cout << testSize << endl;
	dir = test.returnDIR();
	// cout << "\n" << endl;
	cout << dir.size() << endl;
	for (unsigned i = 0 ; i < dir.size(); i++ ) {
			cout <<  dir[i] << endl;
			
	}
	// assert
}

void PathTester::testFind() {

	Path test;
	dir = test.returnDIR();

	dir.find();

}


PathTester::~PathTester() {
	// TODO Auto-generated destructor stub
}

