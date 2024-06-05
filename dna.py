import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("I need 2 arguments: csv file and text file. ")
        sys.exit(1)

    csv_file = sys.argv[1]
    txt_file = sys.argv[2]

    # Read database file into a variable
    database_list = []
    list_of_strs = []
    with open(csv_file, newline='') as csvfile:
        database = csv.DictReader(csvfile)

        for fieldname in database.fieldnames[1:]:
            list_of_strs.append(fieldname)

        for row in database:
            database_list.append(row)

    # Read DNA sequence file into a variable

    with open(txt_file, encoding="utf-8") as f:
        sequence = f.read()

    # Find longest match of each STR in DNA sequence

    longest_strs = {}
    longest_strs.update({"name": ""})
    for x in list_of_strs:
        longest_strs.update({x: str(longest_match(sequence, x))})

    # Check database for matching profiles

    for dict in database_list:
        similarity = 0
        for key, value in dict.items():
            for key_2, value_2 in longest_strs.items():
                if (key == key_2 and value == value_2):
                    similarity += 1

        if similarity == len(database.fieldnames) - 1:
            print(dict['name'])
            break
    else:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
