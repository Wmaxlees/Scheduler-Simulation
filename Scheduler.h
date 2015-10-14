//
// Created by William Lees on 10/14/15.
//

#ifndef SCHEDULER_SIMULATION_SCHEDULER_H
#define SCHEDULER_SIMULATION_SCHEDULER_H

#include "Process.h"

class Scheduler {
public:
    virtual Process getNextProcess() = 0;
    virtual void addProcess(Process process) = 0;
};


#endif //SCHEDULER_SIMULATION_SCHEDULER_H
