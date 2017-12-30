#include <stdio.h>

int main()
{
    /* code */
    char first_name[20];
    char last_name[20];
    char full_name[40];
    printf("Please insert your first name: \n");
    scanf("%s", first_name);
    printf("Please insert your last name: \n");
    scanf("%s", last_name);
    char character_buffer;

    int src_index = 0;
    int dest_index = 0;
    while (first_name[src_index] != '\0')
    {
        full_name[dest_index] = first_name[src_index];
        dest_index++; src_index++;
    }

    character_buffer = ' ';
    full_name[dest_index] = character_buffer;
    src_index = 0; dest_index++;

    while (character_buffer != '\0')
    {
        character_buffer = last_name[src_index];
        full_name[dest_index] = last_name[src_index];
        dest_index++; src_index++;
    }

    printf("Your full name is %s.\n", full_name);

    return 0;
}
