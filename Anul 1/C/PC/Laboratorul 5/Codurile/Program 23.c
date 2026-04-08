#include <stdio.h>

int main() {
    int m, n;
    
    printf("Introduceti numarul de randuri (m): ");
    scanf("%d", &m);
    printf("Introduceti numarul de coloane (n): ");
    scanf("%d", &n);
    
    int arr[m][n];
    
    printf("Introduceti elementele tabloului bidimensional:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    long long produs = 1;
    int existaSubDiagonalPrincipala = 0;
    
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            produs *= arr[i][j];
            existaSubDiagonalPrincipala = 1;
        }
    }

    int sumaSubDiagonal = 0;
    
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n - i; j++) {
            if (i + j < n - 1) {
                sumaSubDiagonal += arr[i][j];
            }
        }
    }

    if (existaSubDiagonalPrincipala) {
        printf("\nProdusul elementelor sub diagonala principala este: %lld\n", produs);
    } else {
        printf("\nNu exista elemente sub diagonala principala.\n");
    }
    
    printf("Suma elementelor sub diagonala principala si sub diagonala secundara este: %d\n", sumaSubDiagonal);
    
    return 0;
}