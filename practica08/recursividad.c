#include <stdio.h>

#define MAX_N 20
#define MAX_STACK 256

int euclidesRecursivo(int a, int b) {
    if (b == 0) {
        return a;
    }
    return euclidesRecursivo(b, a % b);
}

int euclidesIterativo(int a, int b) {
    int residuo;

    while (b != 0) {
        residuo = a % b;
        a = b;
        b = residuo;
    }
    return a;
}

int ackermannRecursivo(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return ackermannRecursivo(m - 1, 1);
    }
    return ackermannRecursivo(m - 1, ackermannRecursivo(m, n - 1));
}

int ackermannIterativo(int m, int n) {
    int pila[MAX_STACK];
    int cima = 0;

    pila[cima++] = m;
    while (cima > 0) {
        m = pila[--cima];
        if (m == 0) {
            n = n + 1;
        } else if (n == 0) {
            n = 1;
            pila[cima++] = m - 1;
        } else {
            n = n - 1;
            pila[cima++] = m - 1;
            pila[cima++] = m;
        }
        if (cima >= MAX_STACK - 2) {
            printf("La pila iterativa de Ackermann se lleno.\n");
            return -1;
        }
    }
    return n;
}

int particionRecursiva(int n, int maximo) {
    if (n == 0) {
        return 1;
    }
    if (n < 0 || maximo == 0) {
        return 0;
    }
    return particionRecursiva(n, maximo - 1) + particionRecursiva(n - maximo, maximo);
}

int particionIterativa(int n) {
    int dp[MAX_N + 1];
    int numero;
    int suma;

    for (suma = 0; suma <= n; suma++) {
        dp[suma] = 0;
    }
    dp[0] = 1;

    for (numero = 1; numero <= n; numero++) {
        for (suma = numero; suma <= n; suma++) {
            dp[suma] += dp[suma - numero];
        }
    }
    return dp[n];
}

long long catalanRecursivo(int n) {
    int i;
    long long total = 0;

    if (n <= 1) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        total += catalanRecursivo(i) * catalanRecursivo(n - 1 - i);
    }
    return total;
}

long long catalanIterativo(int n) {
    long long catalan[MAX_N + 1];
    int i;
    int j;

    catalan[0] = 1;
    for (i = 1; i <= n; i++) {
        catalan[i] = 0;
        for (j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - 1 - j];
        }
    }
    return catalan[n];
}

long long binomialRecursivo(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    if (k < 0 || k > n) {
        return 0;
    }
    return binomialRecursivo(n - 1, k - 1) + binomialRecursivo(n - 1, k);
}

long long binomialIterativo(int n, int k) {
    long long tabla[MAX_N + 1][MAX_N + 1];
    int i;
    int j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                tabla[i][j] = 1;
            } else {
                tabla[i][j] = tabla[i - 1][j - 1] + tabla[i - 1][j];
            }
        }
    }
    return tabla[n][k];
}

void hanoiRecursivo(int n, char origen, char auxiliar, char destino) {
    if (n == 0) {
        return;
    }
    hanoiRecursivo(n - 1, origen, destino, auxiliar);
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    hanoiRecursivo(n - 1, auxiliar, origen, destino);
}

struct MarcoHanoi {
    int n;
    char origen;
    char auxiliar;
    char destino;
    int estado;
};

void hanoiIterativo(int n) {
    struct MarcoHanoi pila[MAX_STACK];
    int cima = 0;

    pila[cima++] = (struct MarcoHanoi){n, 'A', 'B', 'C', 0};
    while (cima > 0) {
        struct MarcoHanoi *actual = &pila[cima - 1];
        if (actual->n == 0) {
            cima--;
        } else if (actual->estado == 0) {
            actual->estado = 1;
            pila[cima++] = (struct MarcoHanoi){actual->n - 1, actual->origen, actual->destino, actual->auxiliar, 0};
        } else if (actual->estado == 1) {
            printf("Mover disco %d de %c a %c\n", actual->n, actual->origen, actual->destino);
            actual->estado = 2;
            pila[cima++] = (struct MarcoHanoi){actual->n - 1, actual->auxiliar, actual->origen, actual->destino, 0};
        } else {
            cima--;
        }
        if (cima >= MAX_STACK - 1) {
            printf("La pila de Hanoi se lleno.\n");
            return;
        }
    }
}

void ejecutarEuclides(void) {
    int a;
    int b;
    printf("Ingrese a y b: ");
    scanf("%d %d", &a, &b);
    printf("Recursivo: %d\n", euclidesRecursivo(a, b));
    printf("Iterativo: %d\n", euclidesIterativo(a, b));
}

void ejecutarAckermann(void) {
    int m;
    int n;
    printf("Ingrese m y n (recomendado m <= 3): ");
    scanf("%d %d", &m, &n);
    printf("Recursivo: %d\n", ackermannRecursivo(m, n));
    printf("Iterativo: %d\n", ackermannIterativo(m, n));
}

void ejecutarParticion(void) {
    int n;
    printf("Ingrese n (0 a %d): ", MAX_N);
    scanf("%d", &n);
    if (n < 0 || n > MAX_N) {
        printf("Valor fuera de rango.\n");
        return;
    }
    printf("Recursivo: %d\n", particionRecursiva(n, n));
    printf("Iterativo: %d\n", particionIterativa(n));
}

void ejecutarCatalan(void) {
    int n;
    printf("Ingrese n (0 a %d): ", MAX_N);
    scanf("%d", &n);
    if (n < 0 || n > MAX_N) {
        printf("Valor fuera de rango.\n");
        return;
    }
    printf("Recursivo: %lld\n", catalanRecursivo(n));
    printf("Iterativo: %lld\n", catalanIterativo(n));
}

void ejecutarBinomial(void) {
    int n;
    int k;
    printf("Ingrese n y k (0 a %d): ", MAX_N);
    scanf("%d %d", &n, &k);
    if (n < 0 || n > MAX_N || k < 0 || k > n) {
        printf("Valores fuera de rango.\n");
        return;
    }
    printf("Recursivo: %lld\n", binomialRecursivo(n, k));
    printf("Iterativo: %lld\n", binomialIterativo(n, k));
}

void ejecutarHanoi(void) {
    int n;
    printf("Numero de discos: ");
    scanf("%d", &n);
    if (n < 1 || n > 8) {
        printf("Use entre 1 y 8 discos para una salida manejable.\n");
        return;
    }
    printf("\nRecursivo:\n");
    hanoiRecursivo(n, 'A', 'B', 'C');
    printf("\nIterativo:\n");
    hanoiIterativo(n);
}

void ejecutarRecursividad(void) {
    int opcion;

    do {
        printf("\n1. Euclides\n2. Ackermann\n3. Particion\n4. Catalan\n");
        printf("5. Coeficiente binomial\n6. Hanoi\n7. Salir\nOpcion: ");
        if (scanf("%d", &opcion) != 1) {
            return;
        }

        if (opcion == 1) {
            ejecutarEuclides();
        } else if (opcion == 2) {
            ejecutarAckermann();
        } else if (opcion == 3) {
            ejecutarParticion();
        } else if (opcion == 4) {
            ejecutarCatalan();
        } else if (opcion == 5) {
            ejecutarBinomial();
        } else if (opcion == 6) {
            ejecutarHanoi();
        } else if (opcion != 7) {
            printf("Opcion no valida.\n");
        }
    } while (opcion != 7);
}

int main(void) {
    ejecutarRecursividad();
    return 0;
}
