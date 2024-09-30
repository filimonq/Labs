#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Element {
    int next;
    char mas[8];
} Element;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, N, F, Q;
    int operation, index, curr;
    char str[8];
    Element arr[200001];
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &N, &F, &Q);
        for (int j = 0; j < N; j++)
        {
            scanf("%s %d", arr[j].mas, &arr[j].next);
        }
        for (int j = 0; j < Q; j++)
        {
            scanf("%d", &operation);
            if (operation == 0)
            {
                scanf("%d %s", &index, str);
                strcpy(arr[N].mas, str);
                if (index == -1)
                {
                    arr[N].next = F;
                    F = N;
                } else 
                {
                    curr = arr[index].next;
                    arr[index].next = N;
                    arr[N].next = curr;
                }
                printf("%d\n", N);
                N++;
            } else 
            {
                scanf("%d", &index);
                if (index == -1)
                {
                    printf("%s\n", arr[F].mas);
                    F = arr[F].next;
                } else
                {
                    printf("%s\n", arr[arr[index].next].mas);
                    arr[index].next = arr[arr[index].next].next;
                } 
            }
        }
        printf("===\n");
        for (int j = F; j != -1; j = arr[j].next)
        {
            printf("%s\n", arr[j].mas);
        }
        printf("===\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}               