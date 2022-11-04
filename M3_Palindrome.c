/*
    M3. Write a program to check whether a given string is a palindrome or not.
*/

#include <stdio.h>

void palindromeCheck(int n) { // n = number of characters in the string
    int sum = 0, rem, temp; // sum = sum of the digits, rem = remainder, temp = temporary variable
    temp = n; // store the number in temp
    while(n!=0) { // while the number is not equal to 0
        rem = n % 10; // find the remainder
        sum = (sum * 10) + rem; // find the sum
        n = n / 10; // divide the number by 10
    }
    if(temp == sum) { // if the number is equal to the sum
        printf("\n%d is a palindromeCheck.\n", temp); // print the number is a palindrome
    }
    else { // if the number is not equal to the sum
        printf("\n%d is not a palindromeCheck.\n", temp); // print the number is not a palindrome
    }
}

int main() { 
    int n; // n = number of characters in the string
    printf("\nEnter any number: "); // input the number
    scanf("%d", &n); // store the number in n
    palindromeCheck(n); // call the function to check if the number is a palindrome
    return 0;
}