#include <stdio.h>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unsigned long long arr[30001];
    int N, k = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%llx", &arr[i]);
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (! (arr[i] & arr[j]))
            {
                k++;
            }
        }
    }
    printf("%d", k);
    fclose(stdin);
    fclose(stdout);
    return 0;
}