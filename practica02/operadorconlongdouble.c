//Edgar Israel Perez Garcia
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long double generarLongDouble(void) {
    return ((long double)rand() / (long double)RAND_MAX) * 100000.0L;
}

void mostrarComparaciones(long double x, long double y) {
    printf("x > y: %d\n", x > y);
    printf("x >= y: %d\n", x >= y);
    printf("x < y: %d\n", x < y);
    printf("x <= y: %d\n", x <= y);
    printf("x == y: %d\n", x == y);
    printf("x != y: %d\n", x != y);
}

void mostrarOperaciones(long double x, long double y) {
    printf("Valor inicial de x: %.5Lf\n", x);
    printf("Valor inicial de y: %.5Lf\n\n", y);

    printf("Aritmeticos\n");
    printf("x + y = %.5Lf\n", x + y);
    printf("x - y = %.5Lf\n", x - y);
    printf("x * y = %.5Lf\n", x * y);
    if (y != 0.0L) {
        printf("x / y = %.5Lf\n", x / y);
    }
    printf("++x = %.5Lf\n", x + 1.0L);
    printf("--x = %.5Lf\n\n", x - 1.0L);

    printf("Relacionales\n");
    mostrarComparaciones(x, y);

    printf("\nAsignacion compuesta\n");
    x += y;
    printf("x += y: %.5Lf\n", x);
    x -= y;
    printf("x -= y: %.5Lf\n", x);
    x *= y;
    printf("x *= y: %.5Lf\n", x);
    if (y != 0.0L) {
        x /= y;
        printf("x /= y: %.5Lf\n", x);
    }

    printf("\nDesbordamiento y subdesbordamiento\n");
    x = LDBL_MAX * 2.0L;
    printf("LDBL_MAX * 2 = %.5Le\n", x);
    x = LDBL_MIN / 2.0L;
    printf("LDBL_MIN / 2 = %.5Le\n", x);
}

int main(void) {
    long double x;
    long double y;

    srand((unsigned)time(NULL));
    x = generarLongDouble();
    y = generarLongDouble();
    if (y == 0.0L) {
        y = 1.0L;
    }

    printf("Rango long double: %.5Le a %.5Le\n\n", LDBL_MIN, LDBL_MAX);
    mostrarOperaciones(x, y);

    return 0;
}
