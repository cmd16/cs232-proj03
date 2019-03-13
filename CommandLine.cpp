/*
 * CommandLine.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: Catherine DeJager
 */

#include "CommandLine.h"

/*
 * construct a CommandLine by reading a command-line from in, parsing it, and building instance variables for argc and argv
 * (you may find the calloc() and free() system calls to be of use here)
 */
CommandLine::CommandLine(istream& in) {
	// read argc, read argv
	char str[256];

	in.get(str, 256);  // get c-string
	cout << str << flush;
}

// return a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i]).
char* CommandLine::getArgVector(int i) const {

}

CommandLine::~CommandLine() {
	// TODO Auto-generated destructor stub
}

