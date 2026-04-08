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

    int max = vector[0];
    int primaPozitie = -1, ultimaPozitie = -1;
    for (int i = 0; i < n; i++) {
        if (vector[i] > max) {
            max = vector[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (vector[i] == max) {
            if (primaPozitie == -1) {
                primaPozitie = i;
            }
            ultimaPozitie = i;
        }
    }

    int sumaPozitive = 0, cntPozitive = 0;
    for (int i = 0; i < n; i++) {
        if (vector[i] > 0) {
            sumaPozitive += vector[i];
            cntPozitive++;
        }
    }

    printf("Pozitiile elementelor maxime: %d si %d\n", primaPozitie, ultimaPozitie);
    if (cntPozitive > 0) {
        printf("Media elementelor pozitive: %.2f\n", (float)sumaPozitive / cntPozitive);
    } else {
        printf("Nu exista elemente pozitive.\n");
    }

    return 0;
}
