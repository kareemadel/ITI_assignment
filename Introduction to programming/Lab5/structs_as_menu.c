#include <stdio.h>
#include "textattr.c"
#include "gotoxy.c"
#include <string.h>


#define ENTRIES 4
#define ENTRY_LENGTH 20
#define CENTER_POSITION 50
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
void add_employee(emp employees[], int employees_count);
void display_employee(emp employees[], int employees_count);
void display_all(emp employees[], int employees_count);


// global variables
int form_height = STRUCT_LENGTH / 2.0 + 0.5;
char entries[STRUCT_LENGTH][40] = {"ID: ", "Name: ", "Age: ", "Salary: ", "Over time: ", "Deduction: "};

int main()
{
    /* code */
    char menu_entries[ENTRIES][ENTRY_LENGTH] = {"Add employee", "Display Employee", "Display All", "Exit"};
    int current_option = 0;
    _Bool running_flag = 1;
    char first_byte, second_byte;


    printf("Please insert the number of employees: \n");
    int employees_count = -1;

    while (employees_count < 0)
    {
        scanf("%d", &employees_count);
    }
    emp * employees = (emp *)malloc(employees_count * sizeof(emp));

    initialize_emp(employees, employees_count);


    while (running_flag)
    {
        system("cls");

        // print the menu
        gotoxy(CENTER_POSITION, 1);
        textattr(0x17);
        printf("MENU ENTRIES");
        textattr(0x07);
        for (int i = 0; i < ENTRIES; i++)
        {
            gotoxy(CENTER_POSITION, i + 2);
            if (current_option == i)
                textattr(0x70);

            printf("%s", menu_entries[i]);
            textattr(0x07);
        }
        gotoxy(0, ENTRIES + 2);

        // wait for an input from the user
        first_byte = getch();

        // if it's an extended key
        if (first_byte < 0)
            second_byte = getch();

        switch (first_byte)
        {
            case -32:
                switch (second_byte)
                {
                    case 72:    //up arrow
                    case 73:    // page up
                        current_option = (current_option - 1 + ENTRIES) % ENTRIES;
                        break;
                    case 80:    //down arrow
                    case 81:    // page down
                        current_option = (current_option + 1) % ENTRIES;
                        break;
                    case 71:    //home
                        current_option = 0;
                        break;
                    case 79:    //end
                        current_option = ENTRIES - 1;
                        break;
                }
                break;
            case 27:    // esc button
                running_flag = 0;
                break;
            case 13:    // enter button
                system("cls");
                switch (current_option)
                {
                    case 0:
                        add_employee(employees, employees_count);
                        break;
                    case 1:
                        display_employee(employees, employees_count);
                        break;
                    case 2:
                        display_all(employees, employees_count);
                        break;
                    case 3:
                        running_flag = 0;
                        break;
                }
        }
    }
    // reset the cursor
    gotoxy(0, form_height + 4);
    free(employees);
    return 0;
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

void display_employee(emp employees[], int employees_count)
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
