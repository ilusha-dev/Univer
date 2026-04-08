#include <stdio.h>

// ================= CITIRE MATRICE =================
void citire_matrice(int (*a)[10], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", (*(a + i) + j));   // CORECT pentru (*a)[]
        }
}

// ================= AFIȘARE MATRICE =================
void afisare_matrice(int (*a)[10], int n, int m) {
    printf("\nMatricea este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", *(*(a + i) + j));
        }
        printf("\n");
    }
}

// ================= SUMA COLOANELOR =================
void suma_coloane(int (*a)[10], int n, int m, int *v) {
    for (int j = 0; j < m; j++) {
        *(v + j) = 0;
        for (int i = 0; i < n; i++) {
            if (*(*(a + i) + j) % 2 == 0) {
            *(v + j) += *(*(a + i) + j);
            }
        }
    }
}

// ================= AFIȘARE VECTOR (CU POINTERI) =================
void afisare_vector(int *v, int m) {
    printf("\nVectorul sumelor pe coloane:\n");
    for (int i = 0; i < m; i++) {
        printf("v[%d] = %d\n", i, *(v + i));
    }
}

// ================= MAIN =================
int main() {
    int a[10][10];
    int v[10];
    int n, m;

    printf("n (linii) = ");
    scanf("%d", &n);
    printf("m (coloane) = ");
    scanf("%d", &m);

    citire_matrice(a, n, m);
    afisare_matrice(a, n, m);

    suma_coloane(a, n, m, v);
    afisare_vector(v, m);

    return 0;
} 