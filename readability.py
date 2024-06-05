from cs50 import get_string
import sys


def main():
    txt = get_string("Write some text: ")

    if len(txt) < 1:
        sys.exit(1)

    number_of_letters = 0
    number_of_words = 1
    number_of_sentences = 0

    for letter in txt:
        # print(letter)

        if letter.isalpha():
            number_of_letters += 1

        elif letter.isspace():
            number_of_words += 1

        elif letter == "." or letter == "?" or letter == "!":
            number_of_sentences += 1

    # print(number_of_letters)
    # print(number_of_words)
    # print(number_of_sentences)

    index = return_index(number_of_letters, number_of_words, number_of_sentences)
    # print(index)

    if index <= 1:
        print("Before Grade 1")

    elif index == 2:
        print("Grade 2")

    elif index == 3:
        print("Grade 3")

    elif index == 5:
        print("Grade 5")

    elif index == 7:
        print("Grade 7")

    elif index == 8:
        print("Grade 8")

    elif index == 9:
        print("Grade 9")

    elif index == 10:
        print("Grade 10")

    elif index >= 16:
        print("Grade 16+")


def return_index(number_of_letters, number_of_words, number_of_sentences):

    # Compute the Coleman-Liau index
    index = 0

    # where L is the average number of letters per 100 words in the text,
    l = number_of_letters / number_of_words * 100

    # and S is the average number of sentences per 100 words in the text.
    s = number_of_sentences / number_of_words * 100

    # index = 0.0588 * L - 0.296 * S - 15.8

    index = 0.0588 * l - 0.296 * s - 15.8

    if index < 1:
        index = 1

    return round(index)


main()
