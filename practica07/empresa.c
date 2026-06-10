#include <stdio.h>
#include <string.h>

#define MAX_EMPLEADOS 30
#define LARGO_NOMBRE 60
#define LARGO_PUESTO 30

struct Empleado {
    char nombre[LARGO_NOMBRE];
    char sexo;
    char puesto[LARGO_PUESTO];
    float sueldo;
    int activo;
};

void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void leerCadena(char cadena[], int largo) {
    if (fgets(cadena, largo, stdin) != NULL) {
        cadena[strcspn(cadena, "\n")] = '\0';
    }
}

void leerEmpleado(struct Empleado empleados[], int *cantidad) {
    struct Empleado nuevo;

    if (*cantidad >= MAX_EMPLEADOS) {
        printf("No hay espacio para mas empleados.\n");
        return;
    }

    printf("Nombre: ");
    leerCadena(nuevo.nombre, LARGO_NOMBRE);
    printf("Sexo (M/F): ");
    scanf(" %c", &nuevo.sexo);
    limpiarBuffer();
    printf("Puesto: ");
    leerCadena(nuevo.puesto, LARGO_PUESTO);
    printf("Sueldo: ");
    scanf("%f", &nuevo.sueldo);
    limpiarBuffer();
    nuevo.activo = 1;

    empleados[*cantidad] = nuevo;
    (*cantidad)++;
}

int buscarEmpleado(struct Empleado empleados[], int cantidad, const char nombre[]) {
    int i;

    for (i = 0; i < cantidad; i++) {
        if (empleados[i].activo && strcmp(empleados[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void imprimirEmpleado(struct Empleado empleado) {
    printf("Nombre: %s | Sexo: %c | Puesto: %s | Sueldo: %.2f\n",
           empleado.nombre, empleado.sexo, empleado.puesto, empleado.sueldo);
}

void imprimirMayorMenorSueldo(struct Empleado empleados[], int cantidad) {
    int i;
    int indiceMayor = -1;
    int indiceMenor = -1;

    for (i = 0; i < cantidad; i++) {
        if (empleados[i].activo) {
            if (indiceMayor == -1 || empleados[i].sueldo > empleados[indiceMayor].sueldo) {
                indiceMayor = i;
            }
            if (indiceMenor == -1 || empleados[i].sueldo < empleados[indiceMenor].sueldo) {
                indiceMenor = i;
            }
        }
    }

    if (indiceMayor == -1) {
        printf("No hay empleados activos.\n");
        return;
    }

    printf("\nEmpleado con mayor sueldo:\n");
    imprimirEmpleado(empleados[indiceMayor]);
    printf("Empleado con menor sueldo:\n");
    imprimirEmpleado(empleados[indiceMenor]);
}

void buscarEImprimir(struct Empleado empleados[], int cantidad) {
    char nombre[LARGO_NOMBRE];
    int indice;

    printf("Nombre a buscar: ");
    leerCadena(nombre, LARGO_NOMBRE);
    indice = buscarEmpleado(empleados, cantidad, nombre);
    if (indice == -1) {
        printf("Empleado no encontrado.\n");
    } else {
        imprimirEmpleado(empleados[indice]);
    }
}

void modificarEmpleado(struct Empleado empleados[], int cantidad) {
    char nombre[LARGO_NOMBRE];
    int indice;

    printf("Nombre del empleado a modificar: ");
    leerCadena(nombre, LARGO_NOMBRE);
    indice = buscarEmpleado(empleados, cantidad, nombre);
    if (indice == -1) {
        printf("Empleado no encontrado.\n");
        return;
    }

    printf("Nuevo puesto: ");
    leerCadena(empleados[indice].puesto, LARGO_PUESTO);
    printf("Nuevo sueldo: ");
    scanf("%f", &empleados[indice].sueldo);
    limpiarBuffer();
    printf("Empleado modificado.\n");
}

void verProgramadores(struct Empleado empleados[], int cantidad) {
    int i;
    int encontrados = 0;

    printf("\n--- Programadores ---\n");
    for (i = 0; i < cantidad; i++) {
        if (empleados[i].activo && strcmp(empleados[i].puesto, "Programador") == 0) {
            imprimirEmpleado(empleados[i]);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("No hay programadores registrados.\n");
    }
}

void darBaja(struct Empleado empleados[], int cantidad) {
    char nombre[LARGO_NOMBRE];
    int indice;

    printf("Nombre del empleado a dar de baja: ");
    leerCadena(nombre, LARGO_NOMBRE);
    indice = buscarEmpleado(empleados, cantidad, nombre);
    if (indice == -1) {
        printf("Empleado no encontrado.\n");
        return;
    }
    empleados[indice].activo = 0;
    printf("Empleado dado de baja.\n");
}

void listarEmpleados(struct Empleado empleados[], int cantidad) {
    int i;

    printf("\n--- Empleados activos ---\n");
    for (i = 0; i < cantidad; i++) {
        if (empleados[i].activo) {
            imprimirEmpleado(empleados[i]);
        }
    }
}

void ejecutarEmpresa(void) {
    struct Empleado empleados[MAX_EMPLEADOS];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n1. Alta de empleado\n");
        printf("2. Mayor y menor sueldo\n");
        printf("3. Buscar empleado\n");
        printf("4. Modificar empleado\n");
        printf("5. Ver programadores\n");
        printf("6. Baja de empleado\n");
        printf("7. Listar empleados\n");
        printf("8. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            return;
        }
        limpiarBuffer();

        if (opcion == 1) {
            leerEmpleado(empleados, &cantidad);
        } else if (opcion == 2) {
            imprimirMayorMenorSueldo(empleados, cantidad);
        } else if (opcion == 3) {
            buscarEImprimir(empleados, cantidad);
        } else if (opcion == 4) {
            modificarEmpleado(empleados, cantidad);
        } else if (opcion == 5) {
            verProgramadores(empleados, cantidad);
        } else if (opcion == 6) {
            darBaja(empleados, cantidad);
        } else if (opcion == 7) {
            listarEmpleados(empleados, cantidad);
        } else if (opcion != 8) {
            printf("Opcion no valida.\n");
        }
    } while (opcion != 8);
}

int main(void) {
    ejecutarEmpresa();
    return 0;
}
