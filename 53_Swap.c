/*
Name         : Prabhat Kiran
Date         : 29th August 2022
Description  : WAP to define a macro swap (t, x, y) that swaps 2 arguments of type t.
Sample Input : 1. Int
               2. char
               3. short
               4. float
               5. double
               6. string
               Enter you choice : 1
               Enter the num1 : 10
               Enter the num2 : 20
Sample Output: After Swapping :
               num1 : 20
               num2 : 10
*/

#include <stdio.h>
#include <stdlib.h>

#define SWAP(t, x, y)               \
{                                   \
    t temp = x;                     \
    x = y;                          \
    y = temp;                       \
}
//The above definition is of a Multi-Line Macro.

int main()
{
    printf ("1. Int\n2. Char\n3. Short\n4. Float\n5. Double\n6. String\nEnter your Choice : ");
    int c;
    scanf ("%d", &c);       //To read the user's choice for executing the particular Swap.

    switch (c)
    {
        case 1 :            //If the user selects to swap the Integer data.
            {
                int a, b;
                printf ("Enter the value1 : ");
                scanf ("%d", &a);
                printf ("Enter the value2 : ");
                scanf ("%d", &b);
                SWAP(int, a, b)                                 //Macro expansion.
                printf ("After Swapping :\nvalue1 : %d\nvalue2 : %d\n", a, b);
            }
            break;
        case 2 :            //If the user selects to swap the Character data.
            {
                char a, b;
                printf ("Enter the value1 : ");
                scanf (" %c", &a);
                printf ("Enter the value2 : ");
                scanf (" %c", &b);
                SWAP(char, a, b)                                //Macro expansion.
                printf ("After Swapping :\nvalue1 : %c\nvalue2 : %c\n", a, b);
            }
            break;
        case 3 :            //If the user selects to swap the Short data.
            {
                short a, b;
                printf ("Enter the value1 : ");
                scanf ("%hd", &a);
                printf ("Enter the value2 : ");
                scanf ("%hd", &b);
                SWAP(short, a, b)                               //Macro expansion.
                printf ("After Swapping :\nvalue1 : %hd\nvalue2 : %hd\n", a, b);
            }
            break;
        case 4 :            //If the user selects to swap the Float data.
            {
                float a, b;
                printf ("Enter the value1 : ");
                scanf ("%f", &a);
                printf ("Enter the value2 : ");
                scanf ("%f", &b);
                SWAP(float, a, b)                               //Macro expansion.
                printf ("After Swapping :\nvalue1 : %f\nvalue2 : %f\n", a, b);
            }
            break;
        case 5 :            //If the user selects to swap the Double data.
            {
                double a, b;
                printf ("Enter the value1 : ");
                scanf ("%lf", &a);
                printf ("Enter the value2 : ");
                scanf ("%lf", &b);
                SWAP(double, a, b)                              //Macro expansion.
                printf ("After Swapping :\nvalue1 : %lf\nvalue2 : %lf\n", a, b);
            }
            break;
        case 6 :            //If the user selects to swap the String data.
            {
                char *a, *b;
                a = (char*) malloc (50 * sizeof (char));        //Memory allocation for reading the 2 strings.
                b = (char*) malloc (50 * sizeof (char));
                getchar ();                                     //To absorb the leftout character in the Input Buffer before reading the next string.
                printf ("Enter the value1 : ");
                scanf ("%50[^\n]", a);                          //Selective scanf().
                getchar ();                                     //To absorb the leftout character in the Input Buffer before reading the next string.
                printf ("Enter the value2 : ");
                scanf ("%50[^\n]", b);                          //Selective scanf().
                SWAP(char*, a, b)                               //Macro expansion.
                printf ("After Swapping :\nvalue1 : %s\nvalue2 : %s\n", a, b);
            }
            break;
        default : printf ("Enter the Choice value between 1 to 6.\n");
    }

    return 0;
}
