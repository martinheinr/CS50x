#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float return_index(int numbers []);
void print_grade(float index);
int* counter_array(int length, string text, int numbers []);

int main(void)
{
    int letters = 0, words = 0, sentences = 0;
    int numbers [] = {letters, words, sentences};

    // Prompt the user for some text
    // Remember string is array of characters

    string text = get_string("Write some text: ");

    int length = strlen(text);

    float index = return_index(counter_array(length, text, numbers));

    print_grade(index);

}

int* counter_array(int length, string text, int numbers [])
{
    int x = 0;

    while (x <= length)
    {
        if (isalpha(text[x]) != 0)
        {
            numbers[0] += 1;
        }
        else if (isblank(text[x]) != 0 || text[x] == 0)
        {
            numbers[1] += 1;
        }
        else if (text[x] == '.' || text[x] == '?' || text[x] == '!')
        {
            numbers[2] += 1;
        }
        x++;
    }

    return numbers;
}

float return_index(int numbers [])
{
    if (numbers[0] <= 0 || numbers[1] <= 0 || numbers[2] <= 0)
    {
        return 1;
    }

    float x = (float) numbers[0];
    float y = (float) numbers[1];
    float z = (float) numbers[2];

    // Compute the Coleman-Liau index
    float index = 0;

    // where L is the average number of letters per 100 words in the text,
    float L = (x / y) * 100;

    //and S is the average number of sentences per 100 words in the text.
    float S = (z / y) * 100;

    // index = 0.0588 * L - 0.296 * S - 15.8

    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index <= 1){
        index = 1;
    }

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
