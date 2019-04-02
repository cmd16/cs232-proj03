/*
 * PathTester.cpp
 *
 *  Created on: Mar 25, 2019, for CS 232 at Calvin College
 *      Author: Daniel Ackuaku and Catherine DeJager
 */

#include "PathTester.h"
#include "Path.h"
#include <assert.h>


//Path test;

PathTester::PathTester() {

}

void PathTester::runTests() {
	testConstructor();
	testFind();
	testFindcmd38();
}

void PathTester::testConstructor(){
	Path test;
	
	const char *path;
	path = getenv("PATH");

//	cout << path << endl;
	vector<string> dir;
	dir = test.returnDIR();
	dir.size();
	cout << dir.size() << endl;
//	for (unsigned i = 0 ; i < dir.size(); i++ ) {
//			cout <<  dir[i] << endl;
//
//	}
	cout << "..... 0 ....." << endl;
}

void PathTester::testFind() {
	Path test1;
	vector<string> dir;
	dir = test1.returnDIR();
//	cout << test1.find("bin2c") << endl ;
	assert ( test1.find("bin2c") != -1 );
	cout << "..... 1 ....." << endl; 
//	cout << test1.find("cat") << "\t" <<"LOOK HERE!!"<<endl;
	cout << "..... 2 ....." << endl; 
//	cout <<   test1.find("zsh") << "\t" << "THIS IS WHERE ZSH IS !! "<<endl ;
	assert ( test1.find("zsh") == 4);  // 5 on Daniel's machine
	cout << " All tests Passed !" << endl;

}

void PathTester::testFindcmd38() {
	Path test;
	vector<string> dir;
	// test find on cmd38's account in ulab
	dir = test.returnDIR();
	cout << "size is " << dir.size() << endl;
	int index = test.find("cat");
	cout << index << endl;
	cout << test.getDirectory(index) << endl;
}


PathTester::~PathTester() {

}

