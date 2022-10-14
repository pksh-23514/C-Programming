/*
Name         : Prabhat Kiran
Date         : 29th August 2022
Description  : WAP to define a macro SIZEOF(x), without using sizeof operator.
Sample Output: 1) Size of int : 4 bytes
                  Size of char : 1 byte
                  Size of float : 4 bytes
                  Size of double : 8 bytes
                  Size of unsigned int : 4 bytes
                  Size of long int : 8 bytes
                  ------
                  ------
*/

#include <stdio.h>

#define SIZEOF(x)   ((char*) (&x + 1) - (char*) (&x))               //MACRO definition
int main()
{
    int i = 5;
    char ch = 'A';
    short s = 23;
    float f = 14.5f;
    double d = 5.23;
    long int l = 235;
    unsigned int j = 14;
    signed int k = -3;
    int arr [] = {1, 2, 3, 4, 5};
    char* str = "Hello";
    
//In all the below statements, the Macro will be expanded as defined above during the Pre-Processing.
    printf ("Size of int : %lu\n", SIZEOF(i));                          //Size of Integer.
    printf ("Size of char : %lu\n", SIZEOF(ch));                        //Size of Character.
    printf ("Size of short : %lu\n", SIZEOF(s));                        //Size of Short.
    printf ("Size of float : %lu\n", SIZEOF(f));                        //Size of Float.
    printf ("Size of double : %lu\n", SIZEOF(d));                       //Size of Double.
    printf ("Size of long : %lu\n", SIZEOF(l));                         //Size of Long.
    printf ("Size of unsigned int : %lu\n", SIZEOF(j));                 //Size of Unsigned Integer.
    printf ("Size of signed int : %lu\n", SIZEOF(k));                   //Size of Signed Integer.
    printf ("Size of int Array of 5 elements : %lu\n", SIZEOF(arr));    //Size of Array of 5 Integers.
    printf ("Size of char* Pointer : %lu\n", SIZEOF(str));              //Size of Pointer to Character.

    return 0;
}
