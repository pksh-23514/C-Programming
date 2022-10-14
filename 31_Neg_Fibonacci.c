/*
Name         : Prabhat Kiran
Date         : 20th July 2022
Description  : WAP to generate negative fibbonacci numbers using recursion.
Sample Input : 1) Enter a number: -8
               2) Enter a number: -10
               3) Enter a number: -21
               4) Enter a number: 21
Sample Output: 1) 0, 1, -1, 2, -3, 5, -8
               2) 0, 1, -1, 2, -3, 5, -8
               3) 0, 1, -1, 2, -3, 5, -8, 13, -21
               4) Invalid input
*/

#include <stdio.h>

void negative_fibonacci (int, int, int, int);       //Function declaration of 'negative_fibonacci' to tell the compiler to search for the function definition later in the code.

int main()
{
    int limit;
    printf ("Enter a number: ");
    scanf ("%d", &limit);
    if (limit > 0)
    {
        printf ("Invalid input\n");
    }
    else
    {
        negative_fibonacci (limit, 0, 1, 0);            //Function call to 'negative_fibonacci' with the function arguments 'limit', '0', '1' and '0'.
        printf ("\n");
    }
    return 0;
}

void negative_fibonacci (int n, int first, int second, int third)
{
    printf ("%d ", third);
    first = second;
    second = third;
    third = first - second;

//Since the value of limit is negative: if 'third' is negative, 'limit' is the last term and if 'thrid' is positive, '-limit' is the last term for the Negative Fibonacci series.
    if ((third < 0 && third  >= n) || (third > 0 && third <= -n))    //If the updated value of 'third' lies between '-limit' to 'limit', then only the next term of the Fibonacci series is calculated.
    {    
        printf (", ");      //If the updated value in 'third' is not the last element of the Fibonacci series, then only the ',' should be printed.
        negative_fibonacci (n, first, second, third);       //The function 'negative_fibonacci' is recursively called with updated values passed as parameters.
    }
}
