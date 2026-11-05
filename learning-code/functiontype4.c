#include <stdio.h>

int addnumbers (int a, int b) {
    return a + b;
}
int Multiplynumbers(int a,int b) {
    return a * b;
}

int Subtractnumbers(int a, int b) {
    return b - a;
}

int main () {
    int sum = addnumbers(10, 20);
    int product = Multiplynumbers(10, 20);
    int subtract = Subtractnumbers(10, 20);

    printf("The sum is %d\n", sum);
    printf("The product is %d\n", product);
    printf("The subtraction is %d\n", subtract);
    return 0;
}