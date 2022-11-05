/*
    6. Write a C program to simulate producer-consumer problem using semaphores.
*/

#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0; // Initialization of semaphores 

void producer(); // producer() Function prototypes
void consumer(); // consumer() Function prototypes

int main() {
    int n; // n = number of processes
    int opt; // opt = option
    printf("\n1. Producer\n2. Consumer\n3. Exit"); // print the menu
    do
    {
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
        printf("\nDo you wish to continue? (Yes = 1, No = 0): "); // ask the user if he/she wants to continue
        scanf("%d", &opt); // store the option in opt
    } while (opt == 1); // do-while loop to continue the program
    return 0;
}

void producer() { // producer() Function definition
    --mutex;    // acquire mutex lock
    ++full;     // increment full
    --empty;    // decrement empty
    x++;        // increment x
    printf("Producer produces the item %d", x); // print the item produced
    ++mutex;    // release mutex lock
}

void consumer() { // consumer() Function definition
    --mutex;    // acquire mutex lock
    --full;     // decrement full
    ++empty;    // increment empty
    printf("Consumer consumes the item %d", x); // print the item consumed
    x--;        // decrement x
    ++mutex;    // release mutex lock
}