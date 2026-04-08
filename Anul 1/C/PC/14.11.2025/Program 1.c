#include <stdio.h>

int main() {
    int eleMax, n, m;

    printf("Introduce-ti valoarea lui n: ");
    scanf("%d\n", &n);
    printf("Introduce-ti valoarea lui m: ");
    scanf("%d\n", &m);

    int A[n][m], arrMax[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%i", A[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
           printf("%i\t", A[i][j]);}
           printf("\n");
    }
    for (int i = 0; i < n; i++) {
        eleMax = A[i][0];
        for (int j = 0; i < m; i++) {
            if (eleMax < A[i][j]) {
                eleMax = A[i][j];
                arrMax[n] = eleMax;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%i", arrMax[n]);
    }
    return 0;
}