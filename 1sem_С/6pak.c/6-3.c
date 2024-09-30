#include <stdio.h>
#include <stdlib.h>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    int t, k, count = 0;
    char * arr[100001];
    int yadurak = 0;
    char tmp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        scanf("%d", &k);
        if (t == 0)
        {
            arr[yadurak] = malloc((sizeof(char) * (k + 1)));
            scanf("%s", arr[yadurak]);
            yadurak++;
        }
        if (t == 1)
        {
            free(arr[k]);
            arr[k] = NULL;
        }
        if (t == 2)
        {
            printf("%s\n", arr[k]);
        }
        if (t == 3)
        {
            scanf(" %c", &tmp);
            count = 0;
            for (int i = 0; arr[k][i] != 0; i++)
            {
                if (tmp == arr[k][i])
                {
                    count++;
                }
            }
            printf("%d\n", count);
        }
    }
    for (int i = 0; i < yadurak; i++)
    {
        if (arr[i] != NULL)
        {
            free(arr[i]);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}