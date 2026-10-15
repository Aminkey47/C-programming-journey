//program to calculate the sum of numbers(10 numbers)
//if the user enters a negative number the loop terminates

#include <stdio.h>

int main () {
    int i;
    double number , sum = 0.0;
    for (i = 1; i <= 10; ++i) {
        printf("Enter n%d: ", i);
        scanf("%lf", &number);
        if(number < 0.0) {      //break whenever number is negative 
            break;
        }
        sum+= number; //sum = sum + number
    }
    printf("Sum = %.2lf\n", sum);
    return 0;
}