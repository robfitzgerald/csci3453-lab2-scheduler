//
//  main.cpp
//  lab2
//
//  Created by Robert Fitzgerald on 7/5/15.
//  Copyright (c) 2015 Robert Fitzgerald. All rights reserved.
//

#include <iostream>
#include "scheduler.h"
#include "PCB.h"
#include "darray.h"

int main(int argc, const char * argv[]) {
    
    // parse argv
    // file with sim data ->
    
    PCB one(1, 0, 10),
        two(2, 1, 2),
        thr(3, 2, 9),
        fou(4, 3, 5);
    darray<PCB> loadProcesses;
    loadProcesses.push_front(one);
    loadProcesses.push_front(two);
    loadProcesses.push_front(thr);
    loadProcesses.push_front(fou);
    
    Scheduler fcfsTest(0, 0);
    fcfsTest.loadUnscheduledPCBs(loadProcesses);
    fcfsTest.run();
    fcfsTest.printResults();
    
    Scheduler srtfTest(1, 0);
    srtfTest.loadUnscheduledPCBs(loadProcesses);
    srtfTest.run();
    srtfTest.printResults();
    
    return 0;
}
