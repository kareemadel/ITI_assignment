#include <stdio.h>

int main(void)
{
    /* Prompts the user to enter integer  */
    printf("Please inset an integer: ");
    int num = 0;
    scanf("%d", &num);
    /* print the octal and hex representation */
    printf("The hex is: %x\nThe octal is: %o\n", num, num);
    return 0;
}