/*
Name         : Prabhat Kiran
Date         : 20th July 2022
Description  : WAP to find factorial of given number using recursion. 
Sample Input : 1) Enter the value of N : 7
               2) Enter the value of N : 5
               3) Enter the value of N : -1
               4) Enter the value of N : 0
Sample Output: 1) Factorial of the given number is 5040
               2) Factorial of the given number is 120
               3) Invalid Input
               4) Factorial of the given number is 1
*/

#include <stdio.h>

int main()
{
    static int num;             //The variables are declared static, so they will be initialised only once. But their values will be modified based on the conditions.
    static unsigned long long int fact = 1;
    static char flag = 1;       //The flag is used to get the input from the user only once. Otherwise, the compiler will call main() recursively and user will be prompted for input each time.

    if (flag == 1)
    {
        printf ("Enter the value of N : ");
        scanf ("%d", &num);
        flag = 0;               //In the next main() function call, since the flag value is static; the value will be '0' and the user will not be prompted for input.
    }
    
    if (num < 0)                //If the value of 'num' is negative, error message is displayed.
    {
        printf ("Invalid Input\n");
    }        
    else if (num > 0)           //If the value of 'num' is greater than '0', then the factorial value should be calculated.
    {
        fact = fact * num;
        num -= 1;       
        main();                 //The recursive function call to main() for calculating the factorial with value of 'num' decreased by 1.
    }
    else                        //If the value of 'num' is '0', it is the end of the Factorial operation and the value stored in 'fact' shall be printed.
    {
        printf ("Factorial of the given number is %llu\n", fact);
    }
    return 0;
}
