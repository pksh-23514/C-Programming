/*
Name         : Prabhat Kiran
Date         : 28th August 2022
Description  : WAP to generate a n*n magic square.
Sample Input : 1) Enter a number: 3
               2) Enter a number: 6
Sample Output: 1) 8      1      6
                  3      5      7
                  4      9      2
               2) Error : Please enter only positive odd numbers
*/

#include <stdio.h>
#include <stdlib.h>

void magic_square (int**, int);

int main()
{
    int size;
    int** sqr;
    printf ("Enter a number: ");
    scanf ("%d", &size);
    if (((size > 0) && (size & 1) == 1))    //The 'size' value should be odd and positive.
    {
        sqr = (int**) calloc (size, sizeof (int*));     //The matrix shall be a Square matrix.
        for (int i = 0; i < size; i++)
        {
            sqr [i] = (int*) calloc (size, sizeof (int));
        }
        
        magic_square (sqr, size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf ("%d\t", sqr [i][j]);
            }
            printf ("\n");
        }
        free (sqr);
    }
    else    //If the value of 'size' is not an odd and positive value, an error message shall be printed.
    {
        printf ("Error : Please enter only positive odd numbers\n");
    }

    return 0;
}

void magic_square (int** p, int n)
{
    int row = 0, col = (n /2), c = 1, i = 0;    //The magic square always starts with the first value being placed at the position - "middle column of the first row".
    while (i < n)       //To run the loop for Rows. The final matrix shall have 'n' number of rows.
    {
        int j = 0;
        while (j < n)   //To run the loop for Columns. The final matrix shall have 'n' number of columns.
        {
            if (row < 0)    //The Boundary condition: If 'row' becomes negative i.e. above the 0th row; it's value should be shifted to the '(n-row)'th row.
            {
                row += n;
            }
            else if (row >= n)   //The Boundary condition: If 'row' value becomes greater than equal to 'n' i.e. below the (n-1)th row; it's value should be shifted to '(row-n)'th row.
            {
                row -= n;
            }
            if (col == n)   //The Boundary condition: If 'col' value becomes equal to 'n' i.e. right of the (n-1)th column; it's value should be shifted to '(col-n)'th column.
            {
                col -= n;
            }
            else if (col < 0)   //The Boundary condition: If 'col' value becomes negative i.e. left of the 0th column; it's value should be shifted to '(n-col)'th column.
            {
                col += n;
            }
            if (p [row][col] == 0)      //If the [row][col] position is empty i.e. having '0'; push the value of 'c' to that position.
            {
                p [row][col] = c;
                c += 1;                 //Increase the value of 'c'.
                row -= 1;               //Decrease the value of 'row' to move UP.
                col += 1;               //Increase the value of 'col' to move RIGHT.
            }
            else                        //If the [row][col] position is occupied; move to the location below the previous position and push the value of 'c' there.
            {
                row += 2;               //Increase the value of 'row' by 2 to go to the row location below the previous position.
                col -= 1;               //Decrease the value of 'col' by 1 to go to the column location same as the previous location.
                continue;               //The loop shall run without increasing the 'j' value till the value of 'c' is pushed on the desired location.
            }
            j += 1;
        }
        i += 1;
    }
}
