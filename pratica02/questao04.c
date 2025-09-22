#include <stdio.h>
#include <stdlib.h>

int main() {
    int const LOWER_LIMIT = 0, HIGHER_LIMIT = 1000;
    int valuesListSize = 0;
    scanf("%d", &valuesListSize);

    if (valuesListSize < LOWER_LIMIT || valuesListSize > HIGHER_LIMIT)
        return 1;

    int *valuesList = calloc(valuesListSize, sizeof(int));

    if (valuesList == NULL)
        return 1;

    for (int i = 0; i < valuesListSize; i++) {
        scanf("%d", &valuesList[i]);

        if (valuesList[i] <= LOWER_LIMIT || valuesList[i] >= HIGHER_LIMIT)
            return 1;
    }

    int searchListSize = 0;
    scanf("%d", &searchListSize);

    if (searchListSize < LOWER_LIMIT || searchListSize > HIGHER_LIMIT)
        return 1;

    int *searchList = calloc(searchListSize, sizeof(int));

    if (searchList == NULL)
        return 1;

    for (int i = 0; i < searchListSize; i++)
        scanf("%d", &searchList[i]);

    for (int i = 0; i < searchListSize; i++) {
        int found = 0;

        for (int j = 0; j < valuesListSize; j++) {
            if (searchList[i] == valuesList[j]) {
                printf("%d\n", j + 1);
                found = 1;
                break;
            }
        }

        if (found != 1)
            printf("NAO\n");
    }

    return 0;
}
