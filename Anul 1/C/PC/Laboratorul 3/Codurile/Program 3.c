#include <stdio.h>

int main() {
    int n;
    double suma = 0;
    printf("Introduceti un numar natural n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        double sum_numarator = (i - 1) * i / 2.0; // suma de la 1 la i-1
        double sum_numitor   = i * (i + 1) / 2.0; // suma de la 1 la i
        if (i == 1) {
            suma += 1;
        } else {
            suma += sum_numarator / sum_numitor;
        }
    }
    printf("Suma primilor %d termeni este: %.6lf\n", n, suma);
    return 0;
}
