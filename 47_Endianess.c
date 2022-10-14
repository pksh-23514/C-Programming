/*
Name         : Prabhat Kiran
Date         : 25th August 2022
Description  : WAP to convert Little Endian data to Big Endian.
Sample Input : 1) Enter the size: 2
                  Enter any number in Hexadecimal: ABCD
               2) Enter the size: 4
                  Enter any number in Hexadecimal: 12345678
Sample Output: 1) After conversion CDAB
               2) After conversion 78563412
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf ("Enter the size: ");
    scanf ("%d", &n);
    void* ch = malloc (n);      //Allocate the memory as per the number of bytes read from the user.
    if (n == 2)                 //If the number of bytes read is 2, input the number as 'short-type' by type-casting the pointer variable to (short*).
    {
        printf ("Enter any number in Hexadecimal: ");
        scanf ("%hX", (short*) ch);
    }
    else if (n == 4)            //If the number of bytes read is 4, input the number as 'int-type' by type-casting the pointer variable to (int*).
    {
        printf ("Enter any number in Hexadecimal: ");
        scanf ("%X", (int*) ch);
    }
    else                        //If the number of bytes read is anything other than 2/4, print an error message.
    {
        printf ("Enter the size of input as 2 or 4!\n");
        return 0;
    }
    
    for (int i = 0; i < (n / 2); i++)   //The loop will run to swap the bytes to convert the Little Endian to Big Endian.
    {
        *(char*) (ch + i) = *(char*) (ch + i) ^ *(char*) (ch + n - i - 1);
        *(char*) (ch + n - i - 1) = *(char*) (ch + i) ^ *(char*) (ch + n - i - 1);
        *(char*) (ch + i) = *(char*) (ch + i) ^ *(char*) (ch + n - i - 1);
    }
    printf ("After Conversion ");
    if (n == 2)                         //If the value of 'n' is 2; print the data as Short type.
    {
        printf ("%hX", *(short*) ch);
    }
    else if (n == 4)                    //If the value of 'n' is 4; print the data as Int type.
    {
        printf ("%X", *(int*) ch);
    }

    printf ("\n");
    free (ch);
    return 0;
}
