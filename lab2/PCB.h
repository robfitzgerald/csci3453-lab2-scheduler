/*
 
 PCB.h
 
 class PCB
 
 a record class to represent a single process control block.  this PCB stores data associated with the simulation of the process scheduler, and produces a report of that data.
 
 */

#ifndef __lab2__pcb__
#define __lab2__pcb__

#include <string>
#include <iomanip>
#include <sstream>

class PCB {
    
public:
    PCB(){};
    PCB(int p, float a, float c): pid(p), arrival(a), CPUburst(c) {
        finish = 0.0;
        timeRemaining = CPUburst;
        waiting = 0.0;
        turnaround = 0.0;
        response = 0.0;
        context = 0;
        responseOccured = false;
    };
    PCB(PCB& copy) {
        pid = copy.getPid();
        arrival = copy.getArrival();
        CPUburst = copy.getCPUBurst();
        finish = copy.getFinish();
        timeRemaining = copy.getRemaining();
        waiting = copy.getWaiting();
        turnaround = copy.getTurnaround();
        response = copy.getResponse();
        context = copy.getContext();
    }
    
    // getters for basic record data
    int getPid() { return pid; }
    float getArrival() { return arrival; }
    float getCPUBurst() { return CPUburst; }
    float getFinish() { return finish; }
    float getRemaining() { return timeRemaining; }
    float getResponse() { return response; }
    bool hasResponseOccured() { return responseOccured; }
    float getWaiting() { return waiting; }
    float getTurnaround() { return turnaround; }
    int getContext() { return context; }
    
    // data recording functions
    void setArrival(float a) { arrival = a; }
    void setResponse(float r) { response = r; }
    void responseHasOccured() { responseOccured = true; }
    void incrementContext() { context++; };
    void incrementWaiting(float);
    void incrementRunning(float);
    void done(float);
    
    // output
    std::string results();
    
private:
    // record data
    int pid;
    float arrival;
    float CPUburst;
    
    // simluation data
    float finish;
    float timeRemaining;
    float waiting;
    float turnaround;
    float response;
    bool responseOccured;
    int context;
};

#endif /* defined(__lab2__pcb__) */
