/*
 * Prompt.cpp
 *
 *  Created on: Mar 25, 2019, for CS 232 at Calvin College
 *      Author: Daniel Ackuaku
 */

#include "Prompt.h"

/* constructor
 * @param: none
 * Precondition: none
 * Postcondition:   a constructor that builds a Prompt as the full path to the working directory
 * return: none
 */
Prompt::Prompt() {
     char handle[360];
     string dummy = getcwd(handle ,360);

     if (getcwd == NULL) {
         cerr << "Propmt(): Error creating prompt" << endl;
     } else {
         currentDir = dummy+'$'+' '; 
     }

    }

/* get
 * @param: none
 * Precondition: none
 * Postcondition:   an accessor that returns the current value of the Prompt.
 * return: string
 */
    string Prompt::get() const {
        return currentDir;
    }


Prompt::~Prompt(){

    }
