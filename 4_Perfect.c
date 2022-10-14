/*
Name         : Prabhat Kiran
Date         : 02nd July 2022
Description  : WAP to check if a number is Perfect or not.
               The first perfect number is 6, because 1, 2, and 3 are its proper positive divisors, and 1 + 2 + 3 = 6.
               Equivalently, the number 6 is equal to half the sum of all its positive divisors: ( 1 + 2 + 3 + 6 ) / 2 = 6.
Sample Input : 1) Enter a number: 6
               2) Enter a number: 10
               3) Enter a number: -1
Sample Output: 1) Yes, entered number is perfect number
               2) No, entered number is not a perfect number
               3) Invalid input, Enter only positive number
*/

#include <stdio.h>

int main()
{
    int num;
    printf ("Enter a number: ");
    scanf ("%d", &num);

    if (num > 0)    //To check whether the number entered by the user is positive or not.
    {
        int sum = 0;
        for (int i=1; i<num; i++)
        {
            if ((num % i) == 0)     //To check if the number stored in 'i' is a factor of the number entered by the user.
            {
                sum = sum + i;      //To find the sum of the factors of the number entered by the user.
            }
        }
        if (sum == num)     //If the sum of the factors is equal to the number entered by the user, it is a Perfect number.
        {
            printf ("Yes, entered number is perfect number\n");
        }
        else
        {
            printf ("No, entered number is not a perfect number\n");
        }
    }
    else    //If the number entered by the user is negative, print the error message.
    {
        printf ("Error : Invalid input, Enter only positive number\n");
    }
    return 0;
}
