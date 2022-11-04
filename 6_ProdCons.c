/*
    6. Write a C program to simulate producer-consumer problem using semaphores.
*/

#include <stdio.h>
#include <stdlib.h>

int mutex=1, full=0, empty=3, x=0; // Initialization of semaphores 

void producer(); // producer() Function prototypes
void consumer(); // consumer() Function prototypes

int main() {
    int n;
    printf("\n1. Producer\n2. Consumer\n3. Exit");
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch(n) {
            case 1: 
                if((mutex==1) && (empty!=0)) {
                    producer();
                }
                else {
                    printf("Buffer is full!!");
                }
                break;
            case 2: 
                if((mutex==1) && (full!=0)) {
                    consumer();
                }
                else {
                    printf("Buffer is empty!!");
                }
                break;

            case 3:
                printf("Exiting");
                exit(0);
                break;
        }
    }
    return 0;
}

void producer() {
    --mutex;    // acquire mutex lock
    ++full;     // increment full
    --empty;    // decrement empty
    x++;        // increment x
    printf("Producer produces the item %d", x); // print the item produced
    ++mutex;    // release mutex lock
}

void consumer() {
    --mutex;    // acquire mutex lock
    --full;     // decrement full
    ++empty;    // increment empty
    printf("Consumer consumes the item %d", x); // print the item consumed
    x--;        // decrement x
    ++mutex;    // release mutex lock
}