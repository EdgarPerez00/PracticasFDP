#include <stdio.h>

int main(int argc, char *argv[]) {
    int numero;
    int max_valor = 0;
    int min_valor = 0;
    int contador = 0;

    printf("Ingrese numeros enteros positivos. Ingrese un numero negativo (ej. -21) para terminar:\n");

    while (1) {
        if (scanf("%d", &numero) != 1) {
            break; 
        }

        if (numero < 0) {
            break;
        }

        if (contador == 0) {
            max_valor = numero;
            min_valor = numero;
        } else {
            if (numero > max_valor) {
                max_valor = numero;
            }
            if (numero < min_valor) {
                min_valor = numero;
            }
        }
        
        contador++;
    }
    
    if (contador > 0) {
        printf("\n--- Resultados ---\n");
        printf("Valor mas alto ingresado: %d\n", max_valor);
        printf("Valor mas bajo ingresado: %d\n", min_valor);
        printf("Numero total de numeros ingresados: %d\n", contador);
    } else {
        printf("\nNo se ingreso ningun numero antes de la senial de parada.\n");
    }

    return 0;
}