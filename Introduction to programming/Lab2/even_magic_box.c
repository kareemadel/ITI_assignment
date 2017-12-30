#include <stdio.h>
#include "gotoxy.c"
#define SCALE 3

int main()
{
    // get user input
    int dimension = 0;
    do
    {
        printf("Please enter the dimension of the box: ");
        scanf("%d", &dimension);
    } while (dimension % 2 == 1);

    int half_dimension = dimension / 2;

    system("cls");

    int x_coordinate, y_coordinate, x_shift, y_shift, increment;
    for (int j = 0; j < 4; j++)
    {
        int area = half_dimension * half_dimension;
        x_shift = 0;
        y_shift = 0;
        increment = j * area;
        if (j == 1 || j == 2)
            x_shift = half_dimension;
        if (j == 1 || j == 3)
            y_shift = half_dimension;
        x_coordinate = half_dimension / 2;
        y_coordinate = 0;
        for (int i = 1; i <= area; i++)
        {
            gotoxy((x_coordinate + x_shift) * SCALE, (y_coordinate + y_shift));
            printf("%d", i + increment);
            if (i % half_dimension == 0)
            {
                y_coordinate = (y_coordinate + 1) % half_dimension;
            }
            else
            {
                x_coordinate = (x_coordinate + 1 + half_dimension) % half_dimension;
                y_coordinate = (y_coordinate - 1 + half_dimension) % half_dimension;
            }
        }
    }


    printf("\n");

    return 0;
}
