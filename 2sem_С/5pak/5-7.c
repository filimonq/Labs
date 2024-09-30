#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int start;
    int finish;
    int weight;
} Edge;

int n, m, k;
int *Darr; // длины путей из 1 вершины
int *pathlen, *parents;
Edge *graph;

void FordBellman()
{
    int u = 0, v = 0;
    for (int i = 1; i < n; i++) // !
    {
        for (int j = 0; j < m; j++) // 
        {
            u = graph[j].start;
            v = graph[j].finish;
            if (Darr[u] != INT_MAX && Darr[v] > Darr[u] + graph[j].weight)
            {
                Darr[v] = Darr[u] + graph[j].weight;
                parents[v] = u;
                pathlen[v] = pathlen[u] + 1;
            } 
        }
    }
}

void printPath(int v)
{
    int *stack = (int*) calloc(n + 1, sizeof(int));
    int top = -1;
    while (v != -1)
    {
        stack[++top] = v;
        v = parents[v];
    }
    while (top >= 0)
    {
        printf(" %d", stack[top--]);
    }
    free(stack);
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &n, &m, &k); // k - друзья володьки
    Darr = (int*) calloc(n + 1, sizeof(int));
    graph = (Edge*) calloc(m + 1, sizeof(Edge));
    parents = (int*) calloc(n + 1, sizeof(int));
    pathlen = (int*) calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        Darr[i] = INT_MAX;
        parents[i] = -1;
        pathlen[i] = 1;
    }
    Darr[1] = 0;
    int *friends;
    friends = (int*) calloc(k, sizeof(int));
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &friends[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &graph[i].start, &graph[i].finish, &graph[i].weight);
    }

    FordBellman();
    
    free(graph);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", Darr[friends[i]]);
        printf(" %d ", pathlen[friends[i]]);
        printPath(friends[i]);
        printf("\n");
    }
    free(Darr);
    free(parents);
    free(pathlen);
    free(friends);
    fclose(stdin);
    fclose(stdout);
    return 0;
}