/*
Name         : Prabhat Kiran
Date         : 10th August 2022
Description  : WAP to implement itoa function.
Sample Input : 1) Enter the number : 1234
               2) Enter the number : -1234
               3) Enter the number : +1234
               4) Enter the number : a1234
Sample Output: 1) Integer to string is 1234
               2) Integer to string is -1234
               3) Integer to string is 1234
               4) Integer to string is 0
*/

#include <stdio.h>

int itoa (int num, char str[]);

int main()
{
    int num;
    char str[10];
    printf ("Enter the number : ");
    int ret = scanf ("%d", &num);
    if ((ret == 0) || (num == 0))   //If the scanf() doesn't read successfully or if it reads a value of '0'; It is represented as string "0" and printed directly.
    {
        str [0] = '0';
        str [1] = '\0';
    }
    else    //If the scanf() successfully reads an integer value, the function call is made.
    {
        itoa (num, str);
    }
    printf ("Integer to string is %s\n", str);
    return 0;
}

int itoa (int num, char str[])
{
    int rem, count = 0, orig = num, i = 0;
    while (num != 0)    //The loop is used to count the number of digits present in the number.
    {
        count += 1;
        num = num / 10;
    }
    if (orig > 0)       //If the number is positive, we don't have to display a '+' sign in the string as default is positive. 
    {
        str [count] = '\0';     //The 'count' position of the string shall be the end of the string.
        num = orig;             //If the number is positive, number shall be left as it is for operation.
        i = count - 1;          //Since the remainder will be picked from the smallest base (0th place) of the number, the string should also be filled from the last position.
    }
    else if (orig < 0)  //If the number is negative, we have to display a '-' sign explicitly in the string to show that it is a negative number.
    {
        str [count + 1] = '\0';     //Since, the first position of the string is taken by '-', we need another extra position of the string to store the complete number.
        str [0] = '-';              //The first position of the string is updated with '-'.
        num = (-orig);              //If the number is negative, number shall be negated to normalise the operation.
        i = count;                  //Since the remainder will be picked from the smallest base (0th place) of the number, the string should also be filled from the last position.
    }
    while (num != 0)
    {
        rem = (num % 10) + 48;      //Conversion of decimal value to ASCII character.
        str [i] = rem;              //Updating the character extracted to it's right position in the string.
        num = num / 10;             //Decreasing the 'num' to remove the value that is converted to string.
        i -= 1;                     //Updating the postion of the string.
    }
}
