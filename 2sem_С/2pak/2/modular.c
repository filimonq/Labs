#include "modular.h"

int MOD;

void evklid(long long a, long long b, long long *x, long long *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return ;
    }
    long long xl; 
    long long yl;
    evklid(b, a % b, &xl, &yl); // расширенный алг. евклида
    *y = xl - (a / b) * yl;
    *x = yl;
}

long long inverse(long long n, long long modul) // обратное
{
    long long x, y;
    evklid(n, modul, &x, &y);
    return ((x % modul + modul) % modul);
}

long long llpnorm(long long n)
{
    return ((n % MOD + MOD) % MOD);
}

int pnorm(int n)
{
    return ((n % MOD + MOD) % MOD);
}

int padd(int a, int b)
{
    return (llpnorm((long long)a + b));
}

int psub(int a, int b)
{
    return (llpnorm((long long)a - b));
}

int pmul(int a, int b)
{
    return (llpnorm((long long)a * b));
}

int pdiv(int a, int b)
{
    return (llpnorm((long long)a * inverse(llpnorm(b), MOD)));
}