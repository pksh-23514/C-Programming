/*
Name         : Prabhat Kiran
Date         : 14th July 2022
Description  : WAP to get 'n' bits from given position of a number.
               Eg. - If num is 12, n is 3 and pos is 4:
                     7 6 5 4 3 2 1 0
               12 -> 0 0 0 0 1 1 0 0
               The program should print 3 (0 1 1).
Sample Input : 1) Enter the number: 12
                  Enter number of bits: 3
                  Enter the pos: 4
               2) Enter the number: 15
                  Enter number of bits: 2
                  Enter the pos: 2
Sample Output: 1) Result = 3
               2) Result = 3
*/

#include <stdio.h>

int get_nbits_from_pos (int, int, int);     //Function declaration of 'get_nbits_from_pos' to tell the compiler to search for the function definition later in the code.

int main()
{
    int num, n, pos, res = 0;
    printf ("Enter the number: ");
    scanf ("%d", &num);
    printf ("Enter number of bits: ");
    scanf ("%d", &n);
    printf ("Enter the pos: ");
    scanf ("%d", &pos);

    res = get_nbits_from_pos (num, n, pos);     //Function call to 'replace_nbits' with the function arguments 'num', 'n' and 'pos'.
    printf ("Result = %d\n", res);
    return 0;
}

int get_nbits_from_pos (int num, int n, int pos)
{
    return ((num & ((1 << n) - 1) << (pos - n + 1)) >> (pos - n + 1));

//'(((1<<n)-1) << (pos-n+1))' : The mask is created to get 'n' bits from LSB side. This is then shifted by 'pos-n+1' as the bits being fetched are from 'pos' and not LSB by shifting frame to 'pos'.
//'(num & mask)' : The AND operation is used to get the 'n' bits from the given position of a number.
//'(final >> (pos-n+1))' : For getting the value in decimal, the 'n' bits need to be shifted back to LSB by shifting the resultant by 'pos-n+1'.
}
