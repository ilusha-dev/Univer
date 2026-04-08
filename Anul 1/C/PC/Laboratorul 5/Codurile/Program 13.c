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
    
    int minPozitiv = INT_MAX;
    int maxNegativ = INT_MIN; 
    int pozMinPozitiv_r = -1, pozMinPozitiv_c = -1;
    int pozMaxNegativ_r = -1, pozMaxNegativ_c = -1;
 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > 0 && arr[i][j] < minPozitiv) {
                minPozitiv = arr[i][j];
                pozMinPozitiv_r = i + 1;
                pozMinPozitiv_c = j + 1;
            }
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (arr[i][j] < 0 && arr[i][j] > maxNegativ) {
                maxNegativ = arr[i][j];
                pozMaxNegativ_r = i + 1;
                pozMaxNegativ_c = j + 1;
            }
        }
    }

    if (pozMinPozitiv_r != -1) {
        printf("Primul element minim pozitiv este: %d la pozitia (%d, %d)\n", minPozitiv, pozMinPozitiv_r, pozMinPozitiv_c);
    } else {
        printf("Nu exista elemente pozitive in tablou.\n");
    }

    if (pozMaxNegativ_r != -1) {
        printf("Ultimul element maxim negativ este: %d la pozitia (%d, %d)\n", maxNegativ, pozMaxNegativ_r, pozMaxNegativ_c);
    } else {
        printf("Nu exista elemente negative in tablou.\n");
    }

    return 0;
}
