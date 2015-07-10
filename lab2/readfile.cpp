//
//  readfile.cpp
//  csci3412_pa1
//
//  Created by Robert Fitzgerald on 2/4/15.
//
//

#include "readfile.h"
#include <fstream>
#include <cstdlib>
#include <vector>
#include "PCB.h"
#include <string>
#include <sstream>
#include <algorithm>
#include "darray.h"

darray<PCB> read_file(const char* fileName)
{
    std::cout << "fileName is " << fileName << std::endl;
    darray<PCB> result;
    std::vector<PCB> A;
    std::ifstream file;
    file.open(fileName);
    
    // return empty array if file is bad
    if (!file.good())
        return result;
    
    // get # of elements in file
    std::string line;
    
    // get data
    while (getline(file,line))
    {
        std::vector<int> p = parse_line(line);
        result.push_back(PCB(p[0], p[1], p[2]));
        line.clear();
    }
    
    //sort(A.begin(), A.end(), predicate);
    
//    for (int i = 0; i < A.size(); ++i) {
//        result.push_back(A.back());
//        A.pop_back();
//    }
    
    return result;
}

std::vector<int> parse_line(std::string line) {
    std::stringstream stream(line);
    std::vector<int> result;
    int n;
    while(stream >> n) {
        result.push_back(n);
    }
    return result;
}

//bool predicate (PCB i, PCB j) {
//    return (i.getPid()>j.getPid());
//}




