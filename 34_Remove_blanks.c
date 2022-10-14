/*
Name         : Prabhat Kiran
Date         : 09th August 2022
Description  : WAP to replace each string of one or more blanks by a single blank.
Sample Input : 1) Pointers     are               sharp     knives.
               2) Welcome                to Emertxe
               3) Welcome to Emertxe
Sample Output: 1) Pointers are sharp knives.
               2) Welcome to Emertxe
               3) Welcome to Emertxe
*/

#include <stdio.h>

void replace_blank (char []);

int main()
{
    char str [50];
    printf ("Enter the string with more spaces in between two words\n");
    scanf ("%[^\n]", str);      //Selective scanf() being used to read till we encounter the new-line character.

    replace_blank (str);
    printf ("%s\n", str);       //To print the modified string.
    return 0;
}

void replace_blank (char str[])
{
    int i = 0;
    while (str [i] != '\0')     //The loop will run till we reach the end of the string.
    {
        if (str [i] == ' ')     //If a blank is encountered in the string, the next character in the string needs to be checked to decide whether modification is required or not.
        {
            if ((str [i + 1] == ' ') || (str [i + 1] == '\t'))  //If the next character in the string is a blank or tab; it needs to be replaced with the subsequent part of the string.
            {
                int j = i;  //The shifting of the subsequent part of the string happens from the position where the blank is encountered to the end of the string.
                while (str [j] != '\0')
                {
                    str [j] = str [j + 1];      //The current position character is replaced with the character at the next position.
                    j += 1;
                }
                continue;   //To repeat this process till we have removed all the multiple gaps in the string.
            }
        }
        else if (str [i] == '\t')   //If a tab is encountered in the string, the next character in the string needs to be checked to decide whether modification is required or not.
        {
            if ((str [i + 1] == '\t') || (str [i + 1] == ' '))  //If the next character in the string is a blank or tab; it needs to be replaced with the subsequent part of the string.
            {
                int j = i;  //The shifting of the subsequent part of the string happens from the position where the tab is encountered to the end of the string.
                while (str [j] != '\0')
                {
                    str [j] = str [j + 1];      //The current position character is replaced with the character at the next position.
                    j += 1;
                }
                continue;   //To repeat this process till we have removed all the multiple gaps in the string.
            }
            else if (str [i + 1] != '\t')   //If there is only one tab encountered, that also shall be replaced by one blank.
            {
                str [i] = ' ';
            }
        }
        i += 1;
    }
}
