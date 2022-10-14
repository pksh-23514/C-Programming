/*
Name         : Prabhat Kiran
Date         : 19th August 2022
Description  : WAP to reverse the given string using recursive method.
Sample Input : 1) Enter a string : Hello World
               2) Enter a string : EMERTXE
Sample Output: 1) Reverse string is : dlroW olleH
               2) Reverse string is : EXTREME
*/

#include <stdio.h>

void reverse_recursive (char str[], int ind, int len);

int main()
{
    char str [30];
    printf ("Enter a string : ");
    scanf ("%[^\n]", str);

    int len = 0;
    while (str [++len] != '\0');    //To find the length of the string.

    reverse_recursive (str, 0, len);
    printf ("Reversed string is : %s\n", str);
    return 0;
}

void reverse_recursive (char str[], int ind, int len)
{
   if (ind >= (len/2))      //If the number of times of swapping the characters in the string reaches half of the length of string i.e. all the character positions are reversed in the string.
   {
       return;              //The recursive function calls shall start winding.
   }
   else         //The swapping of the exact opposite characters from the middile of the string takes place recursively till the complete string is reversed.
   {
        char temp = str [ind];
        str [ind] = str [len - ind - 1];
        str [len - ind - 1] = temp;
        reverse_recursive (str, ind + 1, len);  //The recursive function call with updated string and the next character position to be reversed.
   }
}
