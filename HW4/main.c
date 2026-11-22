#include <stdio.h>
#include <math.h>
#include "sinus.h"
#include "cosinus.h"
#include "exponent.h"
#include "logarifm.h"

struct func {
    const char *name;
    double (*lib_func)(double);
    double (*ref_func)(double, int, double);
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
    double x, eps, libres, tres;

    printf("choose function(");
    for(int i = 0; i < length; i++) {
        printf("%d - %s,\t", i + 1, functions[i].name);
    }
    printf("): ");
    scanf(" %d", &choice);
    if (choice < 1 || length + 1 <= choice) {
        printf("Error: no such function \n");
        return -1;
    }

    printf("Enter x: ");
    scanf(" %lf", &x);

    printf("Enter estimation: ");
    scanf(" %lf", &eps);

    printf("Enter steps(1-1000): ");
    scanf(" %d", &n);
    if (n < 1 || 1000 < n) {
        printf("Error: n is out of range \n");
        return -1;
    }

    printf("output: \n");
    libres = functions[choice - 1].lib_func(x);
    printf("library: %f \n", libres);
    tres = functions[choice - 1].ref_func(x, n, eps);
    printf("tailor: %f \n", tres);
    printf("difference: %lf \n", fabs(tres - libres));
}