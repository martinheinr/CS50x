#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number;
    long x = 0;
    long last_digit;
    long product_of_multiplied = 0;
    long product_of_not_multiplied = 0;
    long card_identifier;
    long checksum;
    bool flag =
        false; // used for setting a flag if it is the digit that needs to be multiplied or not
    void validate(long checksum, long card_identifier);

    do
    {
        card_number = get_long("Card number: ");
    }
    while (card_number < 1);

    card_identifier = card_number;

    while (card_number > x)
    {

        last_digit = card_number % 10;

        if (flag == false)
        {

            product_of_not_multiplied += last_digit;
            flag = true;
            card_number = card_number / 10;
            continue;
        }

        else if (flag == true)
        {

            last_digit = last_digit * 2;

            // handling 2 digit number after multiplication
            // it could be at most 9*2=18

            if (last_digit >= 10)
            {
                long z = last_digit % 10;
                long y = last_digit / 10;

                last_digit = z + y;
            }
            product_of_multiplied += last_digit;
            flag = false;
            card_number = card_number / 10;
            continue;
        }
    }

    checksum = product_of_not_multiplied + product_of_multiplied;

    validate(checksum, card_identifier);
}

void validate(long checksum, long card_identifier)
{
    if (checksum % 10 == 0 &&
        (card_identifier / 1000000000000000 == 4 || card_identifier / 1000000000000 == 4))
    {
        printf("VISA\n");
    }

    else if (checksum % 10 == 0 &&
             (card_identifier / 10000000000000 == 34 || card_identifier / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if (checksum % 10 == 0 &&
             (card_identifier / 100000000000000 == 51 || card_identifier / 100000000000000 == 52 ||
              card_identifier / 100000000000000 == 53 || card_identifier / 100000000000000 == 54 ||
              card_identifier / 100000000000000 == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
