#include <stdio.h>

int main() {
    int numar, inversat = 0;

    printf("Introduceti un numar natural: ");
    scanf("%d", &numar);

    while (numar != 0) {
        int cifra = numar % 10;
        inversat = inversat * 10 + cifra;
        numar = numar / 10;
    }

    printf("Numarul inversat este: %d\n", inversat);

    return 0;
}
