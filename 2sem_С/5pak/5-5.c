#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Color {
    WHITE,
    GRAY,
    BLACK
} Color;

typedef struct Cycle {
    int *arr;
    int cnt;           
} Cycle;

typedef struct Vector {
    int *arr;
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //на сколько элементов выделено место в блоке памяти arr (capacity)
} Vector;

Vector *mas;
int *parents;
Color *mark;
int flag = 0;

void init(int N, int M)
{
    mas = (Vector*) calloc(N + 1, sizeof(Vector));
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
    }
}

int dfs_mark(int v, int parent, int N) // int 
{
    if (flag == 1)
    {
        return 1;
    }
    mark[v] = GRAY;
    parents[v] = parent;
    int u = 0;
    Cycle cycle;
    for (int i = 0; i < mas[v].cnt; i++)
    {
        u = mas[v].arr[i];
        if (mark[u] == WHITE)
        {
            parents[u] = v;
            dfs_mark(u, v, N); 
        } else if (mark[u] == GRAY && !flag) // нашли ПЕРВЫЙ цикл
        {
            flag = 1;
            cycle.arr = calloc(N + 1, sizeof(int)); // под хранение цикла
            cycle.cnt = 0;
            cycle.arr[cycle.cnt++] = u;
            for (int curr = v; curr != u; curr = parents[curr])  // проходимся по всем предкам v пока не встретим u
            {
                cycle.arr[cycle.cnt++] = curr; 
            }
            
            printf("%d\n", cycle.cnt);
            for(int i = cycle.cnt - 1; i >= 0; i--)
            {
                printf("%d ", cycle.arr[i]);
            }
            printf("\n");
            free(cycle.arr);
            return 1;
        }
    }
    mark[v] = BLACK;
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M; // N - вершины, M - ребра
    scanf("%d %d", &N, &M); 
    init(N, M);
    mark = (Color*) calloc(N + 1, sizeof(Color));
    parents = (int*) calloc(N + 1, sizeof(int));

    for (int i = 1; i <= N; i++)
    {
        mark[i] = WHITE;
    }
    for (int i = 1; i <= N; i++)
    {
        if (flag == 1)
        {
            break;
        }
        if (mark[i] == WHITE)
        {   
            dfs_mark(i, -1, N);
        }
    }
    if (flag == 0)
    {
        printf("-1\n");
    }
    for (int i = 0; i <= N; i++)
    {
        free(mas[i].arr);
    }
    fclose(stdin);
    fclose(stdout);
    free(mark);
    free(mas);
    free(parents);
    return 0;
}
