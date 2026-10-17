#include <stdio.h>

int main(void)
{
    double side;
    double area;

    printf("Enter the side length: ");
    if (scanf("%lf", &side) != 1 || side < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    area = side * side;
    printf("Area = %.2f\n", area);
    return 0;
}
