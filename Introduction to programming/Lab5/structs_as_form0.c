#include <stdio.h>
#include "gotoxy.c"
#include <string.h>

#define STRUCT_LENGTH 6

typedef struct
{
    int ID;
    char name[40];
    int age;
    float salary;
    float over_time;
    float deduction;
} emp;

int main()
{
    char entries[STRUCT_LENGTH][40] = {"ID: ", "Name: ", "Age: ", "Salary: ", "Over time: ", "Deduction: "};
    // print the form
    int form_height = STRUCT_LENGTH / 2 + 0.5;
    for (int i = 0; i < STRUCT_LENGTH; i++)
    {
        gotoxy(i / form_height * 50 + 1, i % form_height + 1);
        printf("%s", entries[i]);

    }

    // take the input
    emp employee;
    for (int i = 0; i < STRUCT_LENGTH; i++)
    {
        gotoxy(i / form_height * 50 + 1 + strlen(entries[i]), i % form_height + 1);
        switch (i)
        {
            case 0:
                scanf("%d", &employee.ID);
                fflush(stdin);
                break;
            case 1:
                gets(employee.name);
                break;
            case 2:
                scanf("%d", &employee.age);
                fflush(stdin);
                break;
            case 3:
                scanf("%f", &employee.salary);
                fflush(stdin);
                break;
            case 4:
                scanf("%f", &employee.over_time);
                fflush(stdin);
                break;
            case 5:
                scanf("%f", &employee.deduction);
                fflush(stdin);
                break;
        }
    }

    // print output
    gotoxy(0, form_height + 2);
    printf("Name: %s\nID: %d\nNet salary: %0.2f", employee.name, employee.ID, employee.salary + employee.over_time - employee.deduction);

    // reset the cursor
    gotoxy(0, form_height + 7);

    return 0;
}