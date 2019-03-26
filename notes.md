- XYShell - your shell class, with two public methods:
  - XYShell() - initialize your shell; and
  - void run() - execute your shell.
In addition to executing system programs (e.g., ls, ps, pwd), your shell must also handle cd and pwd as built-in commands (you may find the chdir() and getcwd() system calls to be useful for this).

You should feel free to create other classes as you need them. You may also define additional methods in each of these classes. Methods that define messages to be sent to class objects should be implemented as public methods; methods used to define class utilities or break a big method into more manageable pieces should be defined as private methods. Stylistically, no method should be more than a half-page in length. Remember: Any class that allocates memory dynamically should provide a destructor to reclaim that memory, to avoid leaking memory.
To execute system programs, your shell should use the fork(), waitpid(), and execve() system calls: The fork() call clones the current process to create a child process that is a complete copy of its parent. The child process should then use execve() to execute the user's command.

If no ampersand has been given on the command-line, the parent should use waitpid() to wait until the child terminates; otherwise (an ampersand was given, indicating the command was to be run in the background), it should return to the top of its loop, prompt the user, and await their next command. You may also find the sched_yield() system call to be useful in synchronizing the parent and child processes.

You should read the UNIX manual pages (section 2) for the details of the various system calls listed above, especially what header files must be #include-d to use them. There are also may be WWW tutorials/examples available that you may find useful.

XYShell() pseudocode (may be incorrect):
- create Path
- create Prompt

XYShell.run() pseudocode:
- output prompt (question: is prompt supposed to be created each time we ask for user input (in case directory changes)
- create CommandLine from cin
- check command
  - if command is cd, then do chdir (look at the accepted answer on https://stackoverflow.com/questions/10792227/c-change-working-directory-from-user-input)
  - if command is pwd, then do getcwd (look at the little wrapper in https://stackoverflow.com/questions/2203159/is-there-a-c-equivalent-to-getcwd )
  - if command is exit, then exit
  - if command is something else, then execute the system call
- executing system calls
  - fork() to clone the current process
  - if num returned by fork() is 0, then we are child process. Use execve(const char *filename, char *const argv, char *const envp[])
    - get filename from path somehow?
    - argv = ArgVecPtr from CommandLine
    - envp is extra credit, so I think we can go without?. Use NULL for envp
    - if return value is -1, output errno
  - if num returned by fork() is greater than 0, we are parent and num is pid of child. If CommandLine.noAmpersand(), use waitpid(pid), where pid is the pid of the child.
  - if num returned by fork() is -1, then we have an error. output errno

What to test
  - ls, cd .., pwd, ls -a, ls -l /home/cs/, pwd, ps -ax &, ..., followed by exit
  - invalid command

