//
// Created by William Lees on 10/14/15.
//

#ifndef SCHEDULER_SIMULATION_QUEUE_H
#define SCHEDULER_SIMULATION_QUEUE_H

#include <ostream>

#include "Process.h"

class Queue {
public:
    // Create the queue with a specific size (cannot be resized)
    explicit Queue(unsigned int size);
    ~Queue();

    // Remove the process from the front of the queue and return it
    Process pop();

    // Add a process to the end of the queue
    void push(Process process);

    friend std::ostream& operator<<(std::ostream& os, const Queue& queue);

private:
    Process         *m_pProcessQueue;
    unsigned  int    m_Size;
    int              m_Front;
    int              m_Back;
    bool             m_Full;
};

#endif //SCHEDULER_SIMULATION_QUEUE_H
