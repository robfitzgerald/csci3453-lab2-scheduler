/*
 
 pcb.h
 
 class Pcb
 
 a record class to represent a single process and store data associated with the simulation of the process.
 
 constructor:
 Pcb(pid, arrival_time, cpu_burst_time)
 
 
 
 */

#ifndef __lab2__pcb__
#define __lab2__pcb__

#include <string>
#include <iomanip>
#include <sstream>

class Pcb {
    
public:
    Pcb(int p, float a, float c): pid(p), arrival(a), CPUburst(c), response(0.0) {};
    float getArrival();
    bool completed () { return timeCompleted == CPUburst; }
    bool started() { return (response != 0.0); }
    void advance(float, float, bool);
    void done(float);
    std::string results();
    
private:
    // record data
    int pid;
    float arrival;
    float CPUburst;
    
    // simluation data
    float finish;
    float timeCompleted;
    float waiting;
    float turnaround;
    float response;
    int context;

};

void Pcb::advance(float increment, float time, bool waiting) {
    if (!this->started()) {
        this->response = time;
    }
    if (waiting) {
        this->waiting += increment;
    } else {
        this->timeCompleted += increment;
    }
}

void Pcb::done(float time) {
    this->finish = time;
    this->waiting = this->finish - this->arrival;
    this->turnaround = this->finish - this->arrival;
}

std::string Pcb::results() {
    
    std::ostringstream output;
    output
    << std::setw(4) << this->pid
    << std::setw(8) << this->arrival
    << std::setw(9) << this->CPUburst
    << std::setw(7) << this->finish
    << std::setw(8) << this->waiting
    << std::setw(11) << this->turnaround
    << std::setw(9) << this->context;
    return output.str();
}

#endif /* defined(__lab2__pcb__) */
