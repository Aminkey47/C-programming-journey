#include <stdio.h>

int main ()
{
    int a = 0;

    while (a < 10)
    {
        if (a % 2 == 0)
        {
            printf("%d is even\n", a);
        }
        else
        {
            printf("%d is odd\n", a);
        }

        a++;
    }
    
    return 0;
}