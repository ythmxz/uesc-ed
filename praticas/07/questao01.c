#include <stdio.h>

// Conta a partir da segunda chamada (primeira chamada recursiva)
int num_calls = -1;

int fib(int n) {
    num_calls++;
    if (n == 0 || n == 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 0;
    scanf("%d", &n);

    if (n < 0) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int x = 0;
        scanf("%d", &x);

        if (x < 1 || x > 39) {
            return 1;
        }

        int result = fib(x);
        printf("fib(%d) = %d calls = %d\n", x, num_calls, result);
        num_calls = -1;
    }

    return 0;
}
