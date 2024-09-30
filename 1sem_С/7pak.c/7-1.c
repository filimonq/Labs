#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Element {
    long long index;
    char mas[8];
} Element;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    Element arr[10001];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %s", &arr[i].index, arr[i].mas);
    }
    Element min;
    long long curr;
    for (int i = 0; i < N; i++)
    {
        min.index = LLONG_MAX;
        for (int j = i; j < N; j++)
        {
            if (arr[j].index < min.index)
            {
                curr = j;
                min = arr[j];
            }
        }
        arr[curr] = arr[i];
        arr[i] = min;
    }
    for (int i = 0; i < N; i++)
    {
        printf("%lld %s\n", arr[i].index, arr[i].mas);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
