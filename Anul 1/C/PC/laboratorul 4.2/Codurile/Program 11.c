#include <stdio.h>

int main() {
    int n; 
    printf("Introduce-ti numarul de elemente (n): ");
    scanf("%d", &n);

    int vector[n];
    printf("Introduce-ti valorile vectorului: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);5
    }

    int minPozitiv = -1, maxNegativ = -1000000;
    int pozitieMinPozitiv = -1, pozitieMaxNegativ = -1;

    for (int i = 0; i < n; i++) {
        if (vector[i] > 0 && (minPozitiv == -1 || vector[i] < minPozitiv)) {
            minPozitiv = vector[i];
            pozitieMinPozitiv = i;
        }
        if (vector[i] < 0 && vector[i] > maxNegativ) {
            maxNegativ = vector[i];
            pozitieMaxNegativ = i;
        }
    }

    printf("Primul element minimal pozitiv: %d, pozitia: %d\n", minPozitiv, pozitieMinPozitiv);
    printf("Ultimul element maximal negativ: %d, pozitia: %d\n", maxNegativ, pozitieMaxNegativ);

    return 0;
}
