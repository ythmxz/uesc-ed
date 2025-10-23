#include <stdio.h>

int sequencia_experimento(int a, int b, int f, int n);

int main() {
    int a = 0, b = 0, f = 0, n = 0;
    scanf("%d %d %d %d", &a, &b, &f, &n);

    printf("%d\n", sequencia_experimento(a, b, f, n));

    return 0;
}

int sequencia_experimento(int a, int b, int f, int n) {
    if (n == 1) {
        return a;
    }

    if (n == 2) {
        return b;
    }

    return (sequencia_experimento(a, b, f, n - 2) + sequencia_experimento(a, b, f, n - 1)) * f;
}
