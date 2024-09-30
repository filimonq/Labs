#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    struct Element *next;
    int value;
} Element;

//тип указателя на функцию, которую можно передавать как callback
typedef void(*callback)(void *ctx, int *value);

void func(void *ctx, int *value)
{
    if (*value % 2 == 0)
    {
        *((int*)ctx) += *value;
    }
}

//здесь ctx –- это контекст, который передаётся в func первым аргументом
//последние два параметра задают массив, по элементам которого нужно пройтись
void arrayForeach(void *ctx, callback func, int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        func(ctx, &arr[i]);
    }
}

void listForeach(void *ctx, callback func, Element *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        func(ctx, &arr -> value);
        arr = arr -> next;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, k = 0, a;
    scanf("%d", &N);
    int arr[101];
    Element *first = malloc(sizeof(Element));
    Element *last = first;
    scanf("%d", &a);
    arr[0] = a;
    first -> value = a;
    first -> next = NULL;
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &a);
        arr[i] = a;
        Element *p = malloc(sizeof(Element));
        p -> next = NULL;
        p -> value = a;
        last -> next = p;
        last = p;
    }
    arrayForeach(&k, func, arr, N);
    printf("%d ", k);
    k = 0;
    listForeach(&k, func, first, N);
    printf("%d", k);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
