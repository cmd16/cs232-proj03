/*
 * Path.cpp
 *
 *  Created on: Mar 25, 2019, for CS 232 at Calvin College
 *      Author: Daniel Ackuaku
 */

#include "Path.h"


/* constructor
 * @param: none
 * Precondition: none
 * Postcondition:   a Path constructed from the PATH environment variable
 * return: Null
 */
Path::Path() {
	char * pch;								// initializing a character pointer
	// new version
	char * tempPath = getenv("PATH");
	strcpy(pPath, tempPath);
	pch = strtok(pPath, ":");				// splits the chars into chunks any time the ":" appears
	// old version
//	pPath = getenv("PATH");					// populating the character pointer pPath with the PATH
//	pch = strtok(pPath, ":");				// splits the chars into chunks any time the ":" appears

/* Loop that stores each directory in PATH in a vector */
	while (pch != NULL) {
		directory.push_back(pch);
		pch = strtok(NULL, ":");			// after ":" a NULL is inserted into the character array causing the loop to return to the top
	}

}


/* find
 * @param: none
 * Precondition: none
 * Postcondition:   returns the index of the directory containing program or  Path constructed from the PATH environment variable
 * return: int
 */
int Path::find(const string& program) const {	
	DIR *dir;	
	struct dirent *entry; 						// handle to read from the directory
		for (unsigned i = 0; i < directory.size() ; i++) {
			if ((dir = opendir(directory[i].c_str())) != NULL) {

				while( (entry = readdir(dir)) != NULL) {

					if (entry->d_name == program ) {
						closedir(dir);
						return i;
					} else {
						 
					}
				}
			}
			closedir(dir);
		}
	return -1;
}

/* getDirectory
 * @param: none
 * Precondition: none
 * Postcondition:   an accessor that returns the current value of the directory.
 * return: string
 */
string Path::getDirectory(int i) const {
	if (i >= directory.size() || i < 0) {
		cerr << "getDirectory(): index out of bounds error" << endl;
		return NULL;
	}
	return directory[i];
}



Path::~Path()  {

}

