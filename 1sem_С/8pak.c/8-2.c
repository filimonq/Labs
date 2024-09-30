#include <stdio.h>
typedef union big {
    int num;
    char str[4];
} big;
int reverse(int N)
{
    char c;
    big end;
    end.num = N;
    c = end.str[0];
    end.str[0] = end.str[3];
    end.str[3] = c;
    c = end.str[1];
    end.str[1] = end.str[2];
    end.str[2] = c;    
    return end.num;
}
int main()
{
    FILE *f_in = fopen("input.txt", "rb");
    FILE *f_out = fopen("output.txt", "wb");
    int N, flag = 0;
    fread(&N, sizeof(int), 1, f_in); // по умолчанию little endian
    if (!(1 <= N && N <= 10000)) // проверка на big endian
    {
        N = reverse(N);
        flag = 1;
    }
    int sum = 0, curr = 0;
    for (int i = 0; i < N; i++)
    {
        fread(&curr, sizeof(int), 1, f_in);
        if (flag)
        {
            curr = reverse(curr);
        }
        sum += curr;
    }
    if (flag)
    {
        sum = reverse(sum);
    }
    fwrite(&sum, sizeof(int), 1, f_out);
    fclose(f_in);
    fclose(f_out);
    return 0;
}

