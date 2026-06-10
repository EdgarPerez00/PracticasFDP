#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50
#define LARGO 40
#define ARCHIVO_OBREROS "obreros_practica10.txt"

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Identificacion {
    char nombre[LARGO];
    char apellido[LARGO];
    struct Fecha fechaNacimiento;
    char direccion[LARGO];
    char ciudad[LARGO];
};

struct Obrero {
    struct Identificacion datos;
    long sueldoBase;
    int activo;
};

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

void agregarObrero(struct Obrero *obreros, int *cantidad) {
    struct Obrero *nuevo;

    if (*cantidad >= N) {
        printf("No hay espacio.\n");
        return;
    }

    nuevo = obreros + *cantidad;
    printf("Nombre: ");
    leerCadena(nuevo->datos.nombre, LARGO);
    printf("Apellido: ");
    leerCadena(nuevo->datos.apellido, LARGO);
    printf("Fecha nacimiento (dia mes anio): ");
    scanf("%d %d %d", &nuevo->datos.fechaNacimiento.dia,
          &nuevo->datos.fechaNacimiento.mes,
          &nuevo->datos.fechaNacimiento.anio);
    limpiarBuffer();
    printf("Direccion: ");
    leerCadena(nuevo->datos.direccion, LARGO);
    printf("Ciudad: ");
    leerCadena(nuevo->datos.ciudad, LARGO);
    printf("Sueldo base: ");
    scanf("%ld", &nuevo->sueldoBase);
    limpiarBuffer();
    nuevo->activo = 1;
    (*cantidad)++;
}

void listarObreros(struct Obrero *obreros, int cantidad) {
    struct Obrero *ptr = obreros;
    struct Obrero *fin = obreros + cantidad;

    while (ptr < fin) {
        if (ptr->activo) {
            printf("%s %s | %02d/%02d/%04d | %s | %s | %ld\n",
                   ptr->datos.nombre,
                   ptr->datos.apellido,
                   ptr->datos.fechaNacimiento.dia,
                   ptr->datos.fechaNacimiento.mes,
                   ptr->datos.fechaNacimiento.anio,
                   ptr->datos.direccion,
                   ptr->datos.ciudad,
                   ptr->sueldoBase);
        }
        ptr++;
    }
}

void guardarArchivo(struct Obrero *obreros, int cantidad) {
    FILE *archivo = fopen(ARCHIVO_OBREROS, "w");
    struct Obrero *ptr = obreros;
    struct Obrero *fin = obreros + cantidad;

    if (archivo == NULL) {
        printf("No se pudo guardar el archivo.\n");
        return;
    }

    while (ptr < fin) {
        if (ptr->activo) {
            fprintf(archivo, "%s|%s|%d|%d|%d|%s|%s|%ld\n",
                    ptr->datos.nombre,
                    ptr->datos.apellido,
                    ptr->datos.fechaNacimiento.dia,
                    ptr->datos.fechaNacimiento.mes,
                    ptr->datos.fechaNacimiento.anio,
                    ptr->datos.direccion,
                    ptr->datos.ciudad,
                    ptr->sueldoBase);
        }
        ptr++;
    }
    fclose(archivo);
    printf("Informacion guardada en %s\n", ARCHIVO_OBREROS);
}

void cargarArchivo(struct Obrero *obreros, int *cantidad) {
    FILE *archivo = fopen(ARCHIVO_OBREROS, "r");
    struct Obrero *ptr = obreros;

    *cantidad = 0;
    if (archivo == NULL) {
        return;
    }

    while (*cantidad < N &&
           fscanf(archivo, "%39[^|]|%39[^|]|%d|%d|%d|%39[^|]|%39[^|]|%ld\n",
                  ptr->datos.nombre,
                  ptr->datos.apellido,
                  &ptr->datos.fechaNacimiento.dia,
                  &ptr->datos.fechaNacimiento.mes,
                  &ptr->datos.fechaNacimiento.anio,
                  ptr->datos.direccion,
                  ptr->datos.ciudad,
                  &ptr->sueldoBase) == 8) {
        ptr->activo = 1;
        ptr++;
        (*cantidad)++;
    }

    fclose(archivo);
}

void ejecutarObrerosArchivo(void) {
    struct Obrero *obreros = (struct Obrero *)calloc(N, sizeof(struct Obrero));
    int cantidad = 0;
    int opcion;

    if (obreros == NULL) {
        printf("No se pudo reservar memoria.\n");
        return;
    }

    cargarArchivo(obreros, &cantidad);
    do {
        printf("\n1. Agregar\n2. Listar\n3. Guardar\n4. Salir\nOpcion: ");
        if (scanf("%d", &opcion) != 1) {
            break;
        }
        limpiarBuffer();

        if (opcion == 1) {
            agregarObrero(obreros, &cantidad);
        } else if (opcion == 2) {
            listarObreros(obreros, cantidad);
        } else if (opcion == 3) {
            guardarArchivo(obreros, cantidad);
        }
    } while (opcion != 4);

    guardarArchivo(obreros, cantidad);
    free(obreros);
}

int main(void) {
    ejecutarObrerosArchivo();
    return 0;
}
