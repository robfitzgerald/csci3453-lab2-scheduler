#include "scheduler.h"
#include <iostream>

void Scheduler::advance() {
    checkUnscheduled();
    switch(algorithm) {
        case 0:
            // first come, first serve
            fcfs();
            break;
        case 1:
            // shortest remaining task first
            srtf();
            break;
        case 2:
            // round robin
            rrobin();
            break;
        default: ;
            // something here
    }
    
}


void Scheduler::fcfs() {
    if (running[0].getRemaining() == running[0].getCPUBurst()) {
        runningToTerminated();
        if (ready.size() > 0)
            readyToRun();
    }
    
    if (running.size() > 0) {
        running[0].incrementRunning(SIMULATION_INCREMENT);
    }
    for (int i = 0; i < ready.size(); ++i) {
        ready[i].incrementWaiting(SIMULATION_INCREMENT);
    }
    
}


void Scheduler::srtf() {
    if (running[0].getRemaining() == running[0].getCPUBurst())
        runningToTerminated();
    
    srtfSwapTuple shortest = srtfSwapTest();
    if (shortest.getPid() != running[0].getPid()) {
        ready.moveToFront(shortest.getIndex());
        contextSwitch();
    }
    
    if (running.size() > 0) {
        running[0].incrementRunning(SIMULATION_INCREMENT);
    }
    for (int i = 0; i < ready.size(); ++i) {
        ready[i].incrementWaiting(SIMULATION_INCREMENT);
    }
}


void Scheduler::rrobin() {
    
}


void Scheduler::checkUnscheduled() {
    for (int i = 0; i < unscheduled.size(); ++i) {
        if (unscheduled[i].getArrival() == simulationTime) {
            
            // record response time
            //unscheduled[i].setResponse(simulationTime);
            
            // move from unscheduled to ready queue
            unscheduled.moveToBack(i);
            ready.push_back(unscheduled.back());
            unscheduled.pop_back();
            
            if (running.size() == 0) {
                readyToRun();
            }
            
        }
    }
}


void Scheduler::runningToTerminated() {
    running[0].done(simulationTime);
    terminated.push_back(running[0]);
    running.pop_back();
}


void Scheduler::readyToRun() {
    if (ready.front().hasResponseOccured() == false) {
        ready.front().responseHasOccured();
        float diff = simulationTime - ready.front().getArrival();
        ready[0].setResponse(diff);
    }
    running.push_back(ready.front());
    ready.pop_front();
}


Scheduler::srtfSwapTuple Scheduler::srtfSwapTest() {
    int shortestRemainingPid = running[0].getPid();
    int readyIndex;
    float shortestRemainingTime = running[0].getRemaining();
    for (int i = 0; i < ready.size(); ++i) {
        if (ready[i].getRemaining() < shortestRemainingTime) {
            shortestRemainingPid = ready[i].getPid();
            readyIndex = i;
        }
    }
    return srtfSwapTuple(shortestRemainingPid, readyIndex);
}


void Scheduler::loadUnscheduledPCBs(darray<PCB>& simulation) {
    for (int i = 0; i < simulation.size(); ++i) {
        unscheduled.push_back(simulation[i]);
    }
}


void Scheduler::setAlgorithm(int a) {
    algorithm = a;
}


void Scheduler::setQuantum(int q) {
    quantum = q;
}


void Scheduler::run() {
    while (hasProcesses()) {
        advance();
        simulationTime++;
    }
}


bool Scheduler::hasProcesses() {
    return (   (unscheduled.size() > 0)
            || (ready.size() > 0)
            || (running.size() > 0));
}


void Scheduler::contextSwitch() {
    running[0].incrementContext();
    ready.push_back(running[0]);
    running.pop_back();
    for (int i = 0; i < ready.size(); ++i) {
        ready[i].incrementWaiting(CONTEXT_SWITCH_TIME);
    }
    running.push_front(ready.front());
    ready.pop_front();
}


void Scheduler::printResults() {
    std::cout
    << std::setw(4) << "pid"
    << std::setw(8) << "arrival"
    << std::setw(9) << "CPUburst"
    << std::setw(7) << "finish"
    << std::setw(8) << "waiting"
    << std::setw(11) << "turnaround"
    << std::setw(9) << "response"
    << std::setw(9) << "context" << std::endl;
    for (int i = 0; i < terminated.size(); ++i) {
        std::cout << terminated[i].results();
        std::cout << std::endl;
    }
}



