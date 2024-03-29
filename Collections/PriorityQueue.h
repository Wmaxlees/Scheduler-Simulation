//
// Created by William Lees on 10/14/15.
//

#ifndef SCHEDULER_SIMULATION_PRIORITYQUEUE_H
#define SCHEDULER_SIMULATION_PRIORITYQUEUE_H

#include <ostream>

#include "../Process.h"
#include "Queue.h"


class PriorityQueue {
private:
    struct PrioityPair {
    public:
        unsigned int    priority;
        Process         process;
    };

public:
    // Create the queue with a specific size (cannot be resized)
    explicit PriorityQueue(unsigned int size);

    ~PriorityQueue();

    // Remove the process from the front of the queue and return it
    Process pop();
    const Process &peek() {
        return (*m_pProcessQueue).process;
    }

    // Add a process to the end of the queue
    void push(Process process, unsigned int priority);

    unsigned int getSize() {
        return m_Back;
    }

    friend std::ostream& operator<<(std::ostream& os, const PriorityQueue& queue);
    friend unsigned int getIndex(unsigned int priority, const PriorityQueue& queue);

private:
    PrioityPair     *m_pProcessQueue;
    unsigned  int    m_Size;
    int              m_Back;

};


#endif //SCHEDULER_SIMULATION_PRIORITYQUEUE_H
