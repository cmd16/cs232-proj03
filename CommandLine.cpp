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
		words.push(word);
		if (word == "&") {
			myNoAmpersand = false;
		}
		cout << words.front() << endl;
	}
	cout << "ok" << endl;

	myArgCount = words.size();
	myArgVecPtr = (char**) calloc (myArgCount, sizeof(string));
	// check if memory has been successfully allocated or not
	if (myArgVecPtr == NULL) {
		cout << "Memory not allocated." << endl;
		exit(1);  // TODO: is this how we want to handle that problem?
	}

	for (int i = 0; i < myArgCount; i++) {
		word = words.front();
		cout << word << endl;
		// copy the word as a character array into argv
		//word.copy(*(myArgVecPtr + i), word.size());
		//strcpy(*(myArgVecPtr + i), word.c_str());
		//*(myArgVecPtr + i) = word.c_str();
		cout << getArgVector(i) << endl;
		words.pop();
	}
}

// return a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i]).
char* CommandLine::getArgVector(int i) const {
	return *(myArgVecPtr + i);
}

CommandLine::~CommandLine() {
	// TODO Auto-generated destructor stub
	free(myArgVecPtr);
}

