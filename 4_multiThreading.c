/*
    4. Write a C program to implement multithreaded program using pthreads.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int g = 0; // global variable

void *myThreadFun(void * vargp)  {
    int *myid = (int *)vargp; // store the value argument passed to this thread
    static int s = 0; // static variable
    ++s; // increment static variable
    ++g; // increment global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g); // print the argument, static and global variables
}

int main() {
    int i; // i = loop variable
    pthread_t tid; // tid = thread ID
    for (i = 0; i < 3; i++) { // for loop to create three threads
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid); // create a thread
    }
    pthread_exit(NULL); // exit the thread
    return 0;
}