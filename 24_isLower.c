/*
Name         : Prabhat Kiran
Date         : 14th July 2022
Description  : WAP to implement your own islower() function.
Sample Input : 1) Enter the character: a
               2) Enter the character: 3
Sample Output: 1) Entered character is lower case alphabet
               2) Entered character is not lower case alphabet
*/

#include <stdio.h>

int my_islower (int);     //Function declaration of 'my_islower' to tell the compiler to search for the function definition later in the code.

int main()
{
    char ch;
    int ret;
    printf ("Enter the character: ");
    scanf (" %c", &ch);

    ret = my_islower (ch);  //Function call to 'replace_nbits' with the function argument 'ch'.
    if (ret == 1)           //If the return value from the function call is '1', the character entered by the user is a lower case alphabet.
    {
        printf ("Entered character is lower case alphabet\n");
    }
    else                    //If the return value from the function call is '1', the character entered by the user is a not lower case alphabet.
    {
        printf ("Entered character is not lower case alphabet\n");
    }
    return 0;
}

int my_islower (int ch)
{
    if ((ch >= 'a') && (ch <= 'z'))     //It checks if the character entered by the user belongs in the range of 'a' to 'z'. If yes, then it returns '1'; otherwise '0'.
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
