//Edgar Israel Perez Garcia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBREROS 100
#define MAX_DEPTOS 30
#define ARCH_OBREROS "empresa_obreros.txt"
#define ARCH_DEPTOS "empresa_departamentos.txt"
#define ARCH_SUELDOS "empresa_sueldos.txt"
#define ARCH_RESPALDO "empresa_obreros_respaldo.txt"

struct Obrero {
    int codigo;
    char apellido[30];
    char nombre[25];
    int edad;
    char direccion[35];
    int codigoPostal;
    int codigoDepartamento;
    int activo;
};

struct Departamento {
    int codigoDepartamento;
    char nombreDepartamento[35];
    int activo;
};

struct Sueldo {
    int codigo;
    long sueldoBase;
    long otros;
    int activo;
};

struct Auxiliar {
    int codigo;
    char apellido[30];
};

void limpiarBuffer(void);
void leerCadena(char *cadena, int largo);
int siguienteCodigo(struct Obrero *obreros, int cantidad);
struct Obrero *buscarObrero(struct Obrero *obreros, int cantidad, int codigo);
struct Departamento *buscarDepartamento(struct Departamento *departamentos, int cantidad, int codigo);
struct Sueldo *buscarSueldo(struct Sueldo *sueldos, int cantidad, int codigo);
void agregarDepartamento(struct Departamento *departamentos, int *cantidadDeptos);
void agregarObrero(struct Obrero *obreros, int *cantidadObreros, struct Sueldo *sueldos, int *cantidadSueldos);
void listarObreros(struct Obrero *obreros, int cantidadObreros, struct Departamento *departamentos, int cantidadDeptos, struct Sueldo *sueldos, int cantidadSueldos);
void modificarObrero(struct Obrero *obreros, int cantidadObreros);
void eliminarObrero(struct Obrero *obreros, int cantidadObreros, struct Sueldo *sueldos, int cantidadSueldos);
void guardarArchivos(struct Obrero *obreros, int cantidadObreros, struct Departamento *departamentos, int cantidadDeptos, struct Sueldo *sueldos, int cantidadSueldos);
void cargarArchivos(struct Obrero *obreros, int *cantidadObreros, struct Departamento *departamentos, int *cantidadDeptos, struct Sueldo *sueldos, int *cantidadSueldos);
void respaldarArchivo(void);
void ejecutarEmpresaArchivo(void);

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

int siguienteCodigo(struct Obrero *obreros, int cantidad) {
    int mayor = 0;
    int i;

    for (i = 0; i < cantidad; i++) {
        if ((obreros + i)->codigo > mayor) {
            mayor = (obreros + i)->codigo;
        }
    }
    return mayor + 1;
}

struct Obrero *buscarObrero(struct Obrero *obreros, int cantidad, int codigo) {
    struct Obrero *ptr = obreros;
    struct Obrero *fin = obreros + cantidad;

    while (ptr < fin) {
        if (ptr->activo && ptr->codigo == codigo) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

struct Departamento *buscarDepartamento(struct Departamento *departamentos, int cantidad, int codigo) {
    struct Departamento *ptr = departamentos;
    struct Departamento *fin = departamentos + cantidad;

    while (ptr < fin) {
        if (ptr->activo && ptr->codigoDepartamento == codigo) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

struct Sueldo *buscarSueldo(struct Sueldo *sueldos, int cantidad, int codigo) {
    struct Sueldo *ptr = sueldos;
    struct Sueldo *fin = sueldos + cantidad;

    while (ptr < fin) {
        if (ptr->activo && ptr->codigo == codigo) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

void agregarDepartamento(struct Departamento *departamentos, int *cantidadDeptos) {
    struct Departamento *nuevo;

    if (*cantidadDeptos >= MAX_DEPTOS) {
        printf("No hay espacio para departamentos.\n");
        return;
    }

    nuevo = departamentos + *cantidadDeptos;
    printf("Codigo departamento: ");
    scanf("%d", &nuevo->codigoDepartamento);
    limpiarBuffer();
    printf("Nombre departamento: ");
    leerCadena(nuevo->nombreDepartamento, 35);
    nuevo->activo = 1;
    (*cantidadDeptos)++;
}

void agregarObrero(struct Obrero *obreros, int *cantidadObreros,
                   struct Sueldo *sueldos, int *cantidadSueldos) {
    struct Obrero *nuevo;
    struct Sueldo *sueldo;

    if (*cantidadObreros >= MAX_OBREROS || *cantidadSueldos >= MAX_OBREROS) {
        printf("No hay espacio.\n");
        return;
    }

    nuevo = obreros + *cantidadObreros;
    nuevo->codigo = siguienteCodigo(obreros, *cantidadObreros);
    printf("Apellido: ");
    leerCadena(nuevo->apellido, 30);
    printf("Nombre: ");
    leerCadena(nuevo->nombre, 25);
    printf("Edad: ");
    scanf("%d", &nuevo->edad);
    limpiarBuffer();
    printf("Direccion: ");
    leerCadena(nuevo->direccion, 35);
    printf("Codigo postal: ");
    scanf("%d", &nuevo->codigoPostal);
    printf("Codigo departamento: ");
    scanf("%d", &nuevo->codigoDepartamento);
    limpiarBuffer();
    nuevo->activo = 1;
    (*cantidadObreros)++;

    sueldo = sueldos + *cantidadSueldos;
    sueldo->codigo = nuevo->codigo;
    printf("Sueldo base: ");
    scanf("%ld", &sueldo->sueldoBase);
    printf("Otros pagos: ");
    scanf("%ld", &sueldo->otros);
    limpiarBuffer();
    sueldo->activo = 1;
    (*cantidadSueldos)++;
}

void listarObreros(struct Obrero *obreros, int cantidadObreros,
                   struct Departamento *departamentos, int cantidadDeptos,
                   struct Sueldo *sueldos, int cantidadSueldos) {
    struct Obrero *ptr = obreros;
    struct Obrero *fin = obreros + cantidadObreros;

    while (ptr < fin) {
        if (ptr->activo) {
            struct Departamento *depto = buscarDepartamento(departamentos, cantidadDeptos, ptr->codigoDepartamento);
            struct Sueldo *sueldo = buscarSueldo(sueldos, cantidadSueldos, ptr->codigo);
            printf("%d %s %s | Edad %d | %s | CP %d | Depto: %s | Total: %ld\n",
                   ptr->codigo,
                   ptr->apellido,
                   ptr->nombre,
                   ptr->edad,
                   ptr->direccion,
                   ptr->codigoPostal,
                   depto != NULL ? depto->nombreDepartamento : "Sin departamento",
                   sueldo != NULL ? sueldo->sueldoBase + sueldo->otros : 0L);
        }
        ptr++;
    }
}

void modificarObrero(struct Obrero *obreros, int cantidadObreros) {
    int codigo;
    struct Obrero *obrero;

    printf("Codigo a modificar: ");
    scanf("%d", &codigo);
    limpiarBuffer();
    obrero = buscarObrero(obreros, cantidadObreros, codigo);
    if (obrero == NULL) {
        printf("No encontrado.\n");
        return;
    }
    printf("Nueva direccion: ");
    leerCadena(obrero->direccion, 35);
    printf("Nuevo codigo postal: ");
    scanf("%d", &obrero->codigoPostal);
    limpiarBuffer();
}

void eliminarObrero(struct Obrero *obreros, int cantidadObreros,
                    struct Sueldo *sueldos, int cantidadSueldos) {
    int codigo;
    struct Obrero *obrero;
    struct Sueldo *sueldo;

    printf("Codigo a eliminar: ");
    scanf("%d", &codigo);
    limpiarBuffer();
    obrero = buscarObrero(obreros, cantidadObreros, codigo);
    sueldo = buscarSueldo(sueldos, cantidadSueldos, codigo);
    if (obrero != NULL) {
        obrero->activo = 0;
    }
    if (sueldo != NULL) {
        sueldo->activo = 0;
    }
}

void guardarArchivos(struct Obrero *obreros, int cantidadObreros,
                     struct Departamento *departamentos, int cantidadDeptos,
                     struct Sueldo *sueldos, int cantidadSueldos) {
    FILE *archivoObreros = fopen(ARCH_OBREROS, "w");
    FILE *archivoDeptos = fopen(ARCH_DEPTOS, "w");
    FILE *archivoSueldos = fopen(ARCH_SUELDOS, "w");
    int i;

    if (archivoObreros == NULL || archivoDeptos == NULL || archivoSueldos == NULL) {
        printf("No se pudieron guardar todos los archivos.\n");
        return;
    }

    for (i = 0; i < cantidadObreros; i++) {
        if ((obreros + i)->activo) {
            fprintf(archivoObreros, "%d|%s|%s|%d|%s|%d|%d\n",
                    (obreros + i)->codigo,
                    (obreros + i)->apellido,
                    (obreros + i)->nombre,
                    (obreros + i)->edad,
                    (obreros + i)->direccion,
                    (obreros + i)->codigoPostal,
                    (obreros + i)->codigoDepartamento);
        }
    }
    for (i = 0; i < cantidadDeptos; i++) {
        if ((departamentos + i)->activo) {
            fprintf(archivoDeptos, "%d|%s\n",
                    (departamentos + i)->codigoDepartamento,
                    (departamentos + i)->nombreDepartamento);
        }
    }
    for (i = 0; i < cantidadSueldos; i++) {
        if ((sueldos + i)->activo) {
            fprintf(archivoSueldos, "%d|%ld|%ld\n",
                    (sueldos + i)->codigo,
                    (sueldos + i)->sueldoBase,
                    (sueldos + i)->otros);
        }
    }

    fclose(archivoObreros);
    fclose(archivoDeptos);
    fclose(archivoSueldos);
}

void cargarArchivos(struct Obrero *obreros, int *cantidadObreros,
                    struct Departamento *departamentos, int *cantidadDeptos,
                    struct Sueldo *sueldos, int *cantidadSueldos) {
    FILE *archivoObreros = fopen(ARCH_OBREROS, "r");
    FILE *archivoDeptos = fopen(ARCH_DEPTOS, "r");
    FILE *archivoSueldos = fopen(ARCH_SUELDOS, "r");

    *cantidadObreros = 0;
    *cantidadDeptos = 0;
    *cantidadSueldos = 0;

    if (archivoObreros != NULL) {
        while (*cantidadObreros < MAX_OBREROS &&
               fscanf(archivoObreros, "%d|%29[^|]|%24[^|]|%d|%34[^|]|%d|%d\n",
                      &(obreros + *cantidadObreros)->codigo,
                      (obreros + *cantidadObreros)->apellido,
                      (obreros + *cantidadObreros)->nombre,
                      &(obreros + *cantidadObreros)->edad,
                      (obreros + *cantidadObreros)->direccion,
                      &(obreros + *cantidadObreros)->codigoPostal,
                      &(obreros + *cantidadObreros)->codigoDepartamento) == 7) {
            (obreros + *cantidadObreros)->activo = 1;
            (*cantidadObreros)++;
        }
        fclose(archivoObreros);
    }

    if (archivoDeptos != NULL) {
        while (*cantidadDeptos < MAX_DEPTOS &&
               fscanf(archivoDeptos, "%d|%34[^\n]\n",
                      &(departamentos + *cantidadDeptos)->codigoDepartamento,
                      (departamentos + *cantidadDeptos)->nombreDepartamento) == 2) {
            (departamentos + *cantidadDeptos)->activo = 1;
            (*cantidadDeptos)++;
        }
        fclose(archivoDeptos);
    }

    if (archivoSueldos != NULL) {
        while (*cantidadSueldos < MAX_OBREROS &&
               fscanf(archivoSueldos, "%d|%ld|%ld\n",
                      &(sueldos + *cantidadSueldos)->codigo,
                      &(sueldos + *cantidadSueldos)->sueldoBase,
                      &(sueldos + *cantidadSueldos)->otros) == 3) {
            (sueldos + *cantidadSueldos)->activo = 1;
            (*cantidadSueldos)++;
        }
        fclose(archivoSueldos);
    }
}

void respaldarArchivo(void) {
    FILE *origen = fopen(ARCH_OBREROS, "r");
    FILE *destino = fopen(ARCH_RESPALDO, "w");
    int c;

    if (origen == NULL || destino == NULL) {
        printf("No se pudo crear el respaldo.\n");
        if (origen != NULL) {
            fclose(origen);
        }
        if (destino != NULL) {
            fclose(destino);
        }
        return;
    }

    while ((c = fgetc(origen)) != EOF) {
        fputc(c, destino);
    }
    fclose(origen);
    fclose(destino);
    printf("Respaldo creado en %s\n", ARCH_RESPALDO);
}

void ejecutarEmpresaArchivo(void) {
    struct Obrero *obreros = (struct Obrero *)calloc(MAX_OBREROS, sizeof(struct Obrero));
    struct Departamento *departamentos = (struct Departamento *)calloc(MAX_DEPTOS, sizeof(struct Departamento));
    struct Sueldo *sueldos = (struct Sueldo *)calloc(MAX_OBREROS, sizeof(struct Sueldo));
    struct Auxiliar *auxiliares = (struct Auxiliar *)calloc(MAX_OBREROS, sizeof(struct Auxiliar));
    int cantidadObreros;
    int cantidadDeptos;
    int cantidadSueldos;
    int opcion;

    if (obreros == NULL || departamentos == NULL || sueldos == NULL || auxiliares == NULL) {
        printf("No se pudo reservar memoria.\n");
        free(obreros);
        free(departamentos);
        free(sueldos);
        free(auxiliares);
        return;
    }

    cargarArchivos(obreros, &cantidadObreros, departamentos, &cantidadDeptos, sueldos, &cantidadSueldos);
    do {
        printf("\n1. Agregar departamento\n2. Agregar obrero\n3. Listar obreros\n");
        printf("4. Modificar obrero\n5. Eliminar obrero\n6. Guardar\n7. Respaldo\n8. Salir\nOpcion: ");
        if (scanf("%d", &opcion) != 1) {
            break;
        }
        limpiarBuffer();

        if (opcion == 1) {
            agregarDepartamento(departamentos, &cantidadDeptos);
        } else if (opcion == 2) {
            agregarObrero(obreros, &cantidadObreros, sueldos, &cantidadSueldos);
        } else if (opcion == 3) {
            listarObreros(obreros, cantidadObreros, departamentos, cantidadDeptos, sueldos, cantidadSueldos);
        } else if (opcion == 4) {
            modificarObrero(obreros, cantidadObreros);
        } else if (opcion == 5) {
            eliminarObrero(obreros, cantidadObreros, sueldos, cantidadSueldos);
        } else if (opcion == 6) {
            guardarArchivos(obreros, cantidadObreros, departamentos, cantidadDeptos, sueldos, cantidadSueldos);
        } else if (opcion == 7) {
            guardarArchivos(obreros, cantidadObreros, departamentos, cantidadDeptos, sueldos, cantidadSueldos);
            respaldarArchivo();
        }
    } while (opcion != 8);

    guardarArchivos(obreros, cantidadObreros, departamentos, cantidadDeptos, sueldos, cantidadSueldos);
    free(obreros);
    free(departamentos);
    free(sueldos);
    free(auxiliares);
}

int main(void) {
    ejecutarEmpresaArchivo();
    return 0;
}
