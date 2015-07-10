
#ifndef __lab2__scheduler__
#define __lab2__scheduler__

#include "darray.h"
#include "PCB.h"

class Scheduler
{
private:
    const float CONTEXT_SWITCH_TIME = 0.5;
    const float SIMULATION_INCREMENT = 1;
    const float SIMULATION_TIME_BOUND = 999999;
    darray<PCB> unscheduled, ready, running, waiting, terminated;
    
    class srtfSwapTuple
    {
    public:
        srtfSwapTuple(int p, int i): index(i), pid(p) {}
        int getIndex() { return index; }
        int getPid() { return pid; }
    private:
        int index;
        int pid;
    };
    
    int algorithm;
    float quantum;
    float simulationTime;
    float contextTime;
    
    void advance();
    void fcfs();
    void srtf();
    void rrobin();
    
    void checkUnscheduled();
    void runningToTerminated();
    void readyToRun();
    srtfSwapTuple srtfSwapTest(int, float);

public:
    void loadUnscheduledPCBs(darray<PCB>&);
    Scheduler(int a, int q): algorithm(a), quantum(q) {
        simulationTime = 0;
        contextTime = 0;
    };
    void setAlgorithm(int);
    void setQuantum(int);
    void run();
    bool hasProcesses();
    void contextSwitch();
    void printResults();
};

#endif /* defined(__lab2__scheduler__) */
