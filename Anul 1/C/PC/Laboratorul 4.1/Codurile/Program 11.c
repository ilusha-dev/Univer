//Problema 7

#include <stdio.h>

int main() {
    int n;
    printf("Introduce-ti numarul de elemente (n): ");
    scanf("%d", &n);

    int vector1[n], vector2[n];
    printf("Introduce-ti valorile primului vector: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector1[i]);
    }

    printf("Introduce-ti valorile celui de-al doilea vector: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector2[i]);
    }

    int vector3[n], cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vector1[i] % 2 != 0) {
            vector3[cnt++] = vector1[i];
        }
        if (vector2[i] % 2 != 0) {
            vector3[cnt++] = vector2[i];
        }
    }

    printf("Vectorul cu elementele impare: \n");
    for (int i = 0; i < cnt; i++) {
        printf("%d ", vector3[i]);
    }
    printf("\n");

    return 0;
}
