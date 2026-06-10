#include <stdio.h>
#include <stdlib.h>

void reservarArreglo(int **arreglo, int *tamanio) {
    printf("Cantidad de datos: ");
    scanf("%d", tamanio);
    *arreglo = (int *)malloc(sizeof(int) * (*tamanio));
}

void leerArreglo(int *arreglo, int *tamanio) {
    int *ptr = arreglo;
    int *fin = arreglo + *tamanio;

    while (ptr < fin) {
        printf("Valor %ld: ", (long)(ptr - arreglo + 1));
        scanf("%d", ptr);
        ptr++;
    }
}

void sumarArreglo(int *arreglo, int *tamanio, int *suma) {
    int *ptr = arreglo;
    int *fin = arreglo + *tamanio;

    *suma = 0;
    while (ptr < fin) {
        *suma += *ptr;
        ptr++;
    }
}

void imprimirResumen(int *arreglo, int *tamanio, int *suma) {
    int *ptr = arreglo;
    int *fin = arreglo + *tamanio;

    printf("Datos: ");
    while (ptr < fin) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\nSuma: %d\n", *suma);
}

void ejecutarModularidad(void) {
    int *arreglo;
    int tamanio;
    int suma;

    reservarArreglo(&arreglo, &tamanio);
    if (arreglo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return;
    }

    leerArreglo(arreglo, &tamanio);
    sumarArreglo(arreglo, &tamanio, &suma);
    imprimirResumen(arreglo, &tamanio, &suma);

    free(arreglo);
}

int main(void) {
    ejecutarModularidad();
    return 0;
}
