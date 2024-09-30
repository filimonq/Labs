// производная, потом в квадрат,
// потом прибавляем sum = x + y + z, корень(sum)
// интеграл по симпсону
#include <stdio.h>
#include <math.h>

double derivative(double *c, double t, double l)
{
    return (c[1] + 2 * c[2]*(t-l) + 3 * c[3]*(pow(t-l, 2)));
}

double helper(double *c_x, double *c_y, double *c_z, double t, double l)
{
    double res = 0;
    res += pow(derivative(c_x, t, l), 2);
    res += pow(derivative(c_y, t, l), 2);  
    res += pow(derivative(c_z, t, l), 2); 
    return sqrt(res);
}

double Simpson(double l, double r, double *c_x, double *c_y, double *c_z)
{
    int n = 1000;
    double h = (r - l) / n;
    double res = helper(c_x, c_y, c_z, l, l) + helper(c_x, c_y, c_z, r, l);
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1)
        {
            res += 4 * helper(c_x, c_y, c_z, l + h * i, l);
        } else
        {
            res += 2 * helper(c_x, c_y, c_z, l + h * i, l);
        }
    }
    return res * (h / 3);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    double l, r, t;
    double c_x[4], c_y[4], c_z[4];
    double x = 0, y = 0, z = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
       scanf("%lf %lf", &l, &r);
       scanf("%lf %lf %lf %lf", &c_x[0], &c_x[1], &c_x[2], &c_x[3]);
       scanf("%lf %lf %lf %lf", &c_y[0], &c_y[1], &c_y[2], &c_y[3]);
       scanf("%lf %lf %lf %lf", &c_z[0], &c_z[1], &c_z[2], &c_z[3]);
       ans += Simpson(l, r, c_x, c_y, c_z);
    }
    printf("%0.10lf", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}