/*
    5. Write a C program to simulate the Round Robin CPU scheduling algorithms.
*/

#include <stdio.h>

int main() {
    int i, limit, totalTime = 0; 
    int x, counter = 0, quantum; 
    int waitTime = 0; 
    int turnaroundTime = 0; 
    int arrivalTime[10]; 
    int burstTime[10]; 
    int temp[10]; 
    float avgWaitTime; 
    float avgTurnaroundTime; 
    printf("\nEnter totalTime Number of Processes:\t"); 
    scanf("%d", &limit); 
    x = limit; 
    for(i = 0; i < limit; i++) { 
        printf("\nEnter Details of Process[%d]\n", i + 1); 
        printf("Arrival Time: \t"); 
        scanf("%d", &arrivalTime[i]); 
        printf("Burst Time: \t"); 
        scanf("%d", &burstTime[i]); 
        temp[i] = burstTime[i]; 
    }
    printf("\nEnter Time Quantum: \t"); 
    scanf("%d", &quantum); 
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n"); 
    for(totalTime = 0, i = 0; x != 0; ) { 
        if((temp[i] <= quantum) && (temp[i] > 0)) { 
            totalTime = (totalTime + temp[i]); 
            temp[i] = 0; 
            counter = 1; 
        }
        else if(temp[i] > 0) { 
            temp[i] = (temp[i] - quantum); 
            totalTime = (totalTime + quantum); 
        }
        if((temp[i] == 0) && (counter == 1)) { 
            x--; 
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", 
                (i + 1), burstTime[i], (totalTime - arrivalTime[i]), 
                (totalTime - arrivalTime[i] - burstTime[i])); 
            waitTime = (waitTime + totalTime - arrivalTime[i] - burstTime[i]); 
            turnaroundTime = (turnaroundTime + totalTime - arrivalTime[i]); 
            counter = 0; // set the counter to 0
        }
        if(i == limit - 1) { 
            i = 0; 
        } else if(arrivalTime[i + 1] <= totalTime) { 
            i++; 
        } else { 
            i = 0; 
        }
    }
 
    avgWaitTime = (waitTime * 1.0 / limit); 
    avgTurnaroundTime = (turnaroundTime * 1.0 / limit); 
    printf("\n\nAverage Waiting Time:\t%f", avgWaitTime); 
    printf("\nAverage Turnaround Time:\t%f\n", avgTurnaroundTime); 
    return 0;
}
