#include <stdio.h>
#include <math.h>
#include "sinus.h"
#include "cosinus.h"
#include "exponent.h"
#include "logarifm.h"

struct func {
    const char *name;
    double (*lib_func)(double);
    double (*ref_func)(double, int);
};

int main() {
    const struct func functions[] = {
        { "sin", sin, sinus },
        { "cos", cos, cosinus },
        { "exp", exp, exponent },
        { "log", log, logarifm }
    };
    size_t length = sizeof(functions) / sizeof((functions)[0]);
    int choice, n; 
    double x;

    printf("choose function(");
    for(int i = 0; i < length; i++) {
        printf("%d - %s,\t", i + 1, functions[i].name);
    }
    printf("): ");
    scanf(" %d", &choice);
    if (choice < 0 || length <= choice) {
        printf("Error: no such function \n");
        return -1;
    }

    printf("Enter x: ");
    scanf(" %lf", &x);

    printf("Enter steps(1-1000): ");
    scanf(" %d", &n);
    if (n < 1 || 1000 < n) {
        printf("Error: n is out of range \n");
        return -1;
    }

    printf("output: \n");
    printf("library: %f \n", functions[choice - 1].lib_func(x));
    printf("tailor: %f \n", functions[choice - 1].ref_func(x, n));
}