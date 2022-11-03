#include <stdio.h>

int BSearch(int arr[], int l, int h, int n)
{
    if (h >= l)
    {
        int m = l + (h - l)/2;
        if (arr[m] == n)
        {
            return m;
        }
        if (arr[m] > n)
        {
            return BSearch(arr, l, m-1, n);
        }    
        return BSearch(arr, m+1, h, n);
    }
    return -1;
}

int main(void)
{
    int arr[] = {1, 4, 7, 9, 16, 56, 70};
    int h = 7;
    int n;
    printf("Enter a number: \n");
    scanf("%d", &n);
    int i = BSearch(arr, 0, h-1, n);
    if(i == -1 ) 
    {
        printf("Element %d not found in the array.\n", n);
    }
    else 
    {
        printf("Element %d found at index: %d.\n", n, i);
    }
    return 0;
}