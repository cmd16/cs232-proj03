/*
 * CommandLine.cpp
 *
 *  Created on: Mar 13, 2019, for CS 232 at Calvin College
 *  Used for constructing a CommandLine from an istream
 *      Author: Catherine DeJager
 */

#include "CommandLine.h"
#include <queue>
#include <stdlib.h>  // calloc, exit, free
#include <cstring>
#include <string>
#include <stdexcept>

/*
 * construct a CommandLine by reading a command-line from in, parsing it, and building instance variables for argc and argv
 * (you may find the calloc() and free() system calls to be of use here)
 * Assumption: the istream will be terminated with newline (which cin is).
 */
CommandLine::CommandLine(istream& in) {
	myNoAmpersand = true;
	string word;
	queue<string> words;
	while (in.peek() != '\n') {
		in >> word;
		if (word == "&") {
			myNoAmpersand = false;
		}
		else {
			words.push(word);
		}
	}
	in.ignore();  // read in and ignore the newline character

	myArgCount = words.size();
	myArgVecPtr = (char**) calloc (myArgCount, sizeof(char*));
	// check if memory has been successfully allocated or not
	if (myArgVecPtr == NULL) {
		cerr << "Failed to allocate ArgVecPtr. Exiting now." << endl;
		exit(-1);  // TODO: is this how we want to handle that problem?
	}

	for (int i = 0; i < myArgCount; i++) {
		word = words.front();
		myArgVecPtr[i] = new char[word.size() + 1];
		// copy the word as a character array into argv. strcpy copies the null character
		strcpy(myArgVecPtr[i], word.c_str());
		words.pop();
	}
}

char* CommandLine::getArgVector(int i) const {
	if (i < 0 or i > myArgCount - 1) {
		throw out_of_range("getArgVector(int i): index must be non-negative and less than myArgCount");
	}
	return myArgVecPtr[i];
}

// CommandLine destructor deallocates myArgVecPtr and the char arrays in myArgVec
CommandLine::~CommandLine() {
	for (int i = 0; i < myArgCount; i++) {
		delete [] myArgVecPtr[i];
		myArgVecPtr[i] = NULL;
	}
	free(myArgVecPtr);
}
