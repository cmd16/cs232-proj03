/*
 * CDShell.cpp
 *
 *  Created on: Mar 30, 2019, for CS 232 at Calvin College
 *      Author: Catherine D and Daniel Ackuaku
 */

#include "CDShell.h"
#include <unistd.h>  // fork
#include <sys/wait.h>  // waitpid
#include <sys/param.h>  // MAXPATHLEN
#include <cerrno>		// errno

CDShell::CDShell() {
	myPrompt = Prompt();
}

// execute your shell, using CommandLine, Path, and Prompt. Read in user commands and execute them appropriately.
void CDShell::run() {
	Path myPath;
	cout << "path size " << myPath.returnDIR().size() << endl;
	bool to_exit = false;  // flag to indicate whether we want to exit the program or not
	while (! to_exit) {
		cout << myPrompt.get() << flush;

		CommandLine comm_line(cin);
		string command = comm_line.getCommand();
		if (command == "exit") {
			to_exit = true;
		}
		else if (command == "cd") {
			// change directory (look at the accepted answer on https://stackoverflow.com/questions/10792227/c-change-working-directory-from-user-input)
			char* newDir = comm_line.getArgVector(1);
			int rc = chdir(newDir);
			if (rc == -1) {
				// TODO: handle error. use errno to determine problem
				cerr << "failed to change directory: " << errno << endl;
			}
			myPrompt = Prompt(); // make a new Prompt because the current working directory has changed
		}
		else if (command == "pwd") {
			// do getcwd (adopted from the accepted answer on https://stackoverflow.com/questions/10792227/c-change-working-directory-from-user-input)
			char buffer[MAXPATHLEN];
			char *path = getcwd(buffer, MAXPATHLEN);
			if (!path) {
				// TODO: handle error. use errno to determine problem
				cerr << "failed to get current working directory: " << errno << endl;
			} else {
				string current_path = path;
				cout << current_path << endl;
			}
		}
		else {  // execute the system call
			// find the filename specified in command. If the command can't be found, output an error and continue
			int index = myPath.find(command);
			if (index == -1) {
				cerr << command << ": command not found" << endl;
				continue;
			}
			string filename = myPath.getDirectory(myPath.find(command));
			filename = filename + "/" + command;
			pid_t pid = fork();
			if (pid == 0) {  // we are child process
				int status = execve(filename.c_str(), comm_line.getArgVector(), NULL);
				if (status == -1) {
					cerr << "Error executing command: " << errno << endl;
//					cout << "Last item of argv (should be null): " << comm_line.getArgVector()[comm_line.getArgCount()] << endl;
					if (errno == 14) {
						for (int i = 0; i < comm_line.getArgCount(); i++) {
							cout << comm_line.getArgVector(i) << "!";
						}
						cout << endl;
					}
				}
			}
			else if (pid == -1) {
				// TODO: output error
				cerr << "Error with fork" << errno << endl;
			}
			else if (comm_line.noAmpersand()) {
				waitpid(pid, NULL, 0); // wait for the command to finish
			}
		}
	}
}

CDShell::~CDShell() {

}

