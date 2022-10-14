/*
Name         : Prabhat Kiran
Date         : 27th July 2022
Description  : WAP to count no. of characters, words and lines, entered through stdin.
Sample Input : 1) Hello world
                  Dennis Ritchie
                  Linux
               2) Hello         world
                  Dennis    Ritchie
                  Linux
Sample Output: 1) Character count : 33
                  Line count : 3
                  Word count : 5
               2) Character count : 39
                  Line count : 3
                  Word count : 5
*/

#include <stdio.h>

int main()
{
    char ch, flag = 0;
    int char_c = 0, word_c = 0, line_c = 0;

    while ((ch = getchar()) != EOF)         //The loop will run till the variable 'ch' encounters "EOF" i.e. End of File from the Buffer.
    {
        char_c += 1;        //Each character encountered by the 'ch' should increment the counter 'char_c'.

        if (ch == '\n')     //Each newline character encountered by the 'ch' should increment the counter 'line_c'.
        {
            line_c += 1;
        }

        if (ch == ' ' || ch == '\t' || ch == '\n')      //If the 'ch' receives one or multiple spaces, tabs or newline character; it should increment the counter 'word_c' appropriately.
        {
//The logic in case of multiple spaces, tabs or newline characters is to check if the previous character encountered by 'ch' was anything other than these 3 characters.
            if (flag == 0)      //If 'flag' is 0, this is the first encounter of a space, tab or newline.
            {
                word_c += 1;    //So, the counter 'word_c' should be incremented by 1.
                flag = 1;       //The 'flag' should be changed to 1. This will prevent the increase of 'word_c' if subsequent spaces, tabs or newline characters are encountered.
            }
        }
        else                //If the next character in 'ch' is anything other than space, tab or newline character; then it is a start of another word.
        {
            flag = 0;       //So, the 'flag' is restored to 0 for the next encounter of space, tabs or newline character.
        }
    }
    printf ("\n");
    printf ("Characters: %d\n", char_c);
    printf ("Words: %d\n", word_c);
    printf ("Line: %d\n", line_c);
    return 0;
}
