#include <stdio.h>

int main () {
    int suma, i;
    for (suma = 0, i = 0; i <= 3; ++i) {
        if (i == 2) continue;
        suma += i;
    }
    printf ("suma = %d", suma);

    return 0;
}