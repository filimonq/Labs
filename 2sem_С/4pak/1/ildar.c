#include "integerset.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition (int *a, int l, int r) // hoare
{
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    int curr = 0;
    while (1)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        curr = a[i]; 
        a[i] = a[j]; 
        a[j] = curr;
    }
}

void quickSort(int *a, int l, int r)
{
    if (l < r)
    {
        int random = rand() % (r - l) + l;
        int curr = a[l]; 
        a[l] = a[random]; 
        a[random] = curr;
        int ildar = partition(a, l, r);
        quickSort(a, l, ildar);
        quickSort(a, ildar + 1, r); 
    }
}

typedef struct IntegerSet {
    int *arr;
    int n;
} IntegerSet;

IntegerSet *CreateSet(int *arr, int size)
{
    IntegerSet *set = malloc(sizeof(IntegerSet));
    set -> arr = malloc(sizeof(int) * size);
    set -> n = size;
    int *mas = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        mas[i] = arr[i];
    }
    quickSort(mas, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        if (mas[i] == mas[i+1])
        {
            return 0;
        }
    }
    for (int i = 0; i < size; i++)
    {
        set -> arr[i] = mas[i];
    }
    return set;
}   

int IsInSet(IntegerSet *mas, int n)
{
    if (mas == NULL)
    {
        return 0;
    }
    int min = 0;
    int max = (mas -> n) - 1;
    int mid = 0;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (n < mas -> arr[mid])
        {
            max = mid - 1;
        } else if (n > mas -> arr[mid])
        {
            min = mid + 1;
        } else
        {
            return 1;
        }
    }
    return 0;
}

