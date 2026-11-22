#include "exponent.h"
#include <math.h>


double exponent(double x, int n, double eps) {
    double sum = 0.0;
    double term = 1.0;

    if (x == 0.0)
        return 1.0;

    double lagrange_k = 1.0;
    if (x > 0.0) {
        lagrange_k = pow(3.0, ceil(x));
    }

    for(int i = 0; i < n; i++) {
        if (n > fabs(x) && fabs(term) * lagrange_k < eps) {
            break;
        }
        sum += term;
        term = term * x / (i + 1);
    }
    return sum;
}