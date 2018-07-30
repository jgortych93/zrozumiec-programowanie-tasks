#include <stdio.h>

int main()
{
    for(int x = -123; x; x >>= 1)
        printf("execution\n");

    return 0;
}
