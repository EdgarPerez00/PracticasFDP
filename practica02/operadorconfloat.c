#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <math.h>

#define MAX_FLOAT  340000000
#define MIN_FLOAT -340000000

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));

    float fx = (float)rand() / MAX_FLOAT;
    float fy = (float)rand() / MAX_FLOAT;

    char c;
    short s;
    int i;
    long l;
    float f_var;
    double d;

    printf("Valor inicial de fx: %f\n", fx);
    printf("Valor inicial de fy: %f\n\n", fy);

    printf("fx = fx * fy\n");
    printf("%f * %f.\n", fx, fy);
    fx = fx * fy; 
    printf("fx = %f\n\n", fx);

    printf("fx = fx / fy\n");
    printf("%f / %f.\n", fx, fy);
    if (fy != 0.0f) {
        fx = fx / fy;
        printf("fx = %f\n", fx);
        if (isinf(fx)) printf("El resultado es infinito.\n");
        if (isnan(fx)) printf("El resultado es NaN (No es un Numero).\n");
    } else {
        printf("Error: Division por cero.\n");
    }
    printf("\n");

    printf("fx = fx + fy\n");
    printf("%f + %f.\n", fx, fy);
    fx = fx + fy;
    printf("fx = %f\n\n", fx);

    printf("fx = fx - fy\n");
    printf("%f - %f.\n", fx, fy);
    fx = fx - fy;
    printf("fx = %f\n\n", fx);

    fx++;
    printf("fx++ = %f\n\n", fx);

    fx--;
    printf("fx-- = %f\n\n", fx);

    ++fx;
    printf("++fx = %f\n\n", fx);

    --fx;
    printf("--fx = %f\n\n", fx);

    fx = +fy;
    printf("fx = +fy = %f\n\n", fx);

    fx = -fy;
    printf("fx = -fy = %f\n\n", fx);

    if(fx > fy) {
        printf("%f es mayor que %f\n\n", fx, fy);
    }
    if(fx >= fy) {
        printf("%f es mayor o igual que %f\n\n", fx, fy);
    }

    printf("%f += %f = ", fx, fy);
    fx += fy;
    printf("%f\n\n", fx);

    printf("%f -= %f = ", fx, fy);
    fx -= fy;
    printf("%f\n\n", fx);

    printf("%f *= %f = ", fx, fy);
    fx *= fy;
    printf("%f\n\n", fx);

    if (fy != 0.0f) {
        printf("%f /= %f = ", fx, fy);
        fx /= fy;
        printf("%f\n\n", fx);
    }

    c = (char) fx;
    printf("char : %d\n\n", c);
    s = (short) fx;
    printf("short : %hd\n\n", s);
    i = (int) fx;
    printf("int : %d\n\n", i);
    l = (long) fx;
    printf("long : %ld\n\n", l);
    d = (double) fx;
    printf("double : %lf\n\n", d);

    return 0;
}