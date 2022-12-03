/*
    M2. Write a program to search for a key element in an array using binary search algorithm.
*/

#include <stdio.h>

int binarySearch(int arr[], int l, int h, int n) { // l = low, h = high, n = number to be searched
    if (h >= l) { // base case
        int mid = l + (h - l)/2; 
        if (arr[mid] == n) { 
            return mid; 
        }
        if (arr[mid] > n) { 
            return binarySearch(arr, l, (mid - 1), n); 
        }    
        return binarySearch(arr, (mid + 1), h, n); 
    }
    return -1; 
}

int main(void) {
    int arr[] = {1, 4, 7, 9, 16, 56, 70}; 
    int l = 0; 
    int h = 7; 
    int n; 
    printf("Enter a number: \n"); 
    scanf("%d", &n); 
    int i = binarySearch(arr, l, (h - 1), n); 
    if(i == -1 ) { 
        printf("Element %d not found in the array.\n", n); 
    } else { 
        printf("Element %d found at index: %d.\n", n, i); 
    }
    return 0;
}