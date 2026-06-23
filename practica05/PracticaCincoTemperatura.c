//Edgar Israel Perez Garcia
#include <math.h>
#include <stdio.h>

#define TEMP_INICIAL 10.0
#define TEMP_FINAL -40.0
#define PASO_TEMP 2.5
#define VIENTO_INICIAL 8
#define VIENTO_FINAL 80
#define PASO_VIENTO 8
#define MAX_TEMP 21
#define MAX_VIENTO 10

double calcularSensacionTermica(double temperatura, double viento) {
    return 13.12 + (0.6215 * temperatura) - (11.37 * pow(viento, 0.16)) +
           (0.3965 * temperatura * pow(viento, 0.16));
}

const char *obtenerRiesgo(double sensacion) {
    if (sensacion <= -35.0) {
        return "Riesgo de enfriamiento extremo";
    }
    if (sensacion <= -20.0) {
        return "Riesgo de enfriamiento grave";
    }
    return "Riesgo de enfriamiento moderado";
}

void llenarTemperaturas(double temperaturas[], int *total) {
    double temperatura;
    *total = 0;
    for (temperatura = TEMP_INICIAL; temperatura >= TEMP_FINAL && *total < MAX_TEMP; temperatura -= PASO_TEMP) {
        temperaturas[*total] = temperatura;
        (*total)++;
    }
}

void llenarVientos(double vientos[], int *total) {
    int viento;
    *total = 0;
    for (viento = VIENTO_INICIAL; viento <= VIENTO_FINAL && *total < MAX_VIENTO; viento += PASO_VIENTO) {
        vientos[*total] = (double)viento;
        (*total)++;
    }
}

void llenarTabla(double tabla[][MAX_TEMP], double temperaturas[], int totalTemp,
                 double vientos[], int totalViento) {
    int i;
    int j;

    for (i = 0; i < totalViento; i++) {
        for (j = 0; j < totalTemp; j++) {
            tabla[i][j] = calcularSensacionTermica(temperaturas[j], vientos[i]);
        }
    }
}

void imprimirTabla(double tabla[][MAX_TEMP], double temperaturas[], int totalTemp,
                   double vientos[], int totalViento) {
    int i;
    int j;

    printf("\nTabla de sensacion termica\n");
    printf("Viento ");
    for (j = 0; j < totalTemp; j++) {
        printf("%7.1f", temperaturas[j]);
    }
    printf("\n");

    for (i = 0; i < totalViento; i++) {
        printf("%6.0f ", vientos[i]);
        for (j = 0; j < totalTemp; j++) {
            printf("%7.1f", tabla[i][j]);
        }
        printf("\n");
    }
}

int buscarIndice(double valores[], int total, double buscado) {
    int i;

    for (i = 0; i < total; i++) {
        if (fabs(valores[i] - buscado) < 0.01) {
            return i;
        }
    }
    return -1;
}

void consultarTabla(double tabla[][MAX_TEMP], double temperaturas[], int totalTemp,
                    double vientos[], int totalViento) {
    double temperatura;
    double viento;
    int indiceTemp;
    int indiceViento;
    double sensacion;

    printf("Temperatura a consultar (maximo 10 C, intervalo 2.5): ");
    if (scanf("%lf", &temperatura) != 1) {
        printf("Entrada no valida.\n");
        return;
    }
    if (temperatura > 10.0) {
        printf("La temperatura viola la restriccion t <= 10.\n");
        return;
    }

    printf("Viento a consultar (8 a 80 km/h, intervalo 8): ");
    if (scanf("%lf", &viento) != 1) {
        printf("Entrada no valida.\n");
        return;
    }

    indiceTemp = buscarIndice(temperaturas, totalTemp, temperatura);
    indiceViento = buscarIndice(vientos, totalViento, viento);

    if (indiceTemp == -1 || indiceViento == -1) {
        printf("Los datos no estan en la tabla. Use los intervalos indicados.\n");
        return;
    }

    sensacion = tabla[indiceViento][indiceTemp];
    printf("Sensacion termica: %.2f C\n", sensacion);
    printf("Mensaje de riesgo: %s\n", obtenerRiesgo(sensacion));
}

void ejecutarPrograma(void) {
    double temperaturas[MAX_TEMP];
    double vientos[MAX_VIENTO];
    double tabla[MAX_VIENTO][MAX_TEMP];
    int totalTemp;
    int totalViento;
    int opcion;

    llenarTemperaturas(temperaturas, &totalTemp);
    llenarVientos(vientos, &totalViento);
    llenarTabla(tabla, temperaturas, totalTemp, vientos, totalViento);

    do {
        printf("\n1. Ver tabla\n");
        printf("2. Consultar factor de congelacion\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada no valida.\n");
            return;
        }

        if (opcion == 1) {
            imprimirTabla(tabla, temperaturas, totalTemp, vientos, totalViento);
        } else if (opcion == 2) {
            consultarTabla(tabla, temperaturas, totalTemp, vientos, totalViento);
        } else if (opcion != 3) {
            printf("Opcion no valida.\n");
        }
    } while (opcion != 3);
}

int main(void) {
    ejecutarPrograma();
    return 0;
}
