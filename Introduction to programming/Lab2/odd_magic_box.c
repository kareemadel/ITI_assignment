#include <stdio.h>
#include "textattr.c"
#include "gotoxy.c"

#define SCALE 5

int main()
{
    // get user input
    int dimension = 0;
    do
    {
        printf("Please enter the dimension of the box: ");
        scanf("%d", &dimension);
    } while (dimension % 2 == 0);

    system("cls");

    int area = dimension * dimension;
    int x_coordinate = dimension / 2, y_coordinate = 0;
    for (int i = 1; i <= area; i++)
    {
        gotoxy(x_coordinate * SCALE, y_coordinate);
        printf("%d", i);
        if (i % dimension == 0)
        {
            y_coordinate = (y_coordinate + 1) % dimension;
        }
        else
        {
            x_coordinate = (x_coordinate + 1 + dimension) % dimension;
            y_coordinate = (y_coordinate - 1 + dimension) % dimension;
        }
    }


    printf("\n");

    return 0;
}
