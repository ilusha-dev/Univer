#include <stdio.h> 
#define MAX 100

void matriceInVector(int n, int m, int A[][MAX], int v[]) {
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v[k++] = A[i][j];
        }
    }
}

void extrageLinii(int n, int m, int A[][MAX], int L[][MAX]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = A[i][j];
        }
    }
}

void afiseazaVector(int v[], int dim) {
    for (int i = 0; i < dim; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n, m, A[MAX][MAX], v[MAX * MAX], L[MAX][MAX];
    printf("Introdu numarul de linii: ");
    scanf("%d", &m);
    printf("Introdu numarul de coloane: ");
    scanf("%d", &n);
    printf("Introdu elementele matricei: \n");
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    matriceInVector (m, n, A, v);
    extrageLinii (m, n, A, L);

    printf("Vectorul rezultat din intreaga matrice: \n");
    afiseazaVector(v, m * n);

    printf("Vecotorii corespunzatori fiecarii linii: \n");
    for (int i = 0; i < m; i++) {
        printf("Linia %d: ", i + 1);
        afiseazaVector(L[i], n);
    }

    return 0;
}