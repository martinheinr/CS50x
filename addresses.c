// Prints an integer's address

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    // following line shows the address where n is stored in memory
    printf("%p\n", &n);

    // pointer is address of some variable that you can store in another variable
    // variable that stores an address starts with *, in this case *p
    // so pointer *p points to the memory address where the variable n is storred
    // int *p is syntax for specifying the pointer while if you specify just *p without datatype that just means 'go there'

    int *p = &n;

    // prints the address that is stored in the pointer (address to which pointer is pointing)
    printf("%p\n", p);

    //*p here means go to the memory address and show what is on the address
    printf("%i\n\n", *p);

    printf("STRINGS: \n");

    string s = "HI!";
    // address of the string address of the first character are the same addresses
    // when looking at the address of the string, it will be the address of the first character and computer knows where the string ends because
    // every string ends with \0 so the string "HI!" is stored in memory with 4bytes, 1 byte per character + 1 byte for \0.
    //%p will print the pointer (address) to s

    printf("%p\n", s);

    // printing addresses of each characters will indeed show that address of what is storred in variable s and character "H"
    // is the same following increment in memory addresses for each next character (including \0) that marks the end of the string.

    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);


}
