#include <stdio.h>
#include <limits.h> 

#define NUMERO_MAXIMO 100 
#define CONDICIONAL_PARO 0
#define CONT_VAL_INICIAL 0

int numeros[NUMERO_MAXIMO];
int contador = 0;
int maxValor = INT_MIN; 
int minValor = INT_MAX; 
    

void procesarNumero(int numeroActual) {
    if (contador == CONT_VAL_INICIAL) {
        maxValor = numeroActual;
        minValor = numeroActual;
    } else {
        if (numeroActual > maxValor) {
            maxValor = numeroActual;
        }
        if (numeroActual < minValor) {
            minValor = numeroActual;
        }
    }
}

void leerNumeros() {
    int lectura;

    printf("Ingrese numeros enteros positivos (maximo %d). Ingrese un numero negativo (ej. -21) para terminar:\n", NUMERO_MAXIMO);

    while (contador < NUMERO_MAXIMO) {
        if (scanf("%d", &lectura) != 1) {
            printf("Entrada invalida. Terminando la lectura.\n");
            break; 
        }

        if (lectura < CONDICIONAL_PARO) {
            break;
        }

        numeros[contador] = lectura;
        procesarNumero(lectura);
        contador++;
    }

    if (contador == NUMERO_MAXIMO) {
        printf("\nADVERTENCIA: Se alcanzo el limite de %d numeros.\n", NUMERO_MAXIMO);
    }
}

void imprimirResultados() {
    if (contador > CONT_VAL_INICIAL) {
        printf("\n--- Resultados ---\n");
        printf("Valor mas alto ingresado: %d\n", maxValor);
        printf("Valor mas bajo ingresado: %d\n", minValor);
        printf("Numero total de numeros ingresados: %d\n", contador);
    } else {
        printf("\nNo se ingreso ningun numero antes de la senal de parada.\n");
    }
}


void ejecutarProceso() {
    leerNumeros();
    imprimirResultados();
}


int main(int argc, char *argv[]) {

    ejecutarProceso();    

    return 0;
}