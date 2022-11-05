/*
    M1. Write a program to search for a key element in an array using linear search algorithm.
*/

#include <stdio.h>

int enterArr(int n, int arr[n]) { // enter the elements of the array
    printf("Enter the elements for an array of size %d - \n\n", n); // input the elements of the array
    for(int i = 0; i < n; i++) { // for all the elements in the array
        printf("\tEnter the element at position %d: ", i); // input the element
        scanf("%d", &arr[i]); // store the element in the array
    }
    return n; // return the number of elements in the array
}

int linearSearch(int arr[], int n, int x) { // n = number of elements in the array, x = number to be searched
    for(int i = 0; i < n; i++) { // loop through the array
        if(arr[i] == x) { // if the element is the number to be searched
            return i; // return the index of the element
        }
    }
    return -1; // if the number is not found
}

int main() { 
    int n; // n = number of elements in the array
    printf("Enter the number of elements in the array: "); // input the number of elements in the array
    scanf("%d", &n); // store the number of elements in the array in n
    int arr[n]; // arr = array
    enterArr(n, arr); // call the function to enter the elements of the array
    int x; // x = number to be searched
    printf("Enter the number to be searched: "); // input the number to be searched
    scanf("%d", &x); // store the number to be searched in x
    int result = linearSearch(arr, n, x); // call the function to search for the number
    if(result == -1) { // if the number is not found
        printf("The number %d is not found in the array.\n", x); // print the number is not found
    } 
    else { // if the number is found
        printf("The number %d is found at position %d in the array.\n", x, result); // print the number is found
    }
    return 0;
}