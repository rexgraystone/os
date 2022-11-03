/*
    M3. Write a program to check whether a given string is a palindrome or not.
*/

#include <stdio.h>

void palindrome(int n)
{
    int sum = 0, rem, temp;
    temp = n;
    while(n!=0)
    {
        rem = n%10;
        sum = (sum * 10) + rem;
        n = n/10;
    }
    if(temp == sum)
    {
        printf("\n%d is a palindrome.\n", temp);
    }
    else
    {
        printf("\n%d is not a palindrome.\n", temp);
    }
}

int main()
{
    int n;
    printf("\nEnter any number: ");
    scanf("%d", &n);
    palindrome(n);
    return 0;
}