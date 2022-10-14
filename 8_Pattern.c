/*
Name         : Prabhat Kiran
Date         : 05th July 2022
Description  : WAP to print pyramid pattern as shown below. 
Sample Input : 1) Enter the number: 4
               2) Enter the number: 5
Sample Output: 1) 4
                  3 4
                  2 3 4
                  1 2 3 4
                  2 3 4
                  3 4
                  4
               2) 5
                  4 5
                  3 4 5
                  2 3 4 5
                  1 2 3 4 5
                  2 3 4 5
                  3 4 5
                  4 5
                  5
*/

#include <stdio.h>

int main()
{
    int n;
    printf ("Enter the number of lines the pattern needs to be printed: ");
    scanf ("%d", &n);

    for (int i = n; i >= 1; i--)    //To run the loop for the Rows. The loop will run for the number of times entered by the User.
    {
        for (int j = i; j <= n; j++)    //To run the loop for the Columns. The loop will run for the number of times entered by the User.
        {
            printf ("%d ", j);
        }
        printf ("\n");
    }       //End of the upper part of the pattern
    //The lower part of the pattern has (n - 1) lines only.
    for (int i = 2; i <= n; i++)  //To run the loop for the Rows. The loop will run for one less than the number of times entered by the User.
    {
        for (int j = i; j <= n; j++)    //To run the loop for the Columns. The loop will run from the value of 'i' to the number of times entered by the User.
        {
            printf ("%d ", j);
        }
        printf ("\n");
    }       //End of the lower part of the pattern.
    return 0;
}
