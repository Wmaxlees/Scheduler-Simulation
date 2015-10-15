//
// Created by William Lees on 10/14/15.
//

#ifndef SCHEDULER_SIMULATION_RRSCHEDULER_H
#define SCHEDULER_SIMULATION_RRSCHEDULER_H

#include "Process.h"
#include "Collections/Queue.h"

class RRScheduler {
public:
    // Constructor
    explicit RRScheduler(unsigned int size, unsigned int sliceSize);

    // Implementations of Scheduler functions
    Process getNextProcess();
    void addProcess(Process process);

private:
    Queue               m_Queue;
    unsigned int        m_SliceSize;
    Process             m_CurrentProcess;
};


#endif //SCHEDULER_SIMULATION_RRSCHEDULER_H
