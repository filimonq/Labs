#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int A;
    scanf("%d", &A);
    int * arrA = malloc(sizeof(int) * A);
    for (int i = 0; i < A; i++)
    {
        scanf("%d", &arrA[i]);
    }
    int B;
    scanf("%d", &B);
    int * arrB = malloc(sizeof(int) * B);
    for (int i = 0; i < B; i++)
    {
        scanf("%d", &arrB[i]);
    }
    qsort(arrA, A, sizeof(int), cmp);
    qsort(arrB, B, sizeof(int), cmp);
    int max = A > B ? A : B;
    int * res = malloc(sizeof(int) * A);
    int curr = 0, ja = 0, jb = 0;
    for (int i = 0; i < A; i++) // удалить дубликаты
    {
        curr = arrA[i];
        if (curr != arrA[i+1])
        {
           arrA[ja++] = curr;
        }
    }
    for (int i = 0; i < B; i++)
    {
        curr = arrB[i];
        if (curr != arrB[i+1])
        {
            arrB[jb++] = curr;
        }
    }
    /* for (int i = 0; i < ja; i++)
    {
        printf("%d ", arrA[i]);
    }
    printf("\n"); */
    int k = 0, ind_a = 0, ind_b = 0;
    while (ind_a < ja)
    {
        if (arrA[ind_a] != arrB[ind_b] && arrA[ind_a] < arrB[ind_b])
        {
            res[k++] = arrA[ind_a];
        }
        if (arrA[ind_a] < arrB[ind_b])
        {
            ind_a++;
        } else if (arrA[ind_a] > arrB[ind_b])
        {
            ind_b++;
        } else
        { 
            ind_b++;
            ind_a++;
        }
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", res[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}