/*
    7. Write a C program to simulate Bankers algorithm for the purpose of deadlock avoidance.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int Max[10][10], need[10][10], alloc[10][10], availableResources[10], completed[10], safeSequence[10];
    int numProcesses, numResources, i, j, process, count;
    count = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    for(i = 0; i < numProcesses; i++) {
        completed[i] = 0;
    }
    printf("\n\nEnter the number of resources: ");
    scanf("%d", &numResources);
    printf("\n\nEnter the Max Matrix for each process:"); 
    for(i = 0; i < numProcesses; i++) {
        printf("\nFor process %d: ", i + 1);
        for(j = 0; j < numResources; j++) {
            scanf("%d", &Max[i][j]);
        }
    }
    printf("\n\nEnter the allocation for each process: ");
    for(i = 0; i < numProcesses; i++) {
        printf("\nFor process %d: ",i + 1);
        for(j = 0; j < numResources; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\n\nEnter the Available Resources: ");
    for(i = 0; i < numResources; i++) {
        scanf("%d", &availableResources[i]);
    }
    for(i = 0; i < numProcesses; i++) {
        for(j = 0; j < numResources; j++) {
            need[i][j] = Max[i][j] - alloc[i][j];
        }
    }
    do {
        printf("\n Max matrix:\tAllocation matrix:\n");
        for(i = 0; i < numProcesses; i++) {
            for(j = 0; j < numResources; j++) {
                printf("%d ", Max[i][j]);
            }
            printf("\t\t");
            for(j = 0; j < numResources; j++) {
                printf("%d ", alloc[i][j]);
            }
            printf("\n");
        }
        process = -1;
        for(i = 0; i < numProcesses; i++) {
            if(completed[i] == 0) { //if not completed 
                process = i;
                for(j = 0; j < numResources; j++) {
                    if(availableResources[j] < need[i][j]) {
                        process = -1;
                        break;
                    }
                }
            }
            if(process != -1)
                break;
        }
        if(process != -1) {
            printf("\nProcess %d runs to completion!", process + 1);
            safeSequence[count] = process + 1; count++;
            for(j = 0; j < numResources; j++) {
                availableResources[j] += alloc[process][j];
                alloc[process][j] = 0;
                Max[process][j] = 0;
                completed[process] = 1;
            }
        }
    }
    while(count != numProcesses && process != -1);
    if(count == numProcesses) {
        printf("\nThe system is in a safe state!!\n");
        printf("Safe Sequence: < "); 
        for( i = 0; i < numProcesses; i++) {
            printf("%d ", safeSequence[i]);
        }
        printf(">\n");
    }
    else
        printf("\nThe system is in an unsafe state!!");
}