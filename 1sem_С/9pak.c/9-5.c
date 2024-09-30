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

int main()
{
    FILE *f_in = fopen("input.txt", "rb");
    FILE *f_out = fopen("output.txt", "wb+");
    int N;
    srand(time(0));
    fread(&N, sizeof(int), 1, f_in);
    int * arr = malloc(sizeof(int) * N);
    fread(arr, sizeof(int), N, f_in);
    quickSort(arr, 0, N - 1);
    fwrite(arr, sizeof(int), N, f_out);

    free(arr);
    fclose(f_in);
    fclose(f_out);
    return 0;
}