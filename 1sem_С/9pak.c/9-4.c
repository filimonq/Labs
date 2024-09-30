#include <stdio.h>
#include <stdlib.h>

//merges sorted arrays a[0..ak-1] and b[0..bk-1] into
//one sorted array res[0..rk-1], returning rk from function
void merge(int *res, int l, int mid, int r)
{  
	int i1 = 0, i2 = 0, i_res = l;
    int len_l = mid - l + 1;
    int len_r = r - mid;
    int * a = malloc(sizeof(int) * len_l);
    int * b = malloc(sizeof(int) * len_r);

    for (int i = 0; i < len_l; i++)
    {
        a[i] = res[i + l];
    }
    for (int i = 0; i < len_r; i++)
    {
        b[i] = res[i + mid + 1];
    }

	while (i1 < len_l && i2 < len_r)
    {
		if (a[i1] < b[i2])
        {
			res[i_res++] = a[i1++];
        } else
        {
            res[i_res++] = b[i2++];
        }
    }

    while (i1 < len_l)
    {
        res[i_res++] = a[i1++];
    }
    while (i2 < len_r)
    {
        res[i_res++] = b[i2++];
    }
    free(a);
    free(b);
}
void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (r - l) / 2 + l;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    FILE *f_in = fopen("input.txt", "rb");
    FILE *f_out = fopen("output.txt", "wb+");
    int N;
    fread(&N, sizeof(int), 1, f_in);
    int * arr = malloc(sizeof(int) * N);
    fread(arr, sizeof(int), N, f_in);
    mergeSort(arr, 0, N - 1);
    fwrite(arr, sizeof(int), N, f_out);

    free(arr);
    fclose(f_in);
    fclose(f_out);
    return 0;
}

