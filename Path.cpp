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
 * Postcondition:   retunrs teh index of the directory containing program or  Path constructed from the PATH environment variable
 * return: int
 */
int Path::find(const string& program) const {
	int index = -1;							// sets the default index value			
	DIR *dir;	
	struct dirent *dp; 						// handle to read from the directory

		for (unsigned i = 0; i < directory.size() ; i++) {
			string dirName = directory[i];

		if ((dir = opendir(dirName.c_str())) != NULL) {
			while((dp = readdir (dir)) != NULL) {

				if (dp->d_name == program ) {
				index = i; 
				cout << index << endl; 
				}
			}
		}
		else {
			index = -1;
		}
	}
	return index;
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
	// TODO Auto-generated destructor stub
}

