#include <stdio.h>


int main()
{
    /* code */
    printf("Please press an extended key.\n");
    char fixed_byte;
    while ((fixed_byte = getch()) > 0);

    char extended_char = getch();
    printf("The ascii representation of the extended key you just pressed it %d.\n", extended_char);

    return 0;
}
