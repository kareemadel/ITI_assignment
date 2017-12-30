#include <stdio.h>

int main(void)
{
    /* prompt the user to enter a char */
    printf("Pleas inset a character: ");
    char ch = getch();
    // print the char and its ascii representation.
    printf("The ASCII code of %c is %d.\n", ch, ch);
    return 0;
}