#include <stdio.h>
#include "gotoxy.c"
#include "textattr.c"
#include <conio.h>

#define MAX_POSITION 20
#define MIN_POSITION 1
#define LINE_Y_COORD 1

void initialize_line(char * array, int size);
void print_line(char * array, int size, int current_column, int line_index);
void shift(char * array, int size, int current_column);
void line_editor(char ** start_pointer, char ** current_pointer, char ** last_pointer, int * array_length, int * text_length, int * current_column, char choice, int line_index);

int main(void)
{
    // get the number of lines
    printf("Please insert the number of lines: ");
    int number_of_lines = 0;
    scanf("%d", &number_of_lines);

    // allocate memory to store the length of each line
    int * text_length = (int *) malloc(number_of_lines * sizeof(int));

    // accounting arrays
    int * array_length = (int *) malloc(number_of_lines * sizeof(int));
    int * current_column = (int *) malloc(number_of_lines * sizeof(int));
    char ** start_pointer = (char **) malloc(number_of_lines * sizeof(char *));
    char ** current_pointer = (char **) malloc(number_of_lines * sizeof(char));
    char ** last_pointer = (char **) malloc(number_of_lines * sizeof(char));


    // get the length of each line from user.
    for (int i = 0; i < number_of_lines; i++)
    {
        printf("Please insert the length of line number %d: ", i + 1);
        scanf("%d", &text_length[i]);
        // allocate memory for each line
        start_pointer[i] = (char *) malloc(text_length[i] * sizeof(char));
        array_length[i] = text_length[i] + 1;
        current_column[i] = MIN_POSITION;
        current_pointer[i] = start_pointer[i];
        last_pointer[i] = current_pointer[i];
        initialize_line(start_pointer[i], array_length[i]);
    }


    _Bool run_flag = 1;
    char choice;
    int line_index = 0;
    fflush(stdin);
    system("cls");
    for (int i = 0; i < number_of_lines; i++)
    {
        print_line(start_pointer[i], text_length[i], current_column[i], i);
    }
    while (run_flag)
    {
        print_line(start_pointer[line_index], text_length[line_index], current_column[line_index], line_index);
        choice = getch();
        switch (choice)
        {
            case 27:
                system("cls");
                run_flag = 0;
                break;
            case 13:
                system("cls");
                for (int i = 0; i < number_of_lines; i++)
                {
                    if (*last_pointer[i] == '\0')
                        print_line(start_pointer[i], last_pointer[i] - start_pointer[i], current_column[i], i);
                    else
                        print_line(start_pointer[i], last_pointer[i] - start_pointer[i] + 1, current_column[i], i);
                }
                gotoxy(0, LINE_Y_COORD + 1 + number_of_lines);
                run_flag = 0;
                break;
            case 9://tab
                line_index = (line_index + 1) % number_of_lines;
                break;
            default:
                line_editor(start_pointer, current_pointer, last_pointer, array_length, text_length, current_column, choice, line_index);
                break;

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

void print_line(char * array, int size, int current_column, int line_index)
{
    gotoxy(MIN_POSITION, line_index + LINE_Y_COORD);
    textattr(0x70);
    for (int i = 0; i < size; i++)
    {
        if (array[i] == '\0')
            printf(" ");
        else
            printf("%c", array[i]);
    }
    gotoxy(current_column, line_index + LINE_Y_COORD);
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


void line_editor(char ** start_pointer, char ** current_pointer, char ** last_pointer, int * array_length, int * text_length, int * current_column, char choice, int line_index)
{
    switch (choice)
    {
        case -32:
            choice = getch();
            switch (choice)
            {
                case 71:    //home
                case 73:    //page up
                    current_column[line_index] = MIN_POSITION;
                    current_pointer[line_index] = start_pointer[line_index];
                    break;
                case 75:    //left arrow
                    if (current_pointer[line_index] > start_pointer[line_index])
                    {
                        current_pointer[line_index]--;
                        current_column[line_index]--;
                    }
                    break;
                case 77:    // right arrow
                    if (current_pointer[line_index] < last_pointer[line_index])
                    {
                        current_pointer[line_index]++;
                        current_column[line_index]++;
                    }
                    break;
                case 79:    //end
                case 81:    //page down
                    current_column[line_index] = current_column[line_index] + last_pointer[line_index] - current_pointer[line_index];
                    current_pointer[line_index] = last_pointer[line_index];
                    break;
                case 83:    //delete
                        if (current_pointer[line_index] == last_pointer[line_index] - 1)
                        {
                            *current_pointer[line_index] = '\0';
                            last_pointer[line_index]--;
                        }
                        else if (current_pointer[line_index] < last_pointer[line_index] - 1)
                        {
                            shift(start_pointer[line_index], array_length[line_index], current_column[line_index]);
                            last_pointer[line_index]--;
                        }
                        else if (current_pointer[line_index] == last_pointer[line_index] && last_pointer[line_index] == start_pointer[line_index] + text_length[line_index] - 1)
                        {
                            *current_pointer[line_index] = '\0';
                        }
                        break;
            }
            break;
        case '\b':
            if (current_pointer[line_index] != start_pointer[line_index])
            {
                if (current_pointer[line_index] == last_pointer[line_index] && last_pointer[line_index] != text_length[line_index] + start_pointer[line_index] - 1)
                {
                    *(current_pointer[line_index] - 1) = '\0';
                    current_pointer[line_index]--;
                    last_pointer[line_index]--;
                    current_column[line_index]--;
                }
                else
                    {
                        if (*(text_length[line_index] + start_pointer[line_index] - 1) == '\0')
                            last_pointer[line_index]--;
                        current_pointer[line_index]--;
                        shift(start_pointer[line_index], array_length[line_index], current_column[line_index] - 1);
                        current_column[line_index]--;
                    }
                }
                break;
        default:
            if (isprint(choice))
            {
                if (current_column[line_index] < text_length[line_index])
                {
                    *(current_pointer[line_index]) = choice;
                    if (current_pointer[line_index] == last_pointer[line_index])
                        last_pointer[line_index]++;
                    current_pointer[line_index]++;
                    current_column[line_index]++;
                }
                else if (current_column[line_index] == text_length[line_index])
                    *(current_pointer[line_index]) = choice;
            }
    }
}