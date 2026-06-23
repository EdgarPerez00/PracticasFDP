#include <stdio.h>

#define ACELERACION_GRAVEDAD 32.0
#define PIES_A_METROS 0.3048

int main(void) {
    double tiempo;
    double distanciaPies;
    double distanciaMetros;
    double distanciaKilometros;

    printf("Ingrese el tiempo en segundos: ");
    if (scanf("%lf", &tiempo) != 1 || tiempo < 0.0) {
        printf("Entrada no valida.\n");
        return 1;
    }

    distanciaPies = (ACELERACION_GRAVEDAD * tiempo * tiempo) / 2.0;
    distanciaMetros = distanciaPies * PIES_A_METROS;
    distanciaKilometros = distanciaMetros / 1000.0;

    printf("El objeto avanza una distancia de %.2f pie en caida libre\n", distanciaPies);
    printf("El objeto avanza una distancia de %.2f metros en caida libre\n", distanciaMetros);
    printf("El objeto avanza una distancia de %.2f kilometros en caida libre\n", distanciaKilometros);

    return 0;
}
