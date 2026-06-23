//Edgar Israel Perez Garcia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEA 160

typedef struct Calificacion {
    float matematicas;
    float programacion;
    float ingles;
    float discretas;
    float comunicacionOralYEscrita;
} Calificacion;

typedef struct Estudiante {
    char *boleta;
    char *nombre;
    struct Calificacion *notas;
} Estudiante;

static int configurarFlujos(int argc, char *argv[]);
static Estudiante *leerEstudiantes(int *total);
static void imprimirEstudiantes(const Estudiante *lista, int total);
static void liberarEstudiantes(Estudiante *lista, int total);
static char *duplicarCadena(const char *origen);
static int leerLinea(char *destino, int capacidad);
static float promedio(const Calificacion *notas);
static void mostrarUso(const char *programa);

int main(int argc, char *argv[]) {
    Estudiante *lista;
    int total = 0;

    if (!configurarFlujos(argc, argv)) {
        mostrarUso(argv[0]);
        return 1;
    }

    lista = leerEstudiantes(&total);
    if (lista == NULL && total > 0) {
        fprintf(stderr, "No se pudo reservar memoria.\n");
        return 1;
    }

    imprimirEstudiantes(lista, total);
    liberarEstudiantes(lista, total);

    return 0;
}

static int configurarFlujos(int argc, char *argv[]) {
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            if (freopen(argv[i + 1], "r", stdin) == NULL) {
                fprintf(stderr, "No se pudo redireccionar la entrada desde %s.\n", argv[i + 1]);
                return 0;
            }
            i++;
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            if (freopen(argv[i + 1], "w", stdout) == NULL) {
                fprintf(stderr, "No se pudo redireccionar la salida hacia %s.\n", argv[i + 1]);
                return 0;
            }
            i++;
        } else {
            return 0;
        }
    }

    return 1;
}

static Estudiante *leerEstudiantes(int *total) {
    char linea[MAX_LINEA];
    Estudiante *lista;
    int i;

    if (!leerLinea(linea, sizeof(linea)) || sscanf(linea, "%d", total) != 1 || *total < 0) {
        *total = 0;
        return NULL;
    }

    if (*total == 0) {
        return NULL;
    }

    lista = (Estudiante *)calloc((size_t)*total, sizeof(Estudiante));
    if (lista == NULL) {
        return NULL;
    }

    for (i = 0; i < *total; i++) {
        char boleta[MAX_LINEA];
        char nombre[MAX_LINEA];
        Calificacion notas;

        if (!leerLinea(boleta, sizeof(boleta)) ||
            !leerLinea(nombre, sizeof(nombre)) ||
            !leerLinea(linea, sizeof(linea)) ||
            sscanf(linea, "%f %f %f %f %f",
                   &notas.matematicas,
                   &notas.programacion,
                   &notas.ingles,
                   &notas.discretas,
                   &notas.comunicacionOralYEscrita) != 5) {
            liberarEstudiantes(lista, i);
            *total = 0;
            return NULL;
        }

        (lista + i)->boleta = duplicarCadena(boleta);
        (lista + i)->nombre = duplicarCadena(nombre);
        (lista + i)->notas = (Calificacion *)malloc(sizeof(Calificacion));
        if ((lista + i)->boleta == NULL || (lista + i)->nombre == NULL || (lista + i)->notas == NULL) {
            liberarEstudiantes(lista, i + 1);
            *total = 0;
            return NULL;
        }
        *((lista + i)->notas) = notas;
    }

    return lista;
}

static void imprimirEstudiantes(const Estudiante *lista, int total) {
    int i;

    printf("Reporte de estudiantes\n");
    printf("Total: %d\n", total);

    for (i = 0; i < total; i++) {
        printf("\nEstudiante %d\n", i + 1);
        printf("Boleta: %s\n", (lista + i)->boleta);
        printf("Nombre: %s\n", (lista + i)->nombre);
        printf("Matematicas: %.2f\n", (lista + i)->notas->matematicas);
        printf("Programacion: %.2f\n", (lista + i)->notas->programacion);
        printf("Ingles: %.2f\n", (lista + i)->notas->ingles);
        printf("Discretas: %.2f\n", (lista + i)->notas->discretas);
        printf("Comunicacion oral y escrita: %.2f\n", (lista + i)->notas->comunicacionOralYEscrita);
        printf("Promedio: %.2f\n", promedio((lista + i)->notas));
    }
}

static void liberarEstudiantes(Estudiante *lista, int total) {
    int i;

    if (lista == NULL) {
        return;
    }

    for (i = 0; i < total; i++) {
        free((lista + i)->boleta);
        free((lista + i)->nombre);
        free((lista + i)->notas);
    }
    free(lista);
}

static char *duplicarCadena(const char *origen) {
    char *copia = (char *)malloc(strlen(origen) + 1);
    if (copia != NULL) {
        strcpy(copia, origen);
    }
    return copia;
}

static int leerLinea(char *destino, int capacidad) {
    size_t longitud;

    if (fgets(destino, capacidad, stdin) == NULL) {
        return 0;
    }

    longitud = strlen(destino);
    if (longitud > 0 && destino[longitud - 1] == '\n') {
        destino[longitud - 1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }

    return 1;
}

static float promedio(const Calificacion *notas) {
    return (notas->matematicas + notas->programacion + notas->ingles +
            notas->discretas + notas->comunicacionOralYEscrita) / 5.0f;
}

static void mostrarUso(const char *programa) {
    fprintf(stderr, "Uso: %s [-i entrada.txt] [-o salida.txt]\n", programa);
    fprintf(stderr, "Formato de entrada:\n");
    fprintf(stderr, "N\nboleta\nnombre\nmatematicas programacion ingles discretas comunicacion\n");
}
