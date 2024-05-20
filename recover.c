#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Program accepts only one argument.\n");
        return 1;
    }

    // Open the memory card

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }
    // Create a buffer for a block of data
    uint8_t buffer[512];
    int jpg_number = 0;
    char *filename = malloc(8);
    FILE *img;

    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", jpg_number);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("error");
                return 1;
            }
            fwrite(buffer, 1, 512, img);
            jpg_number++;
        }
        else
        {
            if (img != NULL)
            {
                fwrite(buffer, 1, 512, img);
            }
        }
    }

    free(filename);
    free(img);
    return 0;
}
