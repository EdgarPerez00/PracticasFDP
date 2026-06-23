//Edgar Israel Perez Garcia
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEXTO 1000
#define LETRAS 26

void reservarMemoria(char **letras, int **conteos);
void inicializarLetras(char *letras);
void leerYContar(int *conteos);
void ordenarPorFrecuencia(char *letras, int *conteos);
void imprimirResultados(char *letras, int *conteos);
void ejecutarLetras(void);

void reservarMemoria(char **letras, int **conteos) {
    *letras = (char *)malloc(sizeof(char) * LETRAS);
    *conteos = (int *)calloc(LETRAS, sizeof(int));
}

void inicializarLetras(char *letras) {
    int i;
    for (i = 0; i < LETRAS; i++) {
        *(letras + i) = (char)('a' + i);
    }
}

void leerYContar(int *conteos) {
    int caracter;

    printf("Ingrese texto en minusculas. Termine con punto '.'.\n");
    while ((caracter = getchar()) != EOF && caracter != '.') {
        caracter = tolower(caracter);
        if (caracter >= 'a' && caracter <= 'z') {
            (*(conteos + (caracter - 'a')))++;
        }
    }
}

void ordenarPorFrecuencia(char *letras, int *conteos) {
    int i;
    int j;

    for (i = 0; i < LETRAS - 1; i++) {
        for (j = i + 1; j < LETRAS; j++) {
            if (*(conteos + i) < *(conteos + j)) {
                int conteoAux = *(conteos + i);
                char letraAux = *(letras + i);
                *(conteos + i) = *(conteos + j);
                *(letras + i) = *(letras + j);
                *(conteos + j) = conteoAux;
                *(letras + j) = letraAux;
            }
        }
    }
}

void imprimirResultados(char *letras, int *conteos) {
    int i;

    printf("\nLetra Numero de ocurrencias\n");
    for (i = 0; i < LETRAS; i++) {
        if (*(conteos + i) > 0) {
            printf("%c %d\n", *(letras + i), *(conteos + i));
        }
    }
}

void ejecutarLetras(void) {
    char *letras;
    int *conteos;

    reservarMemoria(&letras, &conteos);
    if (letras == NULL || conteos == NULL) {
        printf("No se pudo reservar memoria.\n");
        free(letras);
        free(conteos);
        return;
    }

    inicializarLetras(letras);
    leerYContar(conteos);
    ordenarPorFrecuencia(letras, conteos);
    imprimirResultados(letras, conteos);

    free(letras);
    free(conteos);
}

int main(void) {
    ejecutarLetras();
    return 0;
}
