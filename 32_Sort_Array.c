/*
Name         : Prabhat Kiran
Date         : 26th July 2022
Description  : Print the values in sorted order without modifying or copying array.
Sample Input : 1) Enter the size : 5
                  Enter 5 elements 
                  10 1 3 8 -1
               2) Enter the size : 7
                  Enter 7 elements 
                  1 3 2 5 4 7 6
               3) Enter the size : 4
                  Enter 4 elements 
                  -1 -2  4 3
Sample Output: 1) After sorting: -1 1 3 8 10
                  Original array values 10 1 3 8 -1
               2) After sorting: 1 2 3 4 5 6 7
                  Original array values 1 3 2 5 4 7 6
               3) After sorting: -2 -1 3 4
                  Original array values -1 -2  4 3
*/

#include <stdio.h>

void print_sort (int [], int);      //Function declaration of 'print_sort' to tell the compiler to search for the function definition later in the code.

int main()
{
    int size;
    printf ("Enter the size : ");
    scanf ("%d", &size);
    int arr[size];
    printf ("Enter the %d elements\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf ("%d", &arr[i]);
    }

    print_sort (arr, size);         //Function call to 'print_sort' with the function arguments 'arr' and 'size'.
    printf ("\n");
    printf ("Original array values ");
    for (int i = 0; i < size; i++)
    {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
    return 0;
}

void print_sort (int a[], int n)
{
    int min = a[0], max = a[0];     //Store the first element of the array in 'min' and 'max' initially.
    for (int i = 1; i < n; i++)     //Run the loop to find the minimum and maximum array element and store them in 'min' and 'max' respectively.
    {
        if (min > a[i])
        {
            min = a[i];
        }
        if (max < a[i])
        {
            max = a[i];
        }
    }
    printf ("After sorting: ");
    for (int i = 0; i < n; i++)
    {
        int sec = max;                  //In each iteration, the 'sec' should be initialised with the 'max' to keep the upper limit of the range intact.
        for (int j = 0; j < n; j++)     //We check for each element in the array to find the minimum element as we have to print the array in ascending order.
        {
            if ((a[j] > min) && (a[j] < sec))   //If the array element lies in the range of ['min','sec']; we store the array element in 'sec' to narrow down the search to a value just after 'min'.
            {
                sec = a[j];
            }
//The logic is to find the values in the range of ['min', 'max'] of the array in an ascending order by narrowing down the value of 'sec = max' to the next element that will be printed.
//The value in 'min' is printed and then it is updated with the value of 'sec' for printing the next smallest value in the consequent iteration.
//This process continues till we reach the last value i.e. 'max'.
        }
        printf ("%d ", min);
        min = sec;
    }
}
