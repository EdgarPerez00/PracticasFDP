#include <stdio.h>

int main(int argc, char *argv[]) {
    int cuartos, diez_centavos, cinco_centavos;
    int valor_total;

    printf("Ingrese la cantidad de cuartos: ");
    scanf("%d", &cuartos);

    printf("Ingrese la cantidad de monedas de diez centavos: ");
    scanf("%d", &diez_centavos);

    printf("Ingrese la cantidad de monedas de cinco centavos: ");
    scanf("%d", &cinco_centavos);

    valor_total = (cuartos * 25) + (diez_centavos * 10) + (cinco_centavos * 5);

    printf("El valor total de las monedas es: %d centavos.\n", valor_total);

    return 0;
}