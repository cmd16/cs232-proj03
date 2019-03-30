/*
 * CDShell.h
 *
 *  Created on: Mar 30, 2019
 *      Author: cmd38
 */

#ifndef CDSHELL_H_
#define CDSHELL_H_
#include "Path.h"
#include "Prompt.h"
#include "CommandLine.h"

class CDShell {
public:
	CDShell();
	void run();
	virtual ~CDShell();
private:
//	Path myPath;
	Prompt myPrompt;
};

#endif /* CDSHELL_H_ */
