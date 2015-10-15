//
// Created by William Lees on 10/14/15.
//

#ifndef SCHEDULER_SIMULATION_PREEMPTIVESCHEDULER_H
#define SCHEDULER_SIMULATION_PREEMPTIVESCHEDULER_H

#include "Process.h"

class PreemptiveScheduler {
public:
    virtual Process getNextProcess() = 0;
    virtual bool addProcess(Process process) = 0;
};


#endif //SCHEDULER_SIMULATION_PREEMPTIVESCHEDULER_H
