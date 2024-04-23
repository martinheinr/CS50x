#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

void counter(int length, string text);
float return_index(float x, float y, float z);
void print_grade(float index);

float number_of_letters = 0;
float number_of_words = 0;
float number_of_sentences = 0;

int main(void)
{
    // Prompt the user for some text
    // Remember string is array of characters

    string text = get_string("Write some text: ");

    int length = strlen(text);

    counter(length, text);

    float index = return_index(number_of_letters, number_of_words, number_of_sentences);

    print_grade(index);

}

void counter(int length, string text)
{

    int x = 0;

    while (x <= length)
    {
        if (isalpha(text[x]) != 0)
        {
            number_of_letters += 1;
        }
        else if (isblank(text[x]) != 0 || text[x] == 0)
        {
            number_of_words += 1;
        }
        else if (text[x] == '.' || text[x] == '?' || text[x] == '!')
        {
            number_of_sentences += 1;
        }
        x++;
    }
}

float return_index(float x, float y, float z)
{
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return 0;
    }

    // Compute the Coleman-Liau index
    float index = 0;

    // where L is the average number of letters per 100 words in the text,
    float L = (x / y) * 100;

    //and S is the average number of sentences per 100 words in the text.
    float S = (z / y) * 100;


    // index = 0.0588 * L - 0.296 * S - 15.8

    index = 0.0588 * L - 0.296 * S - 15.8;

    return roundf(index);
}

void print_grade(float index)
{
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index == 2)
    {
        printf("Grade 2\n");
    }

    else if (index == 3)
    {
        printf("Grade 3\n");
    }

    else if (index == 5)
    {
        printf("Grade 5\n");
    }

    else if (index == 7)
    {
        printf("Grade 7\n");
    }

    else if (index == 8)
    {
        printf("Grade 8\n");
    }

    else if (index == 9)
    {
        printf("Grade 9\n");
    }

    else if (index == 10)
    {
        printf("Grade 10\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}
