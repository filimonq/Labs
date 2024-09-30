#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return *(int *)a - *(int *)b;
}

typedef struct helper {
    int to, from, ind;
} helper; 

int compare2(const void *a, const void *b)
{
    helper *helperA = (helper *)a;
    helper *helperB = (helper *)b;

    if (helperA->to != helperB->to) 
    {
        return helperA->to - helperB->to;
    } else 
    {
        return helperA->from - helperB->from;
    }
}

typedef struct {
    int to; 
    int index; // сохраним суда индекс из input для вывода
    int count; // кратные рёбра
} Edge;

typedef struct Vector {
    Edge *arr;
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //на сколько элементов выделено место в блоке памяти arr (capacity)
} Vector;

Vector *mas;
int *level, *up, *sharnir;
int d = 1;

void init(int N, int M)
{
    helper *edgesCount = (helper*) calloc(M + 1, sizeof(helper)); // кратные ребра

    level = (int*) calloc(N + 1, sizeof(int)); // глубина вершин
    up = (int*) calloc(N + 1, sizeof(int)); // функция верхнего
    mas = (Vector*) calloc(N + 1, sizeof(Vector));
    sharnir = (int*) calloc(N + 1, sizeof(int)); // точки сочленения
    int u, v;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        edgesCount[i].to = (u < v ? u : v);
        edgesCount[i].from = (u < v ? v : u);
        edgesCount[i].ind = i;
    }

    qsort(edgesCount, M, sizeof(helper), compare2);

    for (int i = 0; i <= N; i++)
    {
        mas[i].cnt = 0;
        mas[i].arr = NULL;
    }
    for (int i = 0; i < M; i++)
    {
        u = edgesCount[i].to;
        v = edgesCount[i].from;
        if (mas[u].arr != NULL && mas[u].cnt - 1 >= 0 && mas[u].arr[mas[u].cnt - 1].to == v)
        {
            mas[u].arr[mas[u].cnt - 1].count++;
            mas[v].arr[mas[v].cnt - 1].count++;
        } else
        {
            if (u == v)
            {
                continue;
            }
            if (mas[u].cnt == 0)
            {
                mas[u].cap = 2;
                mas[u].arr = calloc(mas[u].cap, sizeof(Edge));
            }
            if (mas[u].cap >= mas[u].cnt + 2) // влезает 
            {
                mas[u].arr[mas[u].cnt].to = v;
                mas[u].arr[mas[u].cnt].index = edgesCount[i].ind + 1;
                mas[u].arr[mas[u].cnt].count = 1;
                mas[u].cnt++;
            } else
            {
                mas[u].cap *= 2;
                mas[u].arr = realloc(mas[u].arr, mas[u].cap * sizeof(Edge));
                mas[u].arr[mas[u].cnt].to = v;
                mas[u].arr[mas[u].cnt].index = edgesCount[i].ind + 1;
                mas[u].arr[mas[u].cnt].count = 1;
                mas[u].cnt++;
            }
            if (mas[v].cnt == 0)
            {
                mas[v].cap = 2;
                mas[v].arr = calloc(mas[v].cap, sizeof(Edge));
            }
            if (mas[v].cap >= mas[v].cnt + 2) // влезает 
            {
                mas[v].arr[mas[v].cnt].to = u;
                mas[v].arr[mas[v].cnt].index = edgesCount[i].ind + 1;
                mas[v].arr[mas[v].cnt].count = 1;
                mas[v].cnt++;
            } else
            {
                mas[v].cap *= 2;
                mas[v].arr = realloc(mas[v].arr, mas[v].cap * sizeof(Edge));
                mas[v].arr[mas[v].cnt].to = u;
                mas[v].arr[mas[v].cnt].index = edgesCount[i].ind + 1;
                mas[v].arr[mas[v].cnt].count = 1;
                mas[v].cnt++;
            }
        }
    }
}

void dfs(int v, int p) 
{
    level[v] = d++;
    up[v] = level[v];
    int children = 0;
    for (int i = 0; i < mas[v].cnt; i++) 
    {
        int u = mas[v].arr[i].to;
        if (u == p) 
        {   
            continue;
        }
        if (level[u] == 0) 
        {
            children++;
            dfs(u, v);
            up[v] = (up[u] < up[v]) ? up[u] : up[v];
            if (up[u] >= level[v] && p != -1) // точка сочленения И не корень
            { 
                sharnir[v] = 1;
            }
        } else 
        {
            up[v] = (level[u] < up[v]) ? level[u] : up[v];
        }
    }
    if (p == -1 && children > 1) // корневая вершина, у которой больше 1 сына
    { 
        sharnir[v] = 1;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    init(n, m);
    
    for (int i = 1; i <= n; i++)
    {
        if (level[i] == 0)
        {
            dfs(i, -1);
        }
    }

    int countSharnirs = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (sharnir[i] == 1)
        {
            countSharnirs++;
        } 
    }

    printf("%d\n", countSharnirs);
    for (int i = 1; i <= n; i++) 
    {
        if (sharnir[i] == 1)
        {
            printf("%d ", i);
        }
    }

    for (int i = 1; i <= n; i++) 
    {
        free(mas[i].arr);
    }
    free(mas);
    free(level);
    free(up);
    fclose(stdin);
    fclose(stdout);
    free(sharnir);
    return 0;
}
