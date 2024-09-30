#include <stdio.h>

void func(int *par)
{
    *par = 10;
}

int main()
{
    int a = 5;

    printf("%d\n", a);

    func(&a);

    printf("%d\n", a);

    return 0;
}