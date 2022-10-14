/*
Name         : Prabhat Kiran
Date         : 20th July 2022
Description  : WAP to generate fibbonacci numbers using recursion.
Sample Input : 1) Enter a number: 8
               2) Enter a number: 10
               3) Enter a number: 21
               4) Enter a number: -12
Sample Output: 1) 0, 1, 1, 2, 3, 5, 8
               2) 0, 1, 1, 2, 3, 5, 8
               3) 0, 1, 1, 2, 3, 5, 8, 13, 21
               4) Invalid input
*/

#include <stdio.h>

void positive_fibonacci (int, int, int, int);       //Function declaration of 'positive_fibonacci' to tell the compiler to search for the function definition later in the code.

int main()
{
    int limit;
    printf ("Enter a number: ");
    scanf ("%d", &limit);
    if (limit < 0)
    {
        printf ("Invalid input\n");
    }
    else
    {
        positive_fibonacci (limit, 0, 1, 0);            //Function call to 'positive_fibonacci' with the function arguments 'limit', '0', '1' and '0'.
        printf ("\n");
    }
    return 0;
}

void positive_fibonacci (int n, int first, int second, int third)
{
    printf ("%d", third);
    first = second;
    second = third;
    third = first + second;
    if (third <= n)         //If the updated value of 'third' is less than or equal to the 'limit' value, then only the next term of Fibonacci series should be calculated and ',' should be printed.
    {
        printf (", ");
        positive_fibonacci (n, first, second, third);   //The function 'positive_fibonacci' is recursively called with the updated values passed as parameters.
    }
}
