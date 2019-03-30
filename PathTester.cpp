/*
 * PathTester.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: dma2
 */

#include "PathTester.h"
#include "Path.h"
#include <assert.h>

vector<string> dir;
Path test;

PathTester::PathTester() {
	// TODO Auto-generated constructor stub

}

void PathTester::testConstructor(){
	
	char *testSize;
	testSize = getenv("PATH");

	cout << testSize << endl;
	dir = test.returnDIR();
	// cout << "\n" << endl;
	cout << dir.size() << endl;
	for (unsigned i = 0 ; i < dir.size(); i++ ) {
			cout <<  dir[i] << endl;
			
	}
	cout << "..... 0 ....." << endl;
}

void PathTester::testFind() {

	dir = test.returnDIR();
	// test.find("zsh");
	cout << test.find("bin2c") << endl ;
	assert ( test.find("bin2c") != -1 );
	cout << "..... 1 ....." << endl; 
	cout << test.find("cat") << "\t" <<"LOOK HERE!!"<<endl; 
	cout << "..... 2 ....." << endl; 
	cout <<   test.find("zsh") << "\t" << "THIS IS WHERE ZSH IS !! "<<endl ;
	assert ( test.find("zsh") == 5);
	cout << " All tests Passed !" << endl;

}


PathTester::~PathTester() {
	// TODO Auto-generated destructor stub
}

