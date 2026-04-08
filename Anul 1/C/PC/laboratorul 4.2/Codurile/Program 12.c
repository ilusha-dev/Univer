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

    int minPozitiv = -1, maxNegativ = -1000000;
    int pozitieUltimaMinPozitiv = -1, pozitiePrimulMaxNegativ = -1;

    for (int i = 0; i < n; i++) {
        if (vector[i] > 0 && (minPozitiv == -1 || vector[i] < minPozitiv)) {
            minPozitiv = vector[i];
            pozitieUltimaMinPozitiv = i;
        }
        if (vector[i] < 0 && vector[i] > maxNegativ) {
            maxNegativ = vector[i];
            pozitiePrimulMaxNegativ = i;
        }
    }

    printf("Ultimul element minimal pozitiv: %d, pozitia: %d\n", minPozitiv, pozitieUltimaMinPozitiv);
    printf("Primul element maximal negativ: %d, pozitia: %d\n", maxNegativ, pozitiePrimulMaxNegativ);

    return 0;
}
