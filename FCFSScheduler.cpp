//
// Created by William Lees on 10/14/15.
//

#include "FCFSScheduler.h"

// Constructor
FCFSScheduler::FCFSScheduler(unsigned int size) : m_Queue(size) {

}

// Implementations of Scheduler functions
Process FCFSScheduler::getNextProcess() {
    return this->m_Queue.pop();
}

void FCFSScheduler::addProcess(Process process) {
    this->m_Queue.push(process);
}