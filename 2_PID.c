/* 
2.  Write a C program to display PID and PPID 
    using system calls getpid () & getppid ()
*/

#include <stdio.h> 
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h> 

int main() {
    int pid;
    pid = fork();
    if(!pid) {
        printf("Child Process..."); 
        printf("\n\nChild PID: %d", getpid()); 
        printf("\nParent PID: %d", getppid()); 
        printf("\n\nFinished with child\n");
    }
    else {
        wait(NULL);
        printf("\nParent Process..."); 
        printf("\nParent PID: %d", getpid()); 
        printf("\nChild PID: %d\n", pid);
    }
    return 0;
}