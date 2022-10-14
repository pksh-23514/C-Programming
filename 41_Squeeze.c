/*
Name         : Prabhat Kiran
Date         : 09th August 2022
Description  : Squeeze the character in s1 that matches any character in the string s2.
Sample Input : 1) Enter s1 : Dennis Ritchie
                  Enter s2 : Linux
               2) Enter s1 : Welcome
                  Enter s2 : Emertxe
Sample Output: 1) After squeeze s1 : Des Rtche
               2) After squeeze s1 : Wlco
*/

#include <stdio.h>

void squeeze (char[], char[]);

int main()
{
    char str1[30], str2[30];
    printf ("Enter s1 : ");
    scanf ("%[^\n]", str1);
    getchar();
    printf ("Enter s2 : ");
    scanf ("%[^\n]", str2);

    squeeze (str1, str2);
    printf ("After squeeze s1 : %s\n", str1);
    return 0;
}
   
void squeeze (char str1[], char str2[])
{
    int i = 0;
    while (str2 [i] != '\0')        //The loop will run till the end of the input string-2 is reached.
    {
        int j = 0;
        while (str1[j] != '\0')     //The loop will run till the end of the input string-1 is reached.
        {
            if (str1 [j] == str2 [i])       //To match each character in the 'str1' with the character of 'str2' and remove them from 'str1'.
            {
                int k = j;                  //If there is a match, all the characters starting from that index till the end of 'str1' shall be moved one position ahead.
                while (str1 [k] != '\0')    //The loop will run from the matched index till the end of 'str1'.
                {
                    str1 [k] = str1 [k+1];  //The current position character is replaced with the character at the next position.
                    k += 1;
                }
                continue;           //To start the checking process again from the index where the previous matched character was found.
            }
            j += 1;
        }
        i += 1;
    }
}
