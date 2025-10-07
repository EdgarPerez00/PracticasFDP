#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_LONG  2147483647
#define MIN_LONG -2147483648    

int main(int argc, char *argv[]) {
    srand(time(NULL));

    long lx = rand() % MAX_LONG - MIN_LONG;
    long ly = rand();


    char c;
    short s;
    int i;
    long l;
    float f_var;
    double d;

    printf("Valor inicial de lx: %ld\n", lx);
    printf("Valor inicial de ly: %ld\n\n", ly);

    printf("lx = lx * ly\n");
    printf("%ld * %ld.\n", lx, ly);
    lx = lx * ly; 
    printf("lx = %ld\n", lx);

    printf("lx = lx / ly\n");
    printf("%ld / %ld.\n", lx, ly);
    if (ly != 0) {
        printf("lx = %ld\n", lx);
    } else {
        printf("Error: Division por cero.\n");
    }
    printf("\n");

    printf("lx = lx %% ly\n");
    printf("%ld %% %ld.\n", lx, ly);
    if (ly != 0) {
        lx = lx % ly;
        printf("lx = %ld\n", lx);
    } else {
        printf("Error: Modulo por cero.\n");
    }
    printf("\n");

    printf("lx = lx + ly\n");
    printf("%ld + %ld.\n", lx, ly);
    lx = lx + ly;
    printf("lx = %ld\n", lx);

    printf("lx = lx - ly\n");
    printf("%ld - %ld.\n", lx, ly);
    lx = lx - ly;
    printf("lx = %ld\n", lx);

    lx++;
    printf("lx++ = %ld\n\n", lx);
    lx--;
    printf("lx-- = %ld\n\n", lx);

    ++lx;
    printf("++lx = %ld\n\n", lx);

    --lx;
    printf("--lx = %ld\n\n", lx);

    lx = +ly;
    printf("lx = +ly = %ld\n\n", lx);

    lx = -ly;
    printf("lx = -ly = %ld\n\n", lx);

    if(lx > ly) {
        printf("%ld es mayor que %ld\n\n", lx, ly);
    }
    if(lx >= ly) {
        printf("%ld es mayor o igual que %ld\n\n", lx, ly);
    }
    if(lx < ly) {
        printf("%ld es menor que %ld\n\n", lx, ly);
    }
    if(lx <= ly) {
        printf("%ld es menor o igual que %ld\n\n", lx, ly);
    }
    if(lx == ly) {
        printf("%ld es igual a %ld\n\n", lx, ly);
    }
    if(lx != ly) {
        printf("%ld es diferente a %ld\n\n", lx, ly);
    }

    lx = ~ly;
    printf("lx = ~ly = %ld\n\n", lx);

    printf("%ld & %ld = ", lx, ly);
    lx = lx & ly;
    printf("%ld\n\n", lx);

    printf("%ld | %ld = ", lx, ly);
    lx = lx | ly;
    printf("%ld\n\n", lx);

    printf("%ld ^ %ld = ", lx, ly);
    lx = lx ^ ly;
    printf("%ld\n\n", lx);

    printf("%ld << 1 = ", lx);
    lx = lx << 1;
    printf("%ld\n\n", lx);

    printf("%ld >> 1 = ", lx);
    lx = lx >> 1;
    printf("%ld\n\n", lx);

    printf("%ld += %ld = ", lx, ly);
    lx += ly;
    printf("%ld\n\n", lx);

    printf("%ld -= %ld = ", lx, ly);
    lx -= ly;
    printf("%ld\n\n", lx);

    printf("%ld *= %ld = ", lx, ly);
    lx *= ly;
    printf("%ld\n\n", lx);

    if (ly != 0) {
        printf("%ld /= %ld = ", lx, ly);
        lx /= ly;
        printf("%ld\n\n", lx);

        printf("%ld %%= %ld = ", lx, ly);
        lx %= ly;
        printf("%ld\n\n", lx);
    }

    printf("%ld <<= 1 = ", lx);
    lx <<= 1;
    printf("%ld\n\n", lx);

    printf("%ld >>= 1 = ", lx);
    lx >>= 1;
    printf("%ld\n\n", lx);

    printf("%ld &= %ld = ", lx, ly);
    lx &= ly;
    printf("%ld\n\n", lx);

    printf("%ld ^= %ld = ", lx, ly);
    lx ^= ly;
    printf("%ld\n\n", lx);

    printf("%ld |= %ld = ", lx, ly);
    lx |= ly;
    printf("%ld\n\n", lx);

    c = (char) lx;
    printf("char : %d\n\n", c);
    s = (short) lx;
    printf("short : %hd\n\n", s);
    i = (int) lx;
    printf("int : %d\n\n", i);
    f_var = (float) lx;
    printf("float : %f\n\n", f_var);
    d = (double) lx;
    printf("double : %lf\n\n", d);

    return 0;
}