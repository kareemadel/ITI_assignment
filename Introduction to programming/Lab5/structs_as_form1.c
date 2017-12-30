#include <stdio.h>
#include "gotoxy.c"
#include <string.h>
#include <conio.h>

#define STRUCT_LENGTH 6
#define EMP_NUM 5

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
    emp employees[EMP_NUM];
    // print the form
    int form_height = STRUCT_LENGTH / 2 + 0.5;
    int employee_index = 0, employee_number = 1;
    for (employee_index = 0, employee_number = 1; employee_index < EMP_NUM; employee_index++, employee_number++)
    {
        system("cls");
        printf("Employee numer #%d", employee_number);
        for (int i = 0; i < STRUCT_LENGTH; i++)
        {
            gotoxy(i / form_height * 50 + 1, i % form_height + 1);
            printf("%s", entries[i]);

        }

        for (int i = 0; i < STRUCT_LENGTH; i++)
        {
            gotoxy(i / form_height * 50 + 1 + strlen(entries[i]), i % form_height + 1);
            switch (i)
            {
                case 0:
                    scanf("%d", &employees[employee_index].ID);
                    fflush(stdin);
                    break;
                case 1:
                    gets(employees[employee_index].name);
                    break;
                case 2:
                    scanf("%d", &employees[employee_index].age);
                    fflush(stdin);
                    break;
                case 3:
                    scanf("%f", &employees[employee_index].salary);
                    fflush(stdin);
                    break;
                case 4:
                    scanf("%f", &employees[employee_index].over_time);
                    fflush(stdin);
                    break;
                case 5:
                    scanf("%f", &employees[employee_index].deduction);
                    fflush(stdin);
                    break;
            }
        }
    }

    for (employee_index = 0, employee_number = 1; employee_index < EMP_NUM; employee_index++, employee_number++)
    {
        system("cls");
        printf("Employee numer #%d\n", employee_number);
        printf("Name: %s\nID: %d\nNet salary: %0.2f", employees[employee_index].name, employees[employee_index].ID, employees[employee_index].salary + employees[employee_index].over_time - employees[employee_index].deduction);
        getch();
    }

    // reset the cursor
    gotoxy(0, form_height + 4);

    return 0;
}