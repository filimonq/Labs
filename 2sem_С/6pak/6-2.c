#include <stdio.h>
#include <stdlib.h>

void NumberOfSplits(long long *res, int N)
{
    res[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            res[j] = (res[j] + res[j - i]) % 1000000007;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    long long *res = (long long*) calloc(N + 1, sizeof(long long));
    NumberOfSplits(res, N);
    res[N] %= 1000000007;
    printf("%lld", res[N]);
    free(res);
    return 0;
}