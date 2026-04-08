// Problema 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void random_arr(int **arr, int n, int m) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            *(*(arr + i) + j) = rand() % 9;
}

void printArray(int **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%4d", *(*(arr + i) + j));
        printf("\n");
    }
}

int extrage(int **arr, int n, int m, int *v) {
    int len = 0, neg = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (*(arr + j) % 2 == 1) {
                len++;
                if (len < 0){
                    v[neg++] = *(*(arr + i) + j);
    return neg;
        }
    }
}

void merge (int **arr, int l, int m, int r) {
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int **arr, int l, int r){
    
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(**arr, l, m);
        mergeSort(**arr, m + 1, r);

        merge(**arr, l, m, r);
    }
}

int main() {
    int n, m;
    printf("n = "); scanf("%d", &n);
    printf("m = "); scanf("%d", &m);

    int **arr = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        *(arr + i) = malloc(m * sizeof(int));

    random_arr(arr, n, m);
    printf("\nMatricea:\n");
    printArray(arr, n, m);

    int *v = malloc(n * m * sizeof(int));
    int neg = extrage(**arr, n, m, v);

    printf("\nVectorul elementelor pare :\n");
    for (int i = 0; i < len; i++)
        printf("%4d", v[i]);

    mergeSort(**arr, l, r);

    printf("\n\nVectorul sortat:\n");
    for (int i = 0; i < len; i++)
        printf("%4d", v[i]);
    printf("\n");

    free(v);
    for (int i = 0; i < n; i++)
        free(*(arr + i));
    free(arr);

    return 0;
}
