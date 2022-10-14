/*
Name         : Prabhat Kiran
Date         : 14th July 2022
Description  : WAP to implement your own isblank() function.
Sample Input : 1) Enter the character: a
               2) Enter the character:    //Entered space
Sample Output: 1) The character 'a' is not a blank character.
               2) The character ' ' is a blank character.
*/

#include <stdio.h>

int my_isblank (int);       //Function declaration of 'my_isblank' to tell the compiler to search for the function definition later in the code.

int main()
{
    char ch;
    int ret;
    printf ("Enter the character: ");
    scanf ("%c", &ch);

    ret = my_isblank (ch);  //Function call to 'my_isblank' with the function argument 'ch'.
    if (ret == 1)       //If the return value from the function call is '1', the character entered by the user is a blank character.
    {
        printf ("Entered character is a blank character\n");
    }
    else                //If the return value from the function call is '1', the character entered by the user is a blank character.
    {
        printf ("Entered character is not blank character\n");
    }
    return 0;
}

int my_isblank (int ch)
{
    if ((ch == ' ') || (ch == '\t'))    //It checks if the character entered by the user belongs in the range of 'a' to 'z'. If yes, then it returns '1'; otherwise '0'.
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
