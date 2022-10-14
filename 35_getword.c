/*
Name         : Prabhat Kiran
Date         : 09th August 2022
Description  : WAP to implement getword function.
Sample Input : 1) Enter the string : Welcome to Emertxe
               2) Enter the string : Hello
Sample Output: 1) You entered Welcome and the length is 7
               2) You entered Hello and the length is 5
*/

#include <stdio.h>

int getword (char []);

int main()
{
    int len = 0;
    char str [100];
    printf ("Enter the string : ");
    scanf ("%[^\n]", str);          //Selective scanf() being used to read till we encounter the new-line character.

    len = getword (str);
    printf ("You entered %s and the length is %d\n", str, len);     //The end of the first word is marked by 'NULL' so that it can be printed here.
    return 0;
}

int getword (char str[])
{
    int count = 0;
    while (str [count] != '\0')     //The loop will run till we reach the end of the string.
    {
        if ((str [count] == ' ') || (str [count] == '\t') || (str [count] == '\n'))     //If a blank or a tab or a newline character is encountered, it's the end of the first word.
        {
            str [count] = '\0';     //To mark the end of the first word, the blank or tab or newline character shall be replaced by 'NULL' character.
            break;                  //To terminate the loop.
        }
        count += 1;     //The count is used to traverse the string till the end of the first word and store the value of the word length.
    }

    return count;
}
