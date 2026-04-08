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
        int minVal = arr[0][j];
        int minPos = 0;
        
        for (int i = 1; i < m; i++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
                minPos = i;
            }
        }
        
        int temp = arr[minPos][j];
        arr[minPos][j] = arr[j][j];
        arr[j][j] = temp;
    }
    
    printf("\nTabloul dupa interschimbarea valorilor minime cu diagonala principala:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}