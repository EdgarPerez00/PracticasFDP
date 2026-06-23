//Edgar Israel Perez Garcia
#include <stdio.h>

#define MAX_TEXTO 2200

void cargar(int *ptrLongitud, char *texto);
void modificar(char *ptrTexto, int longitud, char buscado, char reemplazo, char *nuevoTexto);
void contar(char *ptrTexto, int longitud, char caracter, int *ptrCuantos);
void buscar(char *ptrTexto, int longitud, char *buscado);
void imprimirResultado(char *textoOriginal, char *textoModificado, int reemplazos);
void ejecutarMenu(char *texto, int longitud);

void cargar(int *ptrLongitud, char *texto) {
    int c;
    char *ptr = texto;

    printf("Ingrese el texto. Termine con Ctrl+Z y Enter, o con una linea que inicie con '#'.\n");
    *ptrLongitud = 0;
    while (*ptrLongitud < MAX_TEXTO - 1 && (c = getchar()) != EOF) {
        if (c == '#' && (*ptrLongitud == 0 || *(ptr - 1) == '\n')) {
            break;
        }
        *ptr = (char)c;
        ptr++;
        (*ptrLongitud)++;
    }
    *ptr = '\0';
}

void modificar(char *ptrTexto, int longitud, char buscado, char reemplazo, char *nuevoTexto) {
    char *origen = ptrTexto;
    char *destino = nuevoTexto;
    int i;

    for (i = 0; i < longitud; i++) {
        if (*origen == buscado) {
            *destino = reemplazo;
        } else {
            *destino = *origen;
        }
        origen++;
        destino++;
    }
    *destino = '\0';
}

void contar(char *ptrTexto, int longitud, char caracter, int *ptrCuantos) {
    int i;
    char *ptr = ptrTexto;

    *ptrCuantos = 0;
    for (i = 0; i < longitud; i++) {
        if (*ptr == caracter) {
            (*ptrCuantos)++;
        }
        ptr++;
    }
}

void buscar(char *ptrTexto, int longitud, char *buscado) {
    int i;
    char *ptr = ptrTexto;

    printf("Caracter a buscar: ");
    scanf(" %c", buscado);

    for (i = 0; i < longitud; i++) {
        if (*ptr == *buscado) {
            printf("Texto desde la primera ocurrencia:\n%s\n", ptr);
            return;
        }
        ptr++;
    }
    printf("El caracter no existe en el texto.\n");
}

void imprimirResultado(char *textoOriginal, char *textoModificado, int reemplazos) {
    printf("\nTexto original:\n%s\n", textoOriginal);
    printf("\nTexto modificado:\n%s\n", textoModificado);
    printf("Cantidad de reemplazos: %d\n", reemplazos);
}

void ejecutarMenu(char *texto, int longitud) {
    int opcion;

    do {
        printf("\n1. Modificar\n");
        printf("2. Contar\n");
        printf("3. Buscar\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            return;
        }

        if (opcion == 1) {
            char buscado;
            char reemplazo;
            char nuevoTexto[MAX_TEXTO];
            int reemplazos;

            printf("Caracter a reemplazar: ");
            scanf(" %c", &buscado);
            printf("Caracter de reemplazo: ");
            scanf(" %c", &reemplazo);
            contar(texto, longitud, buscado, &reemplazos);
            modificar(texto, longitud, buscado, reemplazo, nuevoTexto);
            imprimirResultado(texto, nuevoTexto, reemplazos);
        } else if (opcion == 2) {
            char caracter;
            int cuantos;
            printf("Caracter a contar: ");
            scanf(" %c", &caracter);
            contar(texto, longitud, caracter, &cuantos);
            printf("El caracter aparece %d veces.\n", cuantos);
        } else if (opcion == 3) {
            char buscado;
            buscar(texto, longitud, &buscado);
        } else if (opcion != 4) {
            printf("Opcion no valida.\n");
        }
    } while (opcion != 4);
}

int main(void) {
    char texto[MAX_TEXTO];
    int longitud;

    cargar(&longitud, texto);
    ejecutarMenu(texto, longitud);

    return 0;
}
