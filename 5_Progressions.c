/*
Name         : Prabhat Kiran
Date         : 04th July 2022
Description  : WAP to generate AP, GP & HP series.
Sample Input : 1) Enter the First Number 'A': 2
                  Enter the Common Difference / Ratio 'R': 3
                  Enter the number of terms 'N': 5
               2) Enter the First Number 'A': 2
                  Enter the Common Difference / Ratio 'R': 3
                  Enter the number of terms 'N': -5
Sample Output: 1) AP = 2, 5, 8, 11, 14
                  GP = 2, 6, 18, 54, 162
                  HP = 0.500000, 0.200000, 0.125000, 0.090909, 0.071428
               2) Invalid input
*/

#include <stdio.h>

int main()
{
    int a,r,n;
    printf ("Enter the First Number 'A': ");
    scanf ("%d", &a);
    printf ("Enter the Common Difference / Ratio 'R': ");
    scanf ("%d", &r);
    printf ("Enter the number of terms 'N': ");
    scanf ("%d", &n);

    if ((a != 0) && (n > 0))    //To check if the value of 'A' is not equal to zero and value of 'N' is greater than zero.
    {
        int ap = a, gp = a;
        double hp = (double) 1/a;   //To convert the value of '1/a' to double data-type using explicit type-casting.

        printf ("AP = ");
        for (int i = 1; i <= n; i++)    //The loop will print the user entered number of terms of Arithmetic Progression.
        {
            printf ("%d", ap);
            ap += r;    //To generate the next term of the Arithmentic Progression.
            if (i < n)  //To check if the next term is not the last term of the series. If yes, then only print the separator ','.    
            {
                printf (",");
            }
        }
        
        printf ("\nGP = ");
        for (int i = 1; i <= n; i++)    //The loop will print the user entered number of terms of Geometric Progression.
        {
            printf ("%d", gp);
            gp *= r;    //To generate the next term of the Geometric Progression.
            if (i < n)  //To check if the next term is not the last term of the series. If yes, then only print the separator ','.
            {
                printf (",");
            }
        }

        printf ("\nHP = ");
        ap = a;     //The nth Harmonic Progression is the inverse of the nth Arithmetic Progression.
        for (int i = 1; i <= n; i++)//The loop will print the user entered number of terms of Harmonic Progression.
        {
            printf ("%lf", hp);
            ap += r;    //To generate the next term of the Arithmetic Progression.
            hp = (double) 1 / ap;   //To generate the next term of the Harmonic Progression using the formula of "Harmonic Progression (ith term) = 1/Arithmetic Progression (ith term).
            if (i < n)  //To check if the next term is not the last term of the series. If yes, then only print the separator ','.
            {
                printf (",");
            }
        }
        printf ("\n");
    }
    else    //If the user entered zero for the variable 'A' or a negative value for the variable 'N'; print an error message.
    {
        printf ("Invalid input\n");
    }
    return 0;
}
