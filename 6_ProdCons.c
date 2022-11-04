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
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch(n) {
            case 1: 
                if((mutex==1) && (empty!=0))
                    producer();
                else
                    printf("Buffer is full!!");
                break;
            case 2: 
                if((mutex==1) && (full!=0))
                    consumer();
                else
                    printf("Buffer is empty!!");
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
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces the item %d", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes item %d", x);
    x--;
    ++mutex;
}