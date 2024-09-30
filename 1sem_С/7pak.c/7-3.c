#include <stdio.h>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, P, Q;
    unsigned long long M;
    unsigned long long *xor1, xor2;
    double X = 0, ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d/%d xor %llx", &P, &Q, &M);
        X = ((double)P) / ((double)Q);
        xor1 = (unsigned long long*) & X;
        xor2 = (M) ^ (*xor1);
        ans = *((double*) & xor2); 
        printf("%0.15g\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}