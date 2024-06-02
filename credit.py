from cs50 import get_int, get_string
import math


def main():
    while True:
        card_number = get_string("Card number: ")
        if int(card_number) > 0:
            break

    print(luhns_algorithm(card_number))

def luhns_algorithm(card_number):
    sum_of_multiplied = 0
    sum_of_not_multiplied = 0

    for element in str(card_number[ : :-2]):
        sum_of_not_multiplied = sum_of_not_multiplied + int(element)

    card_number = card_number[:-1]

    for element in str(card_number[ : :-2]):
        digit = int(element) * 2
        if digit > 9:
            digit = (digit % 10) + 1

        sum_of_multiplied = sum_of_multiplied + digit

    checksum = sum_of_not_multiplied + sum_of_multiplied

    if checksum % 10 == 0:
        return True
    else:
        return False

main()

