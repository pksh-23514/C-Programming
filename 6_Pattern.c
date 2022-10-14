/*
Name         : Prabhat Kiran
Date         : 05th July 2022
Description  : WAP to print the numbers in X format as shown below.
Sample Input : 1) Enter the number: 4
               2) Enter the number: 5
Sample Output: 1) 1  4
                   23
                   23
                  1  4
               2) 1   5
                   2 4
                    3
                   2 4
                  1   5
*/

#include <stdio.h>

int main()
{
    int n;
    printf ("Enter the number of lines the pattern needs to be printed: ");
    scanf ("%d", &n);
    
    for (int i = 1; i <= n; i++)    //To run the loop for the Rows. The loop will run for the number of times entered by the User.
    {
        for (int j = 1; j <= n; j++)    //To run the loop for the Columns. The loop will run for the number of times entered by the User.
        {
            if ((j == i) || (j == (n - i + 1)))     //If the value of 'j' is equal to 'i' or equal to '(n - i + 1)', the value of 'j' needs to be printed.
            {
                printf ("%d", j);
            }
            else        //If the condition is false, a space should be printed as per the pattern requirement.
            {
                printf (" ");
            }
        }
        printf ("\n");      //To go to the next line after the previous line pattern is printed.
    }
    return 0;
}
