/*
Name         : Prabhat Kiran
Date         : 18th August 2022
Description  : Generate consecutive NRPS of length n using k distinct character.
Sample Input : 1) Enter the number characters C : 3
                  Enter the Length of the string N : 6
                  Enter 3 distinct characters : a b c
               2) Enter the number characters C : 3
                  Enter the Length of the string N : 7
                  Enter 3 distinct characters : a b a
Sample Output: 1) Possible NRPS is abcbca
               2) Error : Enter distinct characters
*/

#include <stdio.h>

void nrps (char [], int, int);

int main ()
{
    int c;
    printf ("Enter the number of characters C : ");
    scanf ("%d", &c);
    int n;
    printf ("Enter the Length of the string N : ");
    scanf ("%d", &n);
    char str [c];
    printf ("Enter %d distinct characters : ", c);
    scanf (" %[^\n]", str);
    char flag = 0;
    for (int i = 0; i < c; i++)     //To check if the string entered by the user has non-repeating characters.
    {
        for (int j = i + 1; j < c; j++)
        {
            if (str [j] == str [i])
            {
                printf ("Error: Enter distinct characters!\n");
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)      //If the user entered string has non-repeating characters, then call the function to print all the combinations of the string.
    {
        nrps (str, c, n);
        printf ("\n");
    }
    return 0;
}

void nrps (char str[], int c, int n)
{
    int count = 0, j;
    while (1)           //The loop will run till the number of characters printed on the screen becomes equal to length of the string entered by the user.
    {
        for (j = 0; j < c; j++)     //To print the characters in the string.
        {
            printf ("%c", str[j]);
            count += 1;
            if (count == n)         //If the 'count' becomes equal to the desired length of string 'n'; the function shall terminate.
            {
                return;
            }
        }
        for (j = 0; j < (c -1); j++)    //To generate the next possible non-repititive combination of the string by swapping a pair of characters in the string.
        {
            str [j] = str [j] ^ str [j + 1];
            str [j + 1] = str [j] ^ str [j + 1];
            str [j] = str [j] ^ str [j + 1];
        }
    }
}
