#include <stdio.h>
#define LENGTH 10

int main()
{
    /* code */
    int values[LENGTH] = {0};
    int min, max;
    for (int i = 0; i < LENGTH; i ++)
    {
        printf("Please insert ineger %d: ", i + 1);
        scanf("%d", &values[i]);

        if (i == 0)
        {
            min = values[0];
            max = values[0];
        }
        else
        {
            max = values[i] > max ? values[i] : max;
            min = values[i] < min ? values[i] : min;
        }
    }

    printf("The maximum value is %d and the minimum value is %d.\n", max, min);
    return 0;
}
