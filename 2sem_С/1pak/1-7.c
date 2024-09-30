#include <stdio.h>
#include <stdlib.h>

void swap(double **c1, double **c2) // строчки меняем
{
    double *curr = *c1;
    *c1 = *c2;
    *c2 = curr;
}

void print(double **matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N + 1; j++)
        {
           printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    double **matrix = (double **) malloc(sizeof(double) * N);
    double x = 0;
    for (int i = 0; i < N; i++)
    {
        matrix[i] = (double*) malloc(sizeof(double) * (N + 1));
        for (int j = 0; j < N + 1; j++)
        {
            scanf("%lf", &x);
            matrix[i][j] = x;
        }
    }

    double coef = 0;
    for (int i = 0; i < N; i++) // ступенчатый вид
    {
        if (matrix[i][i] == 0)
        {
            for (int j = i; j < N; j++) // если на [i][i] месте 0 меняем строчки
            {
                if (matrix[j][i] != 0)
                {
                    swap(matrix + j, matrix + i); // (&matrix[j], &matrix[i])
                }
            }
        }
        for (int j = i + 1; j < N; j++)
        {
            coef = matrix[j][i] / matrix[i][i];
            for (int l = 0; l < N + 1; l++)
            {
                matrix[j][l] = matrix[j][l] - matrix[i][l] * coef;
            }
        }
    }
    // можно привести к диагональному виду
    double arr[201];
    double ans = 0;
    double curr = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        ans = matrix[i][N];
        for (int j = i + 1; j < N; j++)
        {
            ans = ans - matrix[i][j] * arr[j];
        }
        arr[i] = ans / matrix[i][i];
    }
    for (int i = 0; i < N; i++)
    {
        printf("%lf\n", arr[i]);
    }
    for (int i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
