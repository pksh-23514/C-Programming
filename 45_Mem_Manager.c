/*
Name         : Prabhat Kiran
Date         : 01st September 2022
Description  : Provide a menu to manipulate or display the value of variable of type t.
Sample Input : 1) Menu :
                   1. Add element
                   2. Remove element
                   3. Display element
                   4. Exit from the program
                   Choice ---> 1
                   Enter the type you have to insert:
                   1. int
                   2. char
                   3. float
                   4. double
                   Choice ---> 2
                   Enter the char : k
                   1. Add element
                   2. Remove element
                   3. Display element
                   4. Exit from the program
                   Choice ---> 3
                   -------------------------
                   0 -> k
                   -------------------------
                   1. Add element
                   2. Remove element
                   3. Display element
                   4. Exit from the program
                   Choice ---> 1
                   Enter the type you have to insert:
                   1. int
                   2. char
                   3. float
                   4. double
                   Choice ---> 1
                   Enter the int : 10
                   1. Add element
                   2. Remove element
                   3. Display element
                   4. Exit from the progrm
                   Choice ---> 3
                   ------------------------
                   0 -> k (char)
                   1 -> 10 (int)
                   ------------------------
                   1. Add element
                   2. Remove element
                   3. Display element
                   4. Exit from the program
                   Choice ---> 2
                   0 -> k
                   1 -> 10
                   Enter the index value to be deleted : 0
                   index 0 successfully deleted.
                   1. Add element
                   2. Remove element
                   3. Display element
                   4. Exit from the program
                   Choice ---> 4
*/

#include <stdio.h>
#include <stdlib.h>

void add_element (void*, char[]);           //To add the particular element as per user's choice.
void remove_element (void*, char[]);        //To remove the particular element as per user's choice.
void display_element (void*, char[]);       //To display the particular element as per user's choice.
char status [6];                            //Current status of Memory allocation as per the Index.

int main()
{
    char flag [6] = {0}, choice;
/*
flag[0] = First char flag, flag[1] = Second char flag, flag[2] = short flag, flag[3] = int flag, flag[4] = float flag and flag[5] = double flag.
*/
    void* num = malloc (8 * sizeof (char));

    do
    {
        printf ("Menu :\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n");
        printf ("Choice ---> ");
        scanf ("%hhu", &choice);                    //To read the user's choice for the particular Task to be executed.
        printf ("---------------------------------------------------------------------------------------\n");
        switch (choice)
        {
            case 1 :
                {
                    add_element (num, flag);        //Function call to insert an element.
                }
                break;
            case 2 :
                {
                    remove_element (num, flag);     //Function call to remove an element.
                }
                break;
            case 3:
                {
                    display_element (num, flag);    //Function call to display the elements index-wise.
                }
                break;
            case 4 : printf ("Thank you for using the Memory Manager!\n");
                break;
            default : printf ("You entered the wrong Choice. Please enter the Choice between 1 to 4!\n");
        }
        printf ("---------------------------------------------------------------------------------------\n");
    } while (choice !=4);       //The loop will run till the user enters the option to exit the program i.e. value of 'choice' = 4.

    free (num);
    return 0;
}

void add_element (void* n, char f[])
{
    char ch;
    printf ("Enter the Type you have to Insert :\n1. int\n2. char\n3. short\n4. float\n5. double\n");
    printf ("Choice ---> ");
    scanf ("%hhu", &ch);                                                //To read the user's choice for inserting a particular type of Data.
    printf ("---------------------------------------------------------------------------------------\n");
    switch (ch)
    {
        case 1 :                                                        //If the user wants to insert an Integer.
            {
                if ((f [3] == 0) && (f [4] == 0) && (f [5] == 0))       //If the int flag, float flag and double flag is '0', then only the user can enter the Data.
                {
                    printf ("Enter the int : ");
                    scanf ("%d", (int*) (n + 4));                       //Read the int data from user at position (n+4).
                    f [3] = 1;                                          //Update the int flag as '1'.
                }
                else
                {
                    printf ("Memory is Full!\n");
                }
            }
            break;
        case 2 :                                                        //If the user wants to insert a Character.
            {
                if ((f [0] == 0) && (f [5] == 0))                       //If the first char flag and double flag is '0', then only the user can enter the Data.
                {
                    printf ("Enter the char : ");
                    scanf (" %c", (char*) n);                           //Read the char data from user at position (n).
                    f [0] = 1;                                          //Update the first char flag as '1'.
                }
                else if ((f [1] == 0) && (f [5] == 0))                  //If the second char flag and double flag is '0', then only the user can enter the Data.
                {
                    printf ("Enter the char : ");
                    scanf (" %c", (char*) (n + 1));                     //Read the char data from user at position (n+1).
                    f [1] = 1;                                          //Update the second char flag as '1'.
                }
                else
                {
                    printf ("Memory is Full!\n");
                }
            }
            break;
        case 3 :                                                        //If the user wants to insert a Short.
            {
                if ((f [2] == 0) && (f [5] == 0))                       //If the short flag and double flag is '0', then only the user can enter the Data.
                {
                    printf ("Enter the short : ");
                    scanf ("%hd", (short*) (n + 2));                    //Read the short data from user at position (n+2).
                    f [2] = 1;                                          //Update the short flag as '1'.
                }
                else
                {
                    printf ("Memory is Full!\n");
                }
            }
            break;
        case 4 :                                                        //If the user wants to insert a Float.
            {
                if ((f [3] == 0) && (f [4] == 0) && (f [5] == 0))       //If the int flag, float flag and double flag is '0', then only the user can enter the Data.
                {
                    printf ("Enter the float : ");
                    scanf ("%f", (float*) (n + 4));                     //Read the float data from user at position (n+4).
                    f [4] = 1;                                          //Update the float flag as '1'.
                }
                else
                {
                    printf ("Memory is Full!\n");
                }
            }
            break;
        case 5 :                                                        //If the user wants to insert a Double.
            {
                //If all the flags are '0', then only the user can enter the Data.
                if ((f [5] == 0) && (f [0] == 0) && (f [1] == 0) && (f [2] == 0) && (f [3] == 0) && (f [4] == 0)) 
                {
                    printf ("Enter the double : ");
                    scanf ("%lf", (double*) n);                         //Read the double data from user at position (n).
                    f [5] = 1;                                          //Update the double flag as '1'.
                }
                else
                {
                    printf ("Memory is Full!\n");
                }
            }
            break;
        default : printf ("You entered the wrong Choice. Please enter the Choice between 1 to 5!\n");
    }
    return;
}

void remove_element (void* n, char f[])
{
    display_element (n, f);                                                 //Function call to display the current memory allocation index-wise.
    if ((f [0] == 0) && (f [1] == 0) && (f [2] == 0) && (f [3] == 0) && (f [4] == 0) && (f [5] == 0))
    {
        return;
    }
    printf ("---------------------------------------------------------------------------------------\n");
    
    char ch;
    printf ("Enter the Index value you want to Delete :\n");
    printf ("Choice ---> ");
    scanf (" %hhu", &ch);                                                   //To read the user's choice for deleting a particular type of Data.
    printf ("---------------------------------------------------------------------------------------\n");
    switch (status [ch])                                                    //As per the current status of memory allocation, the index value chosen by user is passed to the Switch case.
    {
        case 'A' :                                                          //If the user wants to delete the first Character.
            {
                if (f [0] == 1)                                             //If the first char flag is '1', then we have a Character data stored in the memory.
                {
                    f [0] = 0;                                              //Update the first char flag as '0'.
                    printf ("Character value successfully deleted.\n");
                }
                else
                {
                    printf ("No Character value present to be deleted.\n");
                }
            }
            break;
        case 'B' :                                                          //If the user wants to delete the second Character.
            {
                if (f [1] == 1)                                             //If the second char flag is '1', then we have a Character data stored in the memory.
                {
                    f [1] = 0;                                              //Update the second char flag as '0'.
                    printf ("Character value successfully deleted.\n");
                }
                else
                {
                    printf ("No Character value present to be deleted.\n");
                }
            }
            break;
        case 'C' :                                                          //If the user wants to delete a Short.
            {
                if (f [2] == 1)                                             //If the short flag is '1', then we have a Short data stored in the memory.
                {
                    f [2] = 0;                                              //Update the short flag as '0'.
                    printf ("Short value successfully deleted.\n");
                }
                else
                {
                    printf ("No Short value present to be deleted.\n");
                }
            }
            break;
        case 'D' :                                                          //If the user wants to delete an Integer.
            {
                if (f [3] == 1)                                             //If the int flag is '1', then we have an Integer data stored in the memory.
                {
                    f [3] = 0;                                              //Update the int flag as '0'.
                    printf ("Integer value successfully deleted.\n");
                }
                else
                {
                    printf ("No Integer value present to be deleted.\n");
                }
            }
            break;
        case 'E' :                                                          //If the user wants to delete a Float.
            {
                if (f [4] == 1)                                             //If the float flag is '1', then we have a Float data stored in the memory.
                {
                    f [3] = 0; f [4] = 0;                                   //Update the float flag as '0'.
                    printf ("Float value successfully deleted.\n");
                }
                else
                {
                    printf ("No Float value present to be deleted.\n");
                }
            }
            break;
        case 'F' :                                                          //If the user wants to delete a Double.
            {
                //If all the other flags are '0' and the double flag is '1', then we have a Double data stored in the memory.
                if ((f [0] == 0) && (f [1] == 0) && (f [2] == 0) && (f [3] == 0) && (f [4] == 0) && (f [5] == 1))
                {
                    f [0] = 0; f [1] = 0; f [2] = 0;                        //Update all the flags as '0'.
                    f [3] = 0; f [4] = 0; f [5] = 0;
                    printf ("Double value successfully deleted.\n");
                }
                else
                {
                    printf ("No Double value present to be deleted.\n");
                }
            }
            break;
        default : printf ("You entered the wrong Choice. Please enter the Choice as per the Index value displayed!\n");
    }
    return;
}

void display_element (void* n, char f[])
{
    char c;
    for (c = 0; c < 6; c++)                                         //To reset the current status of all the Indices as '0'.
        status [c] = 0;
    c = 0;
    if (f [0] == 1)                                                 //If the first char flag is '1', display it as the 'cth' index value.
    {
        printf ("%d -> %c (char)\n", c, *(char*) n);
        status [c] = 'A';                                           //'A' value allocated for the first Character at current Index.
        c += 1;                                                     //Update the index value for next element.
    }
    if (f [1] == 1)                                                 //If the second char flag is '1', display it as the 'cth' index value.
    {
        printf ("%d -> %c (char)\n", c, *(char*) (n + 1));
        status [c] = 'B';                                           //'B' value allocated for the second Character at current Index.
        c += 1;                                                     //Update the index value for next element.
    }
    if (f [2] == 1)                                                 //If the short flag is '1', display it as the 'cth' index value.
    {
        printf ("%d -> %hd (short)\n", c, *(short*) (n + 2));
        status [c] = 'C';                                           //'C' value allocated for the Short at current Index.
        c += 1;                                                     //Update the index value for next element.
    }
    if (f [3] == 1)                                                 //If the int flag is '1', display it as the 'cth' index value.
    {
        printf ("%d -> %d (int)\n", c, *(int*) (n + 4));
        status [c] = 'D';                                           //'D' value allocated for the Integer at current Index.
        c += 1;                                                     //Update the index value for next element.
    }
    if (f [4] == 1)                                                 //If the float flag is '1', display it as the 'cth' index value.
    {
        printf ("%d -> %f (float)\n", c, *(float*) (n + 4));
        status [c] = 'E';                                           //'E' value allocated for the Float at current Index.
        c += 1;                                                     //Update the index value for next element.
    }
    //If all the other flags are '0' and the double flag is '1', display it as the 'cth' index value.
    if ((f [0] == 0) && (f [1] == 0) && (f [2] == 0) && (f [3] == 0) && (f [4] == 0) && (f [5] == 1))
    {
        printf ("%d -> %lf (double)\n", c, *(double*) n);
        status [c] = 'F';                                           //'F' value allocated for the Double at current Index.
    }
    //If all the flags are '0', "No data" message to be displayed.
    if ((f [0] == 0) && (f [1] == 0) && (f [2] == 0) && (f [3] == 0) && (f [4] == 0) && (f [5] == 0) )
    {
        printf ("No Data is stored in the Memory currently!\n");
    }
    return;
}
