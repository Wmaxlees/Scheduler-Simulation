//
// Created by William Lees on 10/14/15.
//

#include "Process.h"

#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Process& process) {
    os << std::setw(20) << std::left << "PID" << process.getM_PID() << '\n' <<
    std::setw(20) << "Arrival" << process.getM_ArrivalTime() << '\n' <<
    std::setw(20) << "CPU Burst" << process.getM_BurstTime() << '\n' <<
    std::setw(20) << "Start Time" << process.getM_StartTime() << '\n' <<
    std::setw(20) << "Last Seen" << process.getM_LastSeen() << '\n' <<
    std::setw(20) << "Remaining" << process.getM_RemainingTime() << '\n' <<
    std::setw(20) << "Finish" << process.getM_FinishTime() << '\n' <<
    std::setw(20) << "Waiting Time" << process.getM_WaitTime() << '\n' <<
    std::setw(20) << "Turn Around" << process.getM_TurnaroundTime() << '\n' <<
    std::setw(20) << "Response Time" << process.getM_ResponseTime() << '\n' <<
    std::setw(20) << "Context Switches" << process.getM_ContextSwitch() << std::right << std::endl;

    return os;
}