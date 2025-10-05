#include <stdio.h>

int main() {
    const int LIMIT = 1000000;

    int *ptrA = NULL, *ptrB = NULL;
    int numA = 0, numB = 0;

    scanf("%d", &numA);
    scanf("%d", &numB);

    if (numA > LIMIT || numB > LIMIT)
        return 1;

    ptrA = &numA, ptrB = &numB;

    printf("%d %d\n", numA, numB);

    int aux = *ptrA;
    *ptrA = *ptrB;
    *ptrB = aux;

    printf("%d %d\n", numA, numB);

    return 0;
}
