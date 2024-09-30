#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
    int *arr;
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //на сколько элементов выделено место в блоке памяти arr (capacity)
} Vector;

Vector *mas;
Vector* masT;
int *visited;
int *vOut; // порядок выхода всех вершин
int *ans;
int ind = 0;

void init(int N, int M)
{
    mas = (Vector*) calloc(N + 1, sizeof(Vector));
    masT = (Vector*) calloc(N + 1, sizeof(Vector));
    int u, v;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        if (mas[u].cnt == 0)
        {
            mas[u].cap = 2;
            mas[u].arr = calloc(mas[u].cap, sizeof(int));
        }
        if (mas[u].cap >= mas[u].cnt + 1) // влезает 
        {
            mas[u].arr[mas[u].cnt] = v;
            mas[u].cnt++;
        } else
        {
            mas[u].cap *= 2;
            mas[u].arr = realloc(mas[u].arr, mas[u].cap * sizeof(int));
            mas[u].arr[mas[u].cnt] = v;
            mas[u].cnt++;
        }

        // разворачиваем ребра
        if (masT[v].cnt == 0)
        {
            masT[v].cap = 2;
            masT[v].arr = calloc(masT[v].cap, sizeof(int));
        }
        if (masT[v].cap >= masT[v].cnt + 1) // влезает 
        {
            masT[v].arr[masT[v].cnt] = u;
            masT[v].cnt++;
        } else
        {
            masT[v].cap *= 2;
            masT[v].arr = realloc(masT[v].arr, masT[v].cap * sizeof(int));
            masT[v].arr[masT[v].cnt] = u;
            masT[v].cnt++;
        }
    }
}

void dfs1(int v)
{
    visited[v] = 1;
    for (int i = 0; i < mas[v].cnt; i++)
    {
        int u = mas[v].arr[i];
        if (visited[u] == 0)
        {
            dfs1(u);
        }
    }
    vOut[ind++] = v;
}

void dfs2(int v, int count)
{
    ans[v] = count; // номер компоненты связности
    for (int i = 0; i < masT[v].cnt; i++)
    {
        int u = masT[v].arr[i];
        if (ans[u] == 0)
        {
            dfs2(u, count);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    visited = (int*) calloc(n + 1, sizeof(int));
    vOut = (int*) calloc(n + 1, sizeof(int));
    ans = (int*) calloc(n + 1, sizeof(int));
    
    init(n, m);
    // первый dfs
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs1(i);
        }
    }

    // обратный dfs
    int count = 0;
    for (int i = ind - 1; i >= 0; i--)
    {
        if (ans[vOut[i]] == 0)
        {
            count++;
            dfs2(vOut[i], count);
        }
    }

    printf("%d\n", count);
    for (int i = 1; i <= n; i++) 
    {
        printf("%d ", ans[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        free(mas[i].arr);
        free(masT[i].arr);
    }
    free(mas);
    free(masT);
    free(ans);
    free(visited);
    free(vOut);
    fclose(stdin);
    fclose(stdout);
    return 0;
}