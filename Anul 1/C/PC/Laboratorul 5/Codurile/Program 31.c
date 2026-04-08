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
    
    for (int i = 0; i < m; i++) {
        int maxVal = arr[i][0];
        int maxPos_c = 0;
        
        for (int j = 1; j < n; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
                maxPos_c = j;
            }
        }
        
        printf("Linia %d: Valoarea maxima este %d, pozitia coloanei: %d\n", i+1, maxVal, maxPos_c+1);
    }
    
    int sumaNegativa = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < 0) {
                sumaNegativa += arr[i][j];
            }
        }
    }
    
    printf("Suma tuturor elementelor negative din tablou este: %d\n", sumaNegativa);
    
    return 0;
}