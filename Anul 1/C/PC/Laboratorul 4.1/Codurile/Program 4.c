#include <stdio.h>

int main() {
    int n, y, i, A[30], found = 0;

    printf("Introduce-ti numarul de elemente n (<=30): ");
    scanf("%d", &n);
    printf("Introduce-ti elemenele vectorului: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Introduce-ti valoarea y: ");
    scanf("%d", &y);

    for (i = 0; i < n; i++) {
        if (A[i] == y) {
            printf("Primul element egal cu %d se afla pe pozitia %d.\n", y, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Nu exista niciun element egal cu %d în vector.\n", y);
    }

    return 0;
}
