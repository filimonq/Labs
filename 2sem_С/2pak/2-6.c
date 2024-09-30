#include <stdio.h>
double Function(double x);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int M;
    double x, ans = 0;
    scanf("%d", &M);
    double dx = 0.000000001;
    for (int i = 0; i < M; i++)
    {
        scanf("%lf", &x);
        if (x > 0.9)
        {
            ans = (Function(x) - Function(x - dx)) / dx;
        } else
        {
            ans = (Function(x + dx) - Function(x)) / dx;
        }
        printf("%lf\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
