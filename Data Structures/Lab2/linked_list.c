/*
    implementing a linked list of integers struct and a functio to sort them.
*/
#include <stdio.h>
#include <conio.h>
#include "textattr.c"
#include "gotoxy.c"

#define ENTRIES 10
#define ENTRY_LENGTH 50
#define CENTER_POSITION 50

typedef struct node
{
    int data;
    struct node * prev_pointer;
    struct node * next_pointer;
} node;


node * create(int data);
void add(node * new_node);
node * search(int target);
int delete_node(node * target_pointer);
int insert_after(node * target_pointer, node * src_pointer);
void display_node(node * target_pointer);
void display_all(void);
void delete_all(void);
int insert_before(node * target_pointer, node * src_pointer);
void bubble_sort(void);

node * head = NULL, * tail = NULL;
int main(void)
{
    /* code */
    char menu_entries[ENTRIES][ENTRY_LENGTH] = {"Add", "Delete Node", "Insert After", "Search", "Display Node", "Display All", "Delete All", "Insert Before", "Sort Nodes", "Exit"};
    int current_option = 0;
    _Bool running_flag = 1;
    char first_byte, second_byte;

    int data_buffer = 0;
    int data_buffer1 = 0;
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
                    case 0: // add
                        printf("Please insert an integer: ");
                        fflush(stdin);
                        scanf("%d", &data_buffer);
                        add(create(data_buffer));
                        printf("The data %d was added, press any key to return to the main menu.\n", data_buffer);
                        getch();
                        break;
                    case 1: // delete node
                        printf("Please insert the integer you want to delete: ");
                        fflush(stdin);
                        scanf("%d", &data_buffer);
                        if (delete_node(search(data_buffer)) == 0)
                            printf("The was deleted successfully, press any key to return to the main menu.\n");
                        else
                            printf("No such node was found, press any key to return to the main menu.\n");
                        getch();
                        break;
                    case 2: // insert after
                        printf("Please insert an integer you want to insert: ");
                        scanf("%d", &data_buffer);
                        printf("and you want to insert that after? ");
                        fflush(stdin);
                        scanf("%d", &data_buffer1);
                        if (insert_after(search(data_buffer1), create(data_buffer)) == 1)
                            printf("The data %d was not found, so the %d was inserted at the begining of the list.\n", data_buffer1, data_buffer);
                        else
                            printf("The data %d was add after %d successfully.\n", data_buffer, data_buffer1);
                        getch();
                        break;
                    case 3:// search
                        printf("Please insert the number you are looking for: ");
                        fflush(stdin);
                        scanf("%d", &data_buffer);
                        if (search(data_buffer) == NULL)
                            printf("The number %d was not found.\n", data_buffer);
                        else
                            printf("The number %d was found.\n", data_buffer);
                        getch();
                        break;
                    case 4: // Display Node
                        printf("Please insert an integer you want to display: ");
                        fflush(stdin);
                        scanf("%d", &data_buffer);
                        display_node(search(data_buffer));
                        break;
                    case 5: // Display All
                        display_all();
                        break;
                    case 6: // Delete All
                        delete_all();
                        break;
                    case 7: // Insert Before
                        printf("Please insert an integer you want to insert: ");
                        fflush(stdin);
                        scanf("%d", &data_buffer);
                        printf("and you want to insert that before? ");
                        fflush(stdin);
                        scanf("%d", &data_buffer1);
                        if (insert_before(search(data_buffer1), create(data_buffer)) == 1)
                            printf("The data %d was not found, so the %d was inserted at the end of the list.\n", data_buffer1, data_buffer);
                        else
                            printf("The data %d was add after %d successfully.\n", data_buffer, data_buffer1);
                        getch();
                        break;
                    case 8: // sort nodes
                        bubble_sort();
                        break;
                    case 9: // exit
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
    new->next_pointer = NULL;
    new->prev_pointer = NULL;
    return new;
}

void add(node * new_node)
{
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->prev_pointer = tail;
        tail->next_pointer = new_node;
        tail = new_node;
    }
}

node * search(int target)
{
    node * current_pointer = head;
    while(current_pointer != NULL)
    {
        if (current_pointer->data == target)
            return current_pointer;
        current_pointer = current_pointer->next_pointer;
    }
    return NULL;
}

int delete_node(node * target_pointer)
{
    if (target_pointer == NULL)
        return 1;
    else if (target_pointer->next_pointer == NULL && target_pointer->prev_pointer == NULL)
    {
        tail = NULL;
        head = NULL;
    }
    else if (target_pointer->next_pointer == NULL)
    {
        target_pointer->prev_pointer->next_pointer = NULL;
        tail = target_pointer->prev_pointer;
    }
    else if (target_pointer->prev_pointer == NULL)
    {
        target_pointer->next_pointer->prev_pointer = NULL;
        head = target_pointer->next_pointer;
    }
    else
    {
        target_pointer->prev_pointer->next_pointer = target_pointer->next_pointer;
        target_pointer->next_pointer->prev_pointer = target_pointer->prev_pointer;
    }
    target_pointer->next_pointer = NULL;
    target_pointer->prev_pointer = NULL;
    free(target_pointer);
    return 0;
}

int insert_after(node * target_pointer, node * src_pointer)
{
    if (target_pointer == NULL)
    {
        src_pointer->prev_pointer = NULL;
        src_pointer->next_pointer = head;
        head = src_pointer;
        return 1;
    }
    else if (tail == target_pointer)
    {
        add(src_pointer);
    }
    else
    {
        src_pointer->prev_pointer = target_pointer;
        src_pointer->next_pointer = target_pointer->next_pointer;
        target_pointer->next_pointer->prev_pointer = src_pointer;
        target_pointer->next_pointer = src_pointer;
    }
    return 0;
}

void display_node(node * target_pointer)
{
    system("cls");
    if (target_pointer != NULL)
        printf("The integer is %d.", target_pointer->data);
    else
        printf("There is no such integer in the list.\n");
    getch();
}

void display_all()
{
    node * current_pointer = head;
    while(current_pointer != NULL)
    {
        printf("%d\n", current_pointer->data);
        current_pointer = current_pointer->next_pointer;
    }
    getch();
}


void delete_all()
{
    node * current_pointer = head;
    while(current_pointer != NULL)
    {
        delete_node(current_pointer);
        current_pointer = head;
    }
}


int insert_before(node * target_pointer, node * src_pointer)
{
    if (target_pointer == NULL)
    {
        add(src_pointer);
        return 1;
    }
    else if (head == target_pointer)
    {
        src_pointer->prev_pointer = NULL;
        src_pointer->next_pointer = head;
        head = src_pointer;
    }
    else
    {
        src_pointer->prev_pointer = target_pointer->prev_pointer;
        src_pointer->next_pointer = target_pointer;
        target_pointer->prev_pointer->next_pointer = src_pointer;
        target_pointer->prev_pointer = src_pointer;
    }
    return 0;
}

void bubble_sort(void)
{
    node * current_pointer = NULL;
    int unsorted = 1;
    while (unsorted)
    {
        current_pointer = head;
        unsorted = 0;
        while (current_pointer->next_pointer != NULL)
        {
            if (current_pointer->data > current_pointer->next_pointer->data)
            {
                unsorted = 1;
                int temp = current_pointer->data;
                current_pointer->data = current_pointer->next_pointer->data;
                current_pointer->next_pointer->data = temp;
            }
            current_pointer = current_pointer->next_pointer;
        }
    }
}
