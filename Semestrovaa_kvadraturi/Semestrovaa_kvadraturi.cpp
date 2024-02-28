#define M_PI 3.14159265358979323846
#include <iostream>
#include <Math.h>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <iomanip> // Для использования setw
#include "Functions.cpp"

int main()
{
    std::vector<double> x(11);
    std::vector<double> y(11);
    x[0] = 0;
    y[0] = Tabulate(x[0]);
    for (int i = 1; i < 11; i++)
    {
        double number = x[i - 1] + step;
        double scaledNumber = number * std::pow(10, 1);
        double roundedScaledNumber = std::round(scaledNumber);
        x[i] = roundedScaledNumber / std::pow(10, 1);
        y[i] = Tabulate(x[i]);
    }
    std::cout << "The value of the integral in nodes\n\n";
    std::cout << "---------------------\n";
    for (int i = 1; i < 11; i++)//вычисление интегралов
    {
        std::cout << "|| " << x[i] << " \t|| " << y[i] << "\n";
    }
    std::cout << "---------------------\n\n\n";
    std::cout << ("The formula of the left rectangles") << "\n\n";
    std::cout << "|| x_i" << "\t|| J_0" << "\t        || J_n" << "\t        || J_0 - J_n" << "\t|| N\n";
    std::cout << "-------------------------------------------------------------------\n";
    for (int i = 1; i < 11; i++)
    {
        CalculateAndWrite(x[i], y[i], Left_Rectangle_Method);
    }
    std::cout << "-------------------------------------------------------------------\n\n\n";
    std::cout << ("The formula of the right rectangles") << "\n\n";
    std::cout << "|| x_i" << "\t|| J_0" << "\t        || J_n" << "\t        || J_0 - J_n" << "\t|| N\n";
    std::cout << "-------------------------------------------------------------------\n";
    for (int i = 1; i < 11; i++)
    {
        CalculateAndWrite(x[i], y[i], Right_Rectangle_Method);
    }
    std::cout << "-------------------------------------------------------------------\n\n\n";
    std::cout << ("The formula of the central rectangles") << "\n\n";
    std::cout << "|| x_i" << "\t|| J_0" << "\t        || J_n" << "\t        || J_0 - J_n" << "\t|| N\n";
    std::cout << "-------------------------------------------------------------------\n";
    for (int i = 1; i < 11; i++)
    {
        CalculateAndWrite(x[i], y[i], Central_Rectangles_Method);
    }
    std::cout << "-------------------------------------------------------------------\n\n\n";
   
    std::cout << ("Simpson's Formula") << "\n\n";
    std::cout << "|| x_i" << "\t|| J_0" << "\t        || J_n" << "\t        || J_0 - J_n" << "\t|| N\n";
    std::cout << "-------------------------------------------------------------------\n";
    for (int i = 1; i < 11; i++)
    {
        CalculateAndWrite(x[i], y[i], Simpson_method);
    }
    std::cout << "-------------------------------------------------------------------\n\n\n";
    std::cout << ("The Gauss method") << "\n\n";
    std::cout << "|| x_i" << "\t|| J_0" << "\t        || J_n" << "\t        || J_0 - J_n" << "\t|| N\n";
    std::cout << "-------------------------------------------------------------------\n";
    for (int i = 1; i < 11; i++)
    {
        CalculateAndWrite(x[i], y[i], Gauss_method);
    }
    std::cout << "-------------------------------------------------------------------\n\n\n";

    return 1;
}
