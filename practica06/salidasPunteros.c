//Edgar Israel Perez Garcia
#include<stdio.h>

void imprimirSalida(int arreglo[]);

void imprimirSalida(int arreglo[]) {
    int *p;
    p = arreglo;
    printf(" %d\n", arreglo[*(p + 7)]);
    printf(" %d\n", *arreglo + 3);
    printf(" %d\n", *p++);
    printf(" %d\n", *(arreglo + 1));
    printf(" %d\n", (*p)++);
    printf(" %d\n", *p);
    printf(" %d\n", *p++);
    printf(" %d\n", *p);
}

int main(void) {
    int arreglo[18] = {
        23, 5, 98, 65, 3, 55, 73, 9, 21, 85, 100, -7, 45, 99, 18, 66, 99, 101
    };
    imprimirSalida(arreglo);

    return 0;
}
