/*
 * Path.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: dma2
 */

#include "Path.h"
#include <stdlib.h>



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
	unsigned i = 0;
	
	// loop that stores each directory in PATH in a vector
	while (pch != NULL) {
		dir.push_back(pch);
		// cout << dir[i] << endl;
		i += 1;
		pch = strtok(NULL, ":");			// after ":" a NULL is inserted into the character array causing the loop to return to the top
	}

}

void Path::run() {


}

Path::~Path() {
	// TODO Auto-generated destructor stub
}

