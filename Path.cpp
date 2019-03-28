/*
 * Path.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: dma2
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
	pPath = getenv("PATH");					// populaing the charcter pointer pPath with the PATH
	pch = strtok(pPath, ":");				// splits the chars into chucnks anytime the ":" appears

	
/* Loop that stores each directory in PATH in a vector */
	while (pch != NULL) {
		directory.push_back(pch);
		pch = strtok(NULL, ":");			// after ":" a NULL is inserted into the character array causing the loop to return to the top
	}

}


/* find
 * @param: none
 * Precondition: none
 * Postcondition:   a Path constructed from the PATH environment variable
 * return: Null
 */
int Path::find(const string& program) const {
	int index = -1;							// sets the default index value			
	DIR *dir;	
	struct dirent *dp; 						// handle to read from the directory

		for (unsigned i = 0; i < sizeof(directory) ; i++) {
			string dirName = directory[i];

		if ((dir = opendir(dirName.c_str())) != NULL) {
			if ((dp = readdir (dir))) {
				if (dp->d_name == program ) {
				index = i; 
				}
			}
		}
		else {
			return index;
		}
	}
	return index;
}


Path::~Path()  {
	// TODO Auto-generated destructor stub
}

