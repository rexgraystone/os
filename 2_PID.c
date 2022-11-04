/* 
    2.  Write a C program to display PID and PPID using system calls getpid () & getppid ().
*/

#include <stdio.h> 
#include <sys/types.h> // for getpid() and getppid()
#include <sys/wait.h> // to avoid warnings for wait()
#include <unistd.h> 

int main() {
    int pID; // pID = process id
    pID = fork(); // create a child process
    if(!pID) { // if the process ID is 0
        printf("Child Process..."); // print child process
        printf("\n\nChild PID: %d", getpid()); // print the child process ID
        printf("\nParent PID: %d", getppid()); // print the parent process ID
        printf("\n\nFinished with child\n"); // print finished with child
    }
    else { // if the process ID is greater than 0
        wait(NULL); // wait for the child process to finish
        printf("\nParent Process..."); // print parent process
        printf("\nParent PID: %d", getpid()); // print the parent process ID
        printf("\nChild PID: %d\n", pID); // print the child process ID
    }
    return 0;
}