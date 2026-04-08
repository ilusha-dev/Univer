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

    for (int j = 0; j < n; j++) {
        int suma = 0;
        
        for (int i = 0; i < m; i++) {
            suma += arr[i][j];
        }
        
        double media = (double)suma / m;
        
        arr[j][j] = (int)media;
    }
    
    printf("\nTabloul dupa interschimbarea mediilor cu diagonala principala:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
