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

    int min = vector[0];
    printf("Pozitiile elementelor minime: ");
    for (int i = 0; i < n; i++) {
        if (vector[i] < min) {
            min = vector[i];
        }
    }

    int sumaPozitive = 0, cntPozitive = 0;
    for (int i = 0; i < n; i++) {
        if (vector[i] == min) {
            printf("%d ", i);
        }
        if (vector[i] > 0) {
            sumaPozitive += vector[i];
            cntPozitive++;
        }
    }

    if (cntPozitive > 0) {
        printf("\nMedia elementelor pozitive: %.2f\n", (float)sumaPozitive / cntPozitive);
    } else {
        printf("\nNu exista elemente pozitive.\n");
    }

    return 0;
}
