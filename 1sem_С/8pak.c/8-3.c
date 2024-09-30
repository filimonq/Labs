#include <stdio.h>
#include <string.h>
#pragma pack(1)

typedef struct file {
    char name[21];
    unsigned long long size;
    char folder;
    unsigned long long time_C;
    unsigned long long time_M;
    char hide_and_seek;
} file;

int main()
{
    FILE *f_in = fopen("input.txt", "rb");
    FILE *f_out = fopen("output.txt", "wb+");
    int N;
    fread(&N, sizeof(int), 1, f_in);
    unsigned long long A, B;
    fread(&A, sizeof(unsigned long long), 1, f_in);
    fread(&B, sizeof(unsigned long long), 1, f_in);
    file arr[1001], curr;
    fread(arr, sizeof(file), N, f_in);

    for (int i = 0; i < N; i++)
    {
        for(int j = 1; j < N; j++)
        {
            if (strcmp(arr[j-1].name, arr[j].name) >= 1)
            {
                curr = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = curr;
            }   
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (arr[i].folder != 1 && arr[i].hide_and_seek != 1 && A <= arr[i].time_C && arr[i].time_M <= B)
        {
            fwrite(arr + i, sizeof(file), 1, f_out);
        }
    }
    fclose(f_in);
    fclose(f_out);
    return 0;
}
