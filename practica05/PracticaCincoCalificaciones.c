//Edgar Israel Perez Garcia
#include <stdio.h>

#define MIN_ALUMNOS 15
#define MAX_ALUMNOS 32
#define RUBROS 3

int leerCantidadAlumnos(void) {
    int cantidad;

    do {
        printf("Cantidad de alumnos (%d a %d): ", MIN_ALUMNOS, MAX_ALUMNOS);
        if (scanf("%d", &cantidad) != 1) {
            while (getchar() != '\n') {
            }
            cantidad = 0;
        }
    } while (cantidad < MIN_ALUMNOS || cantidad > MAX_ALUMNOS);

    return cantidad;
}

float leerCalificacion(const char *texto) {
    float calificacion;

    do {
        printf("%s: ", texto);
        if (scanf("%f", &calificacion) != 1) {
            while (getchar() != '\n') {
            }
            calificacion = -1.0f;
        }
    } while (calificacion < 0.0f || calificacion > 10.0f);

    return calificacion;
}

void leerDatos(int boletas[], float calificaciones[][RUBROS], int cantidad) {
    int i;

    for (i = 0; i < cantidad; i++) {
        printf("\nAlumno %d\n", i + 1);
        printf("Boleta: ");
        scanf("%d", &boletas[i]);
        calificaciones[i][0] = leerCalificacion("Tareas");
        calificaciones[i][1] = leerCalificacion("Trabajos");
        calificaciones[i][2] = leerCalificacion("Examen");
    }
}

float calcularPromedio(float fila[]) {
    return (fila[0] + fila[1] + fila[2]) / 3.0f;
}

void imprimirPromedios(int boletas[], float calificaciones[][RUBROS], int cantidad) {
    int i;

    printf("\n--- Promedios por alumno ---\n");
    for (i = 0; i < cantidad; i++) {
        printf("Boleta %d -> promedio %.2f\n", boletas[i], calcularPromedio(calificaciones[i]));
    }
}

void ejecutarPrograma(void) {
    int boletas[MAX_ALUMNOS];
    float calificaciones[MAX_ALUMNOS][RUBROS];
    int cantidad = leerCantidadAlumnos();

    leerDatos(boletas, calificaciones, cantidad);
    imprimirPromedios(boletas, calificaciones, cantidad);
}

int main(void) {
    ejecutarPrograma();
    return 0;
}
