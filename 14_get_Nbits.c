/*
Name         : Prabhat Kiran
Date         : 14th July 2022
Description  : WAP to get 'n' bits of a given number.
               Eg. - If num is 10 and n is 2
               10 -> 0 0 0 0 1 0 1 0
               Take 2 bits from LSB end of 10 (1 0) and return the corresponding decimal of that. 
               So get_nbits(10, 2) function should return 2.
Sample Input : 1) Enter the number: 10
                  Enter number of bits: 3
               2) Enter the number: 15
                  Enter number of bits: 2
Sample Output: 1) Result = 2
               2) Result = 3
*/

#include <stdio.h>

int get_nbits (int, int);           //Function declaration of 'get_nbits' to tell the compiler to search for the function definition later in the code.

int main()
{
    int num, n, res = 0;
    printf ("Enter the number: ");
    scanf ("%d", &num);
    printf ("Enter number of bits: ");
    scanf ("%d", &n);

    res = get_nbits (num, n);       //Function call to 'get_nbits' with the function arguments 'num' and 'n'.
    printf ("Result = %d\n", res);
    return 0;
}

int get_nbits (int num, int n)
{
    return (num & ((1 << n) - 1));  //This statement evaluates the expression and returns the 'n' bits from LSB of the user entered number in 'int' type.
}
