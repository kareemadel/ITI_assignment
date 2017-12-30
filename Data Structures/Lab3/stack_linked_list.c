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

node * top = NULL;

node * create(int data);
void push(node * new_node);
node * pop(void);
void display_all(void);
void free_stack(void);
int delete_node(node * target_pointer);

int main()
{
    /* code */
    char menu_entries[ENTRIES][ENTRY_LENGTH] = {"Push", "Pop", "Display All", "Free", "Exit"};
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
                    case 0: // push
                        printf("Please insert the number you want to push: ");
                        fflush(stdin);
                        scanf("%d", &temp_integer);
                        push(create(temp_integer));
                        break;
                    case 1: // pop
                        temp_node_pointer = pop();
                        if (temp_node_pointer != NULL)
                            {
                                printf("The popped number is %d.\n", temp_node_pointer->data);
                                getch();
                                delete_node(temp_node_pointer);
                            }
                        else
                        {
                            printf("The stack is empty.\n");
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

node * create(int data)
{
    node * new = (node *) malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void add(node * new_node)
{
    if (root == NULL)
        root = new_node;
    else
    {
        node * moving_pointer = root, * parent_moving_pointer = NULL;
        while (moving_pointer != NULL)
        {
            parent_moving_pointer = moving_pointer;    
            if (new_node->data > moving_pointer->data)
            {
                moving_pointer = moving_pointer->left;
            }
            else
            {
                moving_pointer = moving_pointer->right;
            }
        }

        if (new_node->data > parent_moving_pointer->data)
            parent_moving_pointer->left = new_node;
        else
            parent_moving_pointer->right = new_node;
    }
}

node * search(int data)
{
    node * moving_pointer = root;
    while (moving_pointer != NULL)
    {
        if (moving_pointer->data == data)
            return moving_pointer;
        else if (data > moving_pointer->data)
            moving_pointer = moving_pointer->left;
        else
            moving_pointer = moving_pointer->right;
    }

    return NULL;
}

node * get_parent(int data)
{
    node * moving_pointer = root, * parent_moving_pointer = NULL;
    while (moving_pointer != NULL)
    {
        if (moving_pointer->data == data)
            return parent_moving_pointer;
        parent_moving_pointer = moving_pointer;
        if (data > moving_pointer->data)
            moving_pointer = moving_pointer->left;
        else
            moving_pointer = moving_pointer->right;
    }

    return NULL;
}

void display(node * tree_root)
{
    if (tree_root != NULL)
    {
        display(tree_root->left);
        printf("%d\n", tree_root->data);
        display(tree_root->right);
    }
}

void delete_node(node * tree_node)
{

}
