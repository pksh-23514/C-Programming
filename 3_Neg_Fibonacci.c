/*
Name         : Prabhat Kiran
Date         : 02nd July 2022
Description  : WAP to generate negative Fibonacci numbers.
Sample Input : 1) Enter a number: -8
               2) Enter a number: -10
               3) Enter a number: -21
               4) Enter a number: 13
Sample Output: 1) 0, 1, -1, 2, -3, 5, -8
               2) 0, 1, -1, 2, -3, 5, -8
               3) 0, 1, -1, 2, -3, 5, -8, 13, -21
               4) Invalid input
*/

//Negative Fibonacci can be generated using the Positive Fibonacci series.
//The magnitude of the values for both the series is equal.
//The only difference between both the series lies in the fact that the odd position values in the Negative Fibonacci series are negative in sign.

#include <stdio.h>

int main()
{
    int limit;
    printf ("Enter a number ");
    scanf ("%d", &limit);
    
    if (limit <= 0)     //To check if the number entered by the user is negative or not.
    {
        int first = 0, second = 1, third = 0, count = 1;
        //We run the loop assuming that we are printing the terms of normal Fibonacci series. Therefore, we have to make the 'limit' value positive in magnitude.
        while (third <= (0-limit))      //To run the loop till the term of the Fibonacci series are less than or equal to the value of '(-limit).
        {
            if (count%2 == 1)   //If the position of term of the Fibonacci series is odd, print the value in negative.
            {
                printf ("%d", ((-1)*third));
            }
            else                //If the position of term of the Fiboncci series is even, print the value in positive.
            {
                printf ("%d", third);
            }
            first = second;
            second = third;
            third = first + second;     //To generate the next term of the Fibonacci series.
            count = count + 1;          //To update the position of the terms of the Fibonacci series.
            if (third <= (0-limit))     //If the next term of the Fibonacci series generated is not the last term of the required series, then only the separator ',' needs to be printed.
            {
                printf (", ");
            }
        }
        printf ("\n");
    }
    else    //If the number entered by the User is positive, print an error message.
    {
        printf ("Invalid input\n");
    }
    return 0;
}
