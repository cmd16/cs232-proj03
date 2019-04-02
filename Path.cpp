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

	string newParse = getenv("PATH");
	stringstream stream (newParse);
	string transfer;
	while(getline(stream, transfer, ':')){

		directory.push_back(transfer);
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

