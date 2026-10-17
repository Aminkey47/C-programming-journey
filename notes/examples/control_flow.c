#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("That was not an integer.\n");
        return 1;
    }

    if (number % 2 == 0) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }

    for (int i = 1; i <= 10; ++i) {
        if (i == 7) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
