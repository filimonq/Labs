#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); // input output !!!
    int k = 0, N = 0;
    scanf("%d", &N);
    int * arr = malloc(sizeof(int) * N);
    int * res = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int curr = 0;
    mergeSort(arr, 0, N - 1);
    for (int i = 0; i < N; i++)
    {
        curr = arr[i];
        if (curr != arr[i+1])
        {
            res[k++] = curr;
        }
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d\n", res[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}