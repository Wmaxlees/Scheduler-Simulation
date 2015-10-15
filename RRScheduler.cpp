//
// Created by William Lees on 10/14/15.
//

#include "RRScheduler.h"

// Constructor
RRScheduler::RRScheduler(unsigned int size, unsigned int sliceSize) : m_Queue(size) {
    this->m_SliceSize = sliceSize;
}

// Implementations of Scheduler functions
Process RRScheduler::getNextProcess() {
    this->m_CurrentProcess = this->m_Queue.pop();
}

void RRScheduler::addProcess(Process process) {
    this->m_Queue.push(process);
}