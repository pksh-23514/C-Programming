/*
Name         : Prabhat Kiran
Date         : 25th August 2022
Description  : Read n & n person names of maxlen 20. Sort and print the names.
Sample Input : 1) Enter the size: 5
                  Enter the 5 names of length max 20 characters in each
                  [0] -> Delhi
                  [1] -> Agra
                  [2] -> Kolkata
                  [3] -> Bengaluru
                  [4] -> Chennai
Sample Output: 1) The sorted names are:
                  Agra
                  Bengaluru
                  Chennai
                  Delhi
                  Kolkata
*/

#include <stdio.h>
#include <stdlib.h>

void sort_names (char (*)[20], int);
int my_strcmp (char*, char*);
void my_strcpy (char*, char*);

int main()
{
    char (*name) [20];                                                          //Pointer to the Array of 20 characters is declared.
    int size;
    printf ("Enter the size: ");
    scanf ("%d", &size);
    name = (char(*)[20]) malloc (sizeof (*name) * size);                        //Memory is allocated to the Pointer to Array dynamically.
    printf ("Enter the %d names of length max 20 characters in each\n", size);
    for (int i = 0; i < size; i++)                                              //Each string being an array of characters is being read in Array of Pointers.
    {
        printf ("[%d] -> ", i);
        scanf ("%s", name [i]);
    }

    sort_names (name, size);

    printf ("The sorted names are:\n");
    for (int i = 0; i < size; i++)
    {
        printf ("%s\n", name [i]);
    }

    free (name);        //To free the Pointer to Array.
    return 0;
}

int my_strcmp (char* s1, char* s2)      //To compare the 2 strings 's1' and 's2' and return the appropriate value.
{
    int i = 0;
    while ((s1 [i] == s2 [i]) && (s1 [i] != '\0'))  //The loop will run till either the characters of 's1' and 's2' are found different or 's1' reaches the '\0' character i.e. the End.
    {
        i++;
    }
    if (s1 [i] < s2 [i])        //If the character of 's1' is smaller than the character at 's2'; return a value of '-1'.
    {
        return -1;
    }
    else                        //Otherwise, return a value of '0'.
    {
        return 0;
    }
}

void my_strcpy (char* dest, char* src)     //To copy the Source string into the Destination string.
{
    int i = 0;
    while (src [i] != '\0')
    {
        dest [i] = src [i];
        i++;
    }
    dest [i] = '\0';
}

void sort_names (char (*s) [20], int n)
{
    for (int i = 0; i < n; i++)         //To run the loop for fixing a particular string that will be compared with the other strings in the Array of Strings.
    {
        for (int j = 0; j < n; j++)     //To run the loop for comparing the fixed string to all the other strings in the Array of Strings.
        {
            char temp [20];
            if ((my_strcmp (s[i], s[j])) == -1)     //If the value returned by the 'my_strcmp()' is negative, then the strings must be swapped.
            {
                my_strcpy (temp, s[i]);             //The first string is copied to the 'temp' variable.
                my_strcpy (s[i], s[j]);             //The second string is copied to the first string.
                my_strcpy (s[j], temp);             //The string in 'temp' is copied to the second string.
            }
        }
    }
}
