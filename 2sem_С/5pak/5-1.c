#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char labyrinth[1001][1001]; // лабиринт
int visited[1001][1001];    // посещенные вершины

void dfs(int x, int y, int N)
{
    // проверка, вышли ли мы за пределы лабиринта или попали в стену || посещенное место
    if (x < 0 || x >= N || y < 0 || y >= N || labyrinth[x][y] == '*' || visited[x][y])
        return;
    visited[x][y] = 1;
    // соседние клетки
    if (!visited[x+1][y])
        dfs(x + 1, y, N); // ->
    if (!visited[x-1][y])
        dfs(x - 1, y, N); // <-
    if (!visited[x][y+1])
        dfs(x, y + 1, N); // ↓
    if (!visited[x][y-1])
        dfs(x, y - 1, N); // ↑
}

/*
void dfs(int v)
{
	visited[v] = 1;
	for u in N(v)      // N(v) - все соседи v
	{
		if (!visited[u])
		{
			dfc[u];
		}
	}
}
*/

int main()
{
    int N;
    scanf("%d\n", &N); // возможная ошибка
    
    for (int i = 0; i < N; i++)
    {   //  fgets
        gets(labyrinth[i]); // посимвольно почему-то не работал dfs
        for (int j = 0; j < N; j++)
        { 
            visited[i][j] = 0;
        }
    }
    // ищем вход
    int entrance = 0;
    while (labyrinth[0][entrance] != ' ')
    {
        entrance++; 
    }

    dfs(0, entrance, N); // запускаем поиск в глубину

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {       // непосещена + это пробел = недоступная
            if ((visited[i][j] == 0) && (labyrinth[i][j] == ' ')) 
            {
                ans++;
                dfs(i, j, N);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

