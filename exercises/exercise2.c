//continue skips the current iteration of a loop and continues with the next iteration of the loop.

#include <stdio.h>

int main () {
    int i;
    double number , sum = 0.0;
    for (i = 1; i <= 10; ++i) {
        printf("Enter n%d: ", i);
        scanf("%lf", &number);
        if(number < 0.0) {      
            continue; //skip the rest of the loop and continue with the next iteration
        }
        sum+= number; //sum = sum + number
    }
    printf("Sum = %.2lf\n", sum);
    return 0;
}