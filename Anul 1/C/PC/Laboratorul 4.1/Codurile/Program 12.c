//Problema 3

#include <stdio.h>

int main() {
    int n, vector[n];
    printf("Introduce-ti numarul de elemente (n): ");
    scanf("%d", &n);

    printf("Introduce-ti valorile vectorului: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }

    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += vector[i];
    }
    printf("Media aritmetica a elementelor: %.2f\n", (float)suma / n);

    if (n % 2 == 0)
        printf("Numarul de elemente este par.\n");
    else
        printf("Numarul de elemente este impar.\n");

    return 0;
}
