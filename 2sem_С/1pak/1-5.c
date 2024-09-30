#include <stdio.h>
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        } else
        {
            b -= a;
        }
        return gcd(a, b);
    }
    return b;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    int a, b, c;
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        c = gcd(a, b);
        printf("%d\n", c);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}