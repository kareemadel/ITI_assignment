#include <stdio.h>
#include <stdlib.h>


int main()
{

    char option;
    int counter;
    do
    {
        counter = 0;
        printf("*Menu*\na)Good Morning\nb)Good evening\nc)Exit\n");
        option = getche();

        system("cls");
          switch (option) {
            case 'a':
            case 'A':

              printf("Good Morning.\n");
              break;

            case 'b':
            case 'B':
              printf("Good Evening.\n");
              break;
          }

        getch();
        system("cls");
    }while((option != 'c' && option != 'C'));


    return 0;
}
