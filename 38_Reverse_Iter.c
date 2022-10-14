/*
Name         : Prabhat Kiran
Date         : 09th August 2022
Description  : WAP to reverse the given string using iterative method.
Sample Input : 1) Enter a string : Hello World
               2) Enter a string : EMERTXE
Sample Output: 1) Reverse string is : dlroW olleH
               2) Reverse string is : EXTREME
*/

#include <stdio.h>

void reverse_iterative (char str[]);

int main()
{
    char str[30];
    printf ("Enter any string : ");
    scanf ("%[^\n]", str);

    reverse_iterative (str);
    printf ("Reverse string is : %s\n", str);
    return 0;
}

void reverse_iterative (char str[])
{
    int len = 0;
    while (str [len] != '\0')       //To find the length of the string.
    {
        len += 1;
    }
    char temp;
    for (int i = 0; i < (len/2); i++)//The number of times of swapping the characters in the string shall be equal to half of the length of string. Then, all the character positions are reversed.
    {
        temp = str [i];
        str [i] = str [len - i - 1];    //The swapping of the exact opposite characters from the middile of the string takes place recursively till the complete string is reversed.
        str [len - i - 1] = temp;
    }
}
