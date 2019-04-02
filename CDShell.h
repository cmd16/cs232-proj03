/*
 * CDShell.h
 *
 *  Created on: Mar 30, 2019, for CS 232 at Calvin College
 *      Author: Catherine DeJager and Daniel Ackuaku
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
