#include <stdio.h>
int main()
{
    FILE *f_in = fopen("input.txt", "rb");
    FILE *f_out = fopen("output.txt", "wb");
    int A, B;
    long long C;
    fread(&A, sizeof(int), 1, f_in);
    fread(&B, sizeof(int), 1, f_in);
    C = ((long long) A + (long long) B);
    if (C % 2 < 0)
    {
        C = C / 2 - 1;
    } else
    {
        C /= 2;
    }
    fwrite(&C, sizeof(int), 1, f_out);
    fclose(f_in);
    fclose(f_out);
    return 0;
}