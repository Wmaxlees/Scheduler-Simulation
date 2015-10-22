//
// Created by William Lees on 10/14/15.
//

#include "Queue.h"

#include <iostream>

Queue::Queue(unsigned int size) {
    // Sanity Check
    if (size == 0) {
        throw "Size must be greater than 0";
    }

    // Allocate memory for the process queue
    this->m_pProcessQueue = new Process[size];

    // Set the front and back pointers
    this->m_Front = 0;
    this->m_Back = 0;

    // Set the size
    this->m_Size = size;
    this->m_Full = false;
}

Queue::~Queue() {
    // Release the queue array pointer
    if (this->m_pProcessQueue != nullptr) {
        delete [] this->m_pProcessQueue;
        this->m_pProcessQueue = nullptr;
    }
}

// Remove the process from the front of the queue and return it
Process Queue::pop() {
    // Check that the queue isn't empty
    if (this->m_Front == this->m_Back) {
        if (!this->m_Full) {
            throw "Attempting to pop an empty queue";
        } else {
            this->m_Full = false;
        }
    }

    // Get a pointer to the current end of the queue
    Process *result = &this->m_pProcessQueue[this->m_Back];

    // Figure out the new back of the queue
    this->m_Back = (this->m_Back + 1) % this->m_Size;

    return *result;
}

// Add a process to the end of the queue
void Queue::push(Process process) {
    // Check if the queue is full
    if (this->m_Front == this->m_Back && this->m_Full == true) {
        throw "Queue is full";
    }

    // Add the new item
    this->m_pProcessQueue[this->m_Front] = process;

    // Advance the front pointer
    this->m_Front = (this->m_Front + 1) % this->m_Size;

    if (this->m_Front == this->m_Back) {
        this->m_Full = true;
    }
}

std::ostream& operator<<(std::ostream& os, const Queue& queue)
{
    os << "Queue: ";
    for (unsigned int i = 0; i < queue.m_Size; ++i) {
        if ((queue.m_Back > queue.m_Front && i < queue.m_Back && i >= queue.m_Front) ||
            (queue.m_Back < queue.m_Front && (i < queue.m_Back || i >= queue.m_Front)) ||
            (queue.m_Back == queue.m_Front && queue.m_Full == false)) {
            os << "[x]";
        } else {
            os << "[" << queue.m_pProcessQueue[i].getM_PID() << "]";
        }
    }

    os << std::endl;

    return os;
}

