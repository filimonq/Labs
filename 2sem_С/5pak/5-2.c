#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int *arr;
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //на сколько элементов выделено место в блоке памяти arr (capacity)
} Vector;

Vector *mas;

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
/*
BFS(v0)
visited[*] = false
visited[v0] = true
queue.enqueue(v0)
while !queue.empty()
    v = queue.dequeue()
        for vu ∈ E
            if !visited[u]
                visited[u] = true
                queue.enqueue(u)
*/

void bfs(int start, int N, int M, int *minEdgeCount)
{
    minEdgeCount[start] = 0;
    int *queue = (int*) calloc((M + N), sizeof(int));
    int qStart = 0, qEnd = 0; // начало и конец очереди
    queue[qEnd++] = start; // добавляем начальный элемент в очередь 
    while(qStart < qEnd) // пока очередь не пуста
    {
        int curr = queue[qStart++]; // текущая вершина
        for(int i = 0; i < mas[curr].cnt; i++) // все соседи curr
        {
            int next = mas[curr].arr[i];
            if(minEdgeCount[next] == -1) // вершина не посещена
            {
                minEdgeCount[next] = minEdgeCount[curr] + 1;
                queue[qEnd++] = next; // добавляем вершину в очередь
            }
        }
    }

    free(queue);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    scanf("%d %d", &N, &M); // поменять мб
    init(N, M);
    int *minEdgeCount = (int*) calloc(N + 1, sizeof(int));
    for (int i = 1; i <= N; i++)
    {
        minEdgeCount[i] = -1;
    }
    
    bfs(1, N, M, minEdgeCount);

    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", minEdgeCount[i]);
    }
    
    for (int i = 0; i <= N; i++)
    {
        free(mas[i].arr);
    }

    fclose(stdin);
    fclose(stdout);
    free(minEdgeCount);
    free(mas);
    return 0;
}