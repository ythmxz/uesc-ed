#include <stdio.h>

void calcularQuadrante(double R) {
    int voltas = 0;

    while (R > 360.00) {
        R -= 360.00;
        voltas++;
    }

    printf("QUADRANTE: ");

    if (R >= 0.00 && R < 90.00)
        printf("Primeiro ");
    else if (R >= 90.00 && R < 180.00)
        printf("Segundo ");

    else if (R >= 180.00 && R < 270.00)
        printf("Terceiro ");

    else if (R >= 270.00 && R < 360.00)
        printf("Quarto ");

    printf("Quadrante\n");
    printf("QUANTIDADE DE VOLTAS: %d\n", voltas);
}

int main() {
    double R = 0.00;
    scanf("%lf", &R);

    if (R < 0.00 || R > 1000000000.00)
        return 1;

    calcularQuadrante(R);

    return 0;
}
