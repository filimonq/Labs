#include <stdio.h>
#include <stdlib.h>

int Query(int l, long long sum, int N);

void Init(const int *arr, int n);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, l;
    long long sum;
    scanf("%d", &N);
    scanf("%d", &M);
    int *A = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    Init(A, N);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %lld", &l, &sum);
        int ans = Query(l, sum, N);
        printf("%d\n", ans);
    }
    free(A);
    fclose(stdin);
    fclose(stdout);
    return 0;
}