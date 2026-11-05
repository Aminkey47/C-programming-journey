#include  <stdio.h>

int main () {
    int i = 0, j;
    int c = 0;

    do {
        j = 0;
        do {
            printf("%d", c++);
            j++;
        }while (j < 3);
        printf("\n");
        i++;
    }while (i < 3);
    return 0;
}