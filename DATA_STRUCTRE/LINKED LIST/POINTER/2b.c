#include <stdio.h>

void callByValue(int a)
{
    a = a + 10;
    printf("Inside Call by Value: %d\n", a);
}

void callByReference(int *a)
{
    *a = *a + 10;
    printf("Inside Call by Reference: %d\n", *a);
}

int main()
{
    int x = 20, y = 20;

    printf("Before Call by Value: %d\n", x);
    callByValue(x);
    printf("After Call by Value: %d\n\n", x);

    printf("Before Call by Reference: %d\n", y);
    callByReference(&y);
    printf("After Call by Reference: %d\n", y);

    return 0;
}