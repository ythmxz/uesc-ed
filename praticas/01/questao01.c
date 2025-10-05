#include <math.h>
#include <stdio.h>

void calcularRaizes(double a, double b, double c) {
    double delta = pow(b, 2.00) - 4.00 * a * c;

    if (delta < 0.00) {
        printf("Impossível calcular\n");
        return;
    }

    double x1 = (-b + sqrt(delta)) / (2.00 * a);
    double x2 = (-b - sqrt(delta)) / (2.00 * a);

    printf("Raiz 1: %.5lf\n", x1);
    printf("Raiz 2: %.5lf\n", x2);
}

int main() {
    double valorA = 0.00, valorB = 0.00, valorC = 0.00;

    scanf("%lf", &valorA);

    if (valorA < 0.1 || valorA > 10.00) {
        if (valorA == 0.00)
            printf("Impossível calcular\n");
        return 1;
    }

    scanf("%lf", &valorB);

    if (valorB < -1000.00 || valorB > 1000.00)
        return 1;

    scanf("%lf", &valorC);

    if (valorC < -1000.00 || valorC > 1000.00)
        return 1;

    calcularRaizes(valorA, valorB, valorC);

    return 0;
}
