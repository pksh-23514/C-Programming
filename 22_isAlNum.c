/*
Name         : Prabhat Kiran
Date         : 14th July 2022
Description  : WAP to implement your own isalnum() function.
Sample Input : 1) Enter the character: a
               2) Enter the character: ?
Sample Output: 1) The character 'a' is an alnum character.
               2) The character '?' is not an alnum character.
*/

#include <stdio.h>

int my_isalnum (int);       //Function declaration of 'my_isalnum' to tell the compiler to search for the function definition later in the code.

int main()
{
    char ch;
    int ret;
    printf ("Enter the character: ");
    scanf ("%c", &ch);

    ret = my_isalnum (ch);  //Function call to 'my_isalnum' with the function argument 'ch'.
    if (ret == 1)       //If the return value from the function call is '1', the character entered by the user is an alpha-numeric character.
    {
        printf ("Entered character is alphanumeric character\n");
    }
    else                //If the return value from the function call is '0', the character entered by the user is not an alpha-numeric character.
    {
        printf ("Entered character is not alphanumeric character\n");
    }
    return 0;
}

int my_isalnum (int ch)
{
    //It checks if the character entered by the user belongs in the range of 'a' to 'z' or 'A' to 'Z' or '0' to '9'. If yes, then it returns '1'; otherwise '0'.
    if (((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')) || ((ch >= 'A') && (ch <= 'Z')))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
