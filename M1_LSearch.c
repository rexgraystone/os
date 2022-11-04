/*
    M1. Write a program to search for a key element in an array using linear search algorithm.
*/

#include <stdio.h>

int main() {
    int n, s;
    int arr[n];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("\nEnter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter a number to search in the array: ");
    scanf("%d", &s);
    for(int i = 0; i < n; i++) {
        if(arr[i] == s) {
            printf("\nElement %d found at array position %d.", s, i);
            break;
        }
    }
}