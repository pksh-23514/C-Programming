/*
Name         : Prabhat Kiran
Date         : 14th July 2022
Description  : WAP to replace 'n' bits of a given number.
               Eg. - If num is 10 and n is 3 and val is 12
               10 -> 0 0 0 0 1 0 1 0
               12 -> 0 0 0 0 1 1 0 0
               The program should print result as 12 (1 1 0 0).
Sample Input : 1) Enter the number: 10
                  Enter number of bits: 3
                  Enter the value: 12
               2) Enter the number: 15
                  Enter number of bits: 2
                  Enter the value: 1
Sample Output: 1) Result = 12
               2) Result = 13
*/

#include <stdio.h>

int replace_nbits (int, int, int);      //Function declaration of 'get_nbits' to tell the compiler to search for the function definition later in the code.

int main()
{
    int num, n, val, res = 0;
    printf ("Enter the number: ");
    scanf ("%d", &num);
    printf ("Enter number of bits: ");
    scanf ("%d", &n);
    printf ("Enter the value: ");
    scanf ("%d", &val);

    res = replace_nbits (num, n, val);      //Function call to 'replace_nbits' with the function arguments 'num', 'n' and 'value'.
    printf ("Result = %d\n", res);
    return 0;
}

int replace_nbits (int num, int n, int val)
{
    return ((num & (~((1 << n) - 1))) | (val & ((1 << n) - 1)));    //This statement evaluates the expression and returns the 'n' bits from LSB of the user entered number in 'int' type.
    
    //'(num & (~((1 << n) - 1)))' : It clears the 'n' bits from LSB which will be replaced by the 'n' bits from the other number.
    //'(val & ((1 << n) - 1)) : It gets the 'n' bits from the other number.
    //Both the expressions are operated by OR to achieve the final result.
}
