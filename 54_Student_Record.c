/*
Name         : Prabhat Kiran
Date         : 05th September 2022
Description  : WAP to Implement the student record using array of structures.
Sample Input : Enter no.of students : 2
               Enter no.of subjects : 2
               Enter the name of subject 1 : Maths
               Enter the name of subject 2 : Science
               ----------Enter the student datails-------------
               Enter the student Roll no. : 1
               Enter the student 2 name : Bindhu
               Enter Maths mark : 88
               Enter Science mark : 78
Sample Output: ----Display Menu----
               1. All student details
               2. Particular student details
               Enter your choice : 2
               ----Menu for Particular student----
               1. Name.
               2. Roll no.
               Enter you choice : 1
               Enter the name of the student : Nandhu
               Roll No.   Name           Maths         Science       Average       Grade
               1          Nandhu         99            91            95            A
               Do you want to continue to display(Y/y) : n
*/

#include <stdio.h>
#include <stdlib.h>

struct Student      //The Structure to store the various attrributes for the Student.
{
    int roll;
    char name [50];
    int* marks;
    float average;
    char grade;
};

char grade_calc (float);                                        //The function to calculate the grade received by the student based on the Marks.
void display_all (struct Student [], char* [], int, int);       //To display all the details of all the Students present in the Record.
void name_check (struct Student [], char* [], int, int);        //To display the details of the particular Student based on the input Name of the Student.
void roll_check (struct Student [], char* [], int, int);        //To display the details of the particular Student based on the input Roll no. of the Student.

int main()
{
    int stu_count, sub_count;
    printf ("Enter the number of Students : ");
    scanf ("%d", &stu_count);
    printf ("Enter the number of Subjects : ");
    scanf ("%d", &sub_count);
    getchar ();                 //To absorb the unwanted '\n' from the Input Buffer.

    struct Student s [stu_count];           //The Structure array must have elements equal to the number of Students.
    char* sub [sub_count];                  //The Array of Strings for Subjects must have elements equal to the number of Subjects.
    for (int i = 0; i < sub_count; i++)     //Memory allocation for the Subject array of strings.
    {
        sub [i] = (char*) malloc (50 * sizeof (char));
    }
    for (int i = 0; i < sub_count; i++)     //To read the names of the Subjects.
    {
        printf ("Enter the name of subject %d: ", (i + 1));
        scanf ("%[^\n]", sub [i]);
        getchar ();
    }
    for (int i = 0; i < stu_count; i++)     //To read each Student details in the Structure array.
    {
        printf ("\n----------Enter the student datails-------------\n");
        s [i]. marks = (int*) malloc (sub_count * sizeof (int));            //The 'marks' array in the Structure must be allocated space dynamically as per the number of Subjects.
        printf ("Enter the student Roll no. : " );
        scanf ("%d", &s [i].roll);
        getchar ();
        printf ("Enter the student %d Name : ", s [i].roll);
        scanf ("%[^\n]", s [i].name);
        int sum = 0;
        for (int j = 0; j < sub_count; j++)             //To read the marks obtained by the particular Student in each Subject.
        {
            printf ("Enter the %s marks : ", sub [j]);
            scanf ("%d", &s [i].marks [j]);
            sum += s [i].marks [j];
        }
        s [i].average = (float) sum / (float) sub_count;    //To calculate the Average marks obtained by the particular Student.
        s [i].grade = grade_calc (s [i].average);           //The function call returns the Grade received by the particular Student.
    }
    
    char choice;    //To store the User's choice of continuing or terminating the Operation.
    do
    {
        char ch;
        printf ("\n----------Display Menu----------\n1. All student details\n2. Particular student details\n");
        printf ("Enter your choice : ");
        scanf ("%hhu", &ch);        //To read the choice of printing the details based on the menu displayed.
        switch (ch)
        {
            case 1 :
                {
                    display_all (s, sub, stu_count, sub_count);     //To display all the details of all the Students present in the Record.
                }
                break;
            case 2 :
                {
                    printf ("\n------Menu for Particular student------\n1. Name\n2. Roll no.\n");
                    char c;
                    printf ("Enter your choice : ");
                    scanf ("%hhu", &c);         //To read the choice of whether to search the details of the Student based on the Name or Roll no.
                    switch (c)
                    {
                        case 1 :
                            {
                                name_check (s, sub, stu_count, sub_count);      //To search the details of the Student based on the Name of the Student.
                            }
                            break;
                        case 2 :
                            {
                                roll_check (s, sub, stu_count, sub_count);      //To search the details of the Student based on the Roll no. of the Student.
                            }
                            break;
                        default : printf ("Enter the choice as 1 or 2.\n");
                    }
                }
                break;
            default : printf ("Enter the choice as 1 or 2.\n");
        }

        printf ("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf ("Do you want to continue to display (Y/y) : ");
        scanf (" %c", &choice);
    } while ((choice == 'y') || (choice == 'Y'));

    for (int i = 0; i < sub_count; i++)     //Free the memory allocated to Subject array.
    {
        free (sub [i]);
    }
    for (int i = 0; i < stu_count; i++)
    {
        free (s [i].marks);                 //Free the memory allocated to Marks array of each Student.
    }
    return 0;
}

char grade_calc (float m)       //To calculate and return the Grade received based on the marks obtained by the Student.
{
    if (m < 40.0f)
        return 'F';
    else if (m < 50.0f)
        return 'P';
    else if (m < 60.0f)
        return 'E';
    else if (m < 70.0f)
        return 'D';
    else if (m < 80.0f)
        return 'C';
    else if (m < 90.0f)
        return 'B';
    else
        return 'A';
}

void display_all (struct Student s[], char* sub[], int c1, int c2)      //To display all the details of the Students stored in the Record.
{
    printf ("\nThe details of all the Students present in the Record are:\n");      //To prepare the format in which the details needs to be printed.
    printf ("%-20s%-50s", "Roll no.", "Name");
    for (int i = 0; i < c2; i++)
    {
        printf ("%-20s", sub [i]);
    }
    printf ("%-20s%-20s\n", "Average", "Grade");

    for (int i = 0; i < c1; i++)
    {
        printf ("%-20d", s [i].roll);
        printf ("%-50s", s [i].name);
        for (int j = 0; j < c2; j++)
        {
            printf ("%-20d", s [i].marks [j]);
        }
        printf ("%-20.2f", s [i].average);
        printf ("%-20c\n", s [i].grade);
    }
    return;
}

void roll_check (struct Student s[], char* sub[], int c1, int c2)       //To display the details of a particular Student based on the Roll no. read.
{
    int r;
    char flag = 0;          //To store the status of whether the Student details has been found in the Record or not.
    printf ("Enter the Roll no. of the Student: ");
    scanf ("%d", &r);

    for (int i = 0; i < c1; i++)
    {
        if (s [i].roll == r)        //If the Roll no. read matches with the Roll no. of the Student in the Record, print the details in a particular format.
        {
            printf ("%-20s%-50s", "Roll no.", "Name");
            for (int i = 0; i < c2; i++)
            {
                printf ("%-20s", sub [i]);
            }
            printf ("%-20s%-20s\n", "Average", "Grade");
            
            printf ("%-20d", s [i].roll);
            printf ("%-50s", s [i].name);
            for (int j = 0; j < c2; j++)
            {
                printf ("%-20d", s [i].marks [j]);
            }
            printf ("%-20.2f", s [i].average);
            printf ("%-20c\n", s [i].grade);
            flag = 1;       //Operation successful.
            break;
        }
    }
    if (flag == 0)          //If the Operation fails, print an error message.
    {
        printf ("No Student record found with the Roll number: %d\n", r);
    }
    return;
}

void name_check (struct Student s[], char* sub[], int c1, int c2)       //To display the details of a particular Student based on the Roll no. read.
{
    char n [50];
    char flag = 0;          //To store the status of whether the Student details has been found in the Record or not.
    printf ("Enter the Name of the Student: ");
    getchar ();
    scanf ("%[^\n]", n);

    for (int i = 0; i < c1; i++)
    {
        int j = 0;
        while ((s [i].name [j] == n [j]) && (s [i].name [j] != '\0'))       //If the Name read matches with the Name of the Student in the Record, print the details in a particular format.
        {
            j++;
        }
        if (s [i].name [j] == n [j])
        {
            printf ("%-20s%-50s", "Roll no.", "Name");
            for (int i = 0; i < c2; i++)
            {
                printf ("%-20s", sub [i]);
            }
            printf ("%-20s%-20s\n", "Average", "Grade");
            
            printf ("%-20d", s [i].roll);
            printf ("%-50s", s [i].name);
            for (int j = 0; j < c2; j++)
            {
                printf ("%-20d", s [i].marks [j]);
            }
            printf ("%-20.2f", s [i].average);
            printf ("%-20c\n", s [i].grade);
            flag = 1;       //Operation successful.
            break;
        }
    }
    if (flag == 0)          //If the Operation fails, print an error message.
    {
        printf ("No Student record found with the Name: %s\n", n);
    }
    return;
}
