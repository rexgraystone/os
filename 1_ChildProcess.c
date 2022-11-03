/*  
1.  Write a C program to create a new process 
    that executes a new program using the following 
    system calls: fork(), execlp() & wait().
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *arg[])
{
    int pid;
    pid = fork();
    if(pid < 0)
    {
        printf("Fork failed");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("\nNow in Child Process and it's output is \n");
        execlp("exa", "ls", NULL);
        exit(0);
    }
    else
    {
        printf("\nChild Process created successfully\n");
        printf("\nIt's Process ID is %d\n", getpid());
        wait(NULL);
        printf("\nReturn back to Parent process, now ready to exit\n");
        exit(0);
    }
    return 0;
}
