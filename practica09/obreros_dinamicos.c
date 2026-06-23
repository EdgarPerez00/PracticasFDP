//Edgar Israel Perez Garcia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBREROS 40
#define LARGO 60

struct Obrero {
    char nombre[LARGO];
    char direccion[LARGO];
    int horasExtra;
    int valorPorHora;
    float total;
    float salario;
    int activo;
};

void limpiarBuffer(void);
void leerCadena(char *cadena, int largo);
void calcularSobresueldo(struct Obrero *obrero);
void agregarObrero(struct Obrero *obreros, int *cantidad);
struct Obrero *buscarObrero(struct Obrero *obreros, int cantidad, const char *nombre);
void imprimirObrero(struct Obrero *obrero);
void verObreros(struct Obrero *obreros, int cantidad);
void modificarObrero(struct Obrero *obreros, int cantidad);
void agregarHorasExtra(struct Obrero *obreros, int cantidad);
void ejecutarObreros(void);

void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void leerCadena(char *cadena, int largo) {
    if (fgets(cadena, largo, stdin) != NULL) {
        cadena[strcspn(cadena, "\n")] = '\0';
    }
}

void calcularSobresueldo(struct Obrero *obrero) {
    obrero->total = (float)(obrero->horasExtra * obrero->valorPorHora);
}

void agregarObrero(struct Obrero *obreros, int *cantidad) {
    struct Obrero *nuevo;

    if (*cantidad >= MAX_OBREROS) {
        printf("No hay espacio.\n");
        return;
    }

    nuevo = obreros + *cantidad;
    printf("Nombre: ");
    leerCadena(nuevo->nombre, LARGO);
    printf("Direccion: ");
    leerCadena(nuevo->direccion, LARGO);
    printf("Salario base: ");
    scanf("%f", &nuevo->salario);
    printf("Horas extra: ");
    scanf("%d", &nuevo->horasExtra);
    printf("Valor por hora extra: ");
    scanf("%d", &nuevo->valorPorHora);
    limpiarBuffer();
    calcularSobresueldo(nuevo);
    nuevo->salario += nuevo->total;
    nuevo->activo = 1;
    (*cantidad)++;
}

struct Obrero *buscarObrero(struct Obrero *obreros, int cantidad, const char *nombre) {
    struct Obrero *ptr = obreros;
    struct Obrero *fin = obreros + cantidad;

    while (ptr < fin) {
        if (ptr->activo && strcmp(ptr->nombre, nombre) == 0) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

void imprimirObrero(struct Obrero *obrero) {
    printf("%s | Horas extra: %d | Valor hora: %d | Total extra: %.2f | Salario: %.2f\n",
           obrero->nombre, obrero->horasExtra, obrero->valorPorHora, obrero->total, obrero->salario);
}

void verObreros(struct Obrero *obreros, int cantidad) {
    struct Obrero *ptr = obreros;
    struct Obrero *fin = obreros + cantidad;

    while (ptr < fin) {
        if (ptr->activo) {
            imprimirObrero(ptr);
        }
        ptr++;
    }
}

void modificarObrero(struct Obrero *obreros, int cantidad) {
    char nombre[LARGO];
    struct Obrero *obrero;

    printf("Nombre a modificar: ");
    leerCadena(nombre, LARGO);
    obrero = buscarObrero(obreros, cantidad, nombre);
    if (obrero == NULL) {
        printf("No encontrado.\n");
        return;
    }
    printf("Nueva direccion: ");
    leerCadena(obrero->direccion, LARGO);
    printf("Nuevo salario base: ");
    scanf("%f", &obrero->salario);
    limpiarBuffer();
}

void agregarHorasExtra(struct Obrero *obreros, int cantidad) {
    char nombre[LARGO];
    struct Obrero *obrero;

    printf("Nombre del obrero: ");
    leerCadena(nombre, LARGO);
    obrero = buscarObrero(obreros, cantidad, nombre);
    if (obrero == NULL) {
        printf("No encontrado.\n");
        return;
    }
    printf("Horas extra nuevas: ");
    scanf("%d", &obrero->horasExtra);
    printf("Valor por hora: ");
    scanf("%d", &obrero->valorPorHora);
    limpiarBuffer();
    calcularSobresueldo(obrero);
    obrero->salario += obrero->total;
}

void ejecutarObreros(void) {
    struct Obrero *obreros = (struct Obrero *)calloc(MAX_OBREROS, sizeof(struct Obrero));
    int cantidad = 0;
    int opcion;

    if (obreros == NULL) {
        printf("No se pudo reservar memoria.\n");
        return;
    }

    do {
        printf("\n1. Agregar obrero\n2. Ver obreros\n3. Modificar\n4. Agregar horas extra\n5. Salir\nOpcion: ");
        if (scanf("%d", &opcion) != 1) {
            break;
        }
        limpiarBuffer();

        if (opcion == 1) {
            agregarObrero(obreros, &cantidad);
        } else if (opcion == 2) {
            verObreros(obreros, cantidad);
        } else if (opcion == 3) {
            modificarObrero(obreros, cantidad);
        } else if (opcion == 4) {
            agregarHorasExtra(obreros, cantidad);
        }
    } while (opcion != 5);

    free(obreros);
}

int main(void) {
    ejecutarObreros();
    return 0;
}
