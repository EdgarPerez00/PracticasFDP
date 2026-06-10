#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long generarValor(void) {
    long long alto = rand() % 100000;
    long long bajo = rand() % 100000;
    return (alto * 100000LL) + bajo;
}

void mostrarComparaciones(long long x, long long y) {
    printf("%lld > %lld: %d\n", x, y, x > y);
    printf("%lld >= %lld: %d\n", x, y, x >= y);
    printf("%lld < %lld: %d\n", x, y, x < y);
    printf("%lld <= %lld: %d\n", x, y, x <= y);
    printf("%lld == %lld: %d\n", x, y, x == y);
    printf("%lld != %lld: %d\n", x, y, x != y);
}

void mostrarOperadores(long long x, long long y) {
    printf("Valor inicial de x: %lld\n", x);
    printf("Valor inicial de y: %lld\n\n", y);

    printf("Aritmeticos\n");
    printf("x + y = %lld\n", x + y);
    printf("x - y = %lld\n", x - y);
    printf("x * y = %lld\n", x * y);
    if (y != 0) {
        printf("x / y = %lld\n", x / y);
        printf("x %% y = %lld\n", x % y);
    }
    printf("x++ = %lld\n", x + 1);
    printf("x-- = %lld\n\n", x - 1);

    printf("Relacionales\n");
    mostrarComparaciones(x, y);

    printf("\nBits\n");
    printf("~y = %lld\n", ~y);
    printf("x & y = %lld\n", x & y);
    printf("x | y = %lld\n", x | y);
    printf("x ^ y = %lld\n", x ^ y);
    printf("x << 1 = %lld\n", x << 1);
    printf("x >> 1 = %lld\n\n", x >> 1);

    printf("Asignacion compuesta\n");
    x += y;
    printf("x += y: %lld\n", x);
    x -= y;
    printf("x -= y: %lld\n", x);
    x *= y;
    printf("x *= y: %lld\n", x);
    if (y != 0) {
        x /= y;
        printf("x /= y: %lld\n", x);
        x %= y;
        printf("x %%= y: %lld\n", x);
    }
}

int main(void) {
    long long x;
    long long y;

    srand((unsigned)time(NULL));
    x = generarValor();
    y = generarValor();
    if (y == 0) {
        y = 1;
    }

    printf("Rango long long: %lld a %lld\n\n", LLONG_MIN, LLONG_MAX);
    mostrarOperadores(x, y);

    return 0;
}
