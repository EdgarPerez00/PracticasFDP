//Edgar Israel Perez Garcia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 100
#define MAX_BOLETA 32
#define MAX_NOMBRE 120
#define MAX_ARCHIVO 160

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

typedef struct RegistroArchivo {
    int activo;
    char boleta[MAX_BOLETA];
    char nombre[MAX_NOMBRE];
    Calificacion notas;
} RegistroArchivo;

void registrarEstudiante(Estudiante *lista, int *total);
void mostrarEstudiantes(const Estudiante *lista, int total);
void buscarEstudiante(const Estudiante *lista, int total);
void modificarEstudiante(Estudiante *lista, int total);
void eliminarEstudiante(Estudiante *lista, int *total);
void guardarEnArchivo(const Estudiante *lista, int total);
void cargarDesdeArchivo(Estudiante *lista, int *total);

static void liberarEstudiante(Estudiante *estudiante);
static void liberarLista(Estudiante *lista, int total);
static void inicializarLista(Estudiante *lista);
static void leerLinea(const char *mensaje, char *destino, int capacidad);
static float leerCalificacion(const char *mensaje);
static int leerEntero(const char *mensaje);
static char *duplicarCadena(const char *origen);
static int buscarIndicePorBoleta(const Estudiante *lista, int total, const char *boleta);
static int buscarEspacioDisponible(const Estudiante *lista, int total);
static int contarActivos(const Estudiante *lista, int total);
static float calcularPromedio(const Calificacion *notas);
static void capturarCalificaciones(Calificacion *notas);
static void imprimirEstudiante(const Estudiante *estudiante, int posicion);

int main(void) {
    Estudiante lista[MAX_ESTUDIANTES];
    int total = 0;
    int opcion;

    inicializarLista(lista);

    do {
        printf("\n1. Registrar estudiante\n");
        printf("2. Mostrar estudiantes\n");
        printf("3. Buscar estudiante\n");
        printf("4. Modificar estudiante\n");
        printf("5. Eliminar estudiante\n");
        printf("6. Guardar en archivo binario\n");
        printf("7. Cargar desde archivo binario\n");
        printf("8. Salir\n");
        opcion = leerEntero("Opcion: ");

        switch (opcion) {
            case 1:
                registrarEstudiante(lista, &total);
                break;
            case 2:
                mostrarEstudiantes(lista, total);
                break;
            case 3:
                buscarEstudiante(lista, total);
                break;
            case 4:
                modificarEstudiante(lista, total);
                break;
            case 5:
                eliminarEstudiante(lista, &total);
                break;
            case 6:
                guardarEnArchivo(lista, total);
                break;
            case 7:
                cargarDesdeArchivo(lista, &total);
                break;
            case 8:
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 8);

    liberarLista(lista, total);
    return 0;
}

void registrarEstudiante(Estudiante *lista, int *total) {
    int posicion;
    char boleta[MAX_BOLETA];
    char nombre[MAX_NOMBRE];

    posicion = buscarEspacioDisponible(lista, *total);
    if (posicion == -1) {
        if (*total >= MAX_ESTUDIANTES) {
            printf("No hay espacio disponible para mas estudiantes.\n");
            return;
        }
        posicion = *total;
        (*total)++;
    }

    leerLinea("Boleta: ", boleta, MAX_BOLETA);
    if (boleta[0] == '\0') {
        printf("La boleta no puede quedar vacia.\n");
        if (posicion == *total - 1 && lista[posicion].boleta == NULL) {
            (*total)--;
        }
        return;
    }

    if (buscarIndicePorBoleta(lista, *total, boleta) != -1) {
        printf("Ya existe un estudiante con esa boleta.\n");
        if (posicion == *total - 1 && lista[posicion].boleta == NULL) {
            (*total)--;
        }
        return;
    }

    leerLinea("Nombre: ", nombre, MAX_NOMBRE);
    if (nombre[0] == '\0') {
        printf("El nombre no puede quedar vacio.\n");
        if (posicion == *total - 1 && lista[posicion].boleta == NULL) {
            (*total)--;
        }
        return;
    }

    lista[posicion].boleta = duplicarCadena(boleta);
    lista[posicion].nombre = duplicarCadena(nombre);
    lista[posicion].notas = (Calificacion *)malloc(sizeof(Calificacion));

    if (lista[posicion].boleta == NULL || lista[posicion].nombre == NULL || lista[posicion].notas == NULL) {
        printf("No se pudo reservar memoria.\n");
        liberarEstudiante(&lista[posicion]);
        if (posicion == *total - 1) {
            (*total)--;
        }
        return;
    }

    capturarCalificaciones(lista[posicion].notas);
    printf("Estudiante registrado en la posicion %d.\n", posicion);
}

void mostrarEstudiantes(const Estudiante *lista, int total) {
    int i;

    if (contarActivos(lista, total) == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        if ((lista + i)->boleta != NULL) {
            imprimirEstudiante(lista + i, i);
        }
    }
}

void buscarEstudiante(const Estudiante *lista, int total) {
    char boleta[MAX_BOLETA];
    int indice;

    leerLinea("Boleta a buscar: ", boleta, MAX_BOLETA);
    indice = buscarIndicePorBoleta(lista, total, boleta);
    if (indice == -1) {
        printf("No se encontro la boleta indicada.\n");
        return;
    }

    imprimirEstudiante(lista + indice, indice);
    printf("Promedio: %.2f\n", calcularPromedio((lista + indice)->notas));
}

void modificarEstudiante(Estudiante *lista, int total) {
    char boleta[MAX_BOLETA];
    char nombre[MAX_NOMBRE];
    int indice;

    leerLinea("Boleta del estudiante a modificar: ", boleta, MAX_BOLETA);
    indice = buscarIndicePorBoleta(lista, total, boleta);
    if (indice == -1) {
        printf("No se encontro la boleta indicada.\n");
        return;
    }

    leerLinea("Nuevo nombre: ", nombre, MAX_NOMBRE);
    if (nombre[0] != '\0') {
        char *nuevoNombre = duplicarCadena(nombre);
        if (nuevoNombre == NULL) {
            printf("No se pudo reservar memoria para el nombre.\n");
            return;
        }
        free((lista + indice)->nombre);
        (lista + indice)->nombre = nuevoNombre;
    }

    capturarCalificaciones((lista + indice)->notas);
    printf("Estudiante modificado.\n");
}

void eliminarEstudiante(Estudiante *lista, int *total) {
    char boleta[MAX_BOLETA];
    int indice;

    leerLinea("Boleta del estudiante a eliminar: ", boleta, MAX_BOLETA);
    indice = buscarIndicePorBoleta(lista, *total, boleta);
    if (indice == -1) {
        printf("No se encontro la boleta indicada.\n");
        return;
    }

    liberarEstudiante(lista + indice);
    printf("Estudiante eliminado. La posicion %d queda disponible.\n", indice);
}

void guardarEnArchivo(const Estudiante *lista, int total) {
    char nombreArchivo[MAX_ARCHIVO];
    FILE *archivo;
    int i;

    leerLinea("Nombre del archivo .bin: ", nombreArchivo, MAX_ARCHIVO);
    archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, archivo);
    for (i = 0; i < total; i++) {
        RegistroArchivo registro;
        memset(&registro, 0, sizeof(registro));

        if ((lista + i)->boleta != NULL) {
            registro.activo = 1;
            strncpy(registro.boleta, (lista + i)->boleta, MAX_BOLETA - 1);
            strncpy(registro.nombre, (lista + i)->nombre, MAX_NOMBRE - 1);
            registro.notas = *((lista + i)->notas);
        }

        fwrite(&registro, sizeof(registro), 1, archivo);
    }

    fclose(archivo);
    printf("Archivo guardado con %d posiciones y %d estudiantes activos.\n", total, contarActivos(lista, total));
}

void cargarDesdeArchivo(Estudiante *lista, int *total) {
    char nombreArchivo[MAX_ARCHIVO];
    FILE *archivo;
    int nuevoTotal;
    int i;

    leerLinea("Nombre del archivo .bin: ", nombreArchivo, MAX_ARCHIVO);
    archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para lectura.\n");
        return;
    }

    if (fread(&nuevoTotal, sizeof(int), 1, archivo) != 1 || nuevoTotal < 0 || nuevoTotal > MAX_ESTUDIANTES) {
        printf("El archivo no tiene un formato valido.\n");
        fclose(archivo);
        return;
    }

    liberarLista(lista, *total);
    inicializarLista(lista);
    *total = nuevoTotal;

    for (i = 0; i < *total; i++) {
        RegistroArchivo registro;
        if (fread(&registro, sizeof(registro), 1, archivo) != 1) {
            printf("El archivo termino antes de lo esperado.\n");
            liberarLista(lista, *total);
            inicializarLista(lista);
            *total = 0;
            fclose(archivo);
            return;
        }

        if (registro.activo) {
            (lista + i)->boleta = duplicarCadena(registro.boleta);
            (lista + i)->nombre = duplicarCadena(registro.nombre);
            (lista + i)->notas = (Calificacion *)malloc(sizeof(Calificacion));
            if ((lista + i)->boleta == NULL || (lista + i)->nombre == NULL || (lista + i)->notas == NULL) {
                printf("No se pudo reservar memoria al cargar.\n");
                liberarLista(lista, *total);
                inicializarLista(lista);
                *total = 0;
                fclose(archivo);
                return;
            }
            *((lista + i)->notas) = registro.notas;
        }
    }

    fclose(archivo);
    printf("Archivo cargado. Siguiente registro nuevo parte desde la posicion %d si no hay huecos.\n", *total);
}

static void liberarEstudiante(Estudiante *estudiante) {
    free(estudiante->boleta);
    free(estudiante->nombre);
    free(estudiante->notas);
    estudiante->boleta = NULL;
    estudiante->nombre = NULL;
    estudiante->notas = NULL;
}

static void liberarLista(Estudiante *lista, int total) {
    int i;
    for (i = 0; i < total; i++) {
        liberarEstudiante(lista + i);
    }
}

static void inicializarLista(Estudiante *lista) {
    int i;
    for (i = 0; i < MAX_ESTUDIANTES; i++) {
        (lista + i)->boleta = NULL;
        (lista + i)->nombre = NULL;
        (lista + i)->notas = NULL;
    }
}

static void leerLinea(const char *mensaje, char *destino, int capacidad) {
    size_t longitud;

    printf("%s", mensaje);
    if (fgets(destino, capacidad, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }

    longitud = strlen(destino);
    if (longitud > 0 && destino[longitud - 1] == '\n') {
        destino[longitud - 1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }
}

static float leerCalificacion(const char *mensaje) {
    char linea[64];
    float valor;
    int leidos;

    do {
        leerLinea(mensaje, linea, sizeof(linea));
        leidos = sscanf(linea, "%f", &valor);
        if (leidos != 1 || valor < 0.0f || valor > 10.0f) {
            printf("Ingrese una calificacion entre 0 y 10.\n");
        }
    } while (leidos != 1 || valor < 0.0f || valor > 10.0f);

    return valor;
}

static int leerEntero(const char *mensaje) {
    char linea[64];
    int valor;

    leerLinea(mensaje, linea, sizeof(linea));
    if (sscanf(linea, "%d", &valor) != 1) {
        return -1;
    }
    return valor;
}

static char *duplicarCadena(const char *origen) {
    char *copia = (char *)malloc(strlen(origen) + 1);
    if (copia != NULL) {
        strcpy(copia, origen);
    }
    return copia;
}

static int buscarIndicePorBoleta(const Estudiante *lista, int total, const char *boleta) {
    int i;
    for (i = 0; i < total; i++) {
        if ((lista + i)->boleta != NULL && strcmp((lista + i)->boleta, boleta) == 0) {
            return i;
        }
    }
    return -1;
}

static int buscarEspacioDisponible(const Estudiante *lista, int total) {
    int i;
    for (i = 0; i < total; i++) {
        if ((lista + i)->boleta == NULL) {
            return i;
        }
    }
    return -1;
}

static int contarActivos(const Estudiante *lista, int total) {
    int i;
    int activos = 0;
    for (i = 0; i < total; i++) {
        if ((lista + i)->boleta != NULL) {
            activos++;
        }
    }
    return activos;
}

static float calcularPromedio(const Calificacion *notas) {
    return (notas->matematicas + notas->programacion + notas->ingles +
            notas->discretas + notas->comunicacionOralYEscrita) / 5.0f;
}

static void capturarCalificaciones(Calificacion *notas) {
    notas->matematicas = leerCalificacion("Matematicas: ");
    notas->programacion = leerCalificacion("Programacion: ");
    notas->ingles = leerCalificacion("Ingles: ");
    notas->discretas = leerCalificacion("Discretas: ");
    notas->comunicacionOralYEscrita = leerCalificacion("Comunicacion oral y escrita: ");
}

static void imprimirEstudiante(const Estudiante *estudiante, int posicion) {
    printf("\nPosicion: %d\n", posicion);
    printf("Boleta: %s\n", estudiante->boleta);
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Matematicas: %.2f\n", estudiante->notas->matematicas);
    printf("Programacion: %.2f\n", estudiante->notas->programacion);
    printf("Ingles: %.2f\n", estudiante->notas->ingles);
    printf("Discretas: %.2f\n", estudiante->notas->discretas);
    printf("Comunicacion oral y escrita: %.2f\n", estudiante->notas->comunicacionOralYEscrita);
}
