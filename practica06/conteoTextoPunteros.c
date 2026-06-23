//Edgar Israel Perez Garcia
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXTO 1800
#define MAX_LINEAS 6

void cargar(char *texto);
void esVocal(char caracter, int *ptrContador);
int esConsonante(char caracter);
void contarVocales(char *texto);
void contarConsonantes(char *texto);
void contarEspeciales(char *texto);
void contarBlancos(char *texto);
void ejecutarMenu(char *texto);

void cargar(char *texto) {
    char linea[320];
    int lineas = 0;
    texto[0] = '\0';

    printf("Ingrese texto, maximo %d lineas. Escriba una linea vacia para terminar.\n", MAX_LINEAS);
    while (lineas < MAX_LINEAS && strlen(texto) < MAX_TEXTO - 1) {
        if (fgets(linea, sizeof(linea), stdin) == NULL) {
            break;
        }
        if (strcmp(linea, "\n") == 0) {
            break;
        }
        strncat(texto, linea, MAX_TEXTO - strlen(texto) - 1);
        lineas++;
    }
}

void esVocal(char caracter, int *ptrContador) {
    char c = (char)tolower((unsigned char)caracter);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        (*ptrContador)++;
    }
}

int esConsonante(char caracter) {
    char c = (char)tolower((unsigned char)caracter);
    if (!isalpha((unsigned char)c)) {
        return 0;
    }
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void contarVocales(char *texto) {
    int contador = 0;
    char *ptr = texto;

    while (*ptr != '\0') {
        esVocal(*ptr, &contador);
        ptr++;
    }
    printf("Vocales: %d\n", contador);
}

void contarConsonantes(char *texto) {
    int contador = 0;
    char *ptr = texto;

    while (*ptr != '\0') {
        if (esConsonante(*ptr)) {
            contador++;
        }
        ptr++;
    }
    printf("Consonantes: %d\n", contador);
}

void contarEspeciales(char *texto) {
    int contador = 0;
    char *ptr = texto;

    while (*ptr != '\0') {
        if (!isalnum((unsigned char)*ptr) && !isspace((unsigned char)*ptr)) {
            contador++;
        }
        ptr++;
    }
    printf("Caracteres especiales: %d\n", contador);
}

void contarBlancos(char *texto) {
    int contador = 0;
    char *ptr = texto;

    while (*ptr != '\0') {
        if (isspace((unsigned char)*ptr)) {
            contador++;
        }
        ptr++;
    }
    printf("Espacios en blanco y saltos: %d\n", contador);
}

void ejecutarMenu(char *texto) {
    int opcion;

    do {
        printf("\n1. Cuenta vocales\n");
        printf("2. Cuenta consonantes\n");
        printf("3. Cuenta caracteres especiales\n");
        printf("4. Cuenta caracteres de espacio en blanco\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            return;
        }

        if (opcion == 1) {
            contarVocales(texto);
        } else if (opcion == 2) {
            contarConsonantes(texto);
        } else if (opcion == 3) {
            contarEspeciales(texto);
        } else if (opcion == 4) {
            contarBlancos(texto);
        } else if (opcion != 5) {
            printf("Opcion no valida.\n");
        }
    } while (opcion != 5);
}

int main(void) {
    char texto[MAX_TEXTO];

    cargar(texto);
    ejecutarMenu(texto);

    return 0;
}
