#include "exponent.h"


double exponent(double x, int n) {
    double sum = 0.0;
    double term = 1.0;

    for(int i = 0; i < n; i++) {
        sum += term;
        term = term * x / (i + 1);
    }
    return sum;
}