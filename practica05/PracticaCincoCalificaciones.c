//Edgar Israel Perez Garcia
#include <stdio.h>
#include <stdlib.h>

#define MIN_ALUMNOS 15
#define MAX_ALUMNOS 32
#define RUBROS 3
#define LARGO_LINEA 100

int main(void) {
    int boletas[MAX_ALUMNOS];
    float calificaciones[MAX_ALUMNOS][RUBROS];
    float promedio;
    char linea[LARGO_LINEA];
    int cantidad;
    int i;

    do {
        printf("Cantidad de alumnos (%d a %d): ", MIN_ALUMNOS, MAX_ALUMNOS);
        if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
            return 1;
        }
        cantidad = (int)strtol(linea, NULL, 10);
    } while (cantidad < MIN_ALUMNOS || cantidad > MAX_ALUMNOS);

    for (i = 0; i < cantidad; i++) {
        printf("\nAlumno %d\n", i + 1);

        printf("Boleta: ");
        if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
            return 1;
        }
        boletas[i] = (int)strtol(linea, NULL, 10);

        do {
            printf("Tareas: ");
            if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                return 1;
            }
            calificaciones[i][0] = strtof(linea, NULL);
        } while (calificaciones[i][0] < 0.0f || calificaciones[i][0] > 10.0f);

        do {
            printf("Trabajos: ");
            if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                return 1;
            }
            calificaciones[i][1] = strtof(linea, NULL);
        } while (calificaciones[i][1] < 0.0f || calificaciones[i][1] > 10.0f);

        do {
            printf("Examen: ");
            if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                return 1;
            }
            calificaciones[i][2] = strtof(linea, NULL);
        } while (calificaciones[i][2] < 0.0f || calificaciones[i][2] > 10.0f);
    }

    printf("\n--- Promedios por alumno ---\n");
    for (i = 0; i < cantidad; i++) {
        promedio = (calificaciones[i][0] + calificaciones[i][1] + calificaciones[i][2]) / 3.0f;
        printf("Boleta %d -> promedio %.2f\n", boletas[i], promedio);
    }

    return 0;
}
