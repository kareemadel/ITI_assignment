#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int sum = 0;
    int num = 0;
    while (sum < 100)
    {
        printf("Please insert an integer: ");
        scanf("%d", &num);
        _flushall();
        sum += num;
    }

    printf("The total sum of the entered numbers is %d\n", sum);

    return 0;
}
