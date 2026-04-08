#include <stdio.h> 

void citireArray(int (*arr)[20], int *m, int *n) {
    printf("Introduceti elementele array-ului (%d linii si %d coloeane): \n", *m, *n);
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            scanf("%d", *(*(arr + i) + j));
        }
    }
}

void afisareArray(int (*arr)[20], int *m, int *n) {
    printf("Array-ul introdus este: \n");
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            printf("%4d", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int gasestePare(int (*arr)[20], int *m, int *n, int *A, int linie[30], int coloana[30]) {
    int k = 0;

    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            if (*(*(arr + i) + j) % 2 == 0) {
                *(A + k) = *(*(arr + i) + j);
                linie[k] = i;
                coloana[k] = j;
                k++;
            }
        }
    }
    return k;
}

void afisareVector(int *A, int linie[30], int coloana[30], int k) {
    printf("Elementele pare gasite sunt: \n");
    for (int i = 0; i < k; i++) {
        printf("%d ", *(A + i));
    }

    printf("\n\nIndicii elementelor pare (linie, coloana): \n");
    for (int i = 0; i < k; i++) {
        printf("Element %d la pozitia (%d, %d)\n", *(A + i), linie[i], coloana[i]);
    }
}

int main() { 
    int arr[20][20], A[50], linie[30], coloana[30];
    int m, n;
    printf("Introduceti numarul de linii (M): ");
    scanf("%d", &m);
    printf("Introduceti numarul de coloane (N): ");
    scanf("%d", &n);
    citireArray(arr, &m, &n);
    afisareArray(arr, &m, &n);
    int k = gasestePare(arr, &m, &n, A, linie, coloana);
    afisareVector(A, linie, coloana, k);

    return 0;
}