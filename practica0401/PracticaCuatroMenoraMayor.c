#include <stdio.h>

int main(int argc, char *argv[]) {
    int numeroUno, numeroDos, numeroTres;

    printf("Ingrese el primer valor entero: ");
    scanf("%d", &numeroUno);

    printf("Ingrese el segundo valor entero: ");
    scanf("%d", &numeroDos);

    printf("Ingrese el tercer valor entero: ");
    scanf("%d", &numeroTres);


    if (numeroUno > numeroDos) {
        numeroUno = numeroUno + numeroDos;
        numeroDos = numeroUno - numeroDos;
        numeroUno = numeroUno - numeroDos;
    }

    if (numeroDos > numeroTres) {
        numeroDos = numeroDos + numeroTres;
        numeroTres = numeroDos - numeroTres;
        numeroDos = numeroDos - numeroTres;
    }

    if (numeroUno > numeroDos) {
        numeroUno = numeroUno + numeroDos;
        numeroDos = numeroUno - numeroDos;
        numeroUno = numeroUno - numeroDos;
    }


    printf("\nLos numeros en orden ascendente son: %d, %d, %d\n", numeroUno, numeroDos, numeroTres);

    return 0;
}