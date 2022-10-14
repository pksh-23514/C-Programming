/*
Name         : Prabhat Kiran
Date         : 14th July 2022
Description  : WAP to toggle 'n' bits from given position of a number.
               Eg. - If num is 10, n is 3, and pos is 5
                     7 6 5 4 3 2 1 0
               10 -> 0 0 0 0 1 0 1 0
               Return value -> 0 0 1 1 0 0 1 0
               So the function should return 50 (0 0 1 1 0 0 1 0)
Sample Input : 1) Enter the number: 10
                  Enter number of bits: 3
                  Enter the pos: 5
               2) Enter the number: 15
                  Enter number of bits: 2
                  Enter the pos: 2
Sample Output: 1) Result = 50
               2) Result = 9
*/

#include <stdio.h>

int toggle_nbits_from_pos (int, int, int);      //Function declaration of 'toggle_nbits_from_pos' to tell the compiler to search for the function definition later in the code.

int main()
{
    int num, n, pos, res = 0;
    printf ("Enter the number: ");
    scanf ("%d", &num);
    printf ("Enter number of bits: ");
    scanf ("%d", &n);
    printf ("Enter the pos: ");
    scanf ("%d", &pos);

    res = toggle_nbits_from_pos (num, n, pos);      //Function call to 'toggle_nbits_from_pos' with the function arguments 'num', 'n' and 'pos'.
    printf ("Result = %d\n", res);
    return 0;
}

int toggle_nbits_from_pos (int num, int n, int pos)
{
    return (num ^ (((1 << n) - 1) << (pos - n + 1)));

//'(((1<<n)-1) << (pos-n+1))' : The mask is created to get 'n' bits from LSB side. This is then shifted by 'pos-n+1' as the bits being fetched are from 'pos' and not LSB by shifting frame to 'pos'.
//'(num & mask)' : The XOR operation is used to toggle those 'n' bits.
}
