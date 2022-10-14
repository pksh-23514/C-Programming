/*
Name         : Prabhat Kiran
Date         : 06th July 2022
Description  : WAP to find which day of the year.
Sample Input : 1) Enter the value of 'n' : 9
                  Choose First Day :
                  1. Sunday
                  2. Monday
                  3. Tuesday
                  4. Wednesday
                  5. Thursday
                  6. Friday
                  7. Saturday
                  Enter the option to set the first day : 2
               2) Enter the value of 'n' : 9
                  Choose First Day :
                  1. Sunday
                  2. Monday
                  3. Tuesday
                  4. Wednesday
                  5. Thursday
                  6. Friday
                  7. Saturday
                  Enter the option to set the first day : 8
               3) Enter the value of 'n' : 0
               4) Enter the value of 'n' : 366
Sample Output: 1) The day is Tuesday
               2) Error: Invalid input, first day should be > 0 and <= 7
               3) Error: Invalid Input, n value should be > 0 and <= 365
               4) Error: Invalid Input, n value should be > 0 and <= 365
*/

#include <stdio.h>

int main()
{
    int n;
    printf ("Enter the value of 'n' : ");
    scanf ("%u", &n);
    if ((n > 0) && (n <= 365))      //To check whether the value of 'n' lies in the range of 0-365.
    {
        int first_day;
        printf ("Choose First Day :\n");
        printf ("1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");
        printf ("Enter the option to set the first day : ");
        scanf ("%u", &first_day);

        if ((first_day > 0) && (first_day <=7))     //To check whether the value of 'first_day' lies in the range if 1-7.
        {
            n = ((n + first_day - 1) % 7);      //To calculate the day based on the selection of first day and value of 'n'.
            //As per the problem requirement, the day count should start from the 'first_day' input choice. Therefore, we need to subtract 1 from the sum of 'n + first_day'.
            
            switch (n)
            {
                case 1: printf ("The day is Sunday\n");
                        break;
                case 2: printf ("The day is Monday\n");
                        break;
                case 3: printf ("The day is Tuesday\n");
                        break;
                case 4: printf ("The day is Wednesday\n");
                        break;
                case 5: printf ("The day is Thursday\n");
                        break;
                case 6: printf ("The day is Friday\n");
                        break;
                case 0: printf ("The day is Saturday\n");
                        break;
            }
        }
        else    //If the value of 'first_day' doesn't lies in the range, print an error message.
        {
            printf ("Error: Invalid input, first day should be > 0 and <= 7\n");
        }
    }
    else    //If the value of 'n' doesn't lies in the range, print an error message.
    {
        printf ("Error: Invalid Input, n value should be > 0 and <= 365\n");
    }
    return 0;
}
