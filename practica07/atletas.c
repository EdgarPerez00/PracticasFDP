#include <stdio.h>
#include <string.h>

#define MAX_ATLETAS 30
#define LARGO_NOMBRE 40
#define LARGO_PAIS 25
#define LARGO_DEPORTE 30

struct Dato {
    char nombre[LARGO_NOMBRE];
    char pais[LARGO_PAIS];
};

struct Atleta {
    char deporte[LARGO_DEPORTE];
    struct Dato personal;
    int numeroMedallas;
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

void leerAtleta(struct Atleta *atletas, int *cantidad) {
    struct Atleta *nuevo;

    if (*cantidad >= MAX_ATLETAS) {
        printf("No hay espacio para mas atletas.\n");
        return;
    }

    nuevo = atletas + *cantidad;
    printf("Nombre: ");
    leerCadena(nuevo->personal.nombre, LARGO_NOMBRE);
    printf("Pais: ");
    leerCadena(nuevo->personal.pais, LARGO_PAIS);
    printf("Deporte: ");
    leerCadena(nuevo->deporte, LARGO_DEPORTE);
    printf("Numero de medallas: ");
    scanf("%d", &nuevo->numeroMedallas);
    limpiarBuffer();
    nuevo->activo = 1;
    (*cantidad)++;
}

struct Atleta *buscarAtleta(struct Atleta *atletas, int cantidad, const char *nombre) {
    struct Atleta *ptr = atletas;
    struct Atleta *fin = atletas + cantidad;

    while (ptr < fin) {
        if (ptr->activo && strcmp(ptr->personal.nombre, nombre) == 0) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

void imprimirAtleta(struct Atleta *atleta) {
    printf("%s | %s | %s | Medallas: %d\n",
           atleta->personal.nombre,
           atleta->personal.pais,
           atleta->deporte,
           atleta->numeroMedallas);
}

void atletaConMasMedallas(struct Atleta *atletas, int cantidad) {
    struct Atleta *ptr = atletas;
    struct Atleta *fin = atletas + cantidad;
    struct Atleta *mayor = NULL;

    while (ptr < fin) {
        if (ptr->activo && (mayor == NULL || ptr->numeroMedallas > mayor->numeroMedallas)) {
            mayor = ptr;
        }
        ptr++;
    }

    if (mayor == NULL) {
        printf("No hay atletas registrados.\n");
    } else {
        printf("Atleta con mas medallas:\n");
        imprimirAtleta(mayor);
    }
}

void modificarAtleta(struct Atleta *atletas, int cantidad) {
    char nombre[LARGO_NOMBRE];
    struct Atleta *atleta;

    printf("Nombre a modificar: ");
    leerCadena(nombre, LARGO_NOMBRE);
    atleta = buscarAtleta(atletas, cantidad, nombre);
    if (atleta == NULL) {
        printf("Atleta no encontrado.\n");
        return;
    }

    printf("Nuevo pais: ");
    leerCadena(atleta->personal.pais, LARGO_PAIS);
    printf("Nuevo deporte: ");
    leerCadena(atleta->deporte, LARGO_DEPORTE);
    printf("Nuevo numero de medallas: ");
    scanf("%d", &atleta->numeroMedallas);
    limpiarBuffer();
}

void listarAtletas(struct Atleta *atletas, int cantidad) {
    struct Atleta *ptr = atletas;
    struct Atleta *fin = atletas + cantidad;

    while (ptr < fin) {
        if (ptr->activo) {
            imprimirAtleta(ptr);
        }
        ptr++;
    }
}

void ejecutarAtletas(void) {
    struct Atleta atletas[MAX_ATLETAS];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n1. Alta atleta\n2. Mas medallas\n3. Buscar atleta\n4. Cambiar datos\n5. Listar\n6. Salir\nOpcion: ");
        if (scanf("%d", &opcion) != 1) {
            return;
        }
        limpiarBuffer();
        if (opcion == 1) {
            leerAtleta(atletas, &cantidad);
        } else if (opcion == 2) {
            atletaConMasMedallas(atletas, cantidad);
        } else if (opcion == 3) {
            char nombre[LARGO_NOMBRE];
            struct Atleta *encontrado;
            printf("Nombre a buscar: ");
            leerCadena(nombre, LARGO_NOMBRE);
            encontrado = buscarAtleta(atletas, cantidad, nombre);
            if (encontrado != NULL) {
                imprimirAtleta(encontrado);
            } else {
                printf("No encontrado.\n");
            }
        } else if (opcion == 4) {
            modificarAtleta(atletas, cantidad);
        } else if (opcion == 5) {
            listarAtletas(atletas, cantidad);
        }
    } while (opcion != 6);
}

int main(void) {
    ejecutarAtletas();
    return 0;
}
