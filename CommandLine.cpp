/*
 * CommandLine.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: Catherine DeJager
 */

#include "CommandLine.h"
#include <queue>
#include <stdlib.h>  // calloc, exit, free

/*
 * construct a CommandLine by reading a command-line from in, parsing it, and building instance variables for argc and argv
 * (you may find the calloc() and free() system calls to be of use here)
 */
CommandLine::CommandLine(istream& in) {
	char* word;
	queue<char*> words;
	cout << words.front() << endl;
	cout << "success" << endl;
	while (in.peek() != '\n' && !in.eof()) {
		in >> word;
		words.push(word);
		cout << words.front() << endl;
	}
	words.front();
	cout << "ok" << endl;
	cout << words.front() << endl;

	myArgCount = words.size();
	myArgVecPtr = (char**) calloc (myArgCount, sizeof(string));
	// check if memory has been successfully allocated or not
	if (myArgVecPtr == NULL) {
		cout << "Memory not allocated." << endl;
		exit(1);  // TODO: is this how we want to handle that problem?
	}

	for (int i = 0; i < myArgCount; i++) {
		cout << words.front() << endl;
		words.pop();
	}
}

// return a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i]).
char* CommandLine::getArgVector(int i) const {

}

CommandLine::~CommandLine() {
	// TODO Auto-generated destructor stub
	free(myArgVecPtr);
}

