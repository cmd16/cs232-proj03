/*
 * CommandLine.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Catherine DeJager
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
using namespace std;

class CommandLine {
public:
	CommandLine(istream& in);
	char* getCommand() const { return myCommandPtr; }; // may change to return getArgVector(0);
	int getArgCount() const { return myArgCount; };
	char** getArgVector() const { return myArgVecPtr; };
	char* getArgVector(int i) const;
	bool noAmpersand() const { return myNoAmpersand; };
	virtual ~CommandLine();
private:
	char* myCommandPtr;  // a pointer to the command portion of the command-line (i.e., argv[0])
	int myArgCount; 	 // return the number of command-line arguments on the command-line (i.e., argc).
	char** myArgVecPtr;	 // a pointer to a char* array, each entry of which points to one 'word' of the command-line (i.e., argv).
	bool myNoAmpersand;  // true if and only if no ampersand was given on the command-line
};

#endif /* COMMANDLINE_H_ */
