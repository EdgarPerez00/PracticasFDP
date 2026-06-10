#include <stdio.h>
#include <string.h>

#define MAX_EMPLEADOS 30
#define LARGO 60

struct Empleado {
    char nombre[LARGO];
    char sexo;
    char puesto[LARGO];
    float sueldo;
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

struct Empleado *buscarEmpleado(struct Empleado *empleados, int cantidad, const char *nombre) {
    struct Empleado *ptr = empleados;
    struct Empleado *fin = empleados + cantidad;

    while (ptr < fin) {
        if (ptr->activo && strcmp(ptr->nombre, nombre) == 0) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

void altaEmpleado(struct Empleado *empleados, int *cantidad) {
    struct Empleado *nuevo;

    if (*cantidad >= MAX_EMPLEADOS) {
        printf("Arreglo lleno.\n");
        return;
    }

    nuevo = empleados + *cantidad;
    printf("Nombre: ");
    leerCadena(nuevo->nombre, LARGO);
    printf("Sexo (M/F): ");
    scanf(" %c", &nuevo->sexo);
    limpiarBuffer();
    printf("Puesto: ");
    leerCadena(nuevo->puesto, LARGO);
    printf("Sueldo: ");
    scanf("%f", &nuevo->sueldo);
    limpiarBuffer();
    nuevo->activo = 1;
    (*cantidad)++;
}

void imprimirEmpleado(struct Empleado *empleado) {
    printf("%s | %c | %s | %.2f\n",
           empleado->nombre, empleado->sexo, empleado->puesto, empleado->sueldo);
}

void listar(struct Empleado *empleados, int cantidad) {
    struct Empleado *ptr = empleados;
    struct Empleado *fin = empleados + cantidad;

    while (ptr < fin) {
        if (ptr->activo) {
            imprimirEmpleado(ptr);
        }
        ptr++;
    }
}

void mayorMenor(struct Empleado *empleados, int cantidad) {
    struct Empleado *ptr = empleados;
    struct Empleado *fin = empleados + cantidad;
    struct Empleado *mayor = NULL;
    struct Empleado *menor = NULL;

    while (ptr < fin) {
        if (ptr->activo) {
            if (mayor == NULL || ptr->sueldo > mayor->sueldo) {
                mayor = ptr;
            }
            if (menor == NULL || ptr->sueldo < menor->sueldo) {
                menor = ptr;
            }
        }
        ptr++;
    }

    if (mayor == NULL) {
        printf("No hay empleados activos.\n");
        return;
    }
    printf("Mayor sueldo: ");
    imprimirEmpleado(mayor);
    printf("Menor sueldo: ");
    imprimirEmpleado(menor);
}

void modificar(struct Empleado *empleados, int cantidad) {
    char nombre[LARGO];
    struct Empleado *empleado;

    printf("Nombre a modificar: ");
    leerCadena(nombre, LARGO);
    empleado = buscarEmpleado(empleados, cantidad, nombre);
    if (empleado == NULL) {
        printf("No encontrado.\n");
        return;
    }
    printf("Nuevo puesto: ");
    leerCadena(empleado->puesto, LARGO);
    printf("Nuevo sueldo: ");
    scanf("%f", &empleado->sueldo);
    limpiarBuffer();
}

void baja(struct Empleado *empleados, int cantidad) {
    char nombre[LARGO];
    struct Empleado *empleado;

    printf("Nombre a dar de baja: ");
    leerCadena(nombre, LARGO);
    empleado = buscarEmpleado(empleados, cantidad, nombre);
    if (empleado == NULL) {
        printf("No encontrado.\n");
        return;
    }
    empleado->activo = 0;
}

void ejecutarEmpresaPunteros(void) {
    struct Empleado empleados[MAX_EMPLEADOS];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n1. Alta\n2. Listar\n3. Mayor y menor sueldo\n4. Modificar\n5. Baja\n6. Salir\nOpcion: ");
        if (scanf("%d", &opcion) != 1) {
            return;
        }
        limpiarBuffer();
        if (opcion == 1) {
            altaEmpleado(empleados, &cantidad);
        } else if (opcion == 2) {
            listar(empleados, cantidad);
        } else if (opcion == 3) {
            mayorMenor(empleados, cantidad);
        } else if (opcion == 4) {
            modificar(empleados, cantidad);
        } else if (opcion == 5) {
            baja(empleados, cantidad);
        }
    } while (opcion != 6);
}

int main(void) {
    ejecutarEmpresaPunteros();
    return 0;
}
