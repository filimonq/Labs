#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    long long ans, modul, c1, c2;
    if (argc == 1)
    {
        fprintf(stderr, "No parameters specified.");
        return 13;
    }
    if (argc > 4)
    {
        if (strcmp(argv[1], "-m") == 0)
        {
            sscanf(argv[2], "%lld", &modul);
            sscanf(argv[4], "%lld", &c1);
            sscanf(argv[5], "%lld", &c2);
            if (strcmp(argv[3], "add") == 0)
            {
                ans = (c1 + c2) % modul;
                if (ans < 0)
                {
                    ans = ans + modul;
                }
            } else if (strcmp(argv[3], "sub") == 0)
            {
                ans = (c1 - c2) % modul;
                if (ans < 0)
                {
                    ans = ans + modul;
                }
            } else 
            {
                ans = (c1 * c2) % modul;
                if (ans < 0)
                {
                    ans = ans + modul;
                }
            }
        } else 
        {
            sscanf(argv[5], "%lld", &modul);
            sscanf(argv[2], "%lld", &c1);
            sscanf(argv[3], "%lld", &c2);
            if (strcmp(argv[1], "add") == 0)
            {
                ans = (c1 + c2) % modul;
                if (ans < 0)
                {
                    ans = ans + modul;
                }
            } else if (strcmp(argv[1], "sub") == 0)
            {
                ans = (c1 - c2) % modul;
                if (ans < 0)
                {
                    ans = ans + modul;
                }
            } else 
            {
                ans = (c1 * c2) % modul;
                if (ans < 0)
                {
                    ans = ans + modul;
                }
            }           
        }
    } else
    {
        sscanf(argv[2], "%lld", &c1);
        sscanf(argv[3], "%lld", &c2);
        if (strcmp(argv[1], "add") == 0)
        {
            ans = (c1 + c2);
        } else if (strcmp(argv[1], "sub") == 0)
        {
            ans = (c1 - c2);
        } else 
        {
            ans = (c1 * c2);
        }    
    }
    if (argc != 1)
    {
       printf("%lld\n", ans);
    }
    return 0;
}
// прописываем путь, gcc 1-1.c, ./a.out "данные"