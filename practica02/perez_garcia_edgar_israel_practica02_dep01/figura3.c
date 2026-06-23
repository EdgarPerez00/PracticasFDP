//Edgar Israel Perez Garcia
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE 256

void imprimirEntero(int entero) {
    printf("%d", entero);
}

int main(int argc, char *argv[]) {
    unsigned char cx;
    unsigned char cy;
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;

    (void)argc;
    (void)argv;

    srand((unsigned)time(NULL));
    cx = (unsigned char)(rand() % LIMITE);
    cy = (unsigned char)((rand() % (LIMITE - 1)) + 1);

    printf("Caracter cx: %c %d\n", cx, (int)cx);
    printf("Caracter cy: %c %d\n\n", cy, (int)cy);

    printf("Operadores aritmeticos\n");
    printf("%d * %d = %d\n", cx, cy, (unsigned char)(cx * cy));
    printf("%d / %d = %d\n", cx, cy, (unsigned char)(cx / cy));
    printf("%d mod %d = %d\n", cx, cy, (unsigned char)(cx % cy));
    printf("%d + %d = %d\n", cx, cy, (unsigned char)(cx + cy));
    printf("%d - %d = %d\n\n", cx, cy, (unsigned char)(cx - cy));

    printf("Incrementos y decrementos\n");
    cx++;
    printf("cx++ = %d\n", cx);
    cx--;
    printf("cx-- = %d\n", cx);
    ++cx;
    printf("++cx = %d\n", cx);
    --cx;
    printf("--cx = %d\n\n", cx);

    printf("Relacionales y logicos\n");
    printf("cx > cy: ");
    imprimirEntero(cx > cy);
    printf("\n");
    printf("cx >= cy: ");
    imprimirEntero(cx >= cy);
    printf("\n");
    printf("cx < cy: ");
    imprimirEntero(cx < cy);
    printf("\n");
    printf("cx <= cy: ");
    imprimirEntero(cx <= cy);
    printf("\n");
    printf("cx == cy: ");
    imprimirEntero(cx == cy);
    printf("\n");
    printf("cx != cy: ");
    imprimirEntero(cx != cy);
    printf("\n");
    printf("!cx: ");
    imprimirEntero(!cx);
    printf("\n");
    printf("cx && cy: ");
    imprimirEntero(cx && cy);
    printf("\n");
    printf("cx || cy: ");
    imprimirEntero(cx || cy);
    printf("\n\n");

    printf("Operadores de bits\n");
    printf("~cy = %d\n", (unsigned char)(~cy));
    printf("cx & cy = %d\n", (unsigned char)(cx & cy));
    printf("cx | cy = %d\n", (unsigned char)(cx | cy));
    printf("cx ^ cy = %d\n", (unsigned char)(cx ^ cy));
    printf("cx << 1 = %d\n", (unsigned char)(cx << 1));
    printf("cx >> 1 = %d\n\n", (unsigned char)(cx >> 1));

    printf("Asignacion compuesta\n");
    c = (char)cx;
    c += (char)cy;
    printf("c += cy: %d\n", c);
    c -= (char)cy;
    printf("c -= cy: %d\n", c);
    c *= (char)cy;
    printf("c *= cy: %d\n", c);
    if (cy != 0) {
        c /= (char)cy;
        printf("c /= cy: %d\n", c);
        c %= (char)cy;
        printf("c %%= cy: %d\n", c);
    }
    c <<= 1;
    printf("c <<= 1: %d\n", c);
    c >>= 1;
    printf("c >>= 1: %d\n\n", c);

    printf("Casting o mutacion\n");
    s = (short)cx;
    i = (int)cx;
    l = (long)cx;
    f = (float)cx;
    d = (double)cx;
    printf("short: %hd\n", s);
    printf("int: %d\n", i);
    printf("long: %ld\n", l);
    printf("float: %f\n", f);
    printf("double: %lf\n", d);

    return 0;
}
