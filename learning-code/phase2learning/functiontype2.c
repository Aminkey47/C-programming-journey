#include <stdio.h>

void printSquare (int num) {
    int result = num * num;
    printf("Square ; %d\n" , result);
}
int main () {
    printSquare(5);
    return 0;
}