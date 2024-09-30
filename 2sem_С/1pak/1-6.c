#include <stdio.h>
#define modul 1000000007

long long inverse(long long a)
{
    long long b = 1;
    int deg = modul - 2;
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
    return(b);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    long long n, k;
    long long fact[1000001];
    fact[0] = 1;
    for (int i = 1; i < 1000001; i++)
    {
        fact[i] = (i * fact[i - 1]) % modul;
    }
    long long ans = 0;
    for (int i = 0; i < T; i++)
    {
        ans = 0;
        scanf("%lld %lld", &n, &k);
        ans = ((fact[n] * inverse(fact[n - k])) % modul * inverse(fact[k])) % modul;
        printf("%lld\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
