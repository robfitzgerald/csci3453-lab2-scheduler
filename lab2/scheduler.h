
#ifndef __lab2__scheduler__
#define __lab2__scheduler__

#include "darray.h"
#include "PCB.h"

class Scheduler
{
private:
    float CONTEXT_SWITCH_TIME;
    float SIMULATION_INCREMENT;
    float SIMULATION_NUMERICAL_BOUND;
    darray<PCB> unscheduled, ready, running, waiting, terminated, results;
    
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
    int quantum;
    int thisQuantum;
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
    void advanceThisQuantum();
    
    void sortAndAggregate();
    float avgBurst;
    float avgWait;
    float avgTurn;
    float avgResp;
    int sumContext;
    
public:
    void loadUnscheduledPCBs(darray<PCB>&);
    Scheduler(int a, int q):
        algorithm(a),
        quantum(q),
        CONTEXT_SWITCH_TIME(0.5),
        SIMULATION_INCREMENT(1),
        SIMULATION_NUMERICAL_BOUND(999999)
    {
        simulationTime = 0;
        contextTime = 0;
        if (algorithm != 2) {
            quantum = 1;
        }
        thisQuantum = 0;
        sumContext = 0;
    };
    void setAlgorithm(int);
    void setQuantum(int);
    void run();
    bool hasProcesses();
    void contextSwitch();
    void printResults();
};

#endif /* defined(__lab2__scheduler__) */
