/* 
    2.  Write a C program to display PID and PPID using system calls getpid() & getppid().
*/

#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h> // for getpid() and getppid()
#include <sys/wait.h> // to avoid warnings for wait()
 
int main() {
    int pID; // pID = process id
    pID = fork(); // create a child process
    if(!pID) { // if the process ID is 0
        printf("Child Process..."); 
        printf("\n\nChild PID: %d", getpid()); 
        printf("\nParent PID: %d", getppid()); 
        printf("\n\nFinished with child\n"); 
    } else { // if the process ID is greater than 0
        wait(NULL); // wait for the child process to finish
        printf("\nParent Process..."); 
        printf("\nParent PID: %d", getpid()); 
        printf("\nChild PID: %d\n", pID); 
    }
    return 0;
}