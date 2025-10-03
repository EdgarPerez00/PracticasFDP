#include <stdio.h>

#define MAX_AL 100
#define MAX_R 10
#define MAX_NP 50
#define MAX_NA 50
#define MAX_IDA 15

char nombreProfesor[MAX_NP];
char nombresAlumnos[MAX_AL][MAX_NA];
char boletasAlumnos[MAX_AL][MAX_IDA];
float tareas[MAX_AL][MAX_R];
float trabajos[MAX_AL][MAX_R];
float examenes[MAX_AL][MAX_R];
int numAlumnos = 0;

void leerCadena(char *destino, int maxLen) {
    if (fgets(destino, maxLen, stdin)) {
        int i = 0;
        while (destino[i] != '\n' && destino[i] != '\0') {
            i++;
        }
        if (destino[i] == '\n') {
            destino[i] = '\0';
        }
    }
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ingresarProfesor() {
    printf("Ingrese el nombre del Profesor: ");
    leerCadena(nombreProfesor, MAX_NP);
}

void leerCalificaciones(float matriz[MAX_AL][MAX_R], int indiceAlumno, const char *rubro) {
    int i;
    float calificacion;

    printf("--- Ingreso de %s (Max %d) ---\n", rubro, MAX_R);

    for (i = 0; i < MAX_R; i++) {
        printf("Ingrese calificacion %d/%d: ", i + 1, MAX_R);
        if (scanf("%f", &calificacion) == 1) {
            matriz[indiceAlumno][i] = calificacion;
        } else {
            printf("Entrada no valida. Finalizando ingreso de %s.\n", rubro);
            break; 
        }
    }
    limpiarBuffer();
}

void ingresarAlumno() {
    if (numAlumnos >= MAX_AL) {
        printf("El sistema ha alcanzado el maximo de alumnos (%d).\n", MAX_AL);
        return;
    }

    printf("\n--- Ingreso de Alumno #%d ---\n", numAlumnos + 1);
    
    printf("Ingrese Nombre del Alumno: ");
    leerCadena(nombresAlumnos[numAlumnos], MAX_NA);

    printf("Ingrese Boleta/ID: ");
    leerCadena(boletasAlumnos[numAlumnos], MAX_IDA);

    leerCalificaciones(tareas, numAlumnos, "Tareas");
    leerCalificaciones(trabajos, numAlumnos, "Trabajos");
    leerCalificaciones(examenes, numAlumnos, "Examenes");
    
    numAlumnos++;
}

float calcularPromedioRubro(float matriz[MAX_AL][MAX_R], int indiceAlumno) {
    float suma = 0.0;
    int i;

    for (i = 0; i < MAX_R; i++) {
        suma += matriz[indiceAlumno][i];
    }
    return suma / MAX_R;
}

void mostrarCalificaciones(float matriz[MAX_AL][MAX_R], int indiceAlumno, const char *rubro) {
    int i;
    float promedio = calcularPromedioRubro(matriz, indiceAlumno);

    printf("  %s: ", rubro);
    for (i = 0; i < MAX_R; i++) {
        printf("%.1f ", matriz[indiceAlumno][i]);
    }
    printf("(Promedio: %.2f)\n", promedio);
}

void mostrarReporteAlumno(int indiceAlumno) {
    printf("\n--- Reporte del Alumno ---\n");
    printf("Profesor a cargo: %s\n", nombreProfesor);
    printf("Nombre: %s\n", nombresAlumnos[indiceAlumno]);
    printf("Boleta: %s\n", boletasAlumnos[indiceAlumno]);
    
    mostrarCalificaciones(tareas, indiceAlumno, "Tareas");
    mostrarCalificaciones(trabajos, indiceAlumno, "Trabajos");
    mostrarCalificaciones(examenes, indiceAlumno, "Examenes");
}

void ejecutarSistema() {
    char respuesta;
    int i;

    ingresarProfesor();
    
    do {
        ingresarAlumno();

        if (numAlumnos < MAX_AL) {
            printf("\nDesea ingresar otro alumno? (S/N): ");
            if (scanf(" %c", &respuesta) != 1) {
                respuesta = 'n';
            }
            limpiarBuffer();
        } else {
            respuesta = 'n';
        }
    } while ((respuesta == 's' || respuesta == 'S') && numAlumnos < MAX_AL);

    if (numAlumnos > 0) {
        printf("\n--- REPORTE FINAL DE CALIFICACIONES ---\n");
        for (i = 0; i < numAlumnos; i++) {
            mostrarReporteAlumno(i);
        }
    } else {
        printf("\nNo se ingresaron datos de ningun alumno.\n");
    }
}

int main(int argc, char *argv[]) {
    ejecutarSistema();
    return 0;
}