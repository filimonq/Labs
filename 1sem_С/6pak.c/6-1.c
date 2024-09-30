#include <stdio.h>
#include <stdlib.h>
typedef struct Element {
    double k;
    int index;
} Element;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, F;
    scanf("%d %d", &N, &F);
    Element *arr = malloc(sizeof(Element) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf %d",&arr[i].k, &arr[i].index);  
    }
    for (int i = 0; i < N; i++)
    {
        printf("%0.3lf\n", arr[F].k);
        F = arr[F].index;
    }
    fclose(stdin);
    fclose(stdout);
    free(arr);
    return 0;
}