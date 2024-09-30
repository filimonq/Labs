#include <stdio.h>
#include <stdlib.h>

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

long long mult_modul(long long a, long long b, long long modul)
{ 
    long long ans = 0; // фикс переполнения
    a = a % modul;
    b = b % modul;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % modul;
        }
        a = (2 * a) % modul;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k;
    scanf("%d", &k);
    long long* M = (long long*) malloc(sizeof(long long) * k);
    long long* A = (long long*) malloc(sizeof(long long) * k);
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &M[i]);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &A[i]);
    }
    long long mult = 1;
    for (int i = 0; i < k; i++)
    {
        mult *= M[i];
    }
    long long sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += mult_modul(mult_modul(A[i], mult / M[i], mult), inverse(mult / M[i], M[i]), mult);
    }
    sum = sum % mult;
    printf("%lld\n", sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// a - остаток, b - 1/m.i * (П m), c = 1/b (mod m.i)
