#include <stdio.h>

int main() {
    int n, i, A[30];

    printf("Introduce-ti numarul de elemente n (<=30): ");
    scanf("%d", &n);
    printf("Introduce-ti elementele vectorului: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < n / 2; i++) {
        int temp = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = temp;
    }

    printf("Vectorul dupa modificare: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
