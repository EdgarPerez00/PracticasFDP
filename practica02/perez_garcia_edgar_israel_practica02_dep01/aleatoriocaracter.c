#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    char caracterUno, caracterDos;
    int limite = 26; 

    srand(time(NULL));

    caracterUno = 'a' + (rand() % limite);
    caracterDos = 'a' + (rand() % limite);

    printf("Caracter Uno = %c\n", caracterUno);
    printf("Caracter Dos = %c\n", caracterDos);

    return 0;
}