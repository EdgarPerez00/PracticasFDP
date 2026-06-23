//Edgar Israel Perez Garcia
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 50

void llenarManual(int *vector, int *tamanio);
void llenarAleatorio(int *vector, int *tamanio);
void mostrarVector(int *vector, int *tamanio);
void buscarNumero(int *vector, int *tamanio, int *buscado, int *encontrados);
void ordenarAscendente(int *vector, int *tamanio);
void ordenarDescendente(int *vector, int *tamanio);
void ejecutarVector(void);

void llenarManual(int *vector, int *tamanio) {
    int *ptr = vector;
    int *fin = vector + *tamanio;

    while (ptr < fin) {
        printf("Valor %ld: ", (long)(ptr - vector + 1));
        scanf("%d", ptr);
        ptr++;
    }
}

void llenarAleatorio(int *vector, int *tamanio) {
    int *ptr = vector;
    int *fin = vector + *tamanio;

    srand((unsigned)time(NULL));
    while (ptr < fin) {
        *ptr = rand() % 101;
        ptr++;
    }
}

void mostrarVector(int *vector, int *tamanio) {
    int *ptr = vector;
    int *fin = vector + *tamanio;

    while (ptr < fin) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

void buscarNumero(int *vector, int *tamanio, int *buscado, int *encontrados) {
    int *ptr = vector;
    int *fin = vector + *tamanio;

    *encontrados = 0;
    while (ptr < fin) {
        if (*ptr == *buscado) {
            printf("Encontrado en posicion %ld\n", (long)(ptr - vector + 1));
            (*encontrados)++;
        }
        ptr++;
    }
    if (*encontrados == 0) {
        *encontrados = -1;
    }
}

void ordenarAscendente(int *vector, int *tamanio) {
    int *i;
    int *j;

    for (i = vector; i < vector + *tamanio - 1; i++) {
        for (j = i + 1; j < vector + *tamanio; j++) {
            if (*i > *j) {
                int aux = *i;
                *i = *j;
                *j = aux;
            }
        }
    }
}

void ordenarDescendente(int *vector, int *tamanio) {
    int *i;
    int *j;

    for (i = vector; i < vector + *tamanio - 1; i++) {
        for (j = i + 1; j < vector + *tamanio; j++) {
            if (*i < *j) {
                int aux = *i;
                *i = *j;
                *j = aux;
            }
        }
    }
}

void ejecutarVector(void) {
    int tamanio = TAMANIO;
    int *vector = (int *)malloc(sizeof(int) * TAMANIO);
    int opcion;

    if (vector == NULL) {
        printf("No se pudo reservar memoria.\n");
        return;
    }

    llenarAleatorio(vector, &tamanio);
    do {
        printf("\n1. Llenar manual\n2. Llenar aleatorio\n3. Mostrar\n4. Buscar\n");
        printf("5. Ordenar ascendente\n6. Ordenar descendente\n7. Salir\nOpcion: ");
        if (scanf("%d", &opcion) != 1) {
            break;
        }

        if (opcion == 1) {
            llenarManual(vector, &tamanio);
        } else if (opcion == 2) {
            llenarAleatorio(vector, &tamanio);
        } else if (opcion == 3) {
            mostrarVector(vector, &tamanio);
        } else if (opcion == 4) {
            int buscado;
            int encontrados;
            printf("Numero a buscar: ");
            scanf("%d", &buscado);
            buscarNumero(vector, &tamanio, &buscado, &encontrados);
            if (encontrados < 0) {
                printf("El numero no se encontro.\n");
            }
        } else if (opcion == 5) {
            ordenarAscendente(vector, &tamanio);
        } else if (opcion == 6) {
            ordenarDescendente(vector, &tamanio);
        }
    } while (opcion != 7);

    free(vector);
}

int main(void) {
    ejecutarVector();
    return 0;
}
