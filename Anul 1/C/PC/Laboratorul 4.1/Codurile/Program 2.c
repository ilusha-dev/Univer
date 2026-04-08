#include <stdio.h>

int main() {
    int A[30], sum, n;

    printf("Introduce-ti numarul de elemente al tabloului (n <=30): ");
    scanf("%d", &n);

    printf("Introduce-ti elementele tabloului: \n");
    for(int i = 0; i < n; i++) {
        printf("Elementele tabloului: ");
        scanf("%d", &A[i]);

        if (A[i] >= 0) {
            sum += A[i];
        }
    }
    printf("Suma elementelor pozitive in tablou este: %d\n", sum);

    return 0;
}