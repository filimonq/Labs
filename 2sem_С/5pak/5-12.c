#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int start;
    int finish;
    long long weight;
} Edge;

void FordBellman(Edge *graph, long long *Darr, int *mark, int n, int m)
{
    int u = 0, v = 0;
    for (int i = 1; i < n; i++) // !
    {
        for (int j = 0; j < m; j++) // 
        {
            u = graph[j].start;
            v = graph[j].finish;
            if (Darr[u] != LLONG_MAX && Darr[v] > Darr[u] + graph[j].weight)
            {
                Darr[v] = Darr[u] + graph[j].weight;
            } 
        }
    }

    for (int j = 0; j < m; j++) // 
    {
        u = graph[j].start;
        v = graph[j].finish;
        if (Darr[u] != LLONG_MAX && Darr[v] > Darr[u] + graph[j].weight)
        {
            mark[v] = 1;
        } 
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) // 
        {
            u = graph[j].start;
            v = graph[j].finish;
            if (mark[u] == 1)
            {
                mark[v] = 1;
            } 
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, s;
    scanf("%d %d %d", &N, &M, &s);
    long long *Darr = (long long*) calloc(N + 1, sizeof(long long));
    int *mark = (int*) calloc(N + 1, sizeof(int));
    for (int i = 0; i <= N; i++)
    {
        mark[i] = 0;
        Darr[i] = LLONG_MAX;
    }
    Darr[s] = 0;
    Edge *graph = (Edge*) calloc(M + 1, sizeof(Edge));
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %lld", &graph[i].start, &graph[i].finish, &graph[i].weight);
    }
    
    FordBellman(graph, Darr, mark, N, M);
    
    for (int i = 1; i <= N; i++)
    {
        if (Darr[i] == LLONG_MAX)
        {
            printf("*\n");
        } else if (mark[i] == 1)
        {
            printf("-\n");
        } else
        {
            printf("%lld\n", Darr[i]);
        }
    }
    free(graph);
    free(Darr);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
