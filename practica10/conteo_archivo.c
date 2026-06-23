//Edgar Israel Perez Garcia
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LETRAS 26
#define LARGO_ARCHIVO 80

int terminaConTxt(const char *nombre);
void inicializar(char *letras, int *conteos);
void contarArchivo(FILE *entrada, int *conteos);
void ordenar(char *letras, int *conteos);
void escribirResultados(FILE *salida, char *letras, int *conteos, const char *entrada, const char *nombreSalida);
void ejecutarConteoArchivo(void);

int terminaConTxt(const char *nombre) {
    size_t largo = strlen(nombre);
    return largo > 4 && strcmp(nombre + largo - 4, ".txt") == 0;
}

void inicializar(char *letras, int *conteos) {
    int i;
    for (i = 0; i < LETRAS; i++) {
        *(letras + i) = (char)('a' + i);
        *(conteos + i) = 0;
    }
}

void contarArchivo(FILE *entrada, int *conteos) {
    int caracter;

    while ((caracter = fgetc(entrada)) != EOF && caracter != '.') {
        caracter = tolower(caracter);
        if (caracter >= 'a' && caracter <= 'z') {
            (*(conteos + (caracter - 'a')))++;
        }
    }
}

void ordenar(char *letras, int *conteos) {
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

void escribirResultados(FILE *salida, char *letras, int *conteos, const char *entrada, const char *nombreSalida) {
    int i;

    fprintf(salida, "Lectura del archivo: %s\n", entrada);
    fprintf(salida, "Letra Numero de ocurrencias\n");
    for (i = 0; i < LETRAS; i++) {
        if (*(conteos + i) > 0) {
            fprintf(salida, "%c %d\n", *(letras + i), *(conteos + i));
        }
    }
    printf("Escritura de resultados: %s\n", nombreSalida);
}

void ejecutarConteoArchivo(void) {
    char nombreEntrada[LARGO_ARCHIVO];
    char nombreSalida[LARGO_ARCHIVO];
    char *letras = (char *)malloc(sizeof(char) * LETRAS);
    int *conteos = (int *)malloc(sizeof(int) * LETRAS);
    FILE *entrada;
    FILE *salida;

    if (letras == NULL || conteos == NULL) {
        printf("No se pudo reservar memoria.\n");
        free(letras);
        free(conteos);
        return;
    }

    printf("Archivo de entrada .txt: ");
    scanf("%79s", nombreEntrada);
    printf("Archivo de salida .txt: ");
    scanf("%79s", nombreSalida);

    if (!terminaConTxt(nombreEntrada) || !terminaConTxt(nombreSalida)) {
        printf("Los nombres deben terminar con .txt\n");
        free(letras);
        free(conteos);
        return;
    }

    entrada = fopen(nombreEntrada, "r");
    salida = fopen(nombreSalida, "w");
    if (entrada == NULL || salida == NULL) {
        printf("No se pudieron abrir los archivos.\n");
        if (entrada != NULL) {
            fclose(entrada);
        }
        if (salida != NULL) {
            fclose(salida);
        }
        free(letras);
        free(conteos);
        return;
    }

    inicializar(letras, conteos);
    contarArchivo(entrada, conteos);
    ordenar(letras, conteos);
    escribirResultados(salida, letras, conteos, nombreEntrada, nombreSalida);

    fclose(entrada);
    fclose(salida);
    free(letras);
    free(conteos);
}

int main(void) {
    ejecutarConteoArchivo();
    return 0;
}
