#include <stdio.h>
#include "gotoxy.c"
#include <string.h>

#define STRUCT_LENGTH 6
#define EMP_COUNT 5

typedef struct
{
    int ID;
    char name[40];
    int age;
    float salary;
    float over_time;
    float deduction;
} emp;

void initialize_emp(emp employees[], int employees_count);
void add_employee(emp employees[], int employee_count);
void display_employee(emp employees[], int employee_count);
void display_all(emp employees[], int employees_count);


// global variables
int form_height = STRUCT_LENGTH / 2.0 + 0.5;
char entries[STRUCT_LENGTH][40] = {"ID: ", "Name: ", "Age: ", "Salary: ", "Over time: ", "Deduction: "};

int main()
{
    emp employees[EMP_COUNT];
    // print the form

    initialize_emp(employees, EMP_COUNT);

    add_employee(employees, EMP_COUNT);

    display_employee(employees, EMP_COUNT);

    display_all(employees, EMP_COUNT);

    // reset the cursor
    gotoxy(0, form_height + 4);

    return 0;
}


void initialize_emp(emp employees[], int employees_count)
{
    for(int employee_index = 0; employee_index < employees_count; employee_index++)
    {
        employees[employee_index].ID = -999999;
    }
}

void add_employee(emp employees[], int employee_count)
{
    //take input
    int employee_index = 0, employee_number = 1;
    _Bool run_flag = 1;
    while (run_flag)
    {
        system("cls");
        printf("Please insert the emplyee number from 1 to 5 you would like to enter and view her/his data and enter 0 when you are done: \n");
        scanf("%d", &employee_number);
        employee_index = employee_number - 1;
        if (employee_index == -1)
            run_flag = 0;
        else if (employee_index > -1 && employee_index < employee_count)
        {
            system("cls");
            printf("Employee numer #%d", employee_index + 1);
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
        else;
    }
}

void display_employee(emp employees[], int employee_count)
{
    _Bool run_flag = 1;
    while(run_flag)
    {
        system("cls");
        printf("choose employee number from 1 to %d or enter 0 to stop.\n",EMP_COUNT);
        int employee_index = 0, employee_number = 1;
        scanf("%d", &employee_number);
        employee_index = employee_number - 1;

        if (employee_index == -1)
            run_flag = 0;
        else if (employee_number > EMP_COUNT || employee_number < 0);
        else if (employees[employee_index].ID != -999999)
        {
            system("cls");
            printf("Employee numer #%d\n", employee_number);
            printf("Name: %s\nID: %d\nNet salary: %0.2f", employees[employee_index].name, employees[employee_index].ID, employees[employee_index].salary + employees[employee_index].over_time - employees[employee_index].deduction);
            getch();
        }
        else
        {
            printf("You have not entered data for employee number %d.\n", employee_number);
            getch();
        }
    }
}

void display_all(emp employees[], int employees_count)
{
    for (int employee_index = 0; employee_index < employees_count; employee_index++)
    {
        if (employees[employee_index].ID != -999999)
        {
            system("cls");
            printf("Employee numer #%d\n", employee_index + 1);
            printf("Name: %s\nID: %d\nNet salary: %0.2f", employees[employee_index].name, employees[employee_index].ID, employees[employee_index].salary + employees[employee_index].over_time - employees[employee_index].deduction);
            getch();
        }
    }
}