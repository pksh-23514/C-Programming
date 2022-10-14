/*
Name         : Prabhat Kiran
Date         : 14th July 2022
Description  : WAP to print 'n' bits from LSB of a number.
               Eg. - If num is 10 and n is 12, then print last 12 bits of binary representation of 10.
               The output should be -> 0 0 0 0 0 0 0 0 1 0 1 0
Sample Input : 1) Enter the number: 10
                  Enter number of bits: 12
               2) Enter the number: 15
                  Enter number of bits: 4
Sample Output: 1) Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0
               2) Binary form of 15: 1 1 1 1
*/

#include <stdio.h>

void print_bits (int, int);     //Function declaration of 'print_bits' to tell the compiler to search for the function definition later in the code.

int main()
{
    int num, n;
    printf ("Enter the number: ");
    scanf ("%d", &num);
    printf ("Enter number of bits: ");
    scanf ("%d", &n);

    printf ("Binary form of %d: ", num);
    print_bits (num, n);        //Function call to 'print_bits' with the function arguments 'num' and 'n'.
    printf ("\n");
    return 0;
}

void print_bits (int num, int n)    //Since, there is no value to be returned, the return data-type is 'void'.
{
    while (n > 0)   //The loop will run for 'n' times and print the last 'n' bits of the number.
    {
        if (num & (1 << (n - 1)))   //Since, the bits start from '0': to print 'n' bits, we take the position from 'n-1' to '0'. The mask is created to print bits from the MSB to LSB.
        {
            printf ("1 ");      //If the AND operation is a non-zero value, print "1".
        }
        else
        {
            printf ("0 ");      //If the AND operation is a zero-value, print "0".
        }
        n -= 1;     //To traverse the bits of the number from MSB to LSB.
    }
}
