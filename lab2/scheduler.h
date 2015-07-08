
#ifndef __lab2__scheduler__
#define __lab2__scheduler__

#include "darray.h"
#include "PCB.h"

class Scheduler
{
private:
    darray<PCB> unscheduled, ready, run, waiting, terminated;
    
    int algorithm;
    int quantum;
    float time;
    int simulationDur;
    void advance();
    void fcfs();
    void srtf();
    void rrobin();

public:
    
    Scheduler() {};
    void setAlgorithm(int);
    void setQuantum(int);
    void setSimulationDur(float);
    int run();
};

#include "scheduler.tem"

#endif /* defined(__lab2__scheduler__) */
