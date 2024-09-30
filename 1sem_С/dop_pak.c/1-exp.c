#include <stdio.h>

double taylor(double x)
{
    if (x < 0)
    {
        return 1 / taylor(-x);
    }
    double eps = 1.0E-12;
    double sum = 1;
    double pwr = 1;
    double curr = x / pwr;
    while (eps < curr)
    {
        sum += curr;
        pwr++;
        curr = (curr * x) /  (pwr);
    }
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    double x;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &x);
        x = taylor(x);
        printf("%0.15g\n", x);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}