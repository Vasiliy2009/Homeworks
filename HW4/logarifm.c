#include "logarifm.h"
#include <stdio.h>
#include <math.h>


double logarifm(double x, int n, double eps) {
    if (x <= 0.0 || x > 2.0) {
        printf("Error cann't evaluate log for %lf \n", x);
        return 0;
    }
    double sum = 0.0;
    double t = x - 1.0;
    double term = t;
    double denom_lagrange = (x < 0.0) ? (1.0 + x) : 1.0;

    for(int i = 1; i < n; i++) {
        double error_bound = (x < 0.0) ? (fabs(term) / denom_lagrange) : fabs(term);
        if (error_bound < eps) {
            break;
        }
        sum += term;
        term = -term * t * i / (i + 1);
        if (x < 0.0) {
            denom_lagrange *= (1.0 + x);
        }
    }
    return sum;
}