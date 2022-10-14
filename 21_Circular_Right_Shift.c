/*
Name         : Prabhat Kiran
Date         : 18th July 2022
Description  : WAP to implement Circular right shift.
Sample Input : 1) Enter num: 12
                  Enter n : 3
               2) Enter num: -12
                  Enter n : 3
Sample Output: 1) Result in Binary: 10000000 00000000 00000000 00000001
               2) Result in Binary: 10011111 11111111 11111111 11111110
*/

#include <stdio.h>

int circular_right (int, int);          //Function declaration of 'circular_right' to tell the compiler to search for the function definition later in the code.
int print_bits (int);                   //Function declaration of 'print_bits' to tell the compiler to search for the function definition later in the code.

int main()
{
    int num, n, ret;
    printf ("Enter num: ");
    scanf ("%d", &num);
    printf ("Enter n : ");
    scanf ("%d", &n);

    if ((n >= 0) && (n < 32))
    {
        ret = circular_right (num, n);          //Function call to 'circular_right' with the function arguments 'num' and 'n'.
        printf ("Result in Binary: ");
        print_bits(ret);                        //Function call to 'print_bits' with the function arguments 'ret'.
        printf ("\n");
    }
    else
    {
        printf ("The value of 'n' shall be in the range of 0 to 32.\n");
    }
    return 0;
}

int circular_right (int num, int n)
{
    return (((unsigned int) num >> n) | num << (32 - n));

//'((unsigned int) num << n)' : The bits are right shifted normally. 'unsigned int' type casting is for preventing the MSB from being a sign bit. So, all the vacated bits will be filled with '0'.
//'((num << (32 - n)))' : The LSB side bits are left shifted to position them exactly at the vacated bits on the MSB side.
//'x | y' : The OR operation gives the final result of Circular Right shift.
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
