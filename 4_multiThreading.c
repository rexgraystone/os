/*
    4. Write a C program to implement multithreaded program using pthreads.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int g = 0; 

/**
 * @brief prints the thread ID, static variable and global variable 
 * 
 * @param vargp 
 * @return void* 
 */
void *myThreadFunc(void * vargp)  {
    int *myID = (int *)vargp; // store the value argument passed to this thread
    static int s = 0; 
    ++s; 
    ++g; 
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myID, ++s, ++g); 
}

int main() {
    int i; 
    pthread_t tID; 
    for (i = 0; i < 3; i++) { 
        pthread_create(&tID, NULL, myThreadFunc, (void *)&tID); 
    }
    pthread_exit(NULL); 
    return 0;
}