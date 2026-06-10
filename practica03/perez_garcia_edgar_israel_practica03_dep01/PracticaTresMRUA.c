#include <stdio.h>

int main(int argc, char *argv[]) {
    float tiempo, distancia, producto;
    
    float aceleracion = 32.0; 

    
    printf("Ingrese el tiempo en segundos: ");

    scanf("%f", &tiempo);

    producto = aceleracion * tiempo * tiempo;

    distancia = producto / 2;

    printf("El objeto avanza una distancia de %.2f pies en caida libre.\n", distancia);

    return 0;
}