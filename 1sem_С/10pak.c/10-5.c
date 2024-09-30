#include <stdio.h>
#include <string.h>

double modul(double x)
{
    if (x < 0)
        x = -x;
    return x;
}
double factorial(double x)
{
    double sum = 1;
    for (int i = 2; i <= x; i++)
    {
        sum = sum * i;
    }
    return sum;
}

double power(double x, int pwr)
{
    double sum = 1;
    for (int i = 0; i < pwr; i++)
    {
        sum = sum * x;
    }
    return sum;
}

double taylor(double x)
{
    double eps = 1.0E-12;
    double sum = x;
    double pwr = 1;
    double curr = (power(-1, pwr) * power(x, pwr * 2 + 1)) / (factorial(2 * pwr + 1));
    while (eps < modul(curr))
    {
        sum += curr;
        pwr++;
        curr = ((power(-1, pwr) * power(x, pwr * 2 + 1)) / factorial(2 * pwr + 1));
    }
    return sum;
}

int main()    
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    double x = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &x);
        ans = taylor(x);
        printf("%0.15lf\n", ans);
    }
    return 0;
}
