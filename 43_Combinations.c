/*
Name         : Prabhat Kiran
Date         : 18th August 2022
Description  : WAP to print all possible combinations of given string.
Sample Input : 1) Enter a string: abc
               2) Enter a string: abb
Sample Output: 1) All possible combinations of given string :
                  abc
                  acb
                  bca
                  bac
                  cab
                  cba
               2) Error: please enter distinct characters.
*/

#include <stdio.h>

void combination (char [], int, int);
int my_strlen (char []);

int main()
{
    char str[100];
    int n, res;
    printf ("Enter a string: ");
    scanf ("%100[^\n]", str);
    n = my_strlen (str);
    char flag = 0;
    for (int i = 0; i < n; i++)     //To check if the string entered by the user has non-repeating characters.
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str [j] == str [i])
            {
                printf ("Error: Please enter distinct characters.\n");
                flag = 1;
            }
        }
    }
    if (flag == 0)      //If the user entered string has non-repeating characters, then call the function to print all the combinations of the string.
    {
        printf ("All the possible combinations of the given string are:\n");
        combination (str, 0, n - 1);
    }
    return 0;
}

int my_strlen (char str[])
{
    int count = 0;
    while (str [count] != '\0')     //To determine the length of the string.
    {
        count += 1;
    }
    return count;
}

void combination (char str[], int start, int end)
{
    if (start == end)       //If the starting position of the string becomes equal to the last position of the string i.e all the characters are fixed; print that string combination.
    {
        printf ("%s\n", str);
    }
    else
    {
        char temp;
        for (int i = start; i <= end; i++)      //To fix a character and swap the rest with that particular character till all the characters become fixed and no further swap is possible.
        {
            temp = str [i];                     //To swap the string by fixing a character.
            str [i] = str [start];
            str [start] = temp;
            
            combination (str, start + 1, end);  //The swapped string is again passed recursively to the function with 'start+1' so as to fix the next character and swap the rest in the string.
            
            temp = str [i];                     //After the function is returned, the particular swapping is reversed to backtrack the original string before the function call.
            str [i] = str [start];
            str [start] = temp;
        }
    }
}
