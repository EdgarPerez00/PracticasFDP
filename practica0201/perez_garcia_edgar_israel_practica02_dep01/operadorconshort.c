#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));

    short sx = rand();
    short sy = rand();


    char c;
    short s;
    int i;
    long l;
    float f_var;
    double d;

    printf("Valor inicial de sx: %hd\n", sx);
    printf("Valor inicial de sy: %hd\n\n", sy);

    printf("sx = sx * sy\n");
    printf("%hd * %hd.\n", sx, sy);
    sx = sx * sy; 
    printf("sx = %hd\n", sx);
    printf("\n");

    printf("sx = sx / sy\n");
    printf("%hd / %hd.\n", sx, sy);
    if (sy != 0) {
        sx = sx / sy;
        printf("sx = %hd\n", sx);
    } else {
        printf("Error: Division por cero.\n");
    }
    printf("\n");

    printf("sx = sx %% sy\n");
    printf("%hd %% %hd.\n", sx, sy);
    if (sy != 0) {
        sx = sx % sy;
        printf("sx = %hd\n", sx);
    } else {
        printf("Error: Modulo por cero.\n");
    }
    printf("\n");

    printf("sx = sx + sy\n");
    printf("%hd + %hd.\n", sx, sy);
    sx = sx + sy;
    printf("sx = %hd\n", sx);
    printf("\n");

    printf("sx = sx - sy\n");
    printf("%hd - %hd.\n", sx, sy);
    sx = sx - sy;
    printf("sx = %hd\n", sx);
    printf("\n");

    sx++;
    printf("sx++ = %hd\n\n", sx);
    sx--;
    printf("sx-- = %hd\n\n", sx);

    ++sx;
    printf("++sx = %hd\n\n", sx);

    --sx;
    printf("--sx = %hd\n\n", sx);

    sx = +sy;
    printf("sx = +sy = %hd\n\n", sx);

    sx = -sy;
    printf("sx = -sy = %hd\n\n", sx);

    if(sx > sy) {
        printf("%hd es mayor que %hd\n\n", sx, sy);
    }
    if(sx >= sy) {
        printf("%hd es mayor o igual que %hd\n\n", sx, sy);
    }
    if(sx < sy) {
        printf("%hd es menor que %hd\n\n", sx, sy);
    }
    if(sx <= sy) {
        printf("%hd es menor o igual que %hd\n\n", sx, sy);
    }
    if(sx == sy) {
        printf("%hd es igual a %hd\n\n", sx, sy);
    }
    if(sx != sy) {
        printf("%hd es diferente a %hd\n\n", sx, sy);
    }

    sx = ~sy;
    printf("sx = ~sy = %hd\n\n", sx);

    printf("%hd & %hd = ", sx, sy);
    sx = sx & sy;
    printf("%hd\n\n", sx);

    printf("%hd | %hd = ", sx, sy);
    sx = sx | sy;
    printf("%hd\n\n", sx);

    printf("%hd ^ %hd = ", sx, sy);
    sx = sx ^ sy;
    printf("%hd\n\n", sx);

    printf("%hd << 1 = ", sx);
    sx = sx << 1;
    printf("%hd\n\n", sx);
    
    printf("%hd &= %hd = ", sx, sy);
    sx &= sy;
    printf("%hd\n\n", sx);

    printf("%hd += %hd = ", sx, sy);
    sx += sy;
    printf("%hd\n\n", sx);

    printf("%hd -= %hd = ", sx, sy);
    sx -= sy;
    printf("%hd\n\n", sx);

    printf("%hd *= %hd = ", sx, sy);
    sx *= sy;
    printf("%hd\n\n", sx);

    if (sy != 0) {
        printf("%hd /= %hd = ", sx, sy);
        sx /= sy;
        printf("%hd\n\n", sx);

        printf("%hd %%= %hd = ", sx, sy);
        sx %= sy;
        printf("%hd\n\n", sx);
    }

    printf("%hd <<= 1 = ", sx);
    sx <<= 1;
    printf("%hd\n\n", sx);

    printf("%hd >>= 1 = ", sx);
    sx >>= 1;
    printf("%hd\n\n", sx);

    printf("%hd ^= %hd = ", sx, sy);
    sx ^= sy;
    printf("%hd\n\n", sx);
    printf("%hd |= %hd = ", sx, sy);
    sx |= sy;
    printf("%hd\n\n", sx);

    c = (char) sx;
    printf("char : %d\n\n", c);
    i = (int) sx;
    printf("int : %d\n\n", i);
    l = (long) sx;
    printf("long : %ld\n\n", l);
    f_var = (float) sx;
    printf("float : %f\n\n", f_var);
    d = (double) sx;
    printf("double : %lf\n\n", d);

    return 0;
}