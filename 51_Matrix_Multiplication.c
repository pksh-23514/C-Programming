/*
Name         : Prabhat Kiran
Date         : 28th August 2022
Description  : WAP to find the product of given matrix.
Sample Input : 1) Enter number of rows : 3
                  Enter number of columns : 3
                  Enter values for 3 x 3 matrix :
                  1      2      3
                  1      2      3
                  1      2      3
                  Enter number of rows : 3
                  Enter number of columns : 3
                  Enter values for 3 x 3 matrix :
                  1      1     1
                  2      2     2
                  3      3     3
               2) Enter number of rows : 3
                  Enter number of columns : 3
                  Enter values for 3 x 3 matrix :
                  1      2      3
                  1      2      3
                  1      2      3
                  Enter number of rows : 2
                  Enter number of columns : 3
Sample Output: 1) Product of two matrix :
                  14      14      14
                  14      14      14
                  14      14      14
               2) Matrix multiplication is not possible
*/

#include <stdio.h>
#include <stdlib.h>

int matrix_mul (int**, int, int, int**, int, int, int**, int, int);

int main()
{
    int **mat_a, **mat_b, **result;
    int row1, col1, row2, col2;
    printf ("Enter number of rows : ");
    scanf ("%d", &row1);
    printf ("Enter number of columns : ");
    scanf ("%d", &col1);
    mat_a = (int**) malloc (row1 * sizeof (int *));                 //To dynamically allocate the number of rows in Matrix-1.
    for (int i = 0; i < row1; i++)                                  //To dynamically allocate the number of columns in Matrix-1.
    {
        mat_a [i] = (int*) malloc (col1 * sizeof (int));
    }
    printf ("Enter values for %d x %d matrix :\n", row1, col1);
    for (int i = 0; i < row1; i++)                                  //To read the values in Matrix-1.
    {
        for (int j = 0; j < col1; j++)
        {
            scanf ("%d", &mat_a [i][j]);
        }
    }

    printf ("Enter number of rows : ");
    scanf ("%d", &row2);
    printf ("Enter number of columns : ");
    scanf ("%d", &col2);
    if (col1 == row2)                                   //Matrix multiplication is possible only if: The Number of Columns of the Matrix-1 = The Number of Rows of the Matrix-2.
    {
        mat_b = (int**) malloc (row2 * sizeof (int*));              //To dynamically allocate the number of rows in Matrix-2.
        for (int i = 0; i < row2; i++)                              //To dynamically allocate the number of columns in Matrix-2.
        {
            mat_b [i] = (int*) malloc (col2 * sizeof (int));
        }
        printf ("Enter values for %d x %d matrix :\n", row2, col2);
        for (int i = 0; i < row2; i++)                              //To read the values in Matrix-2.
        {
            for (int j = 0; j < col2; j++)
            {
                scanf ("%d", &mat_b [i][j]);
            }
        }
//The resultant matrix formed from the Multiplication of 2 Matrices has dimensions as: (The Number of Rows of the Matrix-1) X (The Number of Columns of the Matrix-2).
        result = (int**) malloc (row1 * sizeof (int*));             //To dynamically allocate the number of rows in the resultant Matrix.
        for (int i = 0; i < row1; i++)                              //To dynamically allocate the number of columns in the resultant Matrix.
        {
            result [i] = (int*) malloc (col2 * sizeof (int));
        }

        matrix_mul (mat_a, row1, col1, mat_b, row2, col2, result, row1, col2);

        printf ("Product of two matrix : \n");
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                printf ("%d\t", result [i][j]);
            }
            printf ("\n");
        }

        free (mat_b);       //Since, these 2 Arrays are allocated memory dynamically inside the if-block, we can free them here.
        free (result);
    }
    else    //If the Matrix multiplication rule is not satisfied, an error message is printed.
    {
        printf ("Matrix multiplication is not possible\n");
    }

    free (mat_a);           //Since, this array is allocated memory outside the if-block, we have to free it outside of the if-block.
    return 0;
}

int matrix_mul (int** a, int r1, int c1, int** b, int r2, int c2, int** res, int r, int c)
{
    for (int i = 0; i < r1; i++)            //To run the loop for the number of row times of the resultant Matrix.
    {
        for (int j = 0; j < c2; j++)        //To run the loop for the number of column times of the resultant Matrix.
        {
            for (int k = 0; k < c1; k++)    //This loop is used to calculate the sum of the products of combination position from the 2 Matrices being multiplied.
            {
                res [i][j] += (a [i][k] * b [k][j]);
            }
        }
    }
}
