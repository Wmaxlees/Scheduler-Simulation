//
// Created by William Lees on 10/14/15.
//

#include "Process.h"


unsigned int Process::getPID() const {
    return m_PID;
}

void Process::setPID(unsigned int PID) {
    Process::m_PID = PID;
}

unsigned int Process::getArrivalTime() const {
    return m_ArrivalTime;
}

void Process::setArrivalTime(unsigned int arrivalTime) {
    Process::m_ArrivalTime = arrivalTime;
}

unsigned int Process::getBurstTime() const {
    return m_BurstTime;
}

void Process::setBurstTime(unsigned int burstTime) {
    Process::m_BurstTime = burstTime;
}