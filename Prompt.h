/*
 * Prompt.h
 *
 *  Created on: Mar 25, 2019
 *      Author: dma2
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