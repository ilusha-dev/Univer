#include <stdio.h>

int main() {
    int n;
    printf("Introduce-ti numarul de elemente (n): ");
    scanf("%d", &n);

    int vector[n];
    printf("Introduce-ti valorile vectorului: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }

    int minPozitiva = -1;
    printf("Pozitiile elementelor minime pozitive: ");
    for (int i = 0; i < n; i++) {
        if (vector[i] > 0 && (minPozitiva == -1 || vector[i] < minPozitiva)) {
            minPozitiva = vector[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (vector[i] == minPozitiva) {
            printf("%d ", i);
        }
    }

    return 0;
}
