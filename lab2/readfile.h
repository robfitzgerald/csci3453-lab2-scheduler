//
//  readfile.h
//  csci3412_pa1
//
//  Created by Robert Fitzgerald on 2/4/15.
//
//

#ifndef __csci3412_pa1__readfile__
#define __csci3412_pa1__readfile__

#include <vector>
#include <string>
#include "PCB.h"
#include "darray.h"

// ƒ read_file(A,p,r)
//
// precondition:  file is a list of integers which starts after 2 specific lines of metadata (see below)
// postcondition: returns an array made of the # of elements requested by the caller of the function
//

darray<PCB> read_file(const char*);
std::vector<int> parse_line(std::string);
//bool predicate (PCB ,PCB);

#endif /* defined(__csci3412_pa1__readfile__) */
