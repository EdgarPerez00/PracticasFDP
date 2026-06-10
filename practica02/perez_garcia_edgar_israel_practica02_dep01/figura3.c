#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMITE 256
void f(int entero) {
printf("%d", entero);
}
int main(int argc, char *argv[]) {
srand(time(NULL));
// tipos de datos
unsigned char cx = rand() % LIMITE;//90;
unsigned char cy = rand() % LIMITE;//64;

// variables de casteo o mutacion
char c;
short s;
int i;
long l;
float f;
double d;
/***************************** CARACTERES char
***************************/
printf("Caracter cx: %c %d\n", cx, (int)cx);
printf("Caracter cy: %c %d\n", cy, (int)cy );
// Operadores Aritmeticos:
printf("%c * %c = ", cx, cy);
cx = (char) (cx * cy);
printf("%c %d\n", cx, (int)cx);
printf("%c / %c = ", cx, cy);
cx = (char) (cx / cy);
printf("%c\n", cx);
printf("%c mod %c = ", cx, cy);
cx = (char) (cx % cy);

4

printf("%c
\n", cx);
printf("%c + %c = ", cx, cy);
cx = (char) (cx + cy);
printf("%c
\n", cx);
printf("%c

- %c = ", cx, cy);

cx = (char) (cx
- cy);
printf("%c
\n", cx);

cx++;
printf("cx++ = %c
\n", cx);

cx--
;
printf("cx-- = %c
\n", cx);

++cx;
printf("++cx = %c
\n", cx);

--cx;
printf("--cx = %c
\n", cx);
cx = (char) +cy;
printf("cx = +cy = %c
\n", cx);

cx = (char)
-cy;
printf("cx =
-cy = %c
\n", cx);
// Relacionales and logicos:
if(cx > cy) {
printf("%c es mayor que %c

\n", cx, cy);

}
if(cx >= cy) {
printf("%c es mayor o igual que %c

\n", cx, cy);

}
if(cx < cy) {
printf("%c es menor que %c

\n", cx, cy);

}
if(cx <= cy) {
printf("%c es menor o igual que %c

\n", cx, cy);

}
if(cx == cy) {
printf("%c es igual a %c

\n", cx, cy);

}
if(cx != cy) {
printf("%c es diferente a %c

\n", cx, cy);

}
//! f(!x);
//! f(x && y);
//! f(x || y);

5

// operadores de Bits:
cx = (char) ~cy;
printf("cx = ~cy = %c
\n", cx);
printf("%c & %c = ", cx, cy);
cx = (char) (cx & cy);
printf("%c
\n", cx);
printf("%c | %c = ", cx, cy);
cx = (char) (cx | cy);
printf("%c
\n", cx);
printf("%c ^ %c = ", cx, cy);
cx = (char) (cx ^ cy);
printf("%c
\n", cx);
printf("%c << 1 = ", cx);
cx = (char) (cx << 1);
printf("%c
\n", cx);
printf("%c >> 1 = ", cx);
cx = (char) (cx >> 1);
printf("%c
\n", cx);
// Asignacion compuesta:
printf("%c += %c = ", cx, cy);
cx += cy;
printf("%c
\n", cx);
printf("%c

-= %c = ", cx, cy);

cx
-= cy;
printf("%c
\n", cx);
printf("%c *= %c = ", cx, cy);
cx *= cy;
printf("%c
\n", cx);
printf("%c /= %c = ", cx, cy);
cx /= cy;
printf("%c
\n", cx);

printf("%c mod= %c = ", cx, cy);
cx %= cy;
printf("%c
\n", cx);

6

printf("%c <<= 1 = ", cx);
cx <<= 1;
printf("%c\n", cx);
printf("%c >>= 1 = ", cx);
cx >>= 1;
printf("%c\n", cx);
printf("%c &= %c = ", cx, cy);
cx &= cy;
printf("%c\n", cx);
printf("%c ^= %c = ", cx, cy);
cx ^= cy;
printf("%c\n", cx);
printf("%c |= %c = ", cx, cy);
cx |= cy;
printf("%c\n", cx);
// Casting o mutacion
s = (short) cx;
printf("%d\n", s);
i = (int) cx;
printf("%d\n", i);
l = (long) cx;
printf("%ld\n", l);
f = (float) cx;
printf("%f\n", f);
d = (double) cx;
printf("%lf\n", d);
return 0;
}