#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 30
#define LARGO 50

struct DatosPersonales {
    char nombre[LARGO];
    char origen[LARGO];
};

struct DatosLaborales {
    char area[LARGO];
    float sueldo;
};

struct Registro {
    struct DatosPersonales personales;
    struct DatosLaborales laborales;
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

struct Registro *buscarRegistro(struct Registro *registros, int cantidad, const char *nombre) {
    struct Registro *ptr = registros;
    struct Registro *fin = registros + cantidad;

    while (ptr < fin) {
        if (ptr->activo && strcmp(ptr->personales.nombre, nombre) == 0) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

void altaRegistro(struct Registro *registros, int *cantidad) {
    struct Registro *nuevo;

    if (*cantidad >= MAX_REGISTROS) {
        printf("No hay espacio disponible.\n");
        return;
    }

    nuevo = registros + *cantidad;
    printf("Nombre: ");
    leerCadena(nuevo->personales.nombre, LARGO);
    printf("Origen o pais: ");
    leerCadena(nuevo->personales.origen, LARGO);
    printf("Area/deporte: ");
    leerCadena(nuevo->laborales.area, LARGO);
    printf("Sueldo o medallas: ");
    scanf("%f", &nuevo->laborales.sueldo);
    limpiarBuffer();
    nuevo->activo = 1;
    (*cantidad)++;
}

void imprimirRegistro(struct Registro *registro) {
    printf("%s | %s | %s | %.2f\n",
           registro->personales.nombre,
           registro->personales.origen,
           registro->laborales.area,
           registro->laborales.sueldo);
}

void listarRegistros(struct Registro *registros, int cantidad) {
    struct Registro *ptr = registros;
    struct Registro *fin = registros + cantidad;

    while (ptr < fin) {
        if (ptr->activo) {
            imprimirRegistro(ptr);
        }
        ptr++;
    }
}

void modificarRegistro(struct Registro *registros, int cantidad) {
    char nombre[LARGO];
    struct Registro *registro;

    printf("Nombre a modificar: ");
    leerCadena(nombre, LARGO);
    registro = buscarRegistro(registros, cantidad, nombre);
    if (registro == NULL) {
        printf("No encontrado.\n");
        return;
    }

    printf("Nuevo origen o pais: ");
    leerCadena(registro->personales.origen, LARGO);
    printf("Nueva area/deporte: ");
    leerCadena(registro->laborales.area, LARGO);
    printf("Nuevo sueldo o medallas: ");
    scanf("%f", &registro->laborales.sueldo);
    limpiarBuffer();
}

void bajaRegistro(struct Registro *registros, int cantidad) {
    char nombre[LARGO];
    struct Registro *registro;

    printf("Nombre a dar de baja: ");
    leerCadena(nombre, LARGO);
    registro = buscarRegistro(registros, cantidad, nombre);
    if (registro == NULL) {
        printf("No encontrado.\n");
        return;
    }
    registro->activo = 0;
}

void ejecutarEstructurasAnidadas(void) {
    struct Registro registros[MAX_REGISTROS];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n1. Alta\n2. Buscar\n3. Modificar\n4. Baja\n5. Listar\n6. Salir\nOpcion: ");
        if (scanf("%d", &opcion) != 1) {
            return;
        }
        limpiarBuffer();

        if (opcion == 1) {
            altaRegistro(registros, &cantidad);
        } else if (opcion == 2) {
            char nombre[LARGO];
            struct Registro *encontrado;
            printf("Nombre a buscar: ");
            leerCadena(nombre, LARGO);
            encontrado = buscarRegistro(registros, cantidad, nombre);
            if (encontrado != NULL) {
                imprimirRegistro(encontrado);
            } else {
                printf("No encontrado.\n");
            }
        } else if (opcion == 3) {
            modificarRegistro(registros, cantidad);
        } else if (opcion == 4) {
            bajaRegistro(registros, cantidad);
        } else if (opcion == 5) {
            listarRegistros(registros, cantidad);
        }
    } while (opcion != 6);
}

int main(void) {
    ejecutarEstructurasAnidadas();
    return 0;
}
