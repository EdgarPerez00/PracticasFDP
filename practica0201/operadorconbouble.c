#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <math.h>

void f(int entero) {
    printf("%d", entero);
}

int main(int argc, char *argv[]) {
    double dx;
    double dy;

    char c;
    short s;
    int i;
    long l;
    float f_var;
    double d;
    
    printf("--- INICIO DEL PROGRAMA (TIPO DOUBLE) ---\a\n");
    printf("Valor maximo de un double (DBL_MAX): %e\n", DBL_MAX);
    printf("Valor minimo positivo de un double (DBL_MIN): %e\n\n", DBL_MIN);
    
    printf("--- Analizando Multiplicacion (hacia infinito) ---\n");
    dx = DBL_MAX;
    dy = 2.0;
    printf("Operacion: dx (%e) * dy (%f)\n", dx, dy);
    
    dx = dx * dy;

    if(isinf(dx)) {
        printf("Estado: El resultado supero el maximo representable y se convirtio en infinito.\n");
    }
    printf("Valor final de dx: %f\n\n", dx);


    printf("--- Analizando Division (hacia cero) ---\n");
    dx = DBL_MIN;
    dy = 2.0;
    printf("Operacion: dx (%e) / dy (%f)\n", dx, dy);
    
    dx = dx / dy;

    if(dx == 0.0) {
        printf("Estado: El resultado fue tan pequeno que se convirtio en cero (subdesbordamiento).\n");
    }
    printf("Valor final de dx: %e\n\n", dx);
    
    printf("--- Analizando Suma (Perdida de Precision) ---\n");
    dx = 1.0e30;
    dy = 1.0;
    printf("Operacion: dx (%e) + dy (%f)\n", dx, dy);
    double dx_antes_de_suma = dx;

    dx = dx + dy;
    
    if (dx == dx_antes_de_suma) {
        printf("Estado: El segundo numero era demasiado pequeno en comparacion al primero.\n");
        printf("  -> Explicacion: No hubo suficientes digitos de precision para registrar la suma.\n");
    }
    printf("Valor final de dx: %e\n\n", dx);


    printf("--- Analizando operacion invalida (NaN - No es un Numero) ---\n");
    dx = 0.0;
    dy = 0.0;
    printf("Operacion: dx (%f) / dy (%f)\n", dx, dy);

    dx = dx / dy;
    
    if (isnan(dx)) {
        printf("Estado: La operacion es matematicamente indeterminada.\n");
        printf("  -> Explicacion: El resultado es 'NaN' (Not a Number).\n");
    }
    printf("Valor final de dx: %f\n\n", dx);
    
    printf("--- Casting final ---\a\n");
    i = (int) dx;
    printf("dx como int: %d\n", i);
    f_var = (float) dx;
    printf("dx como float: %f\n", f_var);

    return 0;
}