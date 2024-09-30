#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, helper = 0;
    scanf("%d", &N);
    int **res = (int**) calloc(N + 1, sizeof(int*));
    for (int i = 0; i <= N; i++)
    {
        res[i] = (int*) calloc(N + 1, sizeof(int));
    }
    for (int sum = N; sum >= 0; sum--)
    {                                                                // [N - sum] - сумма чисел 
        for(int last = 0; last <= N; last++)                         // [last] - максимальное слагаемое разбиения
        {
            if (sum == N)
            {
                res[sum][last] = 1;
            } else
            {
                helper = last < N - sum ? last : N - sum;
                res[sum][last] = 0;
                for (int x = 1; x <= helper; x++)
                {
                    res[sum][last] += res[sum + x][x];
                    res[sum][last] %= 1000000007;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", res[0][N]);
    for (int i = 0; i <= N; i++)
    {
        free(res[i]);
    }
    free(res);
    return 0;
}