#include <stdio.h>
#include <stdlib.h>

int main() {
    int const LOWER_LIMIT = 0, HIGHER_LIMIT = 1000;
    int size = 0;
    scanf("%d", &size);

    if (size < LOWER_LIMIT || size > HIGHER_LIMIT)
        return 1;

    int *listA = calloc(size, sizeof(int));
    int *listB = calloc(size, sizeof(int));
    int *listC = calloc(size, sizeof(int));

    if (listA == NULL || listB == NULL || listC == NULL)
        return 1;

    for (int i = 0; i < size; i++) {
        scanf("%d", &listA[i]);

        if (listA[i] < LOWER_LIMIT || listA[i] > HIGHER_LIMIT)
            return 1;
    }

    for (int i = 0; i < size; i++) {
        scanf("%d", &listB[i]);

        if (listB[i] < LOWER_LIMIT || listB[i] > HIGHER_LIMIT)
            return 1;
    }

    for (int i = 0, j = size - 1; i < size; i++, j--) {
        listC[i] = listA[i] + listB[j];
        printf("%d ", listC[i]);
    }

    printf("\n");

    free(listA);
    free(listB);
    free(listC);

    return 0;
}
