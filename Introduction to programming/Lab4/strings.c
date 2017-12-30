#include <stdio.h>
#include <string.h>

int main()
{
    /* code */
    char first_name[20];
    char last_name[20];
    char full_name[40];

    printf("Please insert your first name: \n");
    gets(first_name);
    printf("Please insert your last name: \n");
    gets(last_name);

    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);
    printf("You fullname is ");
    puts(full_name);

    return 0;
}
