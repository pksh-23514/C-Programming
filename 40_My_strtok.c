/*
Name         : Prabhat Kiran
Date         : 18th August 2022
Description  : WAP to implement strtok function.
Sample Input : 1) Enter string : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
                  Enter delimiter : ;./-:
               2) Enter string : -;Bangalore;;::---Chennai:;Kolkata:;Delhi:-
                  Enter delimiter : ;./-:
Sample Output: 1) Tokens :
                  Bangalore
                  Chennai
                  Kolkata
                  Delhi
                  Mumbai
               2) Tokens :
                  Bangalore
                  Chennai
                  Kolkata
                  Delhi
*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok (char str[], const char delim[]);

int main()
{
    char str[50], delim[50];
    printf ("Enter the string : ");
    scanf ("%s", str);
    __fpurge (stdout);
    printf ("Enter the delimiter : ");
    scanf ("\n%s", delim);
    __fpurge (stdout);

    char* token = my_strtok (str, delim);
    printf ("Tokens :\n");

    while (token)
    {
        printf ("%s\n", token);
        token = my_strtok (NULL, delim);
    }
    return 0;
}

char *my_strtok (char str[], const char delim[])
{
    static char* orig;      //To retain the string for further function calls.
    static int pos;         //To store the position of the string from where the operation should continue for the current function call.
    if (str != NULL)        //To keep the string for further function calls when "NULL" is passed in place of 'str'.
    {
        orig = str;
    }

    int start = pos;                    //To store the starting position of the token to be returned from the function.
    while (orig [pos] != '\0')          //The loop will run till the end of the input string is reached.
    {
        int j = 0;
        while (delim [j] != '\0')       //To compare each of the character stored in the string with all the delimiters passed to the function as arguments.
        {
            if (orig [pos] == delim [j])
            {
                orig [pos] = '\0';      //If a delimiter is found, it should be replaced with 'NULL' character to mark the end of the token and break the string continuity.
                pos = pos + 1;          //The 'pos' is updated to the position after the delimiter from where the next function call should continue the operation.
                if (orig [start] != '\0')       //Checking for the case where there is no relevant string before the delimeter.
                {
                    return (orig + start);
                }
                else
                {
                    start = pos;    //If there is no relevant string encountered, the starting position of the next token is updated to position after the delimiter.
                    pos -= 1;       //To prevent the double updation of 'pos' as it will be updated at the end of the loop.
                    break;          //As the token isn't relevant; further checking with the delimiter string won't make any sense.
                }
            }
            j += 1;
        }
        pos += 1;
    }
    if (orig [start] == '\0')   //If the starting position of the next token is equal to the end of the string, the program should terminate.
    {
        return NULL;
    }
    else    //If there is no delimiter detected in the loop but the loop has terminated due to reaching the end of the string, last part of the string should be returned as token.
    {
        return (orig + start);
    }
}
