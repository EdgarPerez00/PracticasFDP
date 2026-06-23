#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ALUMNOS 15
#define MAX_ALUMNOS 32
#define MAX_RUBROS 3
#define LARGO_NOMBRE 50
#define LARGO_BOLETA 16
#define LARGO_LINEA 100

int main(void) {
    char nombres[MAX_ALUMNOS][LARGO_NOMBRE];
    char boletas[MAX_ALUMNOS][LARGO_BOLETA];
    char linea[LARGO_LINEA];
    float calificaciones[MAX_ALUMNOS][MAX_RUBROS];
    float promedio;
    int cantidad;
    int i;

    do {
        printf("Ingrese cantidad de alumnos (%d a %d): ", MIN_ALUMNOS, MAX_ALUMNOS);
        if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
            return 1;
        }
        cantidad = (int)strtol(linea, NULL, 10);
    } while (cantidad < MIN_ALUMNOS || cantidad > MAX_ALUMNOS);

    for (i = 0; i < cantidad; i++) {
        printf("\nAlumno %d\n", i + 1);

        printf("Nombre: ");
        if (fgets(nombres[i], LARGO_NOMBRE, stdin) != NULL) {
            nombres[i][strcspn(nombres[i], "\n")] = '\0';
        }

        printf("Boleta: ");
        if (fgets(boletas[i], LARGO_BOLETA, stdin) != NULL) {
            boletas[i][strcspn(boletas[i], "\n")] = '\0';
        }

        do {
            printf("Promedio de tareas (0 a 10): ");
            if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                return 1;
            }
            calificaciones[i][0] = strtof(linea, NULL);
        } while (calificaciones[i][0] < 0.0f || calificaciones[i][0] > 10.0f);

        do {
            printf("Promedio de trabajos (0 a 10): ");
            if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                return 1;
            }
            calificaciones[i][1] = strtof(linea, NULL);
        } while (calificaciones[i][1] < 0.0f || calificaciones[i][1] > 10.0f);

        do {
            printf("Examen (0 a 10): ");
            if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                return 1;
            }
            calificaciones[i][2] = strtof(linea, NULL);
        } while (calificaciones[i][2] < 0.0f || calificaciones[i][2] > 10.0f);
    }

    printf("\n--- Reporte final ---\n");
    for (i = 0; i < cantidad; i++) {
        promedio = (calificaciones[i][0] + calificaciones[i][1] + calificaciones[i][2]) / 3.0f;
        printf("Alumno: %s | Boleta: %s\n", nombres[i], boletas[i]);
        printf("Tareas: %.2f, Trabajos: %.2f, Examen: %.2f, Promedio: %.2f\n\n",
               calificaciones[i][0],
               calificaciones[i][1],
               calificaciones[i][2],
               promedio);
    }

    return 0;
}
