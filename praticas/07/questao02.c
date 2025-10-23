#define MAX 17

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binaryToInt(char string[]) {
    scanf("%s", string);

    if (string[0] == '0' || strlen(string) <= 1) {
        exit(1);
    }

    return strtol(string, NULL, 2);
}

int onlyLoveNeeded(int l, int s) {
    if (l >= s) {
        return l == s;
    }

    return onlyLoveNeeded(l, s - l);
}

int main() {
    int cases = 0;
    scanf("%d", &cases);

    if (cases < 0) {
        return 1;
    }

    char loveString[MAX];
    int loveValue = binaryToInt(loveString);

    for (int i = 0; i < cases; i++) {
        char string1[MAX];
        int value1 = binaryToInt(string1);

        char string2[MAX];
        int value2 = binaryToInt(string2);

        if (onlyLoveNeeded(loveValue, value1) == onlyLoveNeeded(loveValue, value2)) {
            printf("All you need is love!\n");
            return 0;
        }

        printf("Love is not all you need!\n");
    }

    return 0;
}
