/*
Name         : Prabhat Kiran
Date         : 18th July 2022
Description  : WAP to implement Circular left shift.
Sample Input : 1) Enter num: 12
                  Enter n : 3
               2) Enter num: -2
                  Enter n : 3
Sample Output: 1) Result in Binary: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0
               2) Result in Binary: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
*/

#include <stdio.h>

int circular_left (int, int);       //Function declaration of 'circular_left' to tell the compiler to search for the function definition later in the code.
int print_bits (int);               //Function declaration of 'print_bits' to tell the compiler to search for the function definition later in the code.

int main()
{
    int num, n, ret;
    printf ("Enter num: ");
    scanf ("%d", &num);
    printf ("Enter n : ");
    scanf ("%d", &n);

    if ((n >= 0) && (n < 32))
    {
        ret = circular_left (num, n);       //Function call to 'circular_left' with the function arguments 'num' and 'n'.
        printf ("Result in Binary: ");
        print_bits(ret);                    //Function call to 'print_bits' with the function arguments 'ret'.
        printf ("\n");
    }
    else
    {
        printf ("The value of 'n' shall be in the range of 0 to 32.\n");
    }
    return 0;
}

int circular_left (int num, int n)
{
    return ((num << n) | (((unsigned int) num >> (32 - n))));

//'(num << n)' : The bits are left shifted normally and the vacated bits are filled with '0' automatically.
//'(((unsigned int) num >> (32 - n)))' : The MSB side bits are right shifted to position them exactly at the vacated bits on the LSB side.
//'unsigned int' type casting is for preventing the MSB from being a sign bit. So, all the vacated bits in the right shift will be filled with '0'.
//'x | y' : The OR operation gives the final result of Circular Left shift.
}

int print_bits (int res)
{
    for (int i = 31; i >= 0; i--)
    {
        if (res & (1 << i))         //If the AND operation is a non-zero value, print "1".
        {
            printf ("1 ");
        }
        else                        //If the AND operation is a zero-value, print "0".
        {
            printf ("0 ");
        }
    }
    return 1;
}
