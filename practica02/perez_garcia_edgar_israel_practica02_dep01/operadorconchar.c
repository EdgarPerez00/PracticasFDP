#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_CHAR 256

int main(int argc, char *argv[]) {
    srand(time(NULL));

    signed char cx = rand() % MAX_CHAR;
    signed char cy = rand() % MAX_CHAR;


    char c;
    short s;
    int i, vuelta;
    long l, recorrido;
    float f_var;
    double d;

    printf("Valor inicial de cx: %d\n", (int)cx);
    printf("Valor inicial de cy: %d\n\n", (int)cy );
    
    printf("cx = cx * cy\n");
    printf("%d * %d | %c * %c.\n", (int)cx, (int)cy, cx , cy);
    
    cx = cx * cy; 
    recorrido = (long)(cx *cy);
    vuelta = (recorrido < 0) ? ( - recorrido / 256) : (recorrido / 256);
    printf("cx = %d | %c\n", (int)cx, cx);
    printf("valor numerico de cx * cy: %ld\n", recorrido);
    if (recorrido > 127) {
        printf("Desbordamiento por la derecha.\n");
    } else if (recorrido < -128) {
        printf("Desbordamiento por la izquierda\n");
    }
    printf("dio vuelta %d veces\n", vuelta);
    printf("\n");

    printf("cx = cx / cy\n");
    printf("%d / %d | %c / %c.\n", (int)cx, (int)cy, cx, cy);
    if (cy != 0) {
        recorrido = (long)cx / cy;
        cx = cx / cy;
        vuelta = (recorrido < 0) ? ( - recorrido / 256) : (recorrido / 256);
        printf("cx = %d | %c\n", (int)cx, cx);
        printf("valor numerico de cx / cy: %ld\n", recorrido);
        if (recorrido > 127) {
            printf("Desbordamiento por la derecha.\n");
        } else if (recorrido < -128) {
            printf("Desbordamiento por la izquierda\n");
        }
    } else {
        printf("Error: Division por cero.\n");
    }
    printf("dio vuelta %d veces\n", vuelta);
    printf("\n");


    printf("cx = cx %% cy\n");
    printf("%d %% %d | %c %% %c.\n", (int)cx, (int)cy, cx, cy);
    if (cy != 0) {
        recorrido = (long)cx % cy;
        cx = cx % cy;
        vuelta = (recorrido < 0) ? ( - recorrido / 256) : (recorrido / 256);

        printf("cx = %d | %c\n", (int)cx, cx);
        printf("valor numerico de cx %% cy: %ld\n", recorrido);
        if (recorrido > 127) {
            printf("Desbordamiento por la derecha.\n");
        } else if (recorrido < -128) {
            printf("Desbordamiento por la izquierda\n");
        }
    } else {
        printf("Error: Modulo por cero.\n");
    }
    printf("dio vuelta %d veces", vuelta);
    printf("\n");



    printf("cx = cx + cy\n");
    printf("%d + %d | %c + %c.\n", (int)cx, (int)cy, cx, cy);
    recorrido = (long)cx + cy;
    cx = cx + cy;
    vuelta = (recorrido < 0) ? ( - recorrido / 256) : (recorrido / 256);

    printf("cx = %d | %c\n", (int)cx, cx);
    printf("valor numerico de cx + cy: %ld\n", recorrido);
    if (recorrido > 127) {
        printf("Desbordamiento por la derecha.\n");
    } else if (recorrido < -128) {
        printf("Desbordamiento por la izquierda\n");
    }
    printf("dio vuelta %d veces", vuelta);
    printf("\n");

    printf("cx = cx - cy\n");
    printf("%d - %d | %c - %c.\n", (int)cx, (int)cy, cx, cy);
    recorrido = (long)cx - cy;
    cx = cx - cy;
    vuelta = (recorrido < 0) ? ( - recorrido / 256) : (recorrido / 256);
    printf("cx = %d | %c\n", (int)cx, cx);
    printf("valor numerico de cx - cy: %ld\n", recorrido);
    if (recorrido > 127) {
        printf("Desbordamiento por la derecha.\n");
    } else if (recorrido < -128) {
        printf("Desbordamiento por la izquierda\n");
    }
    printf("dio vuelta %d veces", vuelta);
    printf("\n");
    
   


    cx++;
    printf("cx++ = %c\n\n", cx);
    
    cx--;
    printf("cx-- = %c\n\n", cx);

    ++cx;
    printf("++cx = %c\n\n", cx);

    --cx;
    printf("--cx = %c\n\n", cx);

    cx = (signed char) +cy;
    printf("cx = +cy = %c\n\n", cx);

    cx = (signed char)-cy;
    printf("cx = -cy = %c\n\n", cx);

    if(cx > cy) 
    {
        printf("%c es mayor que %c\n\n", cx, cy);
    }
    if(cx >= cy) 
    {
        printf("%c es mayor o igual que %c\n\n", cx, cy);
    }
    if(cx < cy) 
    {
        printf("%c es menor que %c\n\n", cx, cy);
    }
    if(cx <= cy) 
    {
        printf("%c es menor o igual que %c\n\n", cx, cy);
    }
    if(cx == cy) 
    {
        printf("%c es igual a %c\n\n", cx, cy);
    }
    if(cx != cy) 
    {
        printf("%c es diferente a %c\n\n", cx, cy);
    }

    
    cx = (signed char) ~cy;
    printf("cx = ~cy = %c\n\n", cx);
    
    printf("%c & %c = ", cx, cy);
    cx = (signed char) (cx & cy);
    printf("%c\n\n", cx);

    printf("%c | %c = ", cx, cy);
    cx = (signed char) (cx | cy);
    printf("%c\n\n", cx);

    printf("%c ^ %c = ", cx, cy);
    cx = (signed char) (cx ^ cy);
    printf("%c\n\n", cx);

    printf("%c << 1 = ", cx);
    cx = (signed char) (cx << 1);
    printf("%c\n\n", cx);

    printf("%c >> 1 = ", cx);
    cx = (signed char) (cx >> 1);
    printf("%c\n\n", cx);
    
    printf("%c += %c = ", cx, cy);
    cx += cy;
    printf("%c\n\n", cx);

    printf("%c -= %c = ", cx, cy);
    cx -= cy;
    printf("%c\n\n", cx);

    printf("%c += %c = ", cx, cy);
    cx += cy;
    printf("%c\n\n", cx);

    printf("%c-= %c = ", cx, cy);
    cx-= cy;
    printf("%c\n\n", cx);

    printf("%c *= %c = ", cx, cy);
    cx *= cy;
    printf("%c\n\n", cx);

    printf("%c /= %c = ", cx, cy);
    cx /= cy;
    printf("%c\n\n", cx);

    printf("%c mod= %c = ", cx, cy);
    cx %= cy;
    printf("%c\n\n", cx);

    printf("%c <<= 1 = ", cx);
    cx <<= 1;
    printf("%c\n\n", cx);

    printf("%c >>= 1 = ", cx);
    cx >>= 1;
    printf("%c\n\n", cx);

    printf("%c &= %c = ", cx, cy);
    cx &= cy;
    printf("%c\n\n", cx);

    printf("%c ^= %c = ", cx, cy);
    cx ^= cy;
    printf("%c\n\n", cx);

    printf("%c |= %c = ", cx, cy);
    cx |= cy;
    printf("%c\n\n", cx);




    s = (short) cx;
    printf("short : %d\n\n", s);
    i = (int) cx;
    printf("int : %d\n\n", i);
    l = (long) cx;
    printf("long : %ld\n\n", l);
    f_var = (float) cx;
    printf("float = %f\n\n", f_var);
    d = (double) cx;
    printf("double : %lf\n\n", d);

    return 0;
}