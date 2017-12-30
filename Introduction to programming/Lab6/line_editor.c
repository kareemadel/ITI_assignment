#include <stdio.h>
#include "gotoxy.c"
#include "textattr.c"

#define MAX_POSITION 10
#define MIN_POSITION 1
#define LINE_Y_COORD 1

void initialize_line(char * array, int size);
void print_line(char * array, int size, int current_column);
void shift(char * array, int size, int current_column);

int main(void)
{
    /* code */
    int text_length = MAX_POSITION - MIN_POSITION, array_length = text_length + 1;
    int current_column = MIN_POSITION;
    char * const start_pointer = (char * )malloc(array_length * sizeof(char)), *current_pointer = start_pointer, * last_pointer = current_pointer;

    initialize_line(start_pointer, array_length);

    _Bool run_flag = 1;
    char choice;

    while (run_flag)
    {
        print_line(start_pointer, text_length, current_column);
        choice = getch();
        switch (choice)
        {
            case 13:
                system("cls");
                print_line(start_pointer, current_column - 1, current_column);
                gotoxy(0, LINE_Y_COORD + 1);
                run_flag = 0;
                break;
            case 27:
                system("cls");
                run_flag = 0;
                break;
            case -32:
                choice = getch();
                switch (choice)
                {
                    case 71:    //home
                    case 73:    //page up
                        current_column = MIN_POSITION;
                        current_pointer = start_pointer;
                        break;
                    case 75:    //left arrow
                        if (current_pointer > start_pointer)
                        {
                            current_pointer--;
                            current_column--;
                        }
                        break;
                    case 77:    // right arrow
                        if (current_pointer < last_pointer)
                        {
                            current_pointer++;
                            current_column++;
                        }
                        break;
                    case 79:    //end
                    case 81:    //page down
                        current_column = current_column + last_pointer - current_pointer;
                        current_pointer = last_pointer;
                        break;
                    case 83:    //delete
                        if (current_pointer == last_pointer - 1)
                        {
                            *current_pointer = '\0';
                            last_pointer--;
                        }
                        else if (current_pointer < last_pointer - 1)
                        {
                            shift(start_pointer, array_length, current_column);
                            last_pointer--;
                        }
                        else if (current_pointer == last_pointer && last_pointer == start_pointer + text_length - 1)
                        {
                            *current_pointer = '\0';
                        }
                        break;
                }
                break;
            case '\b':
                if (current_pointer != start_pointer)
                {
                    if (current_pointer == last_pointer && last_pointer != text_length + start_pointer - 1)
                    {
                        *(current_pointer - 1) = '\0';
                        current_pointer--;
                        last_pointer--;
                        current_column--;
                    }
                    else
                        {
                            if (*(text_length + start_pointer - 1) == '\0')
                                last_pointer--;
                            current_pointer--;
                            shift(start_pointer, array_length, current_column - 1);
                            current_column--;
                        }
                    }
                break;
            default:
                if (isprint(choice))
                {
                    if (current_column < text_length)
                    {
                        *current_pointer = choice;
                        if (current_pointer == last_pointer)
                            last_pointer++;
                        current_pointer++;
                        current_column++;
                    }
                    else if (current_column == text_length)
                        *current_pointer = choice;
                }
        }
    }
    return 0;
}


void initialize_line(char * array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = '\0';
    }
}

void print_line(char * array, int size, int current_column)
{
    gotoxy(MIN_POSITION, LINE_Y_COORD);
    textattr(0x70);
    for (int i = 0; i < size; i++)
    {
        if (array[i] == '\0')
            printf(" ");
        else
            printf("%c", array[i]);
    }
    gotoxy(current_column, LINE_Y_COORD);
    textattr(0x07);
}

void shift(char * array, int size, int current_column)
{
    size--; // avoid the last char
    for (int i = current_column - 1; i < size; i++)
    {
        array[i] = array[i + 1];
    }
}
