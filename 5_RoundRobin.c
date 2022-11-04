/*
    5. Write a C program to simulate the Round Robin CPU scheduling algorithms.
*/

#include <stdio.h>

int main() {
    int i, limit, totalTime = 0; // i = loop variable, limit = number of processes, totalTime = total time
    int x, counter = 0, quantum; // x = loop variable, counter = counter, quantum = time quantum
    int waitTime = 0; 
    int turnaroundTime = 0; 
    int arrivalTime[10]; 
    int burstTime[10]; 
    int temp[10]; // temp = temporary array
    float avgWaitTime; 
    float avgTurnaroundTime; 
    printf("\nEnter totalTime Number of Processes:\t"); // input the number of processes
    scanf("%d", &limit); // store the number of processes in limit
    x = limit; // store the number of processes in x
    for(i = 0; i < limit; i++) { // loop to input the arrival time and burst time of each process
        printf("\nEnter Details of Process[%d]\n", i + 1); // input the arrival time and burst time of each process
        printf("Arrival Time: \t"); // input the arrival time
        scanf("%d", &arrivalTime[i]); // store the arrival time in arrivalTime[i]
        printf("Burst Time: \t"); // input the burst time
        scanf("%d", &burstTime[i]); // store the burst time in burstTime[i]
        temp[i] = burstTime[i]; // store the burst time in temp[i]
    }
 
    printf("\nEnter Time Quantum: \t"); // input the time quantum
    scanf("%d", &quantum); // store the time quantum in quantum
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n"); // print the headings
    for(totalTime = 0, i = 0; x != 0; ) { // loop to calculate the waiting time, turnaround time and totalTime time
        if((temp[i] <= quantum) && (temp[i] > 0)) { // if the burst time is less than or equal to the time quantum and greater than 0
            totalTime = (totalTime + temp[i]); // add the burst time to the totalTime time
            temp[i] = 0; // set the burst time to 0
            counter = 1; // set the counter to 1
        }
        else if(temp[i] > 0) { // if the burst time is greater than 0
            temp[i] = (temp[i] - quantum); // subtract the time quantum from the burst time
            totalTime = (totalTime + quantum); // add the time quantum to the totalTime time
        }
        if((temp[i] == 0) && (counter == 1)) { // if the burst time is 0 and the counter is 1
            x--; // decrement x
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", 
                (i + 1), burstTime[i], (totalTime - arrivalTime[i]), 
                (totalTime - arrivalTime[i] - burstTime[i])); // print the process ID, burst time, turnaround time and waiting time
            waitTime = (waitTime + totalTime - arrivalTime[i] - burstTime[i]); // calculate the waiting time
            turnaroundTime = (turnaroundTime + totalTime - arrivalTime[i]); // calculate the turnaround time
            counter = 0; // set the counter to 0
        }
        if(i == limit - 1) { // if i is equal to the number of processes - 1
            i = 0; // set i to 0
        }
        else if(arrivalTime[i + 1] <= totalTime) { // if the arrival time of the next process is less than or equal to the totalTime time
            i++; // increment i
        }
        else { // if the arrival time of the next process is greater than the totalTime time
            i = 0; // set i to 0
        }
    }
 
    avgWaitTime = (waitTime * 1.0 / limit); // calculate the average waiting time
    avgTurnaroundTime = (turnaroundTime * 1.0 / limit); // calculate the average turnaround time
    printf("\n\nAverage Waiting Time:\t%f", avgWaitTime); // print the average waiting time
    printf("\nAverage Turnaround Time:\t%f\n", avgTurnaroundTime); // print the average turnaround time
    return 0;
}
