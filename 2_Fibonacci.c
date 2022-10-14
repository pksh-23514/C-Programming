/*
Name         : Prabhat Kiran
Date         : 02nd July 2022
Description  : WAP to generate positive Fibonacci numbers.
Sample Input : 1) Enter a number: 8
               2) Enter a number: 10
               3) Enter a number: 21
               4) Enter a number: -21
Sample Output: 1) 0, 1, 1, 2, 3, 5, 8
               2) 0, 1, 1, 2, 3, 5, 8
               3) 0, 1, 1, 2, 3, 5, 8, 13, 21
               4) Invalid input
*/

#include <stdio.h>

int main()
{
    int limit;
    printf ("Enter a number: ");
    scanf ("%d", &limit);
    
    if (limit >= 0)     //To check if the number entered by the user is positive or not.
    {
        int first = 0, second = 1, third = 0;
        while (third <= limit)      //The Fibonacci series will continue till the generated terms are less than or equal to the number entered by the user.
        {
            printf ("%d", third);   //Print the term of the Fibonacci series.
            first = second;         //Swapping of the terms is done.
            second = third;
            third = first + second; //To generate the next term of the Fibonacci series.
            if (third <= limit)     //If the next term of the Fibonacci series generated is not the last term of the required series, then only the separator ',' needs to be printed.
            {
                printf (", ");
            }
        }
        printf ("\n");
    }
    else    //If the number is negative, print the error message.
    {
        printf ("Invalid input\n");
    }
    return 0;
}
