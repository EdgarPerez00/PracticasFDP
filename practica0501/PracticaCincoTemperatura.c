#include <stdio.h>
#include <math.h>

// --- Constantes (Español, abreviado, mayúsculas) ---
#define MAX_T_IDX 17
#define MAX_V_IDX 8
#define LIM_T 10.0
#define UMBRAL_GRV -20.0
#define UMBRAL_EXT -35.0
#define MARCADOR_NULO -99.9

// --- Variables Globales (camelCase) ---
float temperaturas[MAX_T_IDX] = {10.0, 7.5, 5.0, 2.5, 0.0, -2.5, -5.0, -7.5, -10.0, -12.5, -15.0, -17.5, -20.0, -22.5, -25.0, -27.5, -30.0};
float velocidades[MAX_V_IDX] = {8.0, 16.0, 24.0, 32.0, 40.0, 48.0, 56.0, 64.0};
float tablaSensacion[MAX_V_IDX][MAX_T_IDX];
char *riesgos[] = {"Riesgo de enfriamiento moderado", "Riesgo de enfriamiento grave", "Riesgo de enfriamiento extremo"};


// -----------------------------------------------------------------------------
// --- Funciones de Inicializacion de Datos ---
// -----------------------------------------------------------------------------

void inicializarParteUno() {
    // Fila 0 (8 km/h) a Fila 3 (32 km/h)
    // 17 ELEMENTOS por fila (corresponde a MAX_T_IDX)
    float datos[4][MAX_T_IDX] = {
        // 8 km/h
        {7.5, 5.0, 2.5, 0.0, -2.5, -5.0, -7.5, -10.0, -12.5, -15.0, -17.5, -20.0, -22.5, -25.0, -27.5, -30.0, -32.5},
        
        // 16 km/h (QUITADO EL VALOR EXTRA -45.0)
        {5.0, 2.5, 0.0, -2.5, -5.0, -7.5, -10.0, -12.5, -15.0, -17.5, -20.0, -25.0, -27.5, -32.5, -35.0, -37.5, -40.0},
        
        // 24 km/h
        {2.5, 0.0, -5.0, -7.5, -10.0, -12.5, -17.5, -20.0, -25.0, -27.5, -32.5, -35.0, -37.5, -42.5, -45.0, -47.5, -52.5},
        
        // 32 km/h
        {0.0, -2.5, -7.5, -10.0, -12.5, -17.5, -22.5, -25.0, -30.0, -32.5, -35.0, -37.5, -42.5, -47.5, -50.0, -52.5, -57.5}
    };
    int i;
    int j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < MAX_T_IDX; j++) {
            tablaSensacion[i][j] = datos[i][j];
        }
    }
}

void inicializarParteDos() {
    // Fila 4 (40 km/h) a Fila 7 (64 km/h)
    float datos[4][MAX_T_IDX] = {
        {0.0, -5.0, -7.5, -10.0, -15.0, -17.5, -22.5, -25.0, -30.0, -32.5, -37.5, -40.0, -45.0, -47.5, -52.5, -55.0, -60.0},
        {-2.5, -5.0, -10.0, -12.5, -17.5, -20.0, -25.0, -27.5, -32.5, -35.0, -40.0, -42.5, -47.5, -50.0, -55.0, -57.5, -62.5},
        {-2.5, -7.5, -10.0, -12.5, -17.5, -20.0, -25.0, -30.0, -30.0, -35.0, -42.5, -45.0, -50.0, -52.5, -55.0, -60.0, -67.5},
        {-2.5, -7.5, -10.0, -15.0, -20.0, -22.5, -27.5, -30.0, -35.0, -37.5, -42.5, -45.0, -50.0, -55.0, -60.0, -62.5, -70.0}
    };
    int i;
    int j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < MAX_T_IDX; j++) {
            tablaSensacion[i + 4][j] = datos[i][j];
        }
    }
}

void configurarDatosIniciales() {
    inicializarParteUno();
    inicializarParteDos();
}

// -----------------------------------------------------------------------------
// --- Funciones de Calculo ---
// -----------------------------------------------------------------------------

float calcularWCI(float t, float v) {
    float W;
    if (v < 4.8) {
        printf("ADVERTENCIA: La formula no es valida para velocidades menores a 4.8 km/h.\n");
        return t;
    }
    W = 13.12 + (0.6215 * t) - (11.37 * pow(v, 0.16)) + (0.3965 * t * pow(v, 0.16));
    return W;
}

// -----------------------------------------------------------------------------
// --- Funciones de Reporte y Busqueda ---
// -----------------------------------------------------------------------------

void imprimirSeparador() {
    int k;
    printf("-------|");
    for (k = 0; k < MAX_T_IDX; k++) {
        printf("---------|");
    }
    printf("\n");
}

void imprimirEncabezado() {
    int j;
    printf("\n------------------- TABLA DE SENSACION TERMICA (W) -------------------\n");
    printf("Viento |");
    for (j = 0; j < MAX_T_IDX; j++) {
        printf(" %6.1f C |", temperaturas[j]);
    }
    printf("\n");
}

void imprimirFila(int i) {
    int j;
    printf("%6.0f |", velocidades[i]);
    for (j = 0; j < MAX_T_IDX; j++) {
        float valor = tablaSensacion[i][j];
        if (valor == MARCADOR_NULO) {
            printf("    -    |");
        } else {
            printf(" %6.1f |", valor);
        }
    }
    printf("\n");
}

void imprimirTabla() {
    int i;
    imprimirEncabezado();
    imprimirSeparador();
    for (i = 0; i < MAX_V_IDX; i++) {
        imprimirFila(i);
    }
    imprimirSeparador();
    printf("Rangos de Riesgo:\n");
    printf("  W > %.1f: %s\n", UMBRAL_GRV, riesgos[0]);
    printf("  %.1f >= W > %.1f: %s\n", UMBRAL_GRV, UMBRAL_EXT, riesgos[1]);
    printf("  W <= %.1f: %s\n", UMBRAL_EXT, riesgos[2]);
}

char* obtenerRiesgo(float W) {
    if (W > UMBRAL_GRV) return riesgos[0];
    if (W > UMBRAL_EXT) return riesgos[1];
    return riesgos[2];
}

float buscarEnTabla(float t, float v, char **riesgoPtr) {
    int i;
    int j;
    float resultado = MARCADOR_NULO;

    for (i = 0; i < MAX_V_IDX; i++) {
        if (velocidades[i] == v) {
            for (j = 0; j < MAX_T_IDX; j++) {
                if (temperaturas[j] == t) {
                    resultado = tablaSensacion[i][j];
                    if (resultado != MARCADOR_NULO) {
                        *riesgoPtr = obtenerRiesgo(resultado);
                    }
                    return resultado;
                }
            }
        }
    }
    return MARCADOR_NULO;
}

void realizarConsulta() {
    float t;
    float v;
    float W;
    char *riesgoMensaje;

    printf("\n--- Consulta de Sensacion Termica ---\n");
    printf("Ingrese temperatura (Celsius, max %.1f): ", LIM_T);
    scanf("%f", &t);
    printf("Ingrese velocidad del viento (km/h): ");
    scanf("%f", &v);

    if (t > LIM_T) {
        printf("ERROR: La temperatura %.1fC excede la restriccion de %.1fC.\n", t, LIM_T);
        return;
    }

    W = buscarEnTabla(t, v, &riesgoMensaje);

    if (W != MARCADOR_NULO) {
        printf("\nRESULTADO (Tabla):\n");
    } else {
        printf("\nRESULTADO (Calculo):\n");
        W = calcularWCI(t, v);
        riesgoMensaje = obtenerRiesgo(W);
    }

    if (W == MARCADOR_NULO) {
        printf("Los valores no estan definidos en la tabla para esas condiciones.\n");
    } else {
        printf("Sensacion Termica: %.2f C\n", W);
        printf("Riesgo de Congelacion: %s\n", riesgoMensaje);
    }
}


void mostrarMenu() {
    int opcion;
    do {
        printf("\n*** MENU SENSACION TERMICA ***\n");
        printf("1. Ver la tabla\n");
        printf("2. Realizar una consulta\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada no valida.\n");
            break;
        }

        switch (opcion) {
            case 1:
                imprimirTabla();
                break;
            case 2:
                realizarConsulta();
                break;
            case 3:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 3);
}


int main(int argc, char *argv[]) {
    configurarDatosIniciales();
    mostrarMenu();
    return 0;
}