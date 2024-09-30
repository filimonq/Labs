#include <stdio.h>
#include <stdlib.h>

typedef struct coo {
    int y, x;
} coo;

char labyrinth[101][101]; // лабиринт
int steps[101][101]; // за сколько шагов дойдем от S до [i][j]

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

void bfs(coo S, coo F, int M, int N) // void | int
{
    coo *queue = (coo*) calloc((M * N), sizeof(coo));
    coo curr;
    int qStart = 0, qEnd = 0; // начало и конец очереди
    int ans = -1; // путь не найден
    steps[S.y][S.x] = 0; //  0 | 1
    queue[qEnd++] = S; // добавляем начальный элемент в очередь 
    int newX, newY;
    while (qStart < qEnd)
    {
        curr = queue[qStart++]; // текущая клетка
        if (curr.y == F.y && curr.x == F.x) 
        {
            ans = steps[curr.y][curr.x];
            break;
        }
        newY = curr.y + 1;
        newX = curr.x;
        // елси новая позиция находится в пределах лабиринта, не является стеной и не была посещена
        if ((newY >= 0 && newY < M && newX >= 0 && newX < N) && labyrinth[newY][newX] != 'X' && steps[newY][newX] == 0) {
            queue[qEnd].y = newY; // добавляем поз в конец очереди
            queue[qEnd++].x = newX;
            steps[newY][newX] = steps[curr.y][curr.x] + 1; // кол-во шагов до этой позиции
        }

        newY = curr.y;
        newX = curr.x + 1;
        if ((newY >= 0 && newY < M && newX >= 0 && newX < N) && labyrinth[newY][newX] != 'X' && steps[newY][newX] == 0) {
            queue[qEnd].y = newY;
            queue[qEnd++].x = newX;
            steps[newY][newX] = steps[curr.y][curr.x] + 1;
        }

        newY = curr.y - 1;
        newX = curr.x;
        if ((newY >= 0 && newY < M && newX >= 0 && newX < N) && labyrinth[newY][newX] != 'X' && steps[newY][newX] == 0) {
            queue[qEnd].y = newY;
            queue[qEnd++].x = newX;
            steps[newY][newX] = steps[curr.y][curr.x] + 1; 
        }
        
        newY = curr.y;
        newX = curr.x - 1; 
        if ((newY >= 0 && newY < M && newX >= 0 && newX < N) && labyrinth[newY][newX] != 'X' && steps[newY][newX] == 0) {
            queue[qEnd].y = newY;
            queue[qEnd++].x = newX;
            steps[newY][newX] = steps[curr.y][curr.x] + 1; //
        }

    }
    printf("%d\n", ans); 
    free(queue);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    scanf("%d %d\n", &M, &N);
    for (int i = 0; i < M; i++)
    {  
        fgets(labyrinth[i], 102, stdin); // fgets
        for (int j = 0; j < N; j++)
        { 
            steps[i][j] = 0;
        }
    }
    coo start, finish;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (labyrinth[i][j] == 'S')
            {
                start.y = i;
                start.x = j;                
            }
            if (labyrinth[i][j] == 'F')
            {
                finish.y = i;
                finish.x = j; 
            }
        }
    }
    bfs(start, finish, M, N);

    fclose(stdin);
    fclose(stdout);
    return 0;
}