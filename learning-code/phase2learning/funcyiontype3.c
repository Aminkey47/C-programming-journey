#include <stdio.h>

int getPIValue() {
    return 3;
}
int main () {
    int val = getPIValue();
    printf("The value of PI is %d\n", val);
    return 0;
}