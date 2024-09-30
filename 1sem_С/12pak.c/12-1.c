#include <stdio.h>
#include <stdlib.h>

void heapify(int *arr, int N, int k)
{
    int curr = k;                           //        curr         //
    int left = 2 * k + 1;                   //       /    \        //
    int right = 2 * k + 2;                  //    left    right    //
    if (left < N && arr[left] > arr[curr])
    {
        curr = left;
    }
    if (right < N && arr[right] > arr[curr]) 
    {
        curr = right;
    }
    if (curr != k) 
    {
        int tmp = arr[k];
        arr[k] = arr[curr];
        arr[curr] = tmp;
        heapify(arr, N, curr);
    }
}

void HeapSort(int *arr, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
	{ 
        heapify(arr, N, i);  // выносим макс элемент в верх дерева
    }
    for (int i = N - 1; i >= 0; i--)
    {
        int tmp = arr[0]; // меняем макс и мин элементы
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0); // находим наиб. элемент
    }

}

int main()
{
    FILE *f_in = fopen("input.bin", "rb");
    FILE *f_out = fopen("output.bin", "wb");
    int N, k;
    fread(&N, sizeof(int), 1, f_in);
    int arr[500001];
    for (int i = 0; i < N; i++)
    {
        fread(&arr[i], sizeof(int), 1, f_in);
    }
    HeapSort(arr, N);
    fwrite(&arr, sizeof(int), N, f_out);
    fclose(f_in);
    fclose(f_out);
    return 0;
}