#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, modul;
    scanf("%d", &T);
    scanf("%d", &modul);
    long long a, deg = 0;
    long long b = 0;
    for (int i = 0; i < T; i++)
    {
        scanf("%lld", &a);
        b = 1;
        deg = modul - 2;
        if (a == 0)
        {
            printf("%d\n", -1);
        } else
        {
            while (deg > 0)
            {
                if (deg & 1 == 1)
                {
                    b = (b * a) % modul;
                } 
                deg = deg >> 1;
                a = (a * a) % modul;
            }
            b = b % modul;
            printf("%lld\n", b);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// (a^((m)-2)) % m = inv(a)
