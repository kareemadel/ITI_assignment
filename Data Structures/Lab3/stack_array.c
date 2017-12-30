#include <stdio.h>
#include <conio.h>
#include "textattr.c"
#include "gotoxy.c"

#define ENTRIES 5
#define ENTRY_LENGTH 30
#define CENTER_POSITION 50
#define SIZE 5

int stack[SIZE] = {0};
int top_of_stack = -1;

int push(int element);
int is_empty(void);
int is_full(void);
int pop(void);
void display_all(void);
void free_stack(void);
int delete_node(void);

int main()
{
    /* code */
    char menu_entries[ENTRIES][ENTRY_LENGTH] = {"Push", "Pop", "Display All", "Free", "Exit"};
    int current_option = 0;
    _Bool running_flag = 1;
    char first_byte, second_byte;
    int temp_integer = 0;

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
                    case 0: // push
                        if (is_full())
                        {
                            printf("The stack is full.\n");
                            getch();
                        }
                        else
                        {
                            printf("Please insert the number you want to push: ");
                            fflush(stdin);
                            scanf("%d", &temp_integer);
                            push(temp_integer);
                        }
                        break;
                    case 1: // pull
                        if (is_empty())
                        {
                            printf("The stack is empty.\n");
                            getch();
                        }
                        else
                        {
                            printf("The popped number is %d.\n", pop());
                            getch();
                        }
                        break;
                    case 2: //display all
                        display_all();
                        break;
                    case 3: // free
                        free_stack();
                        printf("The stack is now empty.\n");
                        getch();
                        break;
                    case 4: //exit
                        running_flag = 0;
                        break;
                }
        }
            

    }
    return EXIT_SUCCESS;
}

int push(int element)
{
    if (top_of_stack < SIZE - 1)
    {
        stack[top_of_stack + 1] = element;
        top_of_stack++;
        return EXIT_SUCCESS;
    }
    else
        return EXIT_FAILURE;
}

int pop(void)
{
    top_of_stack--;
    return stack[top_of_stack + 1];
}

int is_empty(void)
{
    if (top_of_stack == -1)
        return 1;
    else
        return 0;
}

int is_full(void)
{
    if (top_of_stack == SIZE - 1)
        return 1;
    else
        return 0;
}

void free_stack(void)
{
    top_of_stack = -1;
}

void display_all(void)
{
    for (int i = top_of_stack; i > -1; i--)
    {
        printf("%d\n", stack[i]);
    }
    getch();
}