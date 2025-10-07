#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

// Constantes 
#define MAX_T_IDX 17
#define MAX_V_IDX 8
#define LIM_T 10.0
#define UMBRAL_GRV -20.0
#define UMBRAL_EXT -35.0
#define MARCADOR_NULO -99.9

// Punteros para los arreglos dinámicos
float *temperaturas;
float *velocidades;
float **tablaSensacion; 
char *riesgos[] = {"Riesgo de enfriamiento moderado", "Riesgo de enfriamiento grave", "Riesgo de enfriamiento extremo"};

// Formula corregida 
float calcularWCI(float t, float v) {
    if (v < 4.8) {
        return MARCADOR_NULO;
    }
    return 13.12 + (0.6215 * t) - (11.37 * pow(v, 0.16)) + (0.3965 * t * pow(v, 0.16));
}

//funciones para poblar de datos la tabla de temperaturas y velocidades
void poblarTemperaturas() {
    float temps[MAX_T_IDX] = {10.0, 7.5, 5.0, 2.5, 0.0, -2.5, -5.0, -7.5, -10.0, -12.5, -15.0, -17.5, -20.0, -22.5, -25.0, -27.5, -30.0};
    for (int i = 0; i < MAX_T_IDX; i++) {
        temperaturas[i] = temps[i];
    }
}

void poblarVelocidades() {
    float vels[MAX_V_IDX] = {8.0, 16.0, 24.0, 32.0, 40.0, 48.0, 56.0, 64.0};
    for (int i = 0; i < MAX_V_IDX; i++) {
        velocidades[i] = vels[i];
    }
}

// funcion para calcular y llenar la tabla de sensacion térmica
void poblarTablaSensacion() {
    for (int i = 0; i < MAX_V_IDX; i++) {
        for (int j = 0; j < MAX_T_IDX; j++) {
            tablaSensacion[i][j] = calcularWCI(temperaturas[j], velocidades[i]);
        }
    }
}

// funcion para configurar y poblar todos los datos
void configurarDatosIniciales() {
    // Asignacion de memoria para los arreglos
    temperaturas = (float *)malloc(MAX_T_IDX * sizeof(float));
    velocidades = (float *)malloc(MAX_V_IDX * sizeof(float));
    tablaSensacion = (float **)malloc(MAX_V_IDX * sizeof(float *));
    for (int i = 0; i < MAX_V_IDX; i++) {
        tablaSensacion[i] = (float *)malloc(MAX_T_IDX * sizeof(float));
    }

    // Comprobacion de que la memoria fue asignada
    if (temperaturas == NULL || velocidades == NULL || tablaSensacion == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }
    
    // Llenar los arreglos con los datos
    poblarTemperaturas();
    poblarVelocidades();
    poblarTablaSensacion(); // La tabla se calcula, no se hardcodea
}

// funciones para imprimir la tabla
void imprimirSeparador() {
    printf("-------|");
    for (int k = 0; k < MAX_T_IDX; k++) {
        printf("---------|");
    }
    printf("\n");
}

void imprimirEncabezado() {
    printf("\n------------------- TABLA DE SENSACION TERMICA (W) -------------------\n");
    printf("Viento |");
    for (int j = 0; j < MAX_T_IDX; j++) {
        printf("%6.1f C |", temperaturas[j]);
    }
    printf("\n");
}

void imprimirFila(int i) {
    printf("%6.0f |", velocidades[i]);
    for (int j = 0; j < MAX_T_IDX; j++) {
        float valor = tablaSensacion[i][j];
        if (valor == MARCADOR_NULO) {
            printf("   N/A   |");
        } else {
            printf("  %6.1f |", valor);
        }
    }
    printf("\n");
}

void imprimirTabla() {
    imprimirEncabezado();
    imprimirSeparador();
    for (int i = 0; i < MAX_V_IDX; i++) {
        imprimirFila(i);
    }
    imprimirSeparador();
    printf("Rangos de Riesgo:\n");
    printf("  W > %.1f: %s\n", UMBRAL_GRV, riesgos[0]);
    printf("  %.1f >= W > %.1f: %s\n", UMBRAL_GRV, UMBRAL_EXT, riesgos[1]);
    printf("  W <= %.1f: %s\n", UMBRAL_EXT, riesgos[2]);
}

// funciones para realizar consultas
char* obtenerRiesgo(float W) {
    if (W > UMBRAL_GRV) return riesgos[0];
    if (W > UMBRAL_EXT) return riesgos[1];
    return riesgos[2];
}

void realizarConsulta() {
    float t, v, W;
    char *riesgoMensaje;

    printf("\n--- Consulta de Sensacion Termica ---\n");
    printf("Ingrese temperatura (Celsius): ");
    scanf("%f", &t);
    printf("Ingrese velocidad del viento (km/h): ");
    scanf("%f", &v);

    if (t > LIM_T) {
        printf("AVISO: La temperatura %.1fC es mayor que el limite de la tabla (%.1fC).\n", t, LIM_T);
    }
    
    printf("\nRESULTADO (Calculo Directo):\n");
    W = calcularWCI(t, v);

    if (W == MARCADOR_NULO) {
        printf("La velocidad del viento es demasiado baja para el calculo.\n");
    } else {
        riesgoMensaje = obtenerRiesgo(W);
        printf("Sensacion Termica: %.2f C\n", W);
        printf("Riesgo de Congelacion: %s\n", riesgoMensaje);
    }
}

// funciones para el menu
void mostrarMenu() {
    int opcion;
    do {
        printf("\n*** MENU SENSACION TERMICA ***\n");
        printf("1. Ver la tabla\n");
        printf("2. Realizar una consulta\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada no valida. Saliendo.\n");
            while(getchar()!='\n'); // Limpia el buffer
            opcion = 3; 
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

// funcion para liberar memoria
void liberarMemoria() {
    free(temperaturas);
    free(velocidades);
    for (int i = 0; i < MAX_V_IDX; i++) {
        free(tablaSensacion[i]);
    }
    free(tablaSensacion);
}

// funcion principal
int main(int argc, char *argv[]) {
    configurarDatosIniciales();
    mostrarMenu();
    liberarMemoria();
    return 0;
}