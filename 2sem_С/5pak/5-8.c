#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum Color {
    WHITE,
    GRAY,
    BLACK
} Color;

typedef struct Request {
    int u;
    int v;
} Request;

typedef struct Edge {
    int to;
    int weight;
} Edge;

typedef struct Vector {
    Edge *arr;
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //на сколько элементов выделено место в блоке памяти arr (capacity)
} Vector;

Vector *mas;

void init(int N, int M)
{
    mas = (Vector*) calloc(N + 1, sizeof(Vector));
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        if (mas[u].cnt == 0)
        {
            mas[u].cap = 2;
            mas[u].arr = calloc(mas[u].cap, sizeof(Vector));
        }
        if (mas[u].cap >= mas[u].cnt + 1) // влезает 
        {
            mas[u].arr[mas[u].cnt].to = v;
            mas[u].arr[mas[u].cnt].weight = w;
            mas[u].cnt++;
        } else
        {
            mas[u].cap *= 2;
            mas[u].arr = realloc(mas[u].arr, mas[u].cap * sizeof(Vector));
            mas[u].arr[mas[u].cnt].to = v;
            mas[u].arr[mas[u].cnt].weight = w;
            mas[u].cnt++;
        }

        // граф неорент.
        if (mas[v].cnt == 0)
        {
            mas[v].cap = 2;
            mas[v].arr = calloc(mas[v].cap, sizeof(Vector));
        }
        if (mas[v].cap >= mas[v].cnt + 1) // влезает 
        {
            mas[v].arr[mas[v].cnt].to = u;
            mas[v].arr[mas[v].cnt].weight = w;
            mas[v].cnt++;
        } else
        {
            mas[v].cap *= 2;
            mas[v].arr = realloc(mas[v].arr, mas[v].cap * sizeof(Vector));
            mas[v].arr[mas[v].cnt].to = u;
            mas[v].arr[mas[v].cnt].weight = w;
            mas[v].cnt++;
        }
    }
}


int n, m, k;
int *Darr, *mark, *parents;
/*
    D[*], mark[*] = +infinity, W
    D[s], mark[s] = 0, G
    while (gray vertex exists):
      u = vertex such that: 1) mark[u] = G
                            2) D[u] = min
      mark[u] = B
      for uv in E:
        if D[v] > D[u] + w(uv):
          D[v], F[v], mark[v] = D[u] + w(uv), u, G
*/

void Dijkstra(int start)
{
    while (1) {
        int u = -1, minDist = INT_MAX;
        for (int i = 1; i <= n; i++) // ищем серую вершину
        {
            if (mark[i] == GRAY && Darr[i] < minDist)
            {
                minDist = Darr[i];
                u = i;
            }
        }
        if (u == -1) // gray vertex !exists
        {   
            break; 
        }
        mark[u] = BLACK;
        for (int i = 0; i < mas[u].cnt; i++)
        {
            int v = mas[u].arr[i].to;
            int w = mas[u].arr[i].weight;
            if (Darr[u] != INT_MAX && Darr[v] > Darr[u] + w)
            {
                Darr[v] = Darr[u] + w;
                parents[v] = u;
                if (mark[v] == WHITE)
                {
                    mark[v] = GRAY;
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    Request *gossipGirls = (Request*) calloc (n + 1, sizeof(Request));
    Darr = (int*) calloc(n + 1, sizeof(int));
    mark = (int*) calloc(n + 1, sizeof(int));
    parents = (int*) calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        Darr[i] = INT_MAX;
        mark[i] = WHITE;
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &gossipGirls[i].u, &gossipGirls[i].v);
    }

    init(n, m);

    for (int i = 0; i < k; i++)
    {
        Darr[gossipGirls[i].u] = 0;
        mark[gossipGirls[i].u] = GRAY;
        Dijkstra(gossipGirls[i].u);
        if (Darr[gossipGirls[i].v] == INT_MAX) 
        {
            printf("NO");
        } else
        {
            int path[3001] = {0};
            path[0] = gossipGirls[i].v;
            int pathlen = 1;
            int now = parents[gossipGirls[i].v];
            while (now != gossipGirls[i].u)
            {
                path[pathlen] = now;
                now = parents[now];
                pathlen++;
            }
            path[pathlen++] = gossipGirls[i].u;
            printf("YES  %d %d ", Darr[gossipGirls[i].v], pathlen);
            for(int j = pathlen - 1; j >= 0; j--)
            {
                printf(" %d", path[j]);
            }
        }
            
        for (int i = 0; i <= n; i++)
        {
            Darr[i] = INT_MAX;
            mark[i] = WHITE;
        }
        printf("\n");
    }
    
    for (int i = 0; i <= n; i++)
    {
        free(mas[i].arr);
    }
    free(parents);
    free(Darr);
    free(gossipGirls);
    free(mark);
    fclose(stdin);
    fclose(stdout);
    return 0;
}