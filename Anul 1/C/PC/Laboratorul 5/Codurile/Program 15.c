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
    
    int negativi[m * n];
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < 0) {
                negativi[count] = arr[i][j];
                count++;
            }
        }
    }
    
    if (count == 0) {
        printf("Nu exista elemente negative in tablou.\n");
        return 0;
    }
  
    long long produs = 1; 
    for (int i = 0; i < count; i++) {
        produs *= negativi[i];
    }
    
    printf("Elementele negative din tablou sunt:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", negativi[i]);
    }
    printf("\n");
    
    printf("Produsul elementelor negative este: %lld\n", produs);
    
    return 0;
}