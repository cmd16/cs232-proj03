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

void PathTester::run(){
	Path test;
	vector<string>dir = test.returnDIR();
	for (unsigned i =0 ; i < sizeof(dir)-3; i++ ) {
			cout <<  dir[i] << endl;
			
	}

}




PathTester::~PathTester() {
	// TODO Auto-generated destructor stub
}

