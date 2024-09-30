#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
    int *arr;
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //на сколько элементов выделено место в блоке памяти arr (capacity)
} Vector;

typedef enum Color {
    WHITE,
    GRAY,
    BLACK
} Color;

Vector *mas;
Color *mark;
int *ans;
int tout = 0;
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

void dfs_mark(int v) 
{
    mark[v] = GRAY;
    int u;
    for (int i = 0; i < mas[v].cnt; i++)
    {
        u = mas[v].arr[i];
        if (mark[u] == WHITE)
        {
            dfs_mark(u); 
        } else if (mark[u] == GRAY && !flag)
        {
            flag = 1;
            printf("NO\n");
            return ;
        }
    } 
    mark[v] = BLACK;
    ans[tout++] = v; // прошли всех чайлдиков, теперь добавляем
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    init(n, m);
    mark = (Color*) calloc(n + 1, sizeof(Color));
    ans = (int*) calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == WHITE) 
        {   
            dfs_mark(i); //
        }
    }

    int *ans_num = (int*) calloc(n + 1, sizeof(int));
    int a = 0;
    for(int i = tout; i >= 0; i--) 
    {
        ans_num[ans[i]] = a++; // получаем номер вершин
        //printf("%d %d %d\n", i, ans_num[ans[i]], ans[i]);
    }
    if (flag == 0)
    {
        printf("YES\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", ans_num[i]);
        }
    }
    
    fclose(stdin);
    fclose(stdout);
    free(mark);
    free(mas);
    free(ans);
    return 0;
}