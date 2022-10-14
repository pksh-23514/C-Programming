/*
Name         : Prabhat Kiran
Date         : 14th July 2022
Description  : WAP to implement your own ispunct() function.
Sample Input : 1) Enter the character: a
               2) Enter the character: $
Sample Output: 1) Entered character is not punctuation character
               2) Entered character is punctuation character
*/

#include <stdio.h>

int my_ispunct (int);   //Function declaration of 'my_ispunct' to tell the compiler to search for the function definition later in the code.

int main()
{
    char ch;
    int ret;
    printf ("Enter the character: ");
    scanf ("%c", &ch);

    ret = my_ispunct (ch);      //Function call to 'replace_nbits' with the function argument 'ch'.
    if (ret == 0)   //If the return value from the function call is '0', the character entered by the user is a Punctuation character.
    {
        printf ("Entered character is punctuation character\n", ch);
    }
    else            //If the return value from the function call is '1', the character entered by the user is not a Punctuation character.
    {
        printf ("Entered character is not punctuation character\n", ch);
    }
    return 0;
}

int my_ispunct (int ch)
{
    //It checks if the character entered by the user belongs in the range of 'a' to 'z' or 'A' to 'Z' or '0' to '9' or space or horizontal tab. If yes, then it returns '1'; otherwise '0'.
    if (((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')) || ((ch >= 'A') && (ch <= 'Z')) || (ch == ' ') || (ch == '\t'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
