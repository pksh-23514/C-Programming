/*
Name         : Prabhat Kiran
Date         : 18th August 2022
Description  : WAP to check given string is Pangram or not.
Sample Input : 1) Enter the string: The quick brown fox jumps over the lazy dog.
               2) Enter the string: The quick brown fox jumps over the dog.
Sample Output: 1) The Entered String is a Pangram String
               2) The Entered String is not a Pangram String
*/

#include <stdio.h>

int pangram (char []);

int main()
{
    char str[100];
    printf ("Enter the string: ");
    scanf ("%[^\n]", str);

    int ret = pangram (str);    //The return value from the function decides if the operation is successful or failure i.e. '1' or '0'.
    if (ret == 1)
    {
        printf ("The Entered String is a Pangram String\n");
    }
    else
    {
        printf ("The Entered String is not a Pangram String\n");
    }
    return 0;
}

int pangram (char str[])
{
    int flag = 1;   //Overall flag determining success or failure.
    for (char ch = 'a'; ch <= 'z'; ch++)    //To check one by one if all the alphabets are present in the given string or not.
    {
        int i = 0, f = 0;   //Individual character flag.
        while (str [i] != '\0')     //To pick a particular alphabet and check it throughout the string.
        {
            if ((ch == str [i]) || (ch == str [i] + 32))    //The alphabet inside the string can be in Upper-case or Lower-case. This condition checks without being case-sensitive.
            {
                f = 1;      //If the particular character is found, character flag is changed to success and the loop is terminated.
                break;
            }
            i += 1;
        }
        flag = flag & f;    //If any of the character is absent, then the overall flag is made '0' for depiciting failure by ANDing it with the character flag.
        if (flag == 0)      //If the overall flag becomes '0', no further checking is required and the loop can be terminated.
        {
            break;
        }
    }
    return flag;    //If all the alphabets are present, '1' is returned depiciting success or else '0' is returned depicting failure.
}
