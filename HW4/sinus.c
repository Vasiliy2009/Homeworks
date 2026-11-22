#include "sinus.h"
#include <math.h>


double sinus(double x, int n, double eps) {
    double sum = 0.0;
    double term = x;
    double x_squared= x * x;

    for(int i = 0; i < n; i++) {
        if (fabs(term) < eps)
            break;
        sum += term;
        int next_i = 2 * i + 3;
        term = -term * x_squared / (next_i * (next_i - 1));
    }
    return sum;
}