#include <stdio.h>
#include <string.h>

typedef struct Factors {
    int k; //сколько различных простых в разложении
    int primes[32]; //различные простые в порядке возрастания
    int powers[32]; //в какие степени надо эти простые возводить
} Factors;

void Factorize(int X, Factors *res);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int M, x;
    scanf("%d", &M);
    Factors ans;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &x);
        printf("%d =", x);
        Factorize(x, &ans);
        for (int j = 0; j < ans.k; j++)
        {
            printf(" ");
            printf("%d^%d", ans.primes[j], ans.powers[j]);
            if (j != ans.k - 1)
            {
                printf(" *");
            }
        }
        if (ans.k == 0)
        {
            printf(" 1");
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}


