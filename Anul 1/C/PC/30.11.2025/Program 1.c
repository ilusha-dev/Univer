#include <stdio.h>

void citireMatrice(int A[30][30], int m, int n) {
    printf("Introduceti elementele matricei (%d linii si %d coloane):\n", m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

void afisareMatrice(int A[30][30], int m, int n) {
    printf("\nMatricea introdusa:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

int gasestePare(int A[30][30], int m, int n, int B[30], int linie[30], int coloana[30]) {
    int k = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] % 2 == 0) {
                B[k] = A[i][j];
                linie[k] = i;
                coloana[k] = j;
                k++;
            }
        }
    }

    return k;  // returnea fix toate elementele pare
}

void afisareVector(int B[30], int linie[30], int coloana[30], int k) {
    printf("\nElementele impare gasite:\n");
    for(int i = 0; i < k; i++) {
        printf("%d ", B[i]);
    }

    printf("\n\nIndicii elementelor pare (linie, coloana):\n");
    for(int i = 0; i < k; i++) {
        printf("Element %d la pozitia (%d, %d)\n", B[i], linie[i], coloana[i]);
    }
}

int main() {
    int A[30][30], B[30], linie[30], coloana[30];
    int m, n;

    printf("Introduceti numarul de linii (M): ");
    scanf("%d", &m);
    printf("Introduceti numarul de coloane (N): ");
    scanf("%d", &n);

    citireMatrice(A, m, n);
    afisareMatrice(A, m, n);

    int k = gasestePare(A, m, n, B, linie, coloana);

    afisareVector(B, linie, coloana, k);

    return 0;
} 