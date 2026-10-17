#include <stdio.h>

int add_numbers(int first, int second);

int main(void)
{
    int total = add_numbers(7, 10);

    printf("Total = %d\n", total);
    return 0;
}

int add_numbers(int first, int second)
{
    return first + second;
}
