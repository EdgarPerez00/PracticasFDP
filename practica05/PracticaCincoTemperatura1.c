#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_TEMP 17
#define TOTAL_VIENTO 9
#define LARGO_LINEA 100

int main(void) {
    double temperaturas[TOTAL_TEMP] = {
        10.0, 7.5, 5.0, 2.5, 0.0, -2.5, -5.0, -7.5, -10.0,
        -12.5, -15.0, -17.5, -20.0, -22.5, -25.0, -27.5, -30.0
    };
    double vientos[TOTAL_VIENTO] = {
        0.0, 8.0, 16.0, 24.0, 32.0, 40.0, 48.0, 56.0, 64.0
    };
    double tabla[TOTAL_VIENTO][TOTAL_TEMP] = {
        {10.0, 7.5, 5.0, 2.5, 0.0, -2.5, -5.0, -7.5, -10.0, -12.5, -15.0, -17.5, -20.0, -22.5, -25.0, -27.5, -30.0},
        {7.5, 5.0, 2.5, 0.0, -2.5, -5.0, -7.5, -10.0, -12.5, -15.0, -17.5, -20.0, -22.5, -25.0, -27.5, -30.0, -32.5},
        {5.0, 2.5, -2.5, -5.0, -7.5, -10.0, -12.5, -15.0, -17.5, -20.0, -25.0, -27.5, -32.5, -35.0, -37.5, -40.0, -45.0},
        {2.5, 0.0, -5.0, -7.5, -10.0, -12.5, -17.5, -20.0, -25.0, -27.5, -32.5, -35.0, -37.5, -42.5, -45.0, -47.5, -52.5},
        {0.0, -2.5, -7.5, -10.0, -12.5, -17.5, -22.5, -22.5, -25.0, -30.0, -35.0, -37.5, -42.5, -47.5, -50.0, -52.5, -57.5},
        {0.0, -5.0, -7.5, -10.0, -15.0, -17.5, -22.5, -25.0, -30.0, -32.5, -37.5, -40.0, -45.0, -47.5, -52.5, -55.0, -60.0},
        {-2.5, -5.0, -10.0, -12.5, -17.5, -20.0, -25.0, -27.5, -32.5, -35.0, -40.0, -42.5, -47.5, -50.0, -55.0, -57.5, -62.5},
        {-2.5, -7.5, -10.0, -12.5, -17.5, -20.0, -25.0, -30.0, -32.5, -37.5, -42.5, -45.0, -50.0, -52.5, -57.5, -60.0, -67.5},
        {-2.5, -7.5, -10.0, -15.0, -20.0, -22.5, -27.5, -30.0, -35.0, -37.5, -42.5, -45.0, -50.0, -55.0, -60.0, -62.5, -70.0}
    };
    char linea[LARGO_LINEA];
    double temperatura;
    double viento;
    double sensacion;
    int indiceTemp;
    int indiceViento;
    int opcion;
    int i;
    int j;

    do {
        printf("\n1. Ver tabla de Concepto.de\n");
        printf("2. Consultar tabla de Concepto.de\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
            printf("Entrada no valida.\n");
            return 1;
        }
        opcion = (int)strtol(linea, NULL, 10);

        switch (opcion) {
            case 1:
                printf("\nTabla de sensacion termica y enfriamiento por viento\n");
                printf("Viento ");
                for (j = 0; j < TOTAL_TEMP; j++) {
                    printf("%7.1f", temperaturas[j]);
                }
                printf("\n");

                for (i = 0; i < TOTAL_VIENTO; i++) {
                    if (i == 0) {
                        printf("Calma  ");
                    } else {
                        printf("%6.0f ", vientos[i]);
                    }

                    for (j = 0; j < TOTAL_TEMP; j++) {
                        printf("%7.1f", tabla[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("Temperatura a consultar (10 a -30 C, intervalo 2.5): ");
                if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                    printf("Entrada no valida.\n");
                    return 1;
                }
                temperatura = strtod(linea, NULL);

                printf("Viento a consultar (0 para calma, o 8 a 64 km/h en intervalo 8): ");
                if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
                    printf("Entrada no valida.\n");
                    return 1;
                }
                viento = strtod(linea, NULL);

                indiceTemp = -1;
                for (i = 0; i < TOTAL_TEMP; i++) {
                    if (fabs(temperaturas[i] - temperatura) < 0.01) {
                        indiceTemp = i;
                    }
                }

                indiceViento = -1;
                for (i = 0; i < TOTAL_VIENTO; i++) {
                    if (fabs(vientos[i] - viento) < 0.01) {
                        indiceViento = i;
                    }
                }

                if (indiceTemp == -1 || indiceViento == -1) {
                    printf("Los datos no estan en la tabla. Use los intervalos indicados.\n");
                    break;
                }

                sensacion = tabla[indiceViento][indiceTemp];
                printf("Sensacion termica segun tabla: %.1f C\n", sensacion);
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
