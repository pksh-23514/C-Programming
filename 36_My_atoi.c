/*
Name         : Prabhat Kiran
Date         : 10th August 2022
Description  : WAP to implement atoi function.
Sample Input : 1) Enter a numeric string: 12345
               2) Enter a numeric string: -12345
               3) Enter a numeric string: +12345
               4) Enter a numeric string: +-12345
               5) Enter a numeric string: 12345-
               6) Enter a numeric string: abcd12345
               7) Enter a numeric string: 12345abcd
               8) Enter a numeric string: ++12345
Sample Output: 1) String to integer is 12345
               2) String to integer is -12345
               3) String to integer is 12345
               4) String to integer is 0
               5) String to integer is 12345
               6) String to integer is 0
               7) String to integer is 12345
               8) String to integer is 0
*/

#include <stdio.h>

int my_atoi (const char[]);

int main()
{
    char str[20];
    printf ("Enter a numeric string : ");
    scanf ("%s", str);

    printf ("String to Integer is %d\n", my_atoi (str));
    return 0;
}

int my_atoi (const char str[])
{
    int temp = 0, num = 0, i = 0, flag = 0;
    while (str [i] != '\0')     //The loop will run till we reach the end of the string.
    {
        if ((str [i] >= '0') && (str [i] <= '9'))   //If the character lies in the range of '0' to '9', it should be converted to an integer value with proper decimal position.
        {
            temp = str [i] - 48;        //Conversion of ASCII character value to decimal value.
            num = (num * 10) + temp;    //Constituting the integer from the base position.
            i += 1;
        }
        else if ((str [i] == '+') || str[i] == '-' && (i == 0))     //If the first position of the string has a '+' or '-', the loop should continue checking ignoring that position.
        {
            i += 1;
        }
        else    //If any character other than the above conditions are encountered, the loop should terminate.
        {
            break;
        }
    }
    if (str [0] == '+')     //If the first position of the string has '+' sign, the function returns a '0' or 'positive number' based on the below condition.
    {
        if ((str [1] == '+') || (str [1] == '-'))
        {
            return 0;
        }
        else
        {
            return (num);
        }
    }
    else if (str [0] == '-')    //If the first position of the string has '-' sign, the function returns a '0' or 'negative number' based on the below condition.
    {
        if ((str [1] == '+') || (str [1] == '-'))
        {
            return 0;
        }
        else
        {
            return (-num);
        }
    }
    else    //If the string starts with any other character apart from '+' or '-', the 'num' calculated is returned as it is.
    {
        return (num);
    }
}
