#include <stdio.h>

double aproxPi(int n) {
    double soma = 0.00;
    double j = 1.00;

    for (int i = 1; i <= n; i += 2) {
        soma += 1.00 / j;
        j += 4.00;
    }

    j = 1.00;

    for (int i = 2; i <= n; i += 2) {
        soma -= 1.00 / (j + 2.00);
        j += 4.00;
    }

    return 4.00 * soma;
}

int main() {
    int n = 0;
    scanf("%d", &n);

    if (n < 1) {
        printf("Número de termos inválido. Deve ser maior ou igual a 1.\n");
        return 1;
    }

    double resultado = aproxPi(n);
    printf("Aproximação de PI: %lf\n", resultado);

    return 0;
}
