#include <stdio.h>
#include <stdlib.h>
#define SIZE 111111

typedef struct Vector {
    char **arr;         //указатель на массив, выделенный на куче
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //на сколько элементов выделено место в блоке памяти arr  (capacity)
} Vector;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    Vector arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i].cnt = 0;
        arr[i].cap = 0;
    }
    int key = 0;
    for (int i = 0; i < N; i++)
    {
        char *str = malloc(sizeof(char) * 10);
        scanf("%d", &key);
        scanf("%s", str);

        if (arr[key].cap == 0)
        {
            arr[key].arr = malloc(sizeof(char*));
            arr[key].cap = 1;
            arr[key].cnt = 0;
        }
        if (arr[key].cnt == arr[key].cap) 
        {
            arr[key].cap *= 2;
            arr[key].arr = realloc(arr[key].arr, arr[key].cap * sizeof(char*));
        }
        arr[key].arr[arr[key].cnt++] = str;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i].cnt > 0)
        {
            for (int j = 0; j < arr[i].cnt; j++)
            {
                printf("%d %s\n", i, arr[i].arr[j]);
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

