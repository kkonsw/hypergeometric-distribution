#include "Computation.h"

double F(double r, int k)
{
    return 1.0 - integral(0.0, r, k);
}

double f(double x, int k)
{
    double result = 0.0;

    if (x <= 0)
    {
        return 0.0;
    }
    else
    {
        result = pow(2.0, (double)(-k)/2.0) * (1.0 / tgamma((double)k/2.0)) * pow(x, (double)k/2.0 - 1.0) * exp(-x/2.0);
        return result;
    }
}

double integral(double a, double b, int k)
{
    double result = 0.0;
    int n = 10000;

    for (int i = 1; i <= n; i++)
    {
        result += (f(a + (b-a)*(double)(i-1)/(double)n, k) + f(a + (b-a)*(double)i/(double)n, k))*(b-a)/(2.0*(double)n);
    }

    return result;
}
