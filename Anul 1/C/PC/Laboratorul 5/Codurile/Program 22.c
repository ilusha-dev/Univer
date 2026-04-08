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
    
    for (int i = 0; i < m && i < n; i++) {
        arr[i][n - i - 1] = 0;
    }

    printf("\nTabloul dupa zerografierea diagonalei secundare:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    long long produs = 1;
    int existaSubDiagonal = 0;
    
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n - i; j++) {
            produs *= arr[i][j];
            existaSubDiagonal = 1;
        }
    }
    
    if (existaSubDiagonal) {
        printf("\nProdusul elementelor sub diagonala secundara este: %lld\n", produs);
    } else {
        printf("\nNu exista elemente sub diagonala secundara.\n");
    }
    
    return 0;
}