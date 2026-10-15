#include <stdio.h>

int main () {
    int n = 5;
    for (int i = 1; i <= n; i++) {      //outer loop - arranging the rows
        for (int j = 1; j <= i; j++) {  //inner loop  - putting in the letters
            printf("%c", 'A' +j-1);
        }
        printf("\n");
    }
}