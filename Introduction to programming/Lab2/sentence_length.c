#include <stdio.h>


int main()
{
    /* code */
    int char_counter = 0;
    char char_buffer;
    printf("Please insert a sentence.\n");
    while ((char_buffer = getche()) != 13)
    {
        char_counter++;
    }
    printf("The number of characters are %d.\n", char_counter);
}
