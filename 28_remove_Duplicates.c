/*
Name         : Prabhat Kiran
Date         : 22nd July 2022
Description  : WAP to remove duplicate elements in a given array.
Sample Input : 1) Enter the size: 5
                  Enter elements into the array: 5 1 3 1 5
               2) Enter the size: 5
                  Enter elements into the array: 2 1 1 1 5
Sample Output: 1) After removing duplicates: 5 1 3
               2) After removing duplicates: 2 1 5
*/

#include <stdio.h>

void fun (int [], int, int [], int*);       //Function declaration of 'fun' to tell the compiler to search for the function definition later in the code.

int main()
{
    int size;
    printf ("Enter the size: ");
    scanf ("%d", &size);
    if (size > 0)           //The size of the array input by the user shall be positive.
    {
        int initial_arr[size];
        int new_size = 0, final_arr[size];
        printf ("Enter elements into the array: ");
        for (int i = 0; i < size; i++)
        {
            scanf ("%d", &initial_arr[i]);
        }
        
        fun (initial_arr, size, final_arr, &new_size);      //Function call to 'fun' with the function argument 'arr', 'size', 'final_arr' and address of 'new_size'.
        printf ("After removing duplicates: ");
        for (int i = 0; i < new_size; i++)
        {
            printf ("%d ", final_arr[i]);
        }
        printf ("\n");
    }
    else                    //If the array size input by user is less than or equal to 0, an error message is printed.
    {
        printf ("Error:  The size of the array cannot be negative.\n");
    }
    return 0;
}

void fun (int a[], int n, int b[], int* c)
{
    for (int i = 0; i < n; i++)     //This loop is to copy the elements of the array into the updated array.
    {
        int j;
        for (j = 0; j < *c; j++)    //This loop is used to check if the elements are duplicate or not.
        {
            if (a[i] == b[j])       //If the element to be copied from the array is already present in the updated array, the loop will terminate pre-maturely.
            {
                break;
            }
        }
        if (j == *c)    //If the loop terminates normally, value of 'j' will be equal to '*c'. If the duplicate element is found, the loop breaks with the value of 'j' being less than '*c'.
        {
            b[*c] = a[i];
            *c += 1;
        }
    }
}
