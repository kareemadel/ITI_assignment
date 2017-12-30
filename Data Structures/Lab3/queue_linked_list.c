#include <stdio.h>
#include <conio.h>
#include "textattr.c"
#include "gotoxy.c"

#define ENTRIES 5
#define ENTRY_LENGTH 30
#define CENTER_POSITION 50

typedef struct node
{
    int data;
    struct node * prev_pointer;
} node;

node * start = NULL, * end = NULL;

node * create(int data);
void enqueue(node * new_node);
node * dequeue(void);
void display_all(void);
void free_queue(void);
int delete_node(node * target_pointer);

int main()
{
    /* code */
    char menu_entries[ENTRIES][ENTRY_LENGTH] = {"Enqueue", "Dequeue", "Display All", "Free", "Exit"};
    int current_option = 0;
    _Bool running_flag = 1;
    char first_byte, second_byte;
    int temp_integer = 0;
    node * temp_node_pointer = NULL;

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
                    case 0: // enqueue
                        printf("Please insert the number you want to enqueue: ");
                        fflush(stdin);
                        scanf("%d", &temp_integer);
                        enqueue(create(temp_integer));
                        break;
                    case 1: // dequeue
                        temp_node_pointer = dequeue();
                        if (temp_node_pointer != NULL)
                            {
                                printf("The dequeued number is %d.\n", temp_node_pointer->data);
                                getch();
                                delete_node(temp_node_pointer);
                            }
                        else
                        {
                            printf("The queue is empty.\n");
                            getch();
                        }
                        break;
                    case 2: //display all
                        display_all();
                        break;
                    case 3: // free
                        free_queue();
                        printf("The queue is now empty.\n");
                        getch();
                        break;
                    case 4: //exit
                        running_flag = 0;
                        break;
                }
        }
            

    }
    return 0;
}

node * create(int data)
{
    node * new = (node *) malloc(sizeof(node));
    new->data = data;
    new->prev_pointer = NULL;
    return new;
}

void enqueue(node * new_node)
{
    if (end != NULL)
    {
        end->prev_pointer = new_node;
        end = new_node;
    }
    else
    {
        start = new_node;
        end = new_node;
    }
}

node * dequeue(void)
{
    if (start != NULL)
    {
        node * dequeued_node = start;
        start = start->prev_pointer;
        if (start == NULL)
            end = NULL;
        return dequeued_node;
    } 

    return NULL;
}

void display_all(void)
{
    node * temp_node_pointer = start;
    while(temp_node_pointer != NULL)
    {
        printf("%d\n", temp_node_pointer->data);
        temp_node_pointer = temp_node_pointer->prev_pointer;
    }
    getch();
}

void free_queue(void)
{
    node * moving_node_pointer = start, * delete_node_pointer = NULL;
    while(moving_node_pointer != NULL)
    {
        delete_node_pointer = moving_node_pointer;        
        moving_node_pointer = moving_node_pointer->prev_pointer;
        delete_node(delete_node_pointer);
    }
    start = NULL;
    end = NULL;
}

int delete_node(node * target_pointer)
{
    if (target_pointer != NULL)
    {
        target_pointer->prev_pointer = NULL;
        free(target_pointer);
        return EXIT_SUCCESS;
    }
    else
        return EXIT_FAILURE;
}
