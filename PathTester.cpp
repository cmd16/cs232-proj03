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
//Path test;

PathTester::PathTester() {
	// TODO Auto-generated constructor stub

}

void PathTester::runTests() {
	testConstructor();
//	testFind();
	testFindcmd38();
}

void PathTester::testConstructor(){
	Path test;
	
	char *path;
	path = getenv("PATH");

//	cout << path << endl;
	dir = test.returnDIR();
	cout << dir.size() << endl;
	for (unsigned i = 0 ; i < dir.size(); i++ ) {
			cout <<  dir[i] << endl;
			
	}
	cout << "..... 0 ....." << endl;
}

void PathTester::testFind() {
	Path test;

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

void PathTester::testFindcmd38() {
	Path test;

	// test find on cmd38's account in ulab
	dir = test.returnDIR();
	cout << "size is " << dir.size() << endl;
	int index = test.find("cat");
	cout << index << endl;
	cout << test.getDirectory(index) << endl;
}


PathTester::~PathTester() {
	// TODO Auto-generated destructor stub
}

