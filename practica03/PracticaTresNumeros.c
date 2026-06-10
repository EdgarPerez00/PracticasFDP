#include <stdio.h>

int main(int argc, char *argv[]) {
    int enteroUno, enteroDos, suma, producto;

    printf("Ingrese el primer numero: ");
    scanf("%d", &enteroUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &enteroDos);

    suma = enteroUno + enteroDos;
    producto = enteroUno * enteroDos;

    printf("La suma de los numeros es: %d\n", suma);
    printf("El producto de los numeros es: %d\n", producto);
 

    printf( "Este es el final del programa." );


    return 0;
}