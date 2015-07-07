
#ifndef __lab2__scheduler__
#define __lab2__scheduler__

#include "darray.h"

template<typename T>
class Scheduler: public darray<T>
{
private:
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
