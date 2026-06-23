#include <ctype.h>
#include <stdio.h>

int main(void) {
    char genero;
    char preferencia;
    char gusto;
    char estilo;

    printf("Bienvenido al selector de corte.\n");
    printf("Es hombre (H) o mujer (M): ");
    if (scanf(" %c", &genero) != 1) {
        return 1;
    }
    genero = (char)tolower((unsigned char)genero);

    if (genero != 'h' && genero != 'm') {
        printf("Opcion de genero no valida.\n");
        return 1;
    }

    printf("Prefieres super heroe (H) o super villano (V): ");
    if (scanf(" %c", &preferencia) != 1) {
        return 1;
    }
    preferencia = (char)tolower((unsigned char)preferencia);

    printf("\n--- Recomendacion ---\n");
    switch (preferencia) {
        case 'h':
            if (genero == 'h') {
                printf("Prefieres bistec (B), sushi (S) o alambre de pastor (A): ");
                if (scanf(" %c", &gusto) != 1) {
                    return 1;
                }
                gusto = (char)tolower((unsigned char)gusto);

                switch (gusto) {
                    case 'b':
                        printf("Recomendacion: corte de parte superior plana.\n");
                        break;
                    case 's':
                        printf("Recomendacion: corte de copete.\n");
                        break;
                    case 'a':
                        printf("Recomendacion: corte estilo capitan clasico.\n");
                        break;
                    default:
                        printf("Opcion no valida.\n");
                        break;
                }
            } else {
                printf("Prefieres animacion (A), comedia (C) o fantasia (F): ");
                if (scanf(" %c", &gusto) != 1) {
                    return 1;
                }
                gusto = (char)tolower((unsigned char)gusto);

                switch (gusto) {
                    case 'a':
                        printf("Recomendacion: corte con flequillo.\n");
                        break;
                    case 'c':
                        printf("Recomendacion: corte sacudido.\n");
                        break;
                    case 'f':
                        printf("Recomendacion: corte largo en capas.\n");
                        break;
                    default:
                        printf("Opcion no valida.\n");
                        break;
                }
            }
            break;
        case 'v':
            printf("Prefieres estilo clasico (C), oscuro (O) o extravagante (E): ");
            if (scanf(" %c", &estilo) != 1) {
                return 1;
            }
            estilo = (char)tolower((unsigned char)estilo);

            switch (estilo) {
                case 'c':
                    printf("Recomendacion: corte mohicano.\n");
                    break;
                case 'o':
                    printf("Recomendacion: corte Wolf cut.\n");
                    break;
                case 'e':
                    printf("Recomendacion: Cabeza rasurada.\n");
                    break;
                default:
                    printf("Opcion no valida.\n");
                    break;
            }
            break;
        default:
            printf("Opcion de preferencia no valida.\n");
            break;
    }

    return 0;
}
