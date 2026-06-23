//Edgar Israel Perez Garcia
#include <stdio.h>

#define MAX 30

void leerArreglo(int *arreglo, int *cantidad);
void buscarDesordenados(int *arreglo, int cantidad, int **desordenados, int *totalDesordenados);
void mostrarDesordenados(int *arreglo, int **desordenados, int totalDesordenados);
void ejecutarPrograma(void);

void leerArreglo(int *arreglo, int *cantidad) {
    int valor;
    int *ptr = arreglo;

    *cantidad = 0;
    printf("Ingrese enteros (maximo %d). Use 0 para terminar.\n", MAX);
    while (*cantidad < MAX) {
        printf("Valor %d: ", *cantidad + 1);
        if (scanf("%d", &valor) != 1 || valor == 0) {
            break;
        }
        *ptr = valor;
        ptr++;
        (*cantidad)++;
    }
}

void buscarDesordenados(int *arreglo, int cantidad, int **desordenados, int *totalDesordenados) {
    int *actual = arreglo + 1;
    int *anterior = arreglo;
    int *fin = arreglo + cantidad;
    int **salida = desordenados;

    *totalDesordenados = 0;
    while (actual < fin) {
        if (*actual < *anterior) {
            *salida = actual;
            salida++;
            (*totalDesordenados)++;
        }
        anterior++;
        actual++;
    }
}

void mostrarDesordenados(int *arreglo, int **desordenados, int totalDesordenados) {
    int i;

    if (totalDesordenados == 0) {
        printf("El arreglo esta ordenado en forma creciente.\n");
        return;
    }

    for (i = 0; i < totalDesordenados; i++) {
        int *elemento = *(desordenados + i);
        int posicion = (int)(elemento - arreglo) + 1;
        printf("El %d esta desordenado y es el elemento numero %d del arreglo.\n",
               *elemento, posicion);
    }
}

void ejecutarPrograma(void) {
    int arreglo[MAX];
    int *desordenados[MAX];
    int cantidad;
    int totalDesordenados;

    leerArreglo(arreglo, &cantidad);
    buscarDesordenados(arreglo, cantidad, desordenados, &totalDesordenados);
    mostrarDesordenados(arreglo, desordenados, totalDesordenados);
}

int main(void) {
    ejecutarPrograma();
    return 0;
}
