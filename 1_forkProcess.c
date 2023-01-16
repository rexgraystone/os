/*  
    1.  Write a C program to create a new process 
        that executes a new program using the following 
        system calls: fork(), execlp() & wait().
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // to avoid warnings for wait()

int main(int argc, char *arg[]) { // argc = argument count, arg = argument vector
    int pID; // pID = process id
    pID = fork(); // create a child process
    if(pID < 0) { 
        printf("Fork failed"); 
        exit(1); 
    } else if(pID == 0) { 
        printf("\nNow in Child Process and it's output is \n"); 
        execlp("ls", "ls", NULL); // execute the ls command
        exit(0); 
    } else { // if the process ID is greater than 0
        printf("\nChild Process created successfully\n"); 
        printf("\nIt's Process ID is %d\n", getpid()); 
        wait(NULL); // wait for the child process to finish
        printf("\nReturn back to Parent process, now ready to exit\n"); 
        exit(0); 
    }
    return 0;
}
