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
    struct node * left;
    struct node * right;
} node;

node * root = NULL;

node * create(int data);
void add(node * new_node);
node * search(int data);
node * get_parent(node * tree_node);
void display(node * tree_root);
void delete_node(node * tree_node);
int which_child(node * child);
node * get_min(node * tree_root);
node * get_max(node * tree_root);

int main()
{
    /* code */
    char menu_entries[ENTRIES][ENTRY_LENGTH] = {"Add", "Search", "Display", "Delete", "Exit"};
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
                    case 0: // add
                        printf("Please insert the number you want to add: ");
                        fflush(stdin);
                        scanf("%d", &temp_integer);
                        add(create(temp_integer));
                        break;
                    case 1: // search
                        printf("Please insert the number you want to search for: ");
                        fflush(stdin);
                        scanf("%d", &temp_integer);
                        temp_node_pointer = search(temp_integer);
                        if (temp_node_pointer == NULL)
                            printf("The element you are searching for doesn't exist.\n");
                        else
                        {
                            printf("The element is found.\n");
                        }
                        getch();
                        break;
                    case 2: //display
                        display(root);
                        getch();
                        break;
                    case 3: // delete
                        printf("Please insert the number you want to delete: ");
                        fflush(stdin);
                        scanf("%d", &temp_integer);
                        temp_node_pointer = search(temp_integer);
                        if (temp_node_pointer == NULL)
                            printf("There is no such element in the tree.\n");
                        else
                        {
                            delete_node(temp_node_pointer);
                            printf("The node was deleted\n");
                        }
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
                moving_pointer = moving_pointer->right;
            }
            else
            {
                moving_pointer = moving_pointer->left;
            }
        }

        if (new_node->data > parent_moving_pointer->data)
            parent_moving_pointer->right = new_node;
        else
            parent_moving_pointer->left = new_node;
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
            moving_pointer = moving_pointer->right;
        else
            moving_pointer = moving_pointer->left;
    }

    return NULL;
}

node * get_parent(node * tree_node)
{
    node * moving_pointer = root, * parent_moving_pointer = NULL;
    while (moving_pointer != NULL)
    {
        if (moving_pointer->data == tree_node->data)
            return parent_moving_pointer;
        parent_moving_pointer = moving_pointer;
        if (tree_node->data > moving_pointer->data)
            moving_pointer = moving_pointer->right;
        else
            moving_pointer = moving_pointer->left;
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
    node * parent_node = get_parent(tree_node);
    // 0 is root, 1 is left, -1 is right
    int node_state = which_child(tree_node);
    // if the node has no children
    if (tree_node->left == NULL && tree_node->right == NULL)
    {
        // the node is the left child
        if (node_state == 1)
            parent_node->left = NULL;
        // right child
        else if (node_state == -1)
            parent_node->right = NULL;
        else
            root = NULL;

    }
    // if it has only left child
    else if (tree_node->right == NULL)
    {
        // the node is the left child
        if (node_state == 1)
            parent_node->left = tree_node->left;
        // right child
        else if (node_state == -1)
            parent_node->right = tree_node->left;
        else
            root = tree_node->left;
    }
    // if it has only right child
    else if (tree_node->left == NULL)
    {
        // the node is the left child
        if (node_state == 1)
            parent_node->left = tree_node->right;
        // right child
        else if (node_state == -1)
            parent_node->right = tree_node->right;
        else
            root = tree_node->right;
    }
    else
    {
        node * temp_node_pointer = NULL;
        // the node is the left child
        if (node_state == 1)
        {
            temp_node_pointer = get_max(tree_node->right);
            temp_node_pointer->left = tree_node->left;
            parent_node->left = tree_node->right;
        }
        // right child
        else if (node_state == -1)
        {
            temp_node_pointer= get_max(tree_node->right);
            temp_node_pointer->left = tree_node->left;
            parent_node->right = tree_node->right;
        }
        else
        {
            temp_node_pointer = get_max(tree_node->right);
            temp_node_pointer->left = tree_node->left;
            root = tree_node->right;
        }
    }
    tree_node->right = NULL;
    tree_node->left = NULL;
    free(tree_node);
}

int which_child(node * child)
{
    node * parent_node = get_parent(child);
    if (parent_node == NULL)
        return 0;
    else if (parent_node->left == child)
        return 1;
    else
        return -1;
}

node * get_min(node * tree_root)
{
    node * moving_pointer = root, * parent_moving_pointer = NULL;
    while (moving_pointer != NULL)
    {
        parent_moving_pointer = moving_pointer;
        moving_pointer = moving_pointer->left;
    }
    return parent_moving_pointer;
}

node * get_max(node * tree_root)
{
    node * moving_pointer = root, * parent_moving_pointer = NULL;
    while (moving_pointer != NULL)
    {
        parent_moving_pointer = moving_pointer;
        moving_pointer = moving_pointer->right;
    }
    return parent_moving_pointer;
}