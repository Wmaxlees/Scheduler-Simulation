//
// Created by William Lees on 10/14/15.
//

#ifndef SCHEDULER_SIMULATION_PROCESS_H
#define SCHEDULER_SIMULATION_PROCESS_H

#include <ostream>

class Process {
public:
    Process() {
        this->m_ArrivalTime = 0;
        this->m_PID = 0;
        this->m_ArrivalTime = 0;
        this->m_BurstTime = 0;

        this->m_LastSeen = 0;
        this->m_RemainingTime = 0;
        this->m_StartTime = 0;

        // Process Time Data
        this->m_FinishTime = 0;
        this->m_TurnaroundTime = 0;
        this->m_WaitTime = 0;
        this->m_ResponseTime = 0;
        this->m_ContextSwitch = 0;
    }

    unsigned int getM_PID() const {
        return m_PID;
    }

    void setM_PID(unsigned int m_PID) {
        Process::m_PID = m_PID;
    }

    unsigned int getM_ArrivalTime() const {
        return m_ArrivalTime;
    }

    void setM_ArrivalTime(unsigned int m_ArrivalTime) {
        Process::m_ArrivalTime = m_ArrivalTime;
    }

    unsigned int getM_BurstTime() const {
        return m_BurstTime;
    }

    void setM_BurstTime(unsigned int m_BurstTime) {
        Process::m_BurstTime = m_BurstTime;
        Process::m_RemainingTime = m_BurstTime;
    }

    unsigned int getM_FinishTime() const {
        return m_FinishTime;
    }

    void setM_FinishTime(unsigned int m_FinishTime) {
        Process::m_FinishTime = m_FinishTime;
    }

    unsigned int getM_TurnaroundTime() const {
        return m_TurnaroundTime;
    }

    void setM_TurnaroundTime(unsigned int m_TurnaroundTime) {
        Process::m_TurnaroundTime = m_TurnaroundTime;
    }

    unsigned int getM_WaitTime() const {
        return m_WaitTime;
    }

    void setM_WaitTime(unsigned int m_WaitTime) {
        Process::m_WaitTime = m_WaitTime;
    }

    unsigned int getM_ResponseTime() const {
        return m_ResponseTime;
    }

    void setM_ResponseTime(unsigned int m_ResponseTime) {
        Process::m_ResponseTime = m_ResponseTime;
    }

    unsigned int getM_ContextSwitch() const {
        return m_ContextSwitch;
    }

    void setM_ContextSwitch(unsigned int m_ContextSwitch) {
        Process::m_ContextSwitch = m_ContextSwitch;
    }

    unsigned int getM_LastSeen() const {
        return m_LastSeen;
    }

    void setM_LastSeen(unsigned int m_LastSeen) {
        Process::m_LastSeen = m_LastSeen;
    }

    unsigned int getM_RemainingTime() const {
        return m_RemainingTime;
    }

    void setM_RemainingTime(unsigned int m_RemainingTime) {
        Process::m_RemainingTime = m_RemainingTime;
    }

    unsigned int getM_StartTime() const {
        return m_StartTime;
    }

    void setM_StartTime(unsigned int m_StartTime) {
        Process::m_StartTime = m_StartTime;
    }

    friend std::ostream& operator<<(std::ostream& os, const Process& process);

private:
    // Run Metadata
    unsigned int        m_PID;
    unsigned int        m_ArrivalTime;
    unsigned int        m_BurstTime;

    unsigned int        m_LastSeen;
    unsigned int        m_RemainingTime;
    unsigned int        m_StartTime;

    // Process Time Data
    unsigned int        m_FinishTime;
    unsigned int        m_TurnaroundTime;   // Finish Time - Start Time
    unsigned int        m_WaitTime;         // Turnaround Time - Burst Time
    unsigned int        m_ResponseTime;     // Start Time - First Time Processed
    unsigned int        m_ContextSwitch;

};


#endif //SCHEDULER_SIMULATION_PROCESS_H
