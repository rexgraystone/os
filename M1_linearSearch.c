/*
    M1. Write a program to search for a key element in an array using linear search algorithm.
*/

#include <stdio.h>

int enterArr(int n, int arr[n]) { 
    printf("Enter the elements for an array of size %d - \n\n", n); 
    for(int i = 0; i < n; i++) { 
        printf("\tEnter the element at position %d: ", i); 
        scanf("%d", &arr[i]); 
    }
    return n; 
}

int linearSearch(int arr[], int n, int x) { 
    for(int i = 0; i < n; i++) { 
        if(arr[i] == x) { 
            return i; 
        }
    }
    return -1; 
}

int main() { 
    int n; 
    printf("Enter the number of elements in the array: "); 
    scanf("%d", &n); 
    int arr[n]; 
    enterArr(n, arr); 
    int x; 
    printf("Enter the number to be searched: "); 
    scanf("%d", &x); 
    int result = linearSearch(arr, n, x); 
    if(result == -1) { 
        printf("The number %d is not found in the array.\n", x); 
    } else { 
        printf("The number %d is found at position %d in the array.\n", x, result); 
    }
    return 0;
}