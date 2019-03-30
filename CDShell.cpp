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
	// create Path
//	myPath = Path();
//	cout << "path size is " << myPath.returnDIR().size() << endl;
	myPrompt = Prompt();
}

void CDShell::run() {
	Path myPath;
	cout << "path size " << myPath.returnDIR().size() << endl;
	bool to_exit = false;  // flag to indicate whether we want to exit the program or not
	while (! to_exit) {
		cout << myPrompt.get() << flush;

		CommandLine comm_line(cin);
		string command = comm_line.getCommand();
		cout << "command: " << command << endl;  // DEBUG
		if (command == "exit") {
			to_exit = true;
		}
		else if (command == "cd") {
			// change directory (look at the accepted answer on https://stackoverflow.com/questions/10792227/c-change-working-directory-from-user-input)
			cout << "changing directory" << endl;
			myPrompt = Prompt(); // make a new Prompt because the current working directory has changed
		}
		else if (command == "pwd") {
			// do getcwd (look at the little wrapper in https://stackoverflow.com/questions/2203159/is-there-a-c-equivalent-to-getcwd )
		}
		else {  // execute the system call
			// find the filename specified in command. If the command can't be found, output an error and continue
			// TODO: clean this up
			int index = myPath.find(command);
			cout << "index is " << index << " size of path is " << myPath.returnDIR().size() << endl;
			if (index == -1) {
				cout << command << ": command not found" << endl;
				continue;
			}
			string filename = myPath.getDirectory(myPath.find(command));
			filename = filename + "/" + command;
			cout << "filename is " << filename << endl;
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
				waitpid(pid, NULL, 0); // wait for the command to finish
			}
		}
	}
}

CDShell::~CDShell() {
	// TODO Auto-generated destructor stub
}

