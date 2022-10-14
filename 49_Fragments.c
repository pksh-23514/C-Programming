/*
Name         : Prabhat Kiran
Date         : 28th August 2022
Description  : WAP to implement fragments using Array of Pointers.
Sample Input : 1) Enter no.of rows : 3
                  Enter no of columns in row[0] : 4
                  Enter no of columns in row[1] : 3
                  Enter no of columns in row[2] : 5
                  Enter 4 values for row[0] : 1 2 3 4
                  Enter 3 values for row[1] : 2 5 9
                  Enter 5 values for row[2] : 1 3 2 4 1
Sample Output: 1) Before sorting output is:
                  1.000000 2.000000 3.000000 4.000000 2.500000
                  2.000000 5.000000 9.000000 5.333333
                  1.000000 3.000000 2.000000 4.000000 1.000000 2.200000
                  After sorting output is:
                  1.000000 3.000000 2.000000 4.000000 1.000000 2.200000
                  1.000000 2.000000 3.000000 4.000000 2.500000
                  2.000000 5.000000 9.000000 5.333333
 */

#include <stdio.h>
#include <stdlib.h>

int fragments (int, float* []);

int main()
{
    int row;
    printf ("Enter no of rows : ");
    scanf ("%d", &row);
    float* arr [row];                   //To allocate the memory for Rows statically.

    fragments (row, arr);
    
    return 0;
}

int fragments (int row, float* arr[])
{
    int col [row];
    for (int i = 0; i < row; i++)       //To allocate the memory for Columns dynamically.
    {
        printf ("Enter no of columns in row[%d] : ", i);
        scanf ("%d", &col [i]);
        arr [i] = (float*) malloc ((col [i] + 1) * sizeof (float));     //'col [i]+1' is used to allocate one additional space for storing the Average of all the values read in that Row.
    }

    for (int i = 0; i < row; i++)
    {
        float sum = 0;
        printf ("Enter %d values for row[%d] : ", col [i], i);
        for (int j = 0; j < col [i]; j++)
        {
            scanf ("%f", &arr [i][j]);
            sum += arr [i][j];                  //To calculate the sum of all the elements being stored in the particular Row.
        }
        arr [i][col [i]] = sum / col [i];       //To calculate the average of all the elements stored in the particular Row. The value is stored in the extra memory allocated in the end.
    }
    
    printf ("Before sorting output is:\n");     //To print the values before the Sorting happens.
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < (col [i] + 1); j++)
        {
            printf ("%f ", arr [i][j]);
        }
        printf ("\n");
    }

    float* t1;                          //The swapping of addresses will take place; so we declare the variable as float*.
    int t2;                             //The swapping of columns will take place; so we declare the variable as int.
    for (int i = 0; i < row; i++)       //To run the loop for fixing one row's average value to compare with the others.
    {
        for (int j = 0; j < row; j++)   //To run the loop for comparing all the other row's average value with the fixed row's average value.
        {
            if (arr [i][col [i]] < arr [j][col [j]])    //To find the smallest row's average value and swap it to the correct position. The 'a[i][c[x]] is the last position of the Row i.e. Average.
            {
                t1 = arr [i];       //To swap the addresses stored in the Array of Pointers.
                arr [i] = arr [j];
                arr [j] = t1;

                t2 = col [i];       //To swap the column values of the particular positions that are swapped in the Array of Pointers.
                col [i] = col [j];
                col [j] = t2;
            }
        }
    }
    
    printf ("After sorting output is:\n");      //To print the values after the Sorting happens.
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < (col [i] + 1); j++)
        {
            printf ("%f ", arr [i][j]);
        }
        printf ("\n");
    }

    for (int i = 0; i < row; i++)       //Since, only the columns are dynamically allocated in the Array of pointers, we have to free each of the address individually stored in 'arr[]'.
    {
        free (arr [i]);
    }

}
