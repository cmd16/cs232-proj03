/*
 * PathTester.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: dma2
 */

#include "PathTester.h"
#include "Path.h"

PathTester::PathTester() {
	// TODO Auto-generated constructor stub

}

void PathTester::testConstructor(){
	Path test;
	char * testSize;
	testSize = getenv("PATH");

	cout << testSize << endl;
	vector<string> dir = test.returnDIR();
	// cout << "\n" << endl;
	cout << dir.size() << endl;
	for (unsigned i = 0 ; i < dir.size(); i++ ) {
			cout <<  dir[i] << endl;
			
	}
	// assert
}

void PathTester::testFind() {

}


PathTester::~PathTester() {
	// TODO Auto-generated destructor stub
}

