#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    c = a + b;

    printf("The sum is %d\n", c);

    if (a > b )
    {
        printf("%d is greater than %d\n", a, b);
    }
    else
    {
        printf("%d is not  greater than %d\n", a, b);
    }
    return 0;
}