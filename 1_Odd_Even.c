/*
Name         : Prabhat Kiran
Date         : 02nd July 2022
Description  : WAP to check if the given number is odd or even.
Sample Input : 1) Enter the value of 'n' : -2
               2) Enter the value of 'n' : 2
               3) Enter the value of 'n' : 0
Sample Output: 1) -2 is negative even number
               2) 2 is positive even number
               3) 0 is neither odd nor even
*/

#include <stdio.h>

int main()
{
    int num;
    printf ("Enter the value of 'n' : ");
    scanf ("%d", &num);

    if (num < 0)    //To check if the number is a negative number.
    {
        if (num % 2 == 0)   //To check if the number is an even number or odd number.
        {
            printf ("%d is negative even number\n", num);
        }
        else
        {
            printf ("%d is negative odd number\n", num);
        }
    }
    else if (num > 0)   //To check if the number is a positive number.
    {
        if (num % 2 == 0)   //To check if the number is an even number or odd number.
        {
            printf ("%d is positive even number\n", num);
        }
        else
        {
            printf ("%d is positive odd number\n", num);
        }
    }
    else    //If the number is zero, then the 'neither odd nor even' message should be printed.
    {
        printf ("%d is neither odd nor even\n", num);
    }
    return 0;
}
