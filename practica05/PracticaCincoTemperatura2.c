#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TEMP_INICIAL 10.0
#define TEMP_FINAL -40.0
#define PASO_TEMP 2.5
#define VIENTO_INICIAL 8
#define VIENTO_FINAL 80
#define PASO_VIENTO 8
#define MAX_TEMP 21
#define MAX_VIENTO 10
#define LARGO_LINEA 100

int main(void) {
    double temperaturas[MAX_TEMP];
    double vientos[MAX_VIENTO];
    double tabla[MAX_VIENTO][MAX_TEMP];
    double temperatura;
    double viento;
    double sensacion;
    double potenciaViento;
    char linea[LARGO_LINEA];
    int totalTemp = 0;
    int totalViento = 0;
    int indiceTemp;
    int indiceViento;
    int opcion;
    int i;
    int j;

    for (temperatura = TEMP_INICIAL; temperatura >= TEMP_FINAL && totalTemp < MAX_TEMP; temperatura -= PASO_TEMP) {
        temperaturas[totalTemp] = temperatura;
        totalTemp++;
    }

    for (i = VIENTO_INICIAL; i <= VIENTO_FINAL && totalViento < MAX_VIENTO; i += PASO_VIENTO) {
        vientos[totalViento] = (double)i;
        totalViento++;
    }

    for (i = 0; i < totalViento; i++) {
        for (j = 0; j < totalTemp; j++) {
            potenciaViento = pow(vientos[i], 0.16);
            tabla[i][j] = 13.12 + (0.6215 * temperaturas[j]) - (11.37 * potenciaViento) +
                          (0.3965 * temperaturas[j] * potenciaViento);
        }
    }

    do {
        printf("\n1. Ver tabla\n");
        printf("2. Consultar factor de congelacion\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
            printf("Entrada no valida.\n");
            return 1;
        }
        opcion = (int)strtol(linea, NULL, 10);

        switch (opcion) {
            case 1:
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
                break;

            case 2:
                printf("Temperatura a consultar (maximo 10 C, intervalo 2.5): ");
                if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                    printf("Entrada no valida.\n");
                    return 1;
                }
                temperatura = strtod(linea, NULL);
                if (temperatura > 10.0) {
                    printf("La temperatura viola la restriccion t <= 10.\n");
                    break;
                }

                printf("Viento a consultar (8 a 80 km/h, intervalo 8): ");
                if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                    printf("Entrada no valida.\n");
                    return 1;
                }
                viento = strtod(linea, NULL);

                indiceTemp = -1;
                for (i = 0; i < totalTemp; i++) {
                    if (fabs(temperaturas[i] - temperatura) < 0.01) {
                        indiceTemp = i;
                    }
                }

                indiceViento = -1;
                for (i = 0; i < totalViento; i++) {
                    if (fabs(vientos[i] - viento) < 0.01) {
                        indiceViento = i;
                    }
                }

                if (indiceTemp == -1 || indiceViento == -1) {
                    printf("Los datos no estan en la tabla. Use los intervalos indicados.\n");
                    break;
                }

                sensacion = tabla[indiceViento][indiceTemp];
                printf("Sensacion termica: %.2f C\n", sensacion);
                if (sensacion <= -35.0) {
                    printf("Mensaje de riesgo: Riesgo de enfriamiento extremo\n");
                } else {
                    if (sensacion <= -20.0) {
                        printf("Mensaje de riesgo: Riesgo de enfriamiento grave\n");
                    } else {
                        printf("Mensaje de riesgo: Riesgo de enfriamiento moderado\n");
                    }
                }
                break;

            case 3:
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}
