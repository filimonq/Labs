#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f_in = fopen("input.txt", "rb");
    FILE *f_out = fopen("output.txt", "wb+");
    printf("{");
    int doc_size;
    fread(&doc_size, sizeof(int), 1, f_in);
    char t = 1, symbol, byte_bool, byte_null;
    double value = 0;
    int L_size = 0, int32 = 0;
    long long int64 = 0;
    int flag = 0;
    while (fread(&t, sizeof(char), 1, f_in) > 0 && t != 0)
    {
        if (flag == 1)
        {
            printf(",");
        } else
        {
            flag = 1;
        }
        printf("\n");
        char name;
        fread(&name, sizeof(char), 1, f_in);
        printf("    ");
        printf("\"");
        while (name != 0)
        {
            printf("%c", name);
            fread(&name, sizeof(char), 1, f_in);
        }
        printf("\": ");
        switch(t)
        {
            case 1:
                fread(&value, sizeof(double), 1, f_in);
                printf("%0.15g", value);
                break;
            case 2:
                fread(&L_size, sizeof(int), 1, f_in);
                printf("\"");
                for (int i = 0; i < L_size - 1; i++)
                {
                    fread(&symbol, sizeof(char), 1, f_in);
                    printf("%c", symbol);
                }
                fread(&symbol, sizeof(char), 1, f_in);
                printf("\"");
                break;
            case 8:
                fread(&byte_bool, sizeof(char), 1, f_in);
                if (byte_bool == 0)
                {
                    printf("false");
                } else
                {
                    printf("true");
                }
                break;
            case 10:
                // fread(&byte_null, sizeof(char), 1, f_in);
                printf("null");
                break;
            case 16:
                fread(&int32, sizeof(int), 1, f_in);
                printf("%d", int32);
                break;
            case 18:
                fread(&int64, sizeof(long long), 1, f_in);
                printf("%lld", int64);
                break;
        }
    }
    printf("\n");
    printf("}\n");
    fclose(f_in);
    fclose(f_out);
    return 0;
}