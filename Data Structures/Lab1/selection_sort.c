#include <stdio.h>
#include "textattr.c"
#include "gotoxy.c"
#include <string.h>

#define ENTRIES 4
#define ENTRY_LENGTH 20
#define CENTER_POSITION 50
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

void initialize_emp(emp employees[], int employees_count);
void add_employee(emp employees[], int employees_count);
void display_all(emp employees[], int employees_count);
void selection_sort(emp * employees, int employees_count);

// global variables
int form_height = STRUCT_LENGTH / 2.0 + 0.5;
char entries[STRUCT_LENGTH][40] = {"ID: ", "Name: ", "Age: ", "Salary: ", "Over time: ", "Deduction: "};


int main(void)
{
    printf("Please insert the number of employees: \n");
    int employees_count = -1;

    while (employees_count < 0)
    {
        scanf("%d", &employees_count);
    }
    emp * employees = (emp *)malloc(employees_count * sizeof(emp));

    initialize_emp(employees, employees_count);

    add_employee(employees, employees_count);

    selection_sort(employees, employees_count);

    printf("The employees in sorted order is\n");
    getch();
    display_all(employees, employees_count);


    // reset the cursor
    gotoxy(0, form_height + 4);

    return 0;
}


void selection_sort(emp * employees, int employees_count)
{
    int i, j;
    int mininum;
    _Bool unsorted = 1;
    for(i = 0; i < employees_count - 1 && unsorted; i++)
    {
        mininum = i;
        for (j = i + 1; j < employees_count; j++)
        {
            if (employees[j].ID < employees[mininum].ID)
            {
                mininum = j;
            }
        }
        if (mininum != i)
        {
            emp temp = employees[i];
            employees[i] = employees[mininum];
            employees[mininum] = temp;
        }
    }
}



void initialize_emp(emp employees[], int employees_count)
{
    for(int employee_index = 0; employee_index < employees_count; employee_index++)
    {
        employees[employee_index].ID = -999999;
    }
}

void add_employee(emp employees[], int employees_count)
{
    //take input
    int employee_index = 0, employee_number = 1;
    _Bool run_flag = 1;
    while (run_flag)
    {
        system("cls");
        printf("Please insert the emplyee number from 1 to %d you would like to enter and view her/his data and enter 0 when you are done: \n", employees_count);
        scanf("%d", &employee_number);
        employee_index = employee_number - 1;
        if (employee_index == -1)
            run_flag = 0;
        else if (employee_index > -1 && employee_index < employees_count)
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