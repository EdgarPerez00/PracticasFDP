#include <stdio.h>

#define ACELERACION_GRAVEDAD 32.0
#define PIES_A_METROS 0.3048

double calcularDistanciaPies(double tiempo) {
    double producto = ACELERACION_GRAVEDAD * tiempo * tiempo;
    return producto / 2.0;
}

void imprimirDistancias(double distanciaPies) {
    double distanciaMetros = distanciaPies * PIES_A_METROS;
    double distanciaKilometros = distanciaMetros / 1000.0;

    printf("Distancia en pies: %.2f\n", distanciaPies);
    printf("Distancia en metros: %.2f\n", distanciaMetros);
    printf("Distancia en kilometros: %.4f\n", distanciaKilometros);
}

int main(void) {
    double tiempo;
    double distanciaPies;

    printf("Ingrese el tiempo en segundos: ");
    if (scanf("%lf", &tiempo) != 1 || tiempo < 0.0) {
        printf("Entrada no valida.\n");
        return 1;
    }

    distanciaPies = calcularDistanciaPies(tiempo);
    imprimirDistancias(distanciaPies);

    printf("\nConclusion: con este modelo ideal el objeto no tiene una altura maxima ");
    printf("de caida; solo dejaria de caer al tocar el suelo o si se conoce una altura inicial.\n");

    return 0;
}
