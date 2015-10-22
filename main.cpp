#include <iostream>
#include <fstream>
#include <iomanip>

#include "Collections/Queue.h"
#include "Collections/PriorityQueue.h"

#define             MAX_FILE_SIZE           12

void runRR(Queue queue, unsigned short quantumSize);
void runSRFT(PriorityQueue queue);
void loadQueue(Queue &queue, std::fstream &file);
void loadPriorityQueue(PriorityQueue &queue, std::fstream &file);
void printResults(PriorityQueue queue);

enum Algorithm {
    FCFS = 0,
    SRTF,
    RR
};

void printUsage() {
    std::cout <<    "Usage:\n \t SchedulerSimulation <filename> <algorithm> <quantum size>\n\n"
                    "\t filename: \t The name of the file containing the process metadata.\n"
                    "\t\t\t Metadata should be formatted as follows: pid arrival_time cpu_burst\\n\n\n"
                    "\t algorithm: \t The scheduling algorithm to be used for choosing processes to run\n"
                    "\t\t\t 0 = FCFS \n"
                    "\t\t\t 1 = SRTF \n"
                    "\t\t\t 2 = RR\n\n"
                    "\tquantum size: \t Only necessary for RR style scheduling algorithms. Specifies\n"
                    "\t\t\t the number of slices each process gets while on the CPU" << std::endl;
}


int main(int argc, char** argv) {
    unsigned short  algorithm;
    unsigned short  quantumSize;
    char*           filename;

    try {

        if (argc >= 3) {
            filename = argv[1];
            algorithm = strtol(argv[2], nullptr, 10);

            if (algorithm == RR) {
                quantumSize = strtol(argv[3], nullptr, 10);
            } else if (algorithm == FCFS) {
                quantumSize = USHRT_MAX;
            }
        } else {
            printUsage();
            return -1;
        }

        // Open the file
        std::fstream file(filename, std::ios_base::in);


        switch (algorithm) {
            case FCFS:
            case RR: {
                Queue queue(MAX_FILE_SIZE);
                loadQueue(queue, file);
                runRR(queue, quantumSize);
                break;
            }

            case SRTF: {
                PriorityQueue queue(MAX_FILE_SIZE);
                loadPriorityQueue(queue, file);
                runSRFT(queue);
                break;
            }

            default:
                std::cout << "Not a known algorithm.\n\n";
                printUsage();
                return -1;
        }
    } catch (const char* e) {
        std::cout << e << std::endl;
    }

    return 0;
}

void runRR(Queue queue, unsigned short quantumSize) {
    unsigned long runtime = 0;
    PriorityQueue finishedQueue(MAX_FILE_SIZE);

    while (queue.getSize() > 0) {
        Process process = queue.pop();

        std::cout << "Queue: " << queue;
        std::cout << "Process:\n" << process << std::endl;

        // process.setM_WaitTime(process.getM_WaitTime() + (runtime - process.getM_LastSeen()));

        while (process.getM_ArrivalTime() > runtime) {
            // std::cout << "No Processes in queue. Waiting 1 tick..." << std::endl;
            ++runtime;
        }

        // Set start time if needed
        if (process.getM_LastSeen() == 0) {
            // std::cout << "First time run\nSetting start time to: " << runtime << std::endl;
            process.setM_StartTime(runtime);

            // std::cout << "Start Time: " << process.getM_StartTime() << "\n";
            // std::cout << "Arrival Time: " << process.getM_ArrivalTime() << std::endl;
            process.setM_ResponseTime(process.getM_StartTime() - process.getM_ArrivalTime());
        }

        if (process.getM_RemainingTime() > quantumSize) {
            // std::cout << "Progression" << std::endl;
            process.setM_RemainingTime(process.getM_RemainingTime() - quantumSize);
            process.setM_ContextSwitch(process.getM_ContextSwitch() + 1);

            // std::cout << "--" << std::endl;

            // Increment the runtime
            runtime += quantumSize;

            process.setM_LastSeen(runtime);

            // std::cout << "--" << std::endl;

            queue.push(process);

            // std::cout << "--";
        } else {// if (process.getM_RemainingTime() <= quantumSize) {
            // std::cout << "Final Run" << std::endl;
            runtime += process.getM_RemainingTime();
            process.setM_RemainingTime(0);

            // std::cout << "--" << std::endl;

            process.setM_FinishTime(runtime);
            process.setM_TurnaroundTime(runtime - process.getM_ArrivalTime());
            process.setM_WaitTime(process.getM_FinishTime() - process.getM_ArrivalTime() - process.getM_BurstTime());

            // std::cout << "--" << std::endl;

            finishedQueue.push(process, process.getM_PID());

            // std::cout << "--" << std::endl;
        }
    }

    printResults(finishedQueue);
}

void runSRFT(PriorityQueue queue) {

}

void loadQueue(Queue &queue, std::fstream &file) {
    unsigned int pid, arrivalTime, burstTime;
    while((file >> pid) && (file >> arrivalTime) && (file >> burstTime)) {
        Process process;
        process.setM_PID(pid);
        process.setM_ArrivalTime(arrivalTime);
        process.setM_BurstTime(burstTime);

        queue.push(process);
    }
}

void loadPriorityQueue(PriorityQueue &queue, std::fstream &file) {
    unsigned int pid, arrivalTime, burstTime;
    while((file >> pid) && (file >> arrivalTime) && (file >> burstTime)) {
        Process process;
        process.setM_PID(pid);
        process.setM_ArrivalTime(arrivalTime);
        process.setM_BurstTime(burstTime);

        queue.push(process, burstTime);
    }
}

void printResults(PriorityQueue queue) {
    unsigned int    waitAvg = 0, turnAroundAvg = 0, respAvg = 0, switchAvg = 0;
    unsigned int    size = queue.getSize();

    std::cout << std::setw(6) << "PID" <<
                 std::setw(8) << "Arrival" <<
                 std::setw(10) << "CPU Burst" <<
                 std::setw(15) << "Start Time" <<
                 std::setw(8) << "Finish" <<
                 std::setw(15) << "Waiting Time" <<
                 std::setw(15) << "Turn Around" <<
                 std::setw(15) << "Response Time" <<
                 std::setw(20) << "Context Switches" << std::endl;

    while (queue.getSize() > 0) {
        Process process = queue.pop();

        // add to avg
        waitAvg += process.getM_WaitTime();
        turnAroundAvg += process.getM_TurnaroundTime();
        respAvg += process.getM_ResponseTime();
        switchAvg += process.getM_ContextSwitch();

        // Print
        std::cout << std::setw(6) << process.getM_PID()
                  << std::setw(8) << process.getM_ArrivalTime()
                  << std::setw(10) << process.getM_BurstTime()
                  << std::setw(15) << process.getM_StartTime()
                  << std::setw(8) << process.getM_FinishTime()
                  << std::setw(15) << process.getM_WaitTime()
                  << std::setw(15) << process.getM_TurnaroundTime()
                  << std::setw(15) << process.getM_ResponseTime()
                  << std::setw(20) << process.getM_ContextSwitch() << std::endl;
    }

    std::cout << std::setfill('-') << std::setw(115) << "" << std::setfill(' ');
    std::cout << "\n" << std::setw(42) << "Averages:" << std::setw(5) << ""
            << std::setw(15) << (double)waitAvg/(double)size
            << std::setw(15) << (double)turnAroundAvg/(double)size
            << std::setw(15) << (double)respAvg/(double)size
            << std::setw(20) << (double)switchAvg/(double)size << std::endl;

}