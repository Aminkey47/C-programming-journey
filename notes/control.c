
#include <stdio.h>

int main(void) {

    // 1. SEQUENCE: Execute instructions in order
    int marks;

    printf("Enter your marks: ");
    scanf("%d", &marks);


    // 2. SELECTION: Make a decision using if-else
    if (marks >= 50) {
        printf("You passed!\n");
    } else {
        printf("You failed.\n");
    }


    // 3. REPETITION: Repeat an instruction using a for loop
    for (int i = 1; i <= 3; i++) {
        printf("Keep learning C!\n");
    }

    return 0;
}
