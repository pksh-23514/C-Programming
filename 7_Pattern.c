/*
Name         : Prabhat Kiran
Date         : 05th July 2022
Description  : WAP to print the triangle pattern as shown below.
Sample Input : 1) Enter the number: 4
               2) Enter the number: 5
Sample Output: 1) 1 2 3 4
                  5     6
                  7 8
                  9
               2) 1 2 3 4 5
                  6       7
                  8    9
                  10 11
                  12
*/

#include <stdio.h>

int main()
{
    int n;
    printf ("Enter the number: ");
    scanf ("%d", &n);
    
    int p = 1;
    for (int i = n; i >= 1; i--)    //To run the loop for the Rows. The loop will run for the number of times entered by the User.
    {
        for (int j = 1; j <= i; j++)    //To run the loop for the Columns. The loop will run for the 'i' number of times.
        {
            if ((i == n) || (j == 1) || (j == i))   //If the value of 'i' is equal to first row i.e. 'n' or 'j' is equal to '1' i.e. 1st column or equal to 'i', the value of 'p' needs to be printed.
            {
                printf ("%d ", p);
                p = p + 1;          //The value of 'p' needs to updated after every printing.
            }
            else    //If the condition is false, a space should be printed as per the pattern requirement.
            {
                printf ("  ");
            }
        }
        printf ("\n");  //To go to the next line after the previous line pattern is printed.
    }
    return 0;
}
