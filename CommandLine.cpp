/*
 * CommandLine.cpp
 *
 *  Created on: Mar 13, 2019
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
 */
CommandLine::CommandLine(istream& in) {
	myNoAmpersand = true;
	string word;
	queue<string> words;
	while (in.peek() != '\n' && !in.eof()) {
		in >> word;
		if (word == "&") {
			myNoAmpersand = false;
		}
		else {
			words.push(word);
		}
	}

	myArgCount = words.size();
	myArgVecPtr = (char**) calloc (myArgCount, sizeof(char*));
	// check if memory has been successfully allocated or not
	if (myArgVecPtr == NULL) {
		exit(1);  // TODO: is this how we want to handle that problem?
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
//	if (i < 0) {
//		throw out_of_range("getArgVector(int i): index too low");
//	}
//	if (i > myArgCount - 1) {
//		throw out_of_range("getArgVector(int i): index too high");
//	}
	return myArgVecPtr[i];
}

CommandLine::~CommandLine() {
	// TODO Auto-generated destructor stub
	for (int i = 0; i < myArgCount; i++) {
		delete [] myArgVecPtr[i];
		myArgVecPtr[i] = NULL;
	}
	free(myArgVecPtr);
}
