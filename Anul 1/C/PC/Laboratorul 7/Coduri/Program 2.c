#include <stdio.h>

void citire_matrice(int note[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("Studentul %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("  Nota la examenul %d: ", j + 1);
            scanf("%d", &note[i][j]);
        }
    }
}

float nota_medie_generala(int note[][100], int m, int n) {
    int suma = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            suma += note[i][j];
        }
    }

    return (float)suma / (m * n);
}

int main() {
    int m, n;
    int note[100][100];

    printf("Introduceti numarul de studenti (m): ");
    scanf("%d", &m);

    printf("Introduceti numarul de examene (n): ");
    scanf("%d", &n);

    citire_matrice(note, m, n);

    float medie = nota_medie_generala(note, m, n);

    printf("\nNota medie a tuturor studentilor la toate examenele este: %.2f\n", medie);

    return 0;
}
