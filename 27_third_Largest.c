/*
Name         : Prabhat Kiran
Date         : 21st July 2022
Description  : WAP to find 3rd largest element in an array.
Sample Input : 1) Enter the size of the Array : 5
                  Enter the elements into the array: 5 1 4 2 8
               2) Enter the size of the Array : 4
                  Enter the elements into the array: 66 22 11 3
Sample Output: 1) Third largest element of the array is 4
               2) Third largest element of the array is 11
*/

#include <stdio.h>

int third_largest (int [], int);        //Function declaration of 'third_largest' to tell the compiler to search for the function definition later in the code.

int main()
{
    int size, ret;
    printf ("Enter the size of the array : ");
    scanf ("%d", &size);
    if (size > 2)           //The size of the array input by the user shall have a minimum of 2 elements.
    {
        int arr[size];
        printf ("Enter the elements into the array: ");
        for (int i = 0; i < size; i++)
        {
            scanf ("%d", &arr[i]);
        }

        ret = third_largest (arr, size);        //Function call to 'third_largest' with the function argument 'arr' and 'size'.
        printf ("Third largest element of the array is %d\n", ret);
    }
    else        //If the array size input by user is less than 3, an error message is printed.
    {
        printf ("Error:  The size of the array cannot be less than 3. Please enter the size greater than 2\n");
    }
    return 0;
}

int third_largest (int a[], int n)
{
    int min = a[0];                 //Initialise the variable 'min' with the first element of the array.
    for (int i = 1; i < n; i++)     //Check for the minimum value from the second element of the array.
    {
        if (min > a[i])     //If the array element is smaller than the 'min', store the array element in 'min'.
        {
            min = a[i];
        }
    }
    int fl = min, sl = min, tl = min;    //Initialise the variables with the minimum element of the array.
    for (int i = 0; i < n; i++)
    {
//If the array element is greater than the 'fl', the value 'a[i]' shall be swapped to 'fl', the value of 'fl' shall be swapped to 'sl' and the value of 'sl' shall be swapped to 'tl'.
        if (fl < a[i])
        {
            tl = sl;
            sl = fl;
            fl = a[i];
        }
//If the array element is greater than the 'sl' and the array element is not equal to 'fl', the value 'a[i]' shall be swapped to 'sl' and the value of 'sl' shall be swapped to 'tl'.
        else if ((sl < a[i]) && (a[i] != fl))
        {
            tl = sl;
            sl = a[i];
        }
//If the array element is greater than the 'tl' and the array element is not equal to 'fl' or 'sl, the value 'a[i]' shall be swapped to 'tl'.
        else if ((tl < a[i]) && (a[i] != fl) && (a[i] != sl))
        {
            tl = a[i];
        }
    }
    return tl;
}
