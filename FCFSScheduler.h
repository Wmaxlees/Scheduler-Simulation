//
// Created by William Lees on 10/14/15.
//

#ifndef SCHEDULER_SIMULATION_FCFSSCHEDULER_H
#define SCHEDULER_SIMULATION_FCFSSCHEDULER_H

#include "Scheduler.h"
#include "Collections/Queue.h"

class FCFSScheduler : public Scheduler {
public:
    // Constructor
    explicit FCFSScheduler(unsigned int size);

    // Implementations of Scheduler functions
    Process getNextProcess();
    void addProcess(Process process);

private:
    Queue       m_Queue;
};


#endif //SCHEDULER_SIMULATION_FCFSSCHEDULER_H
