//Edgar Israel Perez Garcia
#include <stdio.h>
#include <string.h>

#define MIN_ALUMNOS 15
#define MAX_ALUMNOS 32
#define MAX_RUBROS 3
#define LARGO_NOMBRE 50
#define LARGO_BOLETA 16

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

int leerCantidadAlumnos(void) {
    int cantidad;

    do {
        printf("Ingrese cantidad de alumnos (%d a %d): ", MIN_ALUMNOS, MAX_ALUMNOS);
        if (scanf("%d", &cantidad) != 1) {
            limpiarBuffer();
            cantidad = 0;
        }
    } while (cantidad < MIN_ALUMNOS || cantidad > MAX_ALUMNOS);

    limpiarBuffer();
    return cantidad;
}

float leerCalificacion(const char *rubro) {
    float calificacion;

    do {
        printf("%s (0 a 10): ", rubro);
        if (scanf("%f", &calificacion) != 1) {
            limpiarBuffer();
            calificacion = -1.0f;
        }
    } while (calificacion < 0.0f || calificacion > 10.0f);

    return calificacion;
}

void leerAlumnos(char nombres[][LARGO_NOMBRE], char boletas[][LARGO_BOLETA],
                 float calificaciones[][MAX_RUBROS], int cantidad) {
    int i;

    for (i = 0; i < cantidad; i++) {
        printf("\nAlumno %d\n", i + 1);
        printf("Nombre: ");
        leerCadena(nombres[i], LARGO_NOMBRE);
        printf("Boleta: ");
        leerCadena(boletas[i], LARGO_BOLETA);
        calificaciones[i][0] = leerCalificacion("Promedio de tareas");
        calificaciones[i][1] = leerCalificacion("Promedio de trabajos");
        calificaciones[i][2] = leerCalificacion("Examen");
        limpiarBuffer();
    }
}

float calcularPromedio(float calificaciones[][MAX_RUBROS], int alumno) {
    return (calificaciones[alumno][0] + calificaciones[alumno][1] + calificaciones[alumno][2]) / 3.0f;
}

void imprimirReporte(char nombres[][LARGO_NOMBRE], char boletas[][LARGO_BOLETA],
                     float calificaciones[][MAX_RUBROS], int cantidad) {
    int i;

    printf("\n--- Reporte final ---\n");
    for (i = 0; i < cantidad; i++) {
        printf("Alumno: %s | Boleta: %s\n", nombres[i], boletas[i]);
        printf("Tareas: %.2f, Trabajos: %.2f, Examen: %.2f, Promedio: %.2f\n\n",
               calificaciones[i][0],
               calificaciones[i][1],
               calificaciones[i][2],
               calcularPromedio(calificaciones, i));
    }
}

void ejecutarSistema(void) {
    char nombres[MAX_ALUMNOS][LARGO_NOMBRE];
    char boletas[MAX_ALUMNOS][LARGO_BOLETA];
    float calificaciones[MAX_ALUMNOS][MAX_RUBROS];
    int cantidad = leerCantidadAlumnos();

    leerAlumnos(nombres, boletas, calificaciones, cantidad);
    imprimirReporte(nombres, boletas, calificaciones, cantidad);
}

int main(void) {
    ejecutarSistema();
    return 0;
}
