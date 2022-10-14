/*
Name         : Prabhat Kiran
Date         : 18th July 2022
Description  : WAP to put the (b-a+1) LSB’s of num into val[b:a].
               Example: Let's say the values are as follows:
               num = 11 = (0 0 0 0 1 0 1 1) 2
               val = 174 = (1 0 1 0 1 1 1 0) 2
               a = 3,
               b = 5
               No_of_bits = b – a + 1 = 5 – 3 + 1 = 3, get 3 bits from 11 (num) and replace 3 (No_of_bits) from 5th (b) postion of 174 (val) then;
               New 'val' value = (1 0 0 1 1 1 1 0) 2 = 158
Sample Input : Enter the value of 'num' : 11
               Enter the value of 'a' : 3
               Enter the value of 'b' : 5
               Enter the value of 'val': 174
Sample Output: Result : 158
*/

#include <stdio.h>

int replace_nbits_from_pos (int, int, int, int);

int main()
{
    int num, a, b, val, res = 0;
    printf ("Enter the value of 'num' : ");
    scanf ("%d", &num);
    printf ("Enter the value of 'a' : ");
    scanf ("%d", &a);
    printf ("Enter the value of 'b' : ");
    scanf ("%d", &b);
    printf ("Enter the value of 'val' : ");
    scanf ("%d", &val);

    if ((a < 32) && (b < 32) & (a < b))   //To check whether the value of 'a' & 'b' are less than the size of Integer and also the value of 'a' should be less than the value of 'b'. 
    {
        res = replace_nbits_from_pos (num, a, b, val);
        printf ("Result : %d\n", res);
    }
    else    //If the values of 'a' and 'b' are not within the permissible range or if 'a' is greater than 'b', the error is printed.
    {
        printf ("Error : Enter the values of 'a' and 'b' such that they are less than 32. Also, the value of 'a' should be less than the value of 'b'.\n");
    }
    return 0;
}

int replace_nbits_from_pos (int num, int a, int b, int val)
{
    return (((num & ((1 << (b - a + 1)) - 1)) << (b - a + 1)) | (val & (~(((1 << (b - a + 1)) - 1) << (b - a + 1)))));

//'((num & ((1 << (b - a + 1)) - 1))' : The AND operation is used to get the '(b-a+1)' bits from LSB side.
//'((n << (b-a+1))' : These are then shifted by 'b-a+1' to position them in such a way that they start from the position 'b'. These bits are to be replaced from the 'b'th position of the 'val'
//'(~(((1 << (b - a + 1)) - 1) << (b - a + 1)))' : The mask is created to clear the '(b-a+1)' bits from the position 'b' of the number.
//'(val & mask)' : The AND operation clears the '(b-a+1)' bits from the position 'b' of 'val'. The rest of the bits are left as it is.
//'(x | y)' : The OR operation is used to replace the '(b-a+1)' bits from 'num' to 'val' starting from the position 'b'.
}
