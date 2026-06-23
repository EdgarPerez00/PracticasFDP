//Edgar Israel Perez Garcia
#include <limits.h>
#include <stdio.h>

#define NUMERO_MAXIMO 100

void procesarNumero(int numero, int *mayor, int *menor, int *suma, int contador) {
    if (contador == 0) {
        *mayor = numero;
        *menor = numero;
    } else {
        if (numero > *mayor) {
            *mayor = numero;
        }
        if (numero < *menor) {
            *menor = numero;
        }
    }
    *suma += numero;
}

void leerNumeros(int numeros[], int *contador, int *mayor, int *menor, int *suma) {
    int lectura;

    *contador = 0;
    *mayor = INT_MIN;
    *menor = INT_MAX;
    *suma = 0;

    printf("Ingrese numeros enteros. Use un numero negativo para terminar.\n");
    while (*contador < NUMERO_MAXIMO) {
        printf("Numero %d: ", *contador + 1);
        if (scanf("%d", &lectura) != 1) {
            printf("Entrada invalida. Terminando lectura.\n");
            break;
        }
        if (lectura < 0) {
            break;
        }

        numeros[*contador] = lectura;
        procesarNumero(lectura, mayor, menor, suma, *contador);
        (*contador)++;
    }
}

void imprimirResultados(int contador, int mayor, int menor, int suma) {
    if (contador == 0) {
        printf("No se ingresaron numeros validos.\n");
        return;
    }

    printf("\n--- Resultados ---\n");
    printf("Valor mas alto: %d\n", mayor);
    printf("Valor mas bajo: %d\n", menor);
    printf("Suma de valores: %d\n", suma);
    printf("Total de numeros ingresados: %d\n", contador);
}

void ejecutarProceso(void) {
    int numeros[NUMERO_MAXIMO];
    int contador;
    int mayor;
    int menor;
    int suma;

    leerNumeros(numeros, &contador, &mayor, &menor, &suma);
    imprimirResultados(contador, mayor, menor, suma);
}

int main(void) {
    ejecutarProceso();
    return 0;
}
