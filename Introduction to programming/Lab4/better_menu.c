#include <stdio.h>
#define ENTRIES 3
#define ENTRY_LENGTH 10
#define CENTER_POSITION 50
#include "textattr.c"
#include "gotoxy.c"

int main()
{
    /* code */
    char menu_entries[ENTRIES][ENTRY_LENGTH] = {"New", "Display", "Exit"};
    int current_option = 0;
    _Bool running_flag = 1;
    char first_byte, second_byte;

    while (running_flag)
    {
        system("cls");

        // print the menu
        gotoxy(CENTER_POSITION, 1);
        textattr(0x17);
        printf("MENU ENTRIES");
        textattr(0x07);
        for (int i = 0; i < ENTRIES; i++)
        {
            gotoxy(CENTER_POSITION, i + 2);
            if (current_option == i)
                textattr(0x70);

            printf("%s", menu_entries[i]);
            textattr(0x07);
        }
        gotoxy(0, ENTRIES + 2);

        // wait for an input from the user
        first_byte = getch();

        // if it's an extended key
        if (first_byte < 0)
            second_byte = getch();

        switch (first_byte)
        {
            case -32:
                switch (second_byte)
                {
                    case 72:    //up arrow
                    case 73:    // page up
                        current_option = (current_option - 1 + ENTRIES) % ENTRIES;
                        break;
                    case 80:    //down arrow
                    case 81:    // page down
                        current_option = (current_option + 1) % ENTRIES;
                        break;
                    case 71:    //home
                        current_option = 0;
                        break;
                    case 79:    //end
                        current_option = ENTRIES - 1;
                        break;
                }
                break;
            case 27:    // esc button
                running_flag = 0;
                break;
            case 13:    // enter button
                system("cls");
                switch (current_option)
                {
                    case 0:
                        printf("You choose New.\n");
                        getch();
                        break;
                    case 1:
                        printf("You choose Display.\n");
                        getch();
                        break;
                    case 2:
                        running_flag = 0;
                        break;
                }
        }
            

    }
    return 0;
}
