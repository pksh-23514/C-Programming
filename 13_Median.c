/*
Name         : Prabhat Kiran
Date         : 12th July 2022
Description  : WAP to find the median of two unsorted arrays.
Sample Input : 1) Enter the 'n' value for Array A: 5
                  Enter the 'n' value for Array B: 5
                  Enter the elements one by one for Array A: 3 2 8 5 4
                  Enter the elements one by one for Array B: 12 3 7 8 5
               2) Enter the 'n' value for Array A: 5
                  Enter the 'n' value for Array B: 4
                  Enter the elements one by one for Array A: 3 2 8 5 4
                  Enter the elements one by one for Array B: 12 13 7 5
Sample Output: 1) Median of array1 : 4
                  Median of array2 : 7
                  Median of both arrays : 5.5
               2) Median of array1 : 4
                  Median of array2 : 9.5
                  Median of both arrays : 6.75
*/

#include <stdio.h>

int main()
{
    int n1,n2;
    printf ("Enter the 'n' value for Array A: ");
    scanf ("%d", &n1);
    printf ("Enter the 'n' value for Array B: ");
    scanf ("%d", &n2);
    int a[n1], b[n2];

    printf ("Enter the elements one by one for Array A: ");     //To input the elements of the first array from user.
    for (int i = 0; i < n1; i++)
    {
        scanf ("%d", &a[i]);
    }
    printf ("Enter the elements one by one for Array B: ");     //To input the elements of the second array from user.
    for (int i = 0; i < n2; i++)
    {
        scanf ("%d", &b[i]);
    }

    int temp = 0;
    for (int i = 0; i < n1; i++)    //To sort the elements of the first array using Bubble sort technique.
    {
        for (int j = 0; j < (n1 - i - 1); j++)      //The loop will compare the adjacent elements of the array and swap if their order is incorrect.
        {
            if (a[j] > a[j + 1]) //If the value of the element at 'a[j]' is greater than the value at 'a[j+1]', the swapping takes place. This causes the largest element to reach its correct position.
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n2; i++)    //To sort the elements of the first array using Bubble sort technique.
    {
        for (int j = 0; j < (n2 - i - 1); j++)      //The loop will compare the adjacent elements of the array and swap if their order is incorrect.
        {
            if (b[j] > b[j + 1]) //If the value of the element at 'a[j]' is greater than the value at 'a[j+1]', the swapping takes place. This causes the largest element to reach its correct position.
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    
    float med1 = 0.0f, med2 = 0.0f, median = 0.0f;
    if (n1 % 2 == 1)    //If the array size is an odd number, the median of the array is the element at the middle index of the sorted array.
    {
        med1 = (float) a[(n1 / 2)];
    }
    else    //If the array size is an even number, the median of the array is the average of the 2 elements at the index of 'n/2' and '(n/2)-1' of the sorted array.
    {
        med1 = ((float) (a[(n1 / 2) - 1] + a[(n1 / 2)])) / 2.0f;
    }
    if (n2 % 2 == 1)    //If the array size is an odd number, the median of the array is the element at the middle index of the sorted array.
    {
        med2 = (float) b[(n2 / 2)];
    }
    else    //If the array size is an even number, the median of the array is the average of the 2 elements at the index of 'n/2' and '(n/2)-1' of the sorted array.
    {
        med2 = ((float) (b[(n2 / 2) - 1] + b[(n2 / 2)])) / 2.0f;
    }
    median = (med1 + med2) / 2;     //The median of the complete data in both the arrays is the average of the medians of the individual array.

    printf ("Median of array1 : %g\n", med1);
    printf ("Median of array2 : %g\n", med2);
    printf ("Median of both arrays : %g\n", median);
    return 0;
}
