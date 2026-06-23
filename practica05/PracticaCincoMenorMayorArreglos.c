<<<<<<< HEAD
=======
//Edgar Israel Perez Garcia
#include <limits.h>
>>>>>>> 548b6988b379e64e1c0118a6b7c9ee42c4c945a9
#include <stdio.h>
#include <stdlib.h>

#define NUMERO_MAXIMO 100
#define LARGO_LINEA 100

int main(void) {
    int numeros[NUMERO_MAXIMO];
    char linea[LARGO_LINEA];
    int contador = 0;
    int lectura;
    int mayor = 0;
    int menor = 0;
    int suma = 0;

    printf("Ingrese numeros enteros. Use un numero negativo para terminar.\n");
    while (contador < NUMERO_MAXIMO) {
        printf("Numero %d: ", contador + 1);
        if (fgets(linea, LARGO_LINEA, stdin) == NULL) {
            printf("Entrada invalida. Terminando lectura.\n");
            break;
        }

        lectura = (int)strtol(linea, NULL, 10);
        if (lectura < 0) {
            break;
        }

        numeros[contador] = lectura;
        if (contador == 0) {
            mayor = numeros[contador];
            menor = numeros[contador];
        } else {
            if (numeros[contador] > mayor) {
                mayor = numeros[contador];
            }
            if (numeros[contador] < menor) {
                menor = numeros[contador];
            }
        }

        suma = suma + numeros[contador];
        contador++;
    }

    if (contador == 0) {
        printf("No se ingresaron numeros validos.\n");
    } else {
        printf("\n--- Resultados ---\n");
        printf("Valor mas alto: %d\n", mayor);
        printf("Valor mas bajo: %d\n", menor);
        printf("Suma de valores: %d\n", suma);
        printf("Total de numeros ingresados: %d\n", contador);
    }

    return 0;
}
