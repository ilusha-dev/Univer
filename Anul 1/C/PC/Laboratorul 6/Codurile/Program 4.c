#include <stdio.h>

int numar_divizori(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    return count;
}

int coloana_max_divizori(int matrice[][100], int n, int m, int *suma_divizori) {
    int max_divizori = 0;
    int coloana_max = 0;
    for (int j = 0; j < m; j++) {
        int suma = 0;
        for (int i = 0; i < n; i++) {
            suma += numar_divizori(matrice[i][j]);
        }

        if (suma > max_divizori) {
            max_divizori = suma;
            coloana_max = j;
            *suma_divizori = suma;
        }
    }
    return coloana_max;
}

int main() {
    int n, m;
    printf("Introduceti dimensiunile matricei (n m): ");
    scanf("%d %d", &n, &m);

    int matrice[n][m];
    
    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    printf("Matricea introdusa este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    int suma_divizori = 0;
    int coloana_max = coloana_max_divizori(matrice, n, m, &suma_divizori);

    printf("Coloana cu cei mai multi divizori este coloana %d\n", coloana_max + 1);
    printf("Suma divizorilor din aceasta coloana este: %d\n", suma_divizori);

    return 0;
}