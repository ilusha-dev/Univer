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

    int maxNegativ = -1000000;
    int pozitieMaxNegativ = -1;
    int cntPozitive = 0;
    for (int i = 0; i < n; i++) {
        if (vector[i] < 0 && vector[i] > maxNegativ) {
            maxNegativ = vector[i];
            pozitieMaxNegativ = i;
        }
        if (vector[i] > 0) {
            cntPozitive++;
        }
    }

    printf("Valoarea maxima negativa: %d\n", maxNegativ);
    printf("Pozitia primului element cu aceasta valoare: %d\n", pozitieMaxNegativ);
    printf("Numarul elementelor pozitive: %d\n", cntPozitive);

    return 0;
}
