#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    /* code */
    int char_counter = 0;
    int word_counter = 0;
    char char_buffer;
    printf("Please insert a sentence.\n");

    // consum e initial white spaces
    do
    {
        scanf("%c", &char_buffer);
    } while (!isalpha(char_buffer));

    while (char_buffer != '\n')
    {
        // if it's a word, consume it
        do
        {
            char_counter++;
            scanf("%c", &char_buffer);
        } while(isalpha(char_buffer));

        word_counter++;
        
        do
        {
            scanf("%c", &char_buffer);
        } while (!isalpha(char_buffer) && char_buffer != '\n');
    }

    printf("The number of characters are %d.\nThe number of words are %d.\n", char_counter, word_counter);

    return 0;
}