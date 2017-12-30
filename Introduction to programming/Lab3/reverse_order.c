#include <stdio.h>
#define LENGTH 7


int main()
{
    /* code */
    int values[LENGTH] = {0};

    for (int i = 0; i < LENGTH; i++)
    {
        printf("Please insert an integer %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("Here are the values you entered in reverse order.\n");
    for (int i = LENGTH - 1; i > -1; i--)
    {
        printf("Integer %d is %d.\n", i + 1, values[i]);
    }
    return 0;
}
