#include <ctype.h>
#include <stdio.h>

char leerOpcion(const char *mensaje) {
    char opcion;
    printf("%s", mensaje);
    if (scanf(" %c", &opcion) != 1) {
        return '\0';
    }
    return (char)tolower((unsigned char)opcion);
}

void recomendarCorteHeroe(char genero) {
    char gusto;

    if (genero == 'h') {
        gusto = leerOpcion("Prefieres bistec (B), sushi (S) o cine de accion (A): ");
        if (gusto == 'b') {
            printf("Recomendacion: corte de parte superior plana.\n");
        } else if (gusto == 's') {
            printf("Recomendacion: corte de copete.\n");
        } else if (gusto == 'a') {
            printf("Recomendacion: corte estilo capitan clasico.\n");
        } else {
            printf("Opcion no valida.\n");
        }
    } else {
        gusto = leerOpcion("Prefieres animacion (A), comedia (C) o fantasia (F): ");
        if (gusto == 'a') {
            printf("Recomendacion: corte con flequillo.\n");
        } else if (gusto == 'c') {
            printf("Recomendacion: corte sacudido.\n");
        } else if (gusto == 'f') {
            printf("Recomendacion: corte largo en capas.\n");
        } else {
            printf("Opcion no valida.\n");
        }
    }
}

void recomendarCorteVillano(char genero) {
    char estilo = leerOpcion("Prefieres estilo clasico (C), oscuro (O) o extravagante (E): ");

    if (estilo == 'c') {
        printf("Recomendacion: corte mohicano.\n");
    } else if (estilo == 'o') {
        printf("Recomendacion: corte asimetrico con volumen.\n");
    } else if (estilo == 'e') {
        if (genero == 'h') {
            printf("Recomendacion: corte rapado con diseno lateral.\n");
        } else {
            printf("Recomendacion: bob geometrico con color de contraste.\n");
        }
    } else {
        printf("Opcion no valida.\n");
    }
}

int main(void) {
    char genero;
    char preferencia;

    printf("Bienvenido al selector de corte.\n");
    genero = leerOpcion("Es hombre (H) o mujer (M): ");
    if (genero != 'h' && genero != 'm') {
        printf("Opcion de genero no valida.\n");
        return 1;
    }

    preferencia = leerOpcion("Prefieres super heroe (H) o super villano (V): ");
    printf("\n--- Recomendacion ---\n");
    if (preferencia == 'h') {
        recomendarCorteHeroe(genero);
    } else if (preferencia == 'v') {
        recomendarCorteVillano(genero);
    } else {
        printf("Opcion de preferencia no valida.\n");
    }

    return 0;
}
