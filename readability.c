#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Write some text: ");

    //Remember string is array of characters
    int length = strlen(text);

    printf("%i", length);


    // Count the number of letters, words, and sentences in the text
    // I  want to skip empty spaces while counting words and sentences
    // Word is considered to be any sequence of characters (to count number of words you can maybe count spaces. For example count spaces +1)
    // I  can use isalpha from sc50.h to check if it is alphabetical to handle empty spaces in string
    // I assume I would count any period, exclamation point, period or question marks as 1 sentence???

    // Compute the Coleman-Liau index
    // index = 0.0588 * L - 0.296 * S - 15.8
    // where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.



    // Print the grade level
}
