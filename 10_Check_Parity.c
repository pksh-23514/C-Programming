/*
Name         : Prabhat Kiran
Date         : 07th July 2022
Description  : WAP to count number of set bits in a given number and print parity. 
Sample Input : 1) Enter the number : 7
               2) Enter the number : 16
               3) Enter the number : 6
Sample Output: 1) Number of set bits = 3
                  Bit parity is Odd
               2) Number of set bits = 4
                  Bit parity is Even
               3) Number of set bits = 2
                  Bit parity is Even
*/

#include <stdio.h>

int main()
{
    int num;
    printf ("Enter the number : ");
    scanf ("%d", &num);
    
    int count = 0;
    for (int i = 0; i < 32; i++)    //To run the loop from 0th bit to 31st bit as integer values are of 32 bits size.
    {
        if (num & (1 << i))     //To check if the 'i'th bit of the number is Set (=1) or not using Bitwise AND & Left-shift operator.
        {
            count = count + 1;  //To count the number of set bits in the number.
        }
    }

    printf ("Number of set bits = %d\n", count);
    if (count & 1 == 1)     //To check if the value of 'count' is Odd or Even using Bitwise AND operator. If the LSB is 1, number is Odd. If the LSB is 0, number is Even.
    {
        printf ("Bit parity is Odd\n");
    }
    else
    {
        printf ("Bit parity is Even\n");
    }
    return 0;
}
