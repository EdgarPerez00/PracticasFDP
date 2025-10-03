#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_INT 100000
#define MIN_INT -50000

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int ix = rand() % MAX_INT - MIN_INT;
    int iy = rand() % MAX_INT - MIN_INT;

    long long vuelta_ll = 0;

    char c;
    short s;
    int i;
    long l;
    float f_var;
    double d;

    printf("Valor inicial de ix: %d\n", ix);
    printf("Valor inicial de iy: %d\n\n", iy);

    printf("ix = ix * iy\n");
    printf("%d * %d.\n", ix, iy);
    vuelta_ll = (long long)ix * iy;
    ix = ix * iy; 
    printf("ix = %d\n", ix);
    printf("valor teorico de ix * iy: %lld\n", vuelta_ll);
    if (vuelta_ll > INT_MAX) {
        printf("Desbordamiento por la derecha.\n");
    } else if (vuelta_ll < INT_MIN) {
        printf("Desbordamiento por la izquierda\n");
    }
    printf("\n");

    printf("ix = ix / iy\n");
    printf("%d / %d.\n", ix, iy);
    if (iy != 0) {
        vuelta_ll = (long long)ix / iy;
        ix = ix / iy;
        printf("ix = %d\n", ix);
        printf("valor teorico de ix / iy: %lld\n", vuelta_ll);
    } else {
        printf("Error: Division por cero.\n");
    }
    printf("\n");

    printf("ix = ix %% iy\n");
    printf("%d %% %d.\n", ix, iy);
    if (iy != 0) {
        vuelta_ll = (long long)ix % iy;
        ix = ix % iy;
        printf("ix = %d\n", ix);
        printf("valor teorico de ix %% iy: %lld\n", vuelta_ll);
    } else {
        printf("Error: Modulo por cero.\n");
    }
    printf("\n");

    printf("ix = ix + iy\n");
    printf("%d + %d.\n", ix, iy);
    vuelta_ll = (long long)ix + iy;
    ix = ix + iy;
    printf("ix = %d\n", ix);
    printf("valor teorico de ix + iy: %lld\n", vuelta_ll);
    if (vuelta_ll > INT_MAX) {
        printf("Desbordamiento por la derecha.\n");
    } else if (vuelta_ll < INT_MIN) {
        printf("Desbordamiento por la izquierda\n");
    }
    printf("\n");

    printf("ix = ix - iy\n");
    printf("%d - %d.\n", ix, iy);
    vuelta_ll = (long long)ix - iy;
    ix = ix - iy;
    printf("ix = %d\n", ix);
    printf("valor teorico de ix - iy: %lld\n", vuelta_ll);
    if (vuelta_ll > INT_MAX) {
        printf("Desbordamiento por la derecha.\n");
    } else if (vuelta_ll < INT_MIN) {
        printf("Desbordamiento por la izquierda\n");
    }
    printf("\n");

    ix++;
    printf("ix++ = %d\n\n", ix);
    ix--;
    printf("ix-- = %d\n\n", ix);

    ++ix;
    printf("++ix = %d\n\n", ix);

    --ix;
    printf("--ix = %d\n\n", ix);

    ix = +iy;
    printf("ix = +iy = %d\n\n", ix);

    ix = -iy;
    printf("ix = -iy = %d\n\n", ix);

    if(ix > iy) {
        printf("%d es mayor que %d\n\n", ix, iy);
    }
    if(ix >= iy) {
        printf("%d es mayor o igual que %d\n\n", ix, iy);
    }
    if(ix < iy) {
        printf("%d es menor que %d\n\n", ix, iy);
    }
    if(ix <= iy) {
        printf("%d es menor o igual que %d\n\n", ix, iy);
    }
    if(ix == iy) {
        printf("%d es igual a %d\n\n", ix, iy);
    }
    if(ix != iy) {
        printf("%d es diferente a %d\n\n", ix, iy);
    }

    ix = ~iy;
    printf("ix = ~iy = %d\n\n", ix);

    printf("%d & %d = ", ix, iy);
    ix = ix & iy;
    printf("%d\n\n", ix);

    printf("%d | %d = ", ix, iy);
    ix = ix | iy;
    printf("%d\n\n", ix);

    printf("%d ^ %d = ", ix, iy);
    ix = ix ^ iy;
    printf("%d\n\n", ix);

    printf("%d << 1 = ", ix);
    ix = ix << 1;
    printf("%d\n\n", ix);

    printf("%d >> 1 = ", ix);
    ix = ix >> 1;
    printf("%d\n\n", ix);

    printf("%d += %d = ", ix, iy);
    ix += iy;
    printf("%d\n\n", ix);

    printf("%d -= %d = ", ix, iy);
    ix -= iy;
    printf("%d\n\n", ix);

    printf("%d *= %d = ", ix, iy);
    ix *= iy;
    printf("%d\n\n", ix);

    if (iy != 0) {
        printf("%d /= %d = ", ix, iy);
        ix /= iy;
        printf("%d\n\n", ix);

        printf("%d %%= %d = ", ix, iy);
        ix %= iy;
        printf("%d\n\n", ix);
    }

    printf("%d <<= 1 = ", ix);
    ix <<= 1;
    printf("%d\n\n", ix);

    printf("%d >>= 1 = ", ix);
    ix >>= 1;
    printf("%d\n\n", ix);

    printf("%d &= %d = ", ix, iy);
    ix &= iy;
    printf("%d\n\n", ix);

    printf("%d ^= %d = ", ix, iy);
    ix ^= iy;
    printf("%d\n\n", ix);

    printf("%d |= %d = ", ix, iy);
    ix |= iy;
    printf("%d\n\n", ix);

    c = (char) ix;
    printf("char : %d\n\n", c);
    s = (short) ix;
    printf("short : %d\n\n", s);
    l = (long) ix;
    printf("long : %ld\n\n", l);
    f_var = (float) ix;
    printf("float : %f\n\n", f_var);
    d = (double) ix;
    printf("double : %lf\n\n", d);

    return 0;
}