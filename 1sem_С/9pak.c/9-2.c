#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition (int *a, int n, int pivot)
{
    int k_left = 0; // кол-во элементов в левой части
    int * left = malloc(sizeof(int) * n);
    int * right = malloc(sizeof(int) * n);
    int li = 0, ri = 0, flag = 1, k_right = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < pivot)
        {
            left[li++] = a[i];
            k_left++;
        } else if (a[i] > pivot)
        {
            right[ri++] = a[i];
            k_right++;
        } else
        {
            if (flag == 1)
            {
                left[li++] = a[i];
                k_left++;
                flag = 0;
            } else
            {
                right[ri++] = a[i];
                flag = 1;
                k_right++;
            }
        }
    }
    for (int i = 0; i < k_left; i++)
    {
        a[i] = left[i];
    }
    for (int i = 0; i < k_right; i++)
    {   
        a[i + k_left] = right[i];
    }
    return k_left;
}

int main()
{
    FILE *f_in = fopen("input.txt", "rb");
    FILE *f_out = fopen("output.txt", "wb+");

    int N, pivot;
    fread(&N, sizeof(int), 1, f_in);
    fread(&pivot, sizeof(int), 1, f_in);
    int * arr = malloc(sizeof(int) * N);
    fread(arr, sizeof(int), N, f_in);
    int k = partition(arr, N, pivot);
    fwrite(&k, sizeof(int), 1, f_out);
    fwrite(arr, sizeof(int), N, f_out);

    free(arr);
    fclose(f_in);
    fclose(f_out);
    return 0;
}