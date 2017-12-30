#include <stdio.h>

double exponentiate(double base, int exponent);

int main(int argc, char const *argv[])
{
    /* code */
    printf("Please insert the base: \n");
    double base = 0;
    scanf("%lf", &base);
    printf("Please insert the number of exponent: \n");
    int exponent = 0;
    scanf("%d", &exponent);
    printf("%f\n", exponentiate(base, exponent));
    return 0;
}

double exponentiate(double base, int exponent)
{
    if (exponent < 0)
        return exponentiate(1.0 / base, -exponent);
    else if (exponent == 0)
        return 1;
    else if (exponent == 1)
        return base;
    else if (exponent % 2 == 0)
        return exponentiate(base * base, exponent / 2);
    else
        return base * exponentiate(base * base, (exponent - 1) / 2);
}

// double exponentiate(double base, int exponent)
// {
//     if (exponent < 0)
//         return exponentiate(1.0 / base, -exponent);
//     double result = 1;
//     int remainder = 0;
//     while (exponent != 0)
//     {
//         remainder = exponent % 2;
//         exponent = exponent / 2;
//         if (remainder == 1)
//             result *= base;
//         base *= base;
//     }
//     return result;
// }