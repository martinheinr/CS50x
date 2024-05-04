// Swaps two integers using pointers

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    // &  to provide addresses as parameters
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}
// swap expects pointers as parameters
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
