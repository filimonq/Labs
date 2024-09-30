#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n, m, p, k; // n - пункты, m - дороги,
// p - запросы на min путь, k - запросы на min время
int **Dmatrix;
int **I;
void floyd_warshall()
{
    for (int w = 1; w <= n; w++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                if (Dmatrix[u][w] < INT_MAX && Dmatrix[w][v] < INT_MAX
                && Dmatrix[u][v] > Dmatrix[u][w] + Dmatrix[w][v]) 
                {
                    Dmatrix[u][v] = Dmatrix[u][w] + Dmatrix[w][v];
                    I[u][v] = I[u][w];
                }
            }   
        }
    }
}

void printPath(int u, int v)
{
    int path[301] = {0};
    int path_size = 0;
    path[0] = u;
    path_size++;
    while (u != v)
    {
        u = I[u][v];
        path[path_size++] = u; 
    }
    printf(" %d ", path_size);
    for (int i = 0; i < path_size; i++)
    {
        printf(" %d", path[i]);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d %d", &n, &m, &p, &k);
    Dmatrix = (int**) calloc(n + 1, sizeof(int*));
    I = (int**) calloc(n + 1, sizeof(int*));
    for (int i = 0; i <= n; i++) 
    {
        Dmatrix[i] = (int*) calloc(n + 1, sizeof(int));
        I[i] = (int*) calloc(n + 1, sizeof(int));
        for (int j = 0; j <= n; j++) 
        {
            if (i == j)
            {
                Dmatrix[i][j] = 0;
            } else
            {
                Dmatrix[i][j] = INT_MAX;
            }
            I[i][j] = -1;
        }
    }

    int u, v, weight;
    for (int i = 0; i < m; i++) 
    {
        scanf("%d %d %d", &u, &v, &weight);
        if (Dmatrix[u][v] > weight)
        {
            Dmatrix[u][v] = weight;
        }
        if (Dmatrix[v][u] > weight)
        {
            Dmatrix[v][u] = weight;
        }
        I[u][v] = v; // лучший путь - это прямой путь
        I[v][u] = u;
    }

    //
    floyd_warshall();
    //

    for (int i = 0; i < p; i++) // запросы на мин путь
    {
        scanf("%d %d", &u, &v);
        printf("%d ", Dmatrix[u][v]);
        printPath(u, v);
        printf("\n");
    }

    for (int i = 0; i < k; i++) // запросы на мин время
    {
        scanf("%d %d", &u, &v);
        printf("%d\n", Dmatrix[u][v]);
    }

    for (int i = 0; i < n; i++) 
    {
        free(Dmatrix[i]);
        free(I[i]);
    }
    free(I);
    free(Dmatrix);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
