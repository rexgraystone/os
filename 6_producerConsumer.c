/*
    6. Write a C program to simulate producer-consumer problem using semaphores.
*/

# include <stdio.h>
# include <stdlib.h>

int mutex = 1, full = 0, empty = 3, itemNo = 0; // initialize the semaphores

int waitOperation(int);
int signalOperation(int);
void producer(); 
void consumer(); 

int main() {
    int n; 
    int opt; 
    printf("\n1. Producer\n2. Consumer\n"); 
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch(n) {
            case 1: 
                if((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full!!");
                }
                break;
            case 2: 
                if((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty!!");
                }
                break;
        }
        printf("\nDo you wish to continue? (Yes = 1, No = 0): "); 
        scanf("%d", &opt); 
    } while (opt == 1); 
    return 0;
}


/**
 * @brief is used to wait for the semaphore
 * 
 * @param s  
 * @return int 
 */
int waitOperation(int s) {
    return (--s);
}

/**
 * @brief is used to signal the semaphore
 * 
 * @param s 
 * @return int 
 */
int signalOperation(int s) {
    return (++s);
}

void producer() { 
    mutex = waitOperation(mutex);    // acquire mutex lock
    full = signalOperation(full);     
    empty = waitOperation(empty);    
    printf("Producer produces the item %d", ++itemNo); 
    mutex = signalOperation(mutex);    // release mutex lock
}

void consumer() { // consumer() Function definition
    mutex = waitOperation(mutex);    // acquire mutex lock
    full = waitOperation(full);     
    empty = signalOperation;    
    printf("Consumer consumes the item %d", itemNo--); 
    mutex = signalOperation(mutex);    // release mutex lock
}