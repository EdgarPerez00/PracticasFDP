#include <stdio.h>

void sumar(int a, int b, int *ptr);
void dividir(int a, int b, float *ptr);
int * multiplicar(int a, int b);
int * restar(int a, int b);

void mostrarResultado(int a, int b, int suma, float division, int multiplicacion, int resta) {
    printf("\nOperaciones con los números %d y %d:\n", a, b);
    printf("Suma: %d\n", suma);
    printf("División: %.2f\n", division);
    printf("Multiplicación: %d\n", multiplicacion);
    printf("Resta: %d\n", resta);
}

void sumar(int a, int b, int *ptr) {
    *ptr = a + b;
}

void dividir(int a, int b, float *ptr) {
    if (b != 0) {
        *ptr = (float)a / b;
    } else {
        printf("Error: No se puede dividir por cero\n");
        *ptr = 0;
    }
}

int * multiplicar(int a, int b) {
    static int resultado;
    resultado = a * b;
    return &resultado;
}

int * restar(int a, int b) {
    static int resultado;
    resultado = a - b;
    return &resultado;
}

int main(void) {
    int arreglo[18] = {
        23, 5, 98, 65, 3, 55, 73, 9, 21, 85, 100, -7, 45, 99, 18, 66, 99, 101
    };
    int *ptrArreglo = arreglo;
    int num1 = *(ptrArreglo + 0);
    int num2 = *(ptrArreglo + 1);
    int suma;
    float division;
    int *multPtr, *restaPtr;
    
    sumar(num1, num2, &suma);
    dividir(num1, num2, &division);
    multPtr = multiplicar(num1, num2);
    restaPtr = restar(num1, num2);
    
    mostrarResultado(num1, num2, suma, division, *multPtr, *restaPtr);
    
    num1 = *(ptrArreglo + 3);
    num2 = *(ptrArreglo + 4);
    
    sumar(num1, num2, &suma);
    dividir(num1, num2, &division);
    multPtr = multiplicar(num1, num2);
    restaPtr = restar(num1, num2);
    
    mostrarResultado(num1, num2, suma, division, *multPtr, *restaPtr);
    
    return 0;
}
