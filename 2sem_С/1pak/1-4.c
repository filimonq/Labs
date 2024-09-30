#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long T, modul;
    scanf("%lld", &modul);
    scanf("%lld", &T);
    long long n, k;
    long long **C = (long long **) malloc(sizeof(long long*) * 2001);
    for (int i = 0; i < 2001; i++)
    {
        C[i] = (long long*) malloc(sizeof(long long) * (i + 1)); // i + 1?
    }
    for (int i = 0; i < 2001; i++)
    {
	    C[i][0] = C[i][i] = 1;
        // printf("%lld ", C[i][0]);
	    for (int j = 1; j < i; j++)
        {
		    C[i][j] = (C[i-1][j-1] + C[i-1][j]) % modul;
            //printf("%lld ", C[i][j]);
        }
        // printf("%lld", C[i][i]);
        // printf("\n");
    }

    for (int i = 0; i < T; i++)
    {
        scanf("%lld", &n);
        scanf("%lld", &k);
        if (k < 0 || k > n)
        {
            printf("%d\n", 0);
        } else 
        {
            printf("%lld\n", C[n][k]);
        }
    }
    for (int i = 0; i < 2001; i++)
    {
        free(C[i]);
    }
    free(C);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
