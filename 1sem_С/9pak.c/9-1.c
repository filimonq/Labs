#include <stdio.h>
#include <stdlib.h>

//merges sorted arrays a[0..ak-1] and b[0..bk-1] into
//one sorted array res[0..rk-1], returning rk from function
int merge(const int *a, int ak, const int *b, int bk, int * res)
{  
	int i1 = 0, i2 = 0, i_res = 0;
	while (i1 < ak && i2 < bk)
    {
		if (a[i1] < b[i2])
        {
			res[i_res++] = a[i1++];
        } else
        {
            res[i_res++] = b[i2++];
        }
    }
    while (i1 < ak)
    {
        res[i_res++] = a[i1++];
    }
    while (i2 < bk)
    {
        res[i_res++] = b[i2++];
    }
    return i_res;
}

int main()
{
    FILE *f_in = fopen("input.txt", "rb");
    FILE *f_out = fopen("output.txt", "wb+");

    int N = 0, M = 0;
    fread(&N, sizeof(int), 1, f_in);
    fread(&M, sizeof(int), 1, f_in);
    int * a_arr = malloc(sizeof(int) * N);
    int * b_arr = malloc(sizeof(int) * M);
    int * res_arr = malloc(sizeof(int) * (N + M));
    fread(a_arr, sizeof(int), N, f_in);
    fread(b_arr, sizeof(int), M, f_in);
    int rk = merge(a_arr, N, b_arr, M, res_arr);
    fwrite(res_arr, sizeof(int), rk, f_out);

    free(a_arr);
    free(b_arr);
    free(res_arr);
    fclose(f_in);
    fclose(f_out);
    return 0;
}

