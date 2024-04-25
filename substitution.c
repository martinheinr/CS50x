#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool return_if_valid_key(int argc, string user_key);
int cipher_text(string user_key, string plaintext);

int main(int argc, string argv[])
{
    // Key should be provided as an argument. Get the key and validate the key.
    if (!return_if_valid_key(argc, argv[1]))
    {
        return 1;
    }

    // Key is stored as user_key if passes validation.
    string user_key = argv[1];
    string plaintext;

    // Get plaintext.
    plaintext = get_string("Plaintext: ");

    cipher_text(user_key, plaintext);

    return 0;
}

int cipher_text(string user_key, string plaintext)
{
    char lowercase[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char uppercase[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                          'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int chipher[26];
    char chiphered_text[] = "";

    // Loop through the user_key and deduct ascii value to get the difference between the key of 26
    // chars and alphabet Later this difference is added to the plaintext chars to chipher the
    // plaintext
    for (int i = 0; i < strlen(user_key); i++)
    {
        if(islower(user_key[i]) != 0)
        {
        chipher[i] = user_key[i] - lowercase[i];
        }

        else
        {
            chipher[i] = user_key[i] - uppercase[i];
        }
    }

    for (int i = 0; i < strlen(plaintext); i++)
    {
        for (int j = 0; j < 26; j++)
        {

            if (plaintext[i] == uppercase[j] || plaintext[i] == lowercase[j])
            {
                chiphered_text[i] = plaintext[i] + chipher[j];
            }
            else if (isdigit(plaintext[i]) != 0 || ispunct(plaintext[i]) != 0 ||
                     isspace(plaintext[i]) != 0)
            {
                chiphered_text[i] = plaintext[i];
            }
        }
    }

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", chiphered_text[i]);
    }

    printf("\n");
    
    return 0;
}

bool return_if_valid_key(int argc, string user_key)
{
    // Check number of arguments. It needs to be exactly 2. As the first argument, program name is
    // counted and then the second one should be the key.
    if (argc != 2)
    {

        printf("Usage: ./substituttion key\n");
        return false;
    }

    // Check the exact length
    if (strlen(user_key) != 26)
    {
        printf(
            "Key should be exactly 26 alphabetical characters and characters should not repeat.\n");
        return false;
    }

    // CHeck that only alphabetical
    for (int i = 0; i < strlen(user_key); i++)
    {
        if (!isalpha(user_key[i]))
        {
            printf("Key should be exactly 26 alphabetical characters and characters should not "
                   "repeat.\n");
            return false;
        }
    }

    // Check for duplicated letters
    for (int i = 0; i < strlen(user_key); i++)
    {
        for (int j = 0; j < strlen(user_key) - 1; j++)
        {
            if (user_key[i] == user_key[j] && i != j)
            {
                printf("Key should should not contain same chars twice.\n");
                return false;
            }
        }
    }
    return true;
}
