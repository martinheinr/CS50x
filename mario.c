#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    void make_mario_blocks(int height);

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    make_mario_blocks(height);
}

void make_mario_blocks(int height)
{
    int left_spaces = height - 1;

    for (int i = 1; i <= height; i++)
    {

        for (int j = 0; j < left_spaces; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
        left_spaces--;
    }
}
