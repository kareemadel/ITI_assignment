#include <stdio.h>

void swap_by_value(int number1, int number2);
void swap_by_address(int * number1, int * number2);

int main(void)
{
    /* code */
    int number1, number2;
    printf("Please insert the first number: ");
    scanf("%d", &number1);
    printf("Please insert the second number: " );
    scanf("%d", &number2);
    printf("Swapping by value.....\n");
    swap_by_value(number1, number2);
    printf("The first number is %d and the second number is %d.\n", number1, number2);
    printf("Swapping by address.....\n");
    swap_by_address(&number1, &number2);
    printf("The first number is %d and the second number is %d.\n", number1, number2);
    return 0;
}

void swap_by_value(int number1, int number2)
{
    int temp = number1;
    number1 = number2;
    number2 = temp;
}
void swap_by_address(int * number1, int * number2)
{
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}