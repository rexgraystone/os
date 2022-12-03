/*
    M3. Write a program to check whether a given string is a palindrome or not.
*/

#include <stdio.h>

void palindromeCheck(int n) { 
    int sum = 0, rem, temp; 
    temp = n; 
    while(n != 0) { 
        rem = n % 10; 
        sum = (sum * 10) + rem; 
        n = n / 10; 
    }
    if(temp == sum) { 
        printf("\n%d is a palindromeCheck.\n", temp); 
    }
    else { 
        printf("\n%d is not a palindromeCheck.\n", temp); 
    }
}

int main() { 
    int n; 
    printf("\nEnter any number: "); 
    scanf("%d", &n); 
    palindromeCheck(n); 
    return 0;
}