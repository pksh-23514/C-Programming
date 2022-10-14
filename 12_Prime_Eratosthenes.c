/*
Name         : Prabhat Kiran
Date         : 12th July 2022
Description  : WAP to print all primes using Sieve of Eratosthenes method.
Sample Input : 1) Enter the value of 'n' : 20
               2) Enter the value of 'n' : -20
Sample Output: 1) The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
               2) Please enter a positive number which is > 1
*/

#include <stdio.h>

int main()
{
    int n;
    printf ("Enter the value of 'n' : ");
    scanf ("%d", &n);

    if (n > 1)      //The value entered by the user should be greater than '1' as the first prime number is '2'.
    {
        int a[n + 1];   //We create the array starting from '0' till the value of 'n', which makes the total length of array as (n+1). So, we require one additional index.
        for (int i = 0; i < (n + 1); i++)   //The loop is used to create the array such that the element stored at index 'i' has a value 'i'. It runs from '0' to 'n' storing all the values.
        {
            a[i] = i;
        }

        //If a factor is greater than the square root of 'n', the other factor required to multiply with it to make the product equal to 'n'; will necessarily less than the square root of 'n'.
        //So, we need to run the loop upto the square root of 'n'.
        
        for (int i = 2; (i * i) < (n + 1); i++)     //Since, the first prime number is '2', we start checking from 'i=2'.
        {
            //If the value of 'i' is a prime number, then only the multiples of 'i' should be removed from the array.
            //Eg.- If 'i=4', itself and it's multiples are already '0'. '4' is a multiple of '2', which has already been checked and executed in the previous iterations.

            if (a[i] != 0)      //If the index 'i' is a non-zero value, then only it's multiples should be made '0'
            {
                int j = 2;              //We have to retain the original value of 'i'as it is a prime number. So, the multiple starts with '2'.
                while ((i * j) <= n)    //All the multiples of 'i' upto 'n' are made '0' as if they are divisible by 'i', they cannot be a prime number.
                {
                    a[(i * j)] = 0;     //We implement the same in the array. All the positions in the array with index '(i*j)' are updated with the value of '0'.
                    j += 1;
                }
            }
        }

        printf ("The primes less than or equal to %d are :  ", n);
        for (int i = 2; i < (n + 1); i++)       //To print all the prime numbers starting from the value '2'.
        {
            if (a[i] != 0)
            {
                printf ("%d, ", a[i]);
            }
        }
        printf ("\n");        
    }
    else
    {
        printf ("Please enter a positive number which is > 1\n");
    }
    return 0;
}
