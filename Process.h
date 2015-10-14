//
// Created by William Lees on 10/14/15.
//

#ifndef SCHEDULER_SIMULATION_PROCESS_H
#define SCHEDULER_SIMULATION_PROCESS_H


class Process {
public:
    unsigned int getPID() const;
    void setPID(unsigned int PID);

    unsigned int getArrivalTime() const;
    void setArrivalTime(unsigned int arrivalTime);

    unsigned int getBurstTime() const;
    void setBurstTime(unsigned int burstTime);

private:
    unsigned int        m_PID;
    unsigned int        m_ArrivalTime;
    unsigned int        m_BurstTime;

};


#endif //SCHEDULER_SIMULATION_PROCESS_H
