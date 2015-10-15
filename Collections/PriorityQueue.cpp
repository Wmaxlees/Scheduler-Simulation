//
// Created by William Lees on 10/14/15.
//

#include "PriorityQueue.h"

// Create the queue with a specific size (cannot be resized)
PriorityQueue::PriorityQueue(unsigned int size) {
    this->m_pProcessQueue = new PrioityPair[size];
}

PriorityQueue::~PriorityQueue() {
    if (this->m_pProcessQueue != nullptr) {
        delete [] this->m_pProcessQueue;
        this->m_pProcessQueue = nullptr;
    }
}

// Remove the process from the front of the queue and return it
Process PriorityQueue::pop() {
    // Make sure there are items on the queue
    if (this->m_Back < 1) {
        throw "Attepting to access element of empty queue";
    }

    // Get the first item off the queue
    Process process = this->m_pProcessQueue[0].process;

    // Shift the rest of the queue forward
    for (unsigned int i = 1; i <= this->m_Back; ++i) {
        this->m_pProcessQueue[i-1] = this->m_pProcessQueue[i];
    }
    --this->m_Back;

    return process;
}

// Add a process to the end of the queue
void PriorityQueue::push(Process process, unsigned int priority) {
    // Check if there is space
    if (this->m_Back == this->m_Size) {
        throw "Attempting to push onto a full queue";
    }

    // Create the pair
    PrioityPair pair;
    pair.process = process;
    pair.priority = priority;

    // Check if queue is already empty
    if (this->m_Back == 0) {
        this->m_pProcessQueue[0] = pair;
    }

    // Find the spot for the process to go


    // Incremement the back
    ++this->m_Back;
}

// Generate the correct index for the new item
unsigned int getIndex(unsigned int priority, const PriorityQueue& queue) {
    unsigned int bottom = 0;
    unsigned int top = queue.m_Size-1;

    while (top >= bottom) {
        // Figure out the half way point
        unsigned int middle = top - ((top-bottom)/2);

        // Check the value in the middle
        if (queue.m_pProcessQueue[middle].priority > priority) {
            bottom = middle+1;
            continue;
        } else if (queue.m_pProcessQueue[middle].priority < priority) {
            top = middle-1;
            continue;
        } else if (queue.m_pProcessQueue[middle].priority == priority) {
            return middle;
        }
    }

    return queue.m_Size + 1;
}

std::ostream& operator<<(std::ostream& os, const PriorityQueue& queue) {
    for (unsigned int i = 0; i < queue.m_Size; ++i) {
        if (i < queue.m_Back) {
            os << "[" << queue.m_pProcessQueue[i].process.getPID() << ">" << queue.m_pProcessQueue[i].priority << "]";
        } else {
            os << "[x]";
        }
    }

    os << std::endl;

    return os;
}