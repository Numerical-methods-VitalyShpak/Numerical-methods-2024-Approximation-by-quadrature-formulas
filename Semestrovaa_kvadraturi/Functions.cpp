#include <iostream>
#include <Math.h>
#include <string>
#include <vector>

static double step = 0.4;
static double Limit(double x)
{
    if (x != 0) return (sin(x) / x);
    return 1;//первый замечательный предел
}

static double Tabulate(double x)
{
    double a = x;
    double res = x;
    double q;
    int n = 0;
    do
    {
        q = (-1) * x * x * (2 * n + 1) / ((2 * n + 2) * (2 * n + 3) * (2 * n + 3));
        a *= q;
        res += a;
        n++;
    } while (abs(a) > 0.000001);
    return res;
}

static std::vector<double> Tabulate(std::vector<double> x)
{
    std::vector<double> result;
    for (int i = 0; i < x.size(); i++)
    {
        result.push_back(Tabulate(x[i]));
    }
    return result;
}

static double Left_Rectangle_Method(int N, double x0)
{
    double h = x0 / N;
    double result = 0;
    double x = 0;
    for (int i = 0; i < N; i++)
    {
        result += h * Limit(x);
        x += h;
    }
    return result;
}
static double Right_Rectangle_Method(int N, double x0)
{
    double h = x0 / N;
    double sum = 0;
    double x = h;
    for (int i = 0; i < N; i++)
    {
        sum += h * Limit(x);
        x += h;
    }
    return sum;
}
static double Central_Rectangles_Method(int N, double x0)
{
    double h = x0 / N;
    double sum = 0;
    double x = h / 2;
    for (int i = 0; i < N; i++)
    {
        sum += h * Limit(x);
        x += h;
    }
    return sum;
}

static double Simpson_method(int N, double x0)
{
    double h = x0 / N;
    double sum = 0;
    double x = 0;
    for (int i = 0; i < N; i++)
    {
        sum += (Limit(x) + 4 * Limit(x + h / 2) + Limit(x + h)) * h / 6;
        x += h;
    }
    return sum;
}
static double Gauss_method(int N, double x0)
{
    double h = x0 / N;
    double ad1 = (1 - 1.0 / sqrt(3)) * h / 2;
    double ad2 = (1 + 1.0 / sqrt(3)) * h / 2;
    double sum = 0;
    double x = 0;
    for (int i = 0; i < N; i++)
    {
        sum += (Limit(x + ad1) + Limit(x + ad2)) * h / 2;
        x += h;
    }
    return sum;
}
static void CalculateAndWrite(double x, double y, double (*Integtal_Variant)(int, double))
{
    double lastJ = 0;
    double J = 0;
    int n = 1;
    do
    {
        n *= 2;
        lastJ = J;
        J = Integtal_Variant(n, x);
    } while (abs(lastJ - J) > 0.000001);
    double error = abs(J - y);
    std::cout << "|| " << x << " \t|| " << y << " \t|| " << J << " \t|| " << error << " \t|| " << n << "\n";
}