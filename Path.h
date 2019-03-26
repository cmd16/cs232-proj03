/*
 * Path.h
 *
 *  Created on: Mar 25, 2019
 *      Author: dma2
 */

#ifndef PATH_H_
#define PATH_H_
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

class Path {
public:
	Path();
	virtual ~Path();
	void run();
	vector<string> returnDIR() const { return dir; }



private: 
	vector<string> dir;
	char * pPath;
	friend class PathTester;
};

#endif /* PATH_H_ */
