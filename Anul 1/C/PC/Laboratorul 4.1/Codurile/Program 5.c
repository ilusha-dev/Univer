#include <stdio.h>

int main() {
    int n, i, A[30];
    printf("Introduce-ti numarul de elemente n (<=30): ");
    scanf("%d", &n);
    printf("Introduce-ti elementele vectorului: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            A[i] = A[i] * A[i];
        } else {
            A[i] = A[i] + 20;
        }
    }

    printf("Vectorul dupa modificare: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
