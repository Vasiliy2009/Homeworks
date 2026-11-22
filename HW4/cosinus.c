#include "cosinus.h"
#include <math.h>


double cosinus(double x, int n, double eps) {
    double sum = 0.0;
    double term = 1.0;
    double x_squared= x * x;

    for(int i = 0; i < n; i++) {
        if (fabs(term) < eps)
            break;
        sum += term;
        int next_i = 2 * i + 2;
        term = -term * x_squared / (next_i * (next_i - 1));
    }
    return sum;
}