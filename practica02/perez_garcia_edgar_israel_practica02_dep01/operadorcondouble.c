#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <math.h>

#define MAX_DOUBLE  211
#define MIN_DOUBLE 66

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));

    double dx = (double)rand() / (MAX_DOUBLE - MIN_DOUBLE);
    double dy = (double)rand() / (MAX_DOUBLE - MIN_DOUBLE);

    char c;
    short s;
    int i;
    long l;
    float f_var;
    double d;

    printf("Valor inicial de dx: %f\n", dx);
    printf("Valor inicial de dy: %f\n\n", dy);

    printf("dx = dx * dy\n");
    printf("%f * %f.\n", dx, dy);
    dx = dx * dy; 
    printf("dx = %f\n\n", dx);

    printf("dx = dx / dy\n");
    printf("%f / %f.\n", dx, dy);
    if (dy != 0.0) {
        dx = dx / dy;
        printf("dx = %f\n", dx);
        if (isinf(dx)) printf("El resultado es infinito.\n");
        if (isnan(dx)) printf("El resultado es NaN (No es un Numero).\n");
    } else {
        printf("Error: Division por cero.\n");
    }
    printf("\n");

    printf("dx = dx + dy\n");
    printf("%f + %f.\n", dx, dy);
    dx = dx + dy;
    printf("dx = %f\n\n", dx);

    printf("dx = dx - dy\n");
    printf("%f - %f.\n", dx, dy);
    dx = dx - dy;
    printf("dx = %f\n\n", dx);

    dx++;
    printf("dx++ = %f\n\n", dx);

    dx--;
    printf("dx-- = %f\n\n", dx);

    ++dx;
    printf("++dx = %f\n\n", dx);

    --dx;
    printf("--dx = %f\n\n", dx);

    dx = +dy;
    printf("dx = +dy = %f\n\n", dx);

    dx = -dy;
    printf("dx = -dy = %f\n\n", dx);

    if(dx > dy) {
        printf("%f es mayor que %f\n\n", dx, dy);
    }
    if(dx >= dy) {
        printf("%f es mayor o igual que %f\n\n", dx, dy);
    }

    printf("%f += %f = ", dx, dy);
    dx += dy;
    printf("%f\n\n", dx);

    printf("%f -= %f = ", dx, dy);
    dx -= dy;
    printf("%f\n\n", dx);

    printf("%f *= %f = ", dx, dy);
    dx *= dy;
    printf("%f\n\n", dx);

    if (dy != 0.0) {
        printf("%f /= %f = ", dx, dy);
        dx /= dy;
        printf("%f\n\n", dx);
    }

    c = (char) dx;
    printf("char : %d\n\n", c);
    s = (short) dx;
    printf("short : %hd\n\n", s);
    i = (int) dx;
    printf("int : %d\n\n", i);
    l = (long) dx;
    printf("long : %ld\n\n", l);
    f_var = (float) dx;
    printf("float : %f\n\n", f_var);

    return 0;
}