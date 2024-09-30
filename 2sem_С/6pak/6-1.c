#include <stdio.h>
#include <stdlib.h>

int M, N;
char **board;
int *col;
int *hasV;
int *hasS;
int *hasD;

void print()
{
    for(int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == '?' && col[i] == j)
            {
                printf("X");
            } else
            {
                printf("%c", '.');
            }
        }
        printf("\n");
    }

}

int search(int r)
{
    if (r == M)
    {
        return 1;
    }
    for (int c = 0; c < N; c++)
    {
        if (board[r][c] == '.' || hasV[c] || hasS[r+c] || hasD[r-c+N])
        {
            continue;
        }
        col[r] = c;
        hasV[c] = hasS[r+c] = hasD[r-c+N] = 1;
        if (search(r + 1))
        {
            return 1;
        }
        hasV[c] = hasS[r+c] = hasD[r-c+N] = 0;
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &M, &N);
    board = (char**) calloc(M + 1, sizeof(char*));
    col = (int*) calloc(N + 1, sizeof(int));
    hasV = (int*) calloc(N + 1, sizeof(int));
    hasS = (int*) calloc(2*N + 1, sizeof(int));
    hasD = (int*) calloc(2*N + 1, sizeof(int));

    for (int i = 0; i < M; i++)
    {
        board[i] = (char*) calloc(N + 1, sizeof(char));
        scanf("%s", board[i]);
    }
    if (search(0) == 1)
    {
        printf("YES\n");
        print();
    } else
    {
        printf("NO");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}