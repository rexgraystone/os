/*  
    1.  Write a C program to create a new process 
        that executes a new program using the following 
        system calls: fork(), execlp() & wait().
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *arg[]) { // argc = argument count, arg = argument vector
    int pID; // pID = process id
    pID = fork(); // create a child process
    if(pID < 0) { // if the process ID is less than 0
        printf("Fork failed"); // print fork failed
        exit(1); // exit the program
    }
    else if(pID == 0) { // if the process ID is 0
        printf("\nNow in Child Process and it's output is \n"); // print now in child process
        execlp("ls", "ls", NULL); // execute the ls command
        exit(0); // exit the program
    }
    else { // if the process ID is greater than 0
        printf("\nChild Process created successfully\n"); // print child process created successfully
        printf("\nIt's Process ID is %d\n", getpid()); // print the process ID
        wait(NULL); // wait for the child process to finish
        printf("\nReturn back to Parent process, now ready to exit\n"); // print return back to parent process
        exit(0); // exit the program
    }
    return 0;
}
