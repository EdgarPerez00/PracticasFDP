#include <stdio.h>
#include <ctype.h> // Para la función tolower()

/**
 * Programa que determina un corte de pelo basándose en el diagrama de flujo provisto.
 */
int main(int argc, char *argv[]) {
    char genero, preferencia, gusto;

    // --- 1. Hombre o Mujer? ---
    printf("Bienvenido al selector de corte. \n");
    printf("¿Es Hombre (H) o Mujer (M)? Ingrese H o M: ");
    if (scanf(" %c", &genero) != 1) return 1;
    genero = tolower(genero);

    // --- Lógica del Árbol de Decisión ---
    if (genero == 'h') {
        // --- Rama: HOMBRE ---
        printf("¿Prefieres Super heroe (H) o Super villano (V)? Ingrese H o V: ");
        if (scanf(" %c", &preferencia) != 1) return 1;
        preferencia = tolower(preferencia);

        if (preferencia == 'h') {
            // Hombre -> Super heroe
            printf("¿Prefieres Bistec (B) o Sushi (S)? Ingrese B o S: ");
            if (scanf(" %c", &gusto) != 1) return 1;
            gusto = tolower(gusto);
            
            printf("\n--- Recomendacion ---\n");
            if (gusto == 'b') {
                printf("Corte de parte superior plana\n");
            } else if (gusto == 's') {
                printf("Corte de copete\n");
            } else {
                printf("Opcion de comida no valida.\n");
            }
        } else if (preferencia == 'v') {
            // Hombre -> Super villano
            printf("\n--- Recomendacion ---\n");
            printf("Deberia pedir un corte Mohicano\n");
        } else {
            printf("\nOpcion de preferencia no valida.\n");
        }

    } else if (genero == 'm') {
        // --- Rama: MUJER ---
        printf("¿Prefieres Super heroe (H) o Super villano (V)? Ingrese H o V: ");
        if (scanf(" %c", &preferencia) != 1) return 1;
        preferencia = tolower(preferencia);

        if (preferencia == 'v') {
            // Mujer -> Super villano
            printf("\n--- Recomendacion ---\n");
            printf("Debería pedir un corte Mohicano\n");
        } else if (preferencia == 'h') {
            // Mujer -> Super heroe
            printf("¿Prefieres Animado (A) o Comedia (C)? Ingrese A o C: ");
            if (scanf(" %c", &gusto) != 1) return 1;
            gusto = tolower(gusto);

            printf("\n--- Recomendacion ---\n");
            if (gusto == 'a') {
                printf("Corte de flequillo\n");
            } else if (gusto == 'c') {
                printf("Corte de sacudida\n");
            } else {
                printf("Opcion de pelicula no valida.\n");
            }
        } else {
            printf("\nOpcion de preferencia no valida.\n");
        }

    } else {
        // Género no válido
        printf("\nOpcion de genero no valida. El programa ha terminado.\n");
    }

    return 0;
}