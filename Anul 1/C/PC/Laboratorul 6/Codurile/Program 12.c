#include <stdio.h>

double suma_domeniu_colorat(double matrice[][100], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 1) {
                suma += matrice[i][j];
            }
        }
    }
    return suma;
}

int numar_elemente_domeniu_colorat(double matrice[][100], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    printf("Introduceti dimensiunea matricei (n, n fiind numar impar): ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("n trebuie sa fie un numar impar!\n");
        return 1;
    }

    double matrice[n][n];

    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrice[i][j]);
        }
    }

    printf("Matricea introdusa este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matrice[i][j]);
        }
        printf("\n");
    }

    double suma = suma_domeniu_colorat(matrice, n);
    int numar_elemente = numar_elemente_domeniu_colorat(matrice, n);

    printf("Suma elementelor din domeniul colorat este: %.2f\n", suma);
    printf("Numarul elementelor din domeniul colorat este: %d\n", numar_elemente);

    return 0;
}
