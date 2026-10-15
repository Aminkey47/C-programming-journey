//This statement drops a single iteration in a loop, if a specified condition occurs and continues with the next iteration in the loop

#include <stdio.h>

int main () {
    int i;

    for (i = 0; i < 10; i ++) {
        if(i==4) {
            continue;
        }
        printf("%d\n", i);
    }
    
}