#include <stdio.h>
#include <limits.h>

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
    
    int maxNegativ = INT_MIN;
    int pozMaxNegativ_r = -1, pozMaxNegativ_c = -1;
    int numarPozitive = 0;
 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < 0 && arr[i][j] > maxNegativ) {
                maxNegativ = arr[i][j];
                pozMaxNegativ_r = i + 1;
                pozMaxNegativ_c = j + 1;
            }
            if (arr[i][j] > 0) {
                numarPozitive++;
            }
        }
    }
    
    if (pozMaxNegativ_r != -1) {
        printf("Valoarea maxima negativa este: %d la pozitia (%d, %d)\n", maxNegativ, pozMaxNegativ_r, pozMaxNegativ_c);
    } else {
        printf("Nu exista elemente negative in tablou.\n");
    }
    
    printf("Numarul elementelor pozitive este: %d\n", numarPozitive);
    
    return 0;
}