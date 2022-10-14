/*
Name         : Prabhat Kiran
Date         : 07th July 2022
Description  : WAP to check N th bit is set or not, If yes, clear the M th bit.
Sample Input : 1) Enter the number: 19
                  Enter 'N': 1
                  Enter 'M': 4
               2) Enter the number: 19
                  Enter 'N': 2
                  Enter 'M': 4
Sample Output: 1) Updated value of num is 3
               2) Updated value of num is 19
*/

#include <stdio.h>

int main()
{
    int num,m,n;
    printf ("Enter the number: ");
    scanf ("%d", &num);
    printf ("Enter 'N': ");
    scanf ("%d", &n);
    printf ("Enter 'M': ");
    scanf ("%d", &m);
    
    if (num & (1 << n))     //To check if the 'n'th bit of the number is set or not using Bitwise AND & Left-shift operator. If yes, 'm'th bit of the number should be cleared.
    {
        num = num & (~ (1 << m));   //To clear the 'm'th bit of the number using the mask. The mask is created by complementing the value of 1 left-shifted 'm' times.
    }
    
    printf ("Updated value of num is %d\n", num);
    return 0;
}
