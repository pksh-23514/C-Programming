/*
Name         : Prabhat Kiran
Date         : 21st August 2022
Description  : Variance calculation with dynamic arrays.
Sample Input : 1) Enter the no.of elements : 10
                  Enter the 10 elements:
                  [0] -> 9
                  [1] -> 12
                  [2] -> 15
                  [3] -> 18
                  [4] -> 20
                  [5] -> 22
                  [6] -> 23
                  [7] -> 24
                  [8] -> 26
                  [9] -> 31
Sample Output: 1) Variance is 40.000000
*/

#include <stdio.h>
#include <stdlib.h>

float variance (int*, int);

int main()
{
    int* ptr = NULL;
    int n;
    printf ("Enter the number of elements : ");
    scanf ("%d", &n);

    ptr = (int*) malloc (n * sizeof (int));         //To allocate memory for 'n' integers dynamically.
    if (ptr != NULL)                                //If the memory allocation is successful, then only we can take the input from user.
    {
        printf ("Enter the %d elements:\n", n);     //To input the 'n' numbers from the user.
        for (int i = 0; i < n; i++)
        {
            printf ("[%d] -> ", i);
            scanf ("%d", &ptr [i]);
        }
    }

    float var = variance (ptr, n);
    printf ("Variance is %f\n", var);
    free (ptr);
    return 0;
}

float variance (int* p, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p [i];                       //To compute the sum of all the 'n' elements in the array.
    }
    float avg = (float) sum / (float) n;    //To compute the average of the 'n' elements in the array.
    
    sum = 0;                                //To use the 'sum' variable for calculating the sum of the squares of the 'n' deviations in the array.
    for (int i = 0; i < n; i++)
    {
        p [i] = p [i] - (int) avg;          //To compute the deviation of each element from the mean of the 'n' elements in the array.
        p [i] = p [i] * p [i];              //To compute the square of the deviation of each element in the array.
        sum += p [i];                       //To compute the sum of the squares of the deviation of 'n' elements in the array.
    }

    return ((float) sum / (float) n);       //To return the value of Variance which is equal to the (Sum of squares of deviations / Number of elements in the array).
}
