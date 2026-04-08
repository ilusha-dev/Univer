#include <stdio.h>
#include <math.h>

int main() {
    double rezultat = sqrt(100);

    for (int i = 98; i >= 2; i -= 2) {
        rezultat = sqrt(i + rezultat);
    }

    printf("Rezultatul expresiei este: %.6lf\n", rezultat);

    return 0;
}
