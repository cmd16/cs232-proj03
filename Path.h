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
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
using namespace std;

class Path {
public:
	Path();
	virtual ~Path();
	int find(const string& program) const;
	string getDirectory(int i) const ;
	vector<string> returnDIR() const { return directory; }



private: 
	vector<string> directory;
	char * pPath;
	friend class PathTester;
};

#endif /* PATH_H_ */
