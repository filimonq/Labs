// бин поиск
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

long long binary_search(long long index, long long arr[], int N)
{
    long long min = -1, Rj = 0, max = N - 1;
    while (min <= max) 
    {
        Rj = (min + max) / 2;
         if (index < arr[Rj])
        {
            max = Rj - 1;
        } else if (index > arr[Rj])
        {
            min = Rj + 1;
        } else if(arr[Rj] == index)
        {
            if (Rj + 1 < N)
            {
                if (arr[Rj+1] == index)
                {
                    min = Rj + 1;
                } else
                {
                    return Rj;
                }
            } else
            {
                return Rj;
            }
        }
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, Q;
    long long A_mas[200001];
	scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A_mas[i]);
    }
    scanf("%d", &Q);
    long long ans = 0, k;
    for (int i = 0; i < Q; i++)
    {
        scanf("%lld", &k);

        k += ans;
        ans = binary_search(k, A_mas, N);  
        printf("%lld\n", ans);      
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}