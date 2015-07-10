#include "PCB.h"

void PCB::incrementWaiting(float inc) {
    waiting += inc;
    // is that it?
}

void PCB::incrementRunning(float inc) {
    timeRemaining -= inc;
}

void PCB::done(float time) {
    finish = time;
    turnaround = finish - arrival;
}


std::string PCB::results() {
    
    std::ostringstream output;
    output
    << std::setw(4) << pid
    << std::setw(8) << arrival
    << std::setw(9) << CPUburst
    << std::setw(7) << finish
    << std::setw(8) << waiting
    << std::setw(11) << turnaround
    << std::setw(9) << response
    << std::setw(9) << context;
    return output.str();
}
