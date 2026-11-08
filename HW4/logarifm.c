#include "logarifm.h"
#include <stdio.h>


double logarifm(double x, int n) {
    if (x <= 0.0 || x > 2.0) {
        printf("Error cann't evaluate log for %lf \n", x);
        return 0;
    }
    double sum = 0.0;
    double t = x - 1.0;
    double term = t;

    for(int i = 1; i < n; i++) {
        sum += term;
        term = -term * t * i / (i + 1);
    }
    return sum;
}