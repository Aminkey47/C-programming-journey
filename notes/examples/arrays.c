#include <stdio.h>

int main(void)
{
    int scores[] = {72, 85, 91, 68, 88};
    int sum = 0;
    int count = (int)(sizeof scores / sizeof scores[0]);

    for (int index = 0; index < count; ++index) {
        sum += scores[index];
    }

    printf("Average = %.2f\n", (double)sum / count);
    return 0;
}
