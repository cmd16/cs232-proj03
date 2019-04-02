/*
 * Prompt.h
 *
 *  Created on: Mar 25, 2019, for CS 232 at Calvin College
 *      Author: Daniel Ackuaku
 */

#ifndef PROMPT_H_
#define PROMPT_H_
#include "Path.h"
#include <unistd.h>

class Prompt {
public:
	Prompt();
    string get() const ;
	virtual ~Prompt();
    




private: 
	string currentDir;
};


#endif
