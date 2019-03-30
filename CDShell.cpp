/*
 * CDShell.cpp
 *
 *  Created on: Mar 30, 2019
 *      Author: Catherine D and Daniel A
 */

#include "CDShell.h"
#include <unistd.h>  // fork
#include <sys/wait.h>  // waitpid

CDShell::CDShell() {
	// TODO Auto-generated constructor stub
	// create Path
	myPath = Path();
	myPrompt = Prompt();
}

void CDShell::run() {
	bool to_exit = false;  // flag to indicate whether we want to exit the program or not
	while (! to_exit) {
		cout << myPrompt.get() << flush;
		CommandLine comm_line(cin);
		char* command = comm_line.getCommand();
		if (strcmp(command, "exit")) {
			to_exit = true;
		}
		else if (strcmp(command, "cd")) {
			// change directory (look at the accepted answer on https://stackoverflow.com/questions/10792227/c-change-working-directory-from-user-input)
			myPrompt = Prompt(); // make a new Prompt because the current working directory has changed
		}
		else if (strcmp(command, "pwd")) {
			// do getcwd (look at the little wrapper in https://stackoverflow.com/questions/2203159/is-there-a-c-equivalent-to-getcwd )
		}
		else {  // execute the system call
			// find the filename specified in command. If the command can't be found, output an error and continue
			// TODO: clean this up
			string filename = myPath.getDirectory(myPath.find(command));
			pid_t pid = fork();
			if (pid == 0) {  // we are child process
				int status = execve(filename.c_str(), comm_line.getArgVector(), NULL);
				if (status == -1) {
					// TODO: figure out how to output error
					cout << "Error executing command" << endl;
				}
			}
			else if (pid == -1) {
				// TODO: output error
				cout << "Error with fork" << endl;
			}
			else if (comm_line.noAmpersand()) {
				waitpid(pid, NULL, WNOHANG);  // don't care about status. TODO: change to something else later. look at https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/rtwaip.htm
			}
		}
	}
}

CDShell::~CDShell() {
	// TODO Auto-generated destructor stub
}

