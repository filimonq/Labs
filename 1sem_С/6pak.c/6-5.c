#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    struct Element *next;
    char mas[8];
} Element;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Element *arr[1000001] = {0};
    Element *massivchik[1000001] = {0};
    int N, key;
    scanf("%d", &N);
    char str[8];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &key);
        if (arr[key])
        {
            Element *p;
            p = massivchik[key];
            p -> next = malloc(sizeof(Element));
            scanf("%s", p -> next -> mas);
            p -> next -> next = NULL;
            massivchik[key] = p -> next;

        } else
        {
            arr[key] = malloc(sizeof(Element));
            scanf("%s", arr[key] -> mas);
            arr[key] -> next = NULL;
            massivchik[key] = arr[key];
        }
    }
    for (int i = 0; i < 1000001; i++)
    {
        if (arr[i])
        {
            for (Element *p = arr[i]; p; p = p -> next)
            {
                printf("%d %s\n", i, p -> mas);
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
