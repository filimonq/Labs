#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find(int index, int arr[], int N)
{
    int min = 0, mid = 0, max = N - 1;
    while (max - min > 1) 
    {
        mid = (min + max) / 2;
        if (index < arr[mid])
            max = mid;
        else
            min = mid;
    }
    if (abs(index - arr[min]) > abs(index - arr[max]))
    {
        printf("%d %d\n", max, abs(index - arr[max]));
    } else
    {
        printf("%d %d\n", min, abs(index - arr[min]));
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, Q;
	scanf("%d", &N);
	int A[200001];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	scanf("%d", &Q);
    int y;
	for (int i = 0; i < Q; i++)
	{
        scanf("%d", &y);
        find(y, A, N);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
